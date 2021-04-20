<template>
  <div class="container">
    <div class="row justify-content-center">
      <router-link to="/question" class="btn question col-3">Frage 1</router-link>
      <router-link to="/question" class="btn question col-3">Frage 2</router-link>
      <router-link to="/question" class="btn question col-3">Frage 3</router-link>
      <router-link to="/question" class="btn question col-3">Frage 4</router-link>
    </div>
    <div class="row justify-content-center">
      <router-link to="/question" class="btn question col-3">Frage 5</router-link>
      <router-link to="/question" class="btn question col-3">Frage 6</router-link>
      <router-link to="/question" class="btn question col-3">Frage 7</router-link>
      <router-link to="/question" class="btn question col-3">Frage 8</router-link>
    </div>
    <div class="row justify-content-center">
      <router-link to="/question" class="btn question col-3">Frage 9</router-link>
      <router-link to="/question" class="btn question col-3">Frage 10</router-link>
      <router-link to="/question" class="btn question col-3">Frage 11</router-link>
      <router-link to="/question" class="btn question col-3">Frage 12</router-link>
    </div>
    <div class="row justify-content-center">
      <router-link to="/question" class="btn question col-3">Frage 13</router-link>
      <router-link to="/question" class="btn question col-3">Frage 14</router-link>
      <router-link to="/question" class="btn question col-3">Frage 15</router-link>
      <router-link to="/question" class="btn question col-3">Frage 16</router-link>
    </div>
  </div>
</template>

<script>
import Button from "../components/Buttons";

export default {
  name: "Selection",
  components: {
    Button,
  },
};
</script>

<style scoped>
.question {
  background-color: darkblue;
  color: white;
  text-align: center;
  font-size: 20px;
  border: 2px solid white;
  display: -webkit-flex;
  display: -ms-flexbox;
  display: flex;
  flex-direction: column;
  height: 10rem;
  justify-content: center;
}
</style>
