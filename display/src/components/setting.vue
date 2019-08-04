<template>
  <v-container px-2 pt-2 pb-0 grid-list-xl>
    <v-layout text-xs-center wrap>
      <v-flex xs12 pt-0 pb-0>
        <h1 class="display-3 font-weight-medium">Setting</h1>
      </v-flex>

      <v-flex xs12 pb-2 pt-3>
        <v-btn
          large
          block
          class="py-2 my-0 px-2 text-none"
          style="height: auto;"
          @click.stop="dialog = true"
          color="blue-grey lighten-4"
        >
          <h2 class="display-1 font-weight-medium">Time :</h2>
          <v-spacer />
          <h2 class="display-1 font-weight-regular">{{min}}:00</h2>
          <h2 class="display-1 font-weight-medium">&nbsp;min</h2>
        </v-btn>
      </v-flex>

      <v-flex xs12 pt-2 pb-2>
        <v-btn
          large
          block
          class="py-2 my-0 px-2 text-none"
          style="height: auto;"
          @click.stop="dialog2 = true"
          color="blue-grey lighten-4"
        >
          <h2 class="display-1 font-weight-medium">Pre-temp :</h2>
          <v-spacer />
          <h2 class="display-1 font-weight-regular">{{temp}}</h2>
          <h2 class="display-1 font-weight-medium">&nbsp;°C</h2>
        </v-btn>
      </v-flex>

      <v-flex xs12 pb-2 pt-3>
        <!-- <v-card style="height: 144px;">
          <v-card-title class="pb-0">
            <h2 class="headline font-weight-medium">Status</h2>
          </v-card-title>
          <v-layout column justify-space-around style="height: calc(100% - 48px);">
            <v-card-text class="headline px-0">
              Wait for temp
              <br />Remaining 999 sec
            </v-card-text>
          </v-layout>
        </v-card>-->
        <v-card style="height: 144px;">
          <v-card-title class="pb-0">
            <h2 class="headline font-weight-medium">Status</h2>
          </v-card-title>
          <v-layout column justify-space-around style="height: calc(100% - 48px);">
            <v-card-text class="display-1 font-weight-medium px-0">READY</v-card-text>
          </v-layout>
        </v-card>
        <!-- <v-card style="height: 144px;" color="red" dark>
          <v-card-title class="pb-0">
            <h2 class="headline font-weight-medium">Status</h2>
          </v-card-title>
          <v-layout column justify-space-around style="height: calc(100% - 48px);">
            <v-card-text class="display-1 font-weight-medium px-0">WATER FULL</v-card-text>
          </v-layout>
        </v-card>-->
      </v-flex>

      <v-flex xs6 pb-0>
        <v-btn
          large
          class="display-1 px-3 py-2 my-0 font-weight-medium"
          style="height: auto"
          block
          color="success"
          to="run"
        >START</v-btn>
      </v-flex>
      <v-flex xs6 pb-0>
        <v-btn
          large
          class="display-1 px-3 py-2 my-0 font-weight-medium"
          style="height: auto"
          block
          color="error"
        >STOP</v-btn>
      </v-flex>
    </v-layout>

    <v-dialog v-model="dialog" width="70%">
      <v-card class="text-xs-center">
        <v-card-text>
          <h2 class="display-2 font-weight-bold">Time</h2>
        </v-card-text>

        <v-card-text>
          <v-layout justify-center row wrap>
            <v-flex xs8>
              <v-btn
                large
                class="display-1 px-2 py-2"
                style="height: auto"
                color="primary"
                @click="min++"
              >+</v-btn>
            </v-flex>
            <v-flex xs4></v-flex>
            <v-flex xs8>
              <h2 class="display-1 font-weight-medium my-2">{{min}}:00</h2>
            </v-flex>
            <v-flex xs4>
              <h2 class="display-1 font-weight-medium my-2">min</h2>
            </v-flex>
            <v-flex xs8>
              <v-btn
                large
                class="display-1 px-2 py-2"
                style="height: auto"
                color="primary"
                @click="min--"
              >-</v-btn>
            </v-flex>
            <v-flex xs4></v-flex>
          </v-layout>
        </v-card-text>
      </v-card>
    </v-dialog>

    <v-dialog v-model="dialog2" width="70%">
      <v-card class="text-xs-center">
        <v-card-text>
          <h2 class="display-2 font-weight-bold">Pre-temp</h2>
        </v-card-text>

        <v-card-text>
          <v-layout justify-center row wrap>
            <v-flex xs8>
              <v-btn
                large
                class="display-1 px-2 py-2"
                style="height: auto"
                color="primary"
                @click="temp++"
              >+</v-btn>
            </v-flex>
            <v-flex xs4></v-flex>
            <v-flex xs8>
              <h2 class="display-1 font-weight-medium my-2">{{temp}}</h2>
            </v-flex>
            <v-flex xs4>
              <h2 class="display-1 font-weight-medium my-2 pr-2">°C</h2>
            </v-flex>
            <v-flex xs8>
              <v-btn
                large
                class="display-1 px-2 py-2"
                style="height: auto"
                color="primary"
                @click="temp--"
              >-</v-btn>
            </v-flex>
            <v-flex xs4></v-flex>
          </v-layout>
        </v-card-text>
      </v-card>
    </v-dialog>
  </v-container>
</template>

<script>
export default {
  data() {
    return {
      dialog: false,
      dialog2: false,
      temp: 0,
      min: 10
    };
  }
};
</script>