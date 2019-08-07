// https://www.makearduino.com/article/6/stm32-arduino-%E0%B9%80%E0%B8%88%E0%B8%B2%E0%B8%B0%E0%B8%A5%E0%B8%B6%E0%B8%81-pwm-timer

#define WORKING_PIN PA6
#define AIMING_PIN PA7
#define LASER_PIN PB6
#define BTN_PIN PB15

uint16_t setFreq = 0;   // Max 65535
uint16_t setDura = 0;   // Max 65535
uint8_t setMode = 0;    // Val 0 - 2
uint8_t setWorking = 0; // Val 0 - 100
uint8_t setAiming = 0;  // Val 0 - 100

uint16_t setOnTime = 100;   // Max 65535
uint16_t setOffTime = 100;  // Max 65535

bool enable = false;
bool lastBTNstage = LOW;
uint64_t startTime = 0;
uint16_t pwmDuty = 0;

void setup() {
  Serial.begin(115200);

  pinMode(LASER_PIN, PWM);
  pwmWrite(LASER_PIN, 0);

  pinMode(WORKING_PIN, PWM);
  pinMode(AIMING_PIN, PWM);
  pwmWrite(WORKING_PIN, 0);
  pwmWrite(AIMING_PIN, 0);

  pinMode(BTN_PIN, INPUT_PULLDOWN);
}

void loop() {
  if (Serial.available()) {
    char inByte = Serial.read();
    switch(inByte) {
      case 'd': case 'D':
        setDura = getNum();
        break;
        
      case 'f': case 'F':
        setFreq = getNum();
        break;
        
      case 'm': case 'M':
        setMode = getNum() % 3;
        break;
        
      case 'e': case 'E':
        enable = getNum() != 0;
        if (enable) {
          setTimer();
          pwmDuty = map(setDura, 0, 1000000 / setFreq, 0, Timer4.getOverflow());
        }
        else pwmWrite(LASER_PIN,0);
        break;

      case 'w': case 'W':
        setWorking = getNum() % 101;
        pwmWrite(WORKING_PIN, map(setWorking, 0, 100, 0, 65535));
        break;

      case 'a': case 'A':
        setAiming = getNum() % 101;
        pwmWrite(AIMING_PIN, map(setAiming, 0, 100, 0, 65535));
        break;
        
      case '+':
        setOnTime = getNum();
        break;
      case '-':
        setOffTime = getNum();
        break;
    }
  }

  if (!enable) return;
  
  bool BTNstage = getBtn();
  if (!BTNstage) {              // Not press
    pwmWrite(LASER_PIN,0);
    lastBTNstage = BTNstage;
    return;
  } else if (!lastBTNstage) {   // Press but not before
    startTime = millis();
  }
  
  switch(setMode) {
    case 0:
      if (millis() - startTime < 900) pwmWrite(LASER_PIN, pwmDuty);
      else pwmWrite(LASER_PIN, 0);
      break;
    case 1:
      pwmWrite(LASER_PIN, pwmDuty);
      break;
    case 2:
      if ((millis() - startTime) % (setOnTime + setOffTime) < setOnTime) {
        pwmWrite(LASER_PIN, pwmDuty);
      } else pwmWrite(LASER_PIN, 0);
  }

  lastBTNstage = BTNstage;
}

uint64_t lastBTN = 0;
bool getBtn() {
  bool BTNstage = digitalRead(BTN_PIN);
  if (millis() - lastBTN <= 50) return HIGH;
  else {
    if (BTNstage) lastBTN = millis();
    else lastBTN = 0;
    return BTNstage;
  }
}

uint64_t getNum() {
  uint64_t in = 0;
  while(Serial.available()) {
    in *= 10;
    in += Serial.read() - '0';
  }
  return in;
}

void setTimer() {
  if (setFreq == 0) return;
  uint32_t prescaleFactor = ((long double)F_CPU / 65536.0 / setFreq) + 1;
  Timer4.setPrescaleFactor(prescaleFactor);
  Timer4.setOverflow(F_CPU / (setFreq * prescaleFactor));
}
