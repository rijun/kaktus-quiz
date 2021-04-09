<template>
  <div class="container">
    <div class="row justify-content-center">
      <div class="question col-3">One of four</div>
      <div class="question col-3">Two of four</div>
      <div class="question col-3">Three of four</div>
      <div class="question col-3">Four of four</div>
    </div>
    <div class="row justify-content-center">
      <div class="question col-3">One of four</div>
      <div class="question col-3">Two of four</div>
      <div class="question col-3">Three of four</div>
      <div class="question col-3">Four of four</div>
    </div>
    <div class="row justify-content-center">
      <div class="question col-3">One of four</div>
      <div class="question col-3">Two of four</div>
      <div class="question col-3">Three of four</div>
      <div class="question col-3">Four of four</div>
    </div>
    <div class="row justify-content-center">
      <div class="question col-3">One of four</div>
      <div class="question col-3">Two of four</div>
      <div class="question col-3">Three of four</div>
      <div class="question col-3">Four of four</div>
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
  font-size: 20px;
  border: 2px solid white;
  height: 20%;
  width: 20%;
}
</style>
