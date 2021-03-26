<template>
  <div>
    <AppHeader />

    <AddTeam @add-team="addTeam" />

    <Teams :teams="teams" />
    <Button text="Quiz starten"/>
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
    async addTeam(team) {
      const res = await fetch("http://localhost:5001/teams", {
        method: "POST",
        headers: {
          "Content-type": "application/json",
        },
        body: JSON.stringify(team),
      });
      const data = await res.json();

      this.teams = [...this.teams, data];
    },
    async fetchTeams() {
      const res = await fetch("http://localhost:5001/teams");

      const data = await res.json();

      return data;
    },
  },
  async created() {
    this.teams = await this.fetchTeams();
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

body{
    min-height: 100%;
    background-color: slategray;
    background-image: url("./assets/bamboo-forest.jpeg");
}
</style>
