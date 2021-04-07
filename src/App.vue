<template>
  <div>
    <AppHeader />
    <router-view></router-view>
  </div>
</template>

<script>
import AppHeader from "./components/AppHeader";

export default {
  name: "App",
  components: {
    AppHeader,
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
}

body {
  min-height: 100%;
  background-color: slategray;
  background-image: url("./assets/bamboo-forest.jpeg");
}
</style>
