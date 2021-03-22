<template>
  <div>
    <AppHeader />
    <Button text="Generate Team"/>
  </div>
</template>

<script>
import AppHeader from "./components/AppHeader";
import Button from "./components/Buttons";

export default {
  name: "App",
  components: {
    AppHeader,
    Button,
  },
};

</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
