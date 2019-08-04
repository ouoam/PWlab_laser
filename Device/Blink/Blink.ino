// https://www.makearduino.com/article/6/stm32-arduino-%E0%B9%80%E0%B8%88%E0%B8%B2%E0%B8%B0%E0%B8%A5%E0%B8%B6%E0%B8%81-pwm-timer

uint16_t frequency[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200, 300, 400, 500, 900, 0};                     // in Hz
uint16_t duration[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 0}; // in us
uint8_t iFreq = 0;
uint8_t iDura = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(PA0, INPUT_PULLDOWN);
  pinMode(PA1, INPUT_PULLDOWN);
  pinMode(PA2, INPUT_PULLDOWN);
  pinMode(PA3, INPUT_PULLDOWN);

  pinMode(PB6,PWM);

  Timer3.setPrescaleFactor(2);
  pinMode(PA6,PWM);

  setTimer();
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(PA0)) {
    iDura++;
    if (duration[iDura] == 0) iDura--;
    delay(300);
    setTimer();
  }
  if (digitalRead(PA1)) {
    if (iDura == 0) iDura++;
    iDura--;
    delay(300);
    setTimer();
  }

  if (digitalRead(PA2)) {
    iFreq++;
    if (frequency[iFreq] == 0) iFreq--;
    delay(300);
    setTimer();
  }
  if (digitalRead(PA3)) {
    if (iFreq == 0) iFreq++;
    iFreq--;
    delay(300);
    setTimer();
  }
}

void setTimer() {
  uint32_t prescaleFactor = 1;
  prescaleFactor = ((long double)F_CPU / 65536.0 / frequency[iFreq]) + 1;
  Timer4.setPrescaleFactor(prescaleFactor);
  Timer4.setOverflow(F_CPU / (frequency[iFreq] * prescaleFactor));

  pwmWrite(PB6,map(duration[iDura], 0, 1000000 / frequency[iFreq], 0, Timer4.getOverflow()));

  pwmWrite(PA6,map(duration[iDura], 0, 1600, 0, 65535));
}
