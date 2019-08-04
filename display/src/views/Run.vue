<template>
  <v-container px-2 pt-2 pb-0 grid-list-l>
    <v-layout text-xs-center wrap>
      <v-flex xs12 pt-0 pb-0>
        <h1 class="display-3 font-weight-medium">Working</h1>
      </v-flex>

      <v-flex xs12 pb-2 pt-3>
        <v-card>
          <v-card-text class="pa-2">
            <v-layout row wrap>
              <v-flex xs12 pb-1>
                <h2 class="display-1 font-weight-medium">Time (Min)</h2>
              </v-flex>
              <v-flex xs3>
                <v-btn
                  large
                  class="display-1 mx-0 px-1 py-1 my-0 font-weight-medium"
                  style="height: auto; min-width: -webkit-fill-available;"
                  color="success"
                >-</v-btn>
              </v-flex>
              <v-flex xs6>
                <h2 class="display-1 font-weight-regular pt-1">{{min}}:00</h2>
              </v-flex>
              <v-flex xs3>
                <v-btn
                  large
                  class="display-1 mx-0 px-1 py-1 my-0 font-weight-medium"
                  style="height: auto; min-width: -webkit-fill-available;"
                  color="success"
                >+</v-btn>
              </v-flex>
            </v-layout>
          </v-card-text>
        </v-card>
      </v-flex>

      <v-flex xs12 pt-2 pb-2>
        <v-card>
          <v-card-text class="pa-2">
            <v-layout row wrap>
              <v-flex xs12 pb-1>
                <h2 class="display-1 font-weight-medium">Fan Speed</h2>
              </v-flex>
              <v-flex xs3>
                <v-btn
                  large
                  class="display-1 mx-0 px-1 py-1 my-0 font-weight-medium"
                  style="height: auto; min-width: -webkit-fill-available;"
                  color="success"
                >-</v-btn>
              </v-flex>
              <v-flex xs6>
                <h2 class="display-1 font-weight-regular pt-1">{{temp}}</h2>
              </v-flex>
              <v-flex xs3>
                <v-btn
                  large
                  class="display-1 mx-0 px-1 py-1 my-0 font-weight-medium"
                  style="height: auto; min-width: -webkit-fill-available;"
                  color="success"
                >+</v-btn>
              </v-flex>
            </v-layout>
          </v-card-text>
        </v-card>
      </v-flex>

      <v-flex xs12 py-2>
        <v-btn
          large
          class="display-1 px-3 py-2 my-0 font-weight-medium"
          style="height: auto"
          block
          color="primary"
        >DEFROST</v-btn>
      </v-flex>

      <v-flex xs6 pt-1 pb-0 pr-2>
        <v-btn
          large
          class="display-1 px-3 py-2 my-0 font-weight-medium"
          style="height: auto"
          block
          color="amber"
        >RESUME</v-btn>
      </v-flex>
      <v-flex xs6 pt-1 pb-0 pl-2>
        <v-btn
          large
          class="display-1 px-3 py-2 my-0 font-weight-medium"
          style="height: auto"
          block
          color="error"
        >STOP</v-btn>
      </v-flex>
    </v-layout>
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