<template>
  <div>
    <AppHeader />
    <AddTeam />
  </div>
</template>

<script>
import AppHeader from "./components/AppHeader";
import Button from "./components/Buttons";
import AddTeam from "./components/AddTeam";

export default {
  name: "App",
  components: {
    AppHeader,
    Button,
    AddTeam,
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
</style>
