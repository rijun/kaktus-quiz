<template>
  <div>
    <AppHeader />
    <AddTeam />
    <Teams :teams="teams" />
  </div>
</template>

<script>
import AppHeader from "./components/AppHeader";
import Button from "./components/Buttons";
import AddTeam from "./components/AddTeam";
import Teams from "./components/Teams";

export default {
  name: "App",
  components: {
    AppHeader,
    Button,
    AddTeam,
    Teams,
  },
  data() {
    return {
      teams: [],
    };
  },
  methods: {
   async fetchTeams() {
     const res = await fetch('http://localhost:5001/teams')

     const data = await res.json()

     return data
    }
  },
  async created() {
    this.teams = await this.fetchTeams()
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
