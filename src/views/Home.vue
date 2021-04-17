<template>
  <AddTeam @add-team="addTeam" />
  <Teams :teams="teams" />
  <router-link
    to="/selection"
    class="btn btn-lg btn-primary btn-start"
    tag="button" 
    >Quiz starten</router-link
  >
  <button @click="quizStarted">Greet</button>
</template>

<script>
import Button from "../components/Buttons";
import AddTeam from "../components/AddTeam";
import Teams from "../components/Teams";



export default {
  name: "Home",
  components: {
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
  quizStarted: function(event) {
   alert('Hello Vadim!')
  },
};
</script>

<style scoped>

</style>