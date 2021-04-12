<template>
  <div class="container">
    <div class="row justify-content-center">
      <div class="question col-3">Frage 1</div>
      <div class="question col-3">Frage 2</div>
      <div class="question col-3">Frage 3</div>
      <div class="question col-3">Frage 4</div>
    </div>
    <div class="row justify-content-center">
      <div class="question col-3 align-middle">Frage 5</div>
      <div class="question col-3">Frage 6</div>
      <div class="question col-3">Frage 7</div>
      <div class="question col-3">Frage 8</div>
    </div>
    <div class="row justify-content-center">
      <div class="question col-3">Frage 9</div>
      <div class="question col-3">Frage 10</div>
      <div class="question col-3">Frage 11</div>
      <div class="question col-3">Frage 12</div>
    </div>
    <div class="row justify-content-center">
      <div class="question col-3">Frage 13</div>
      <div class="question col-3">Frage 14</div>
      <div class="question col-3">Frage 15</div>
      <div class="question col-3">Frage 16</div>
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
