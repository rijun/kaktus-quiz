<template>
  <AddTeam @add-team="addTeam" />
  <Teams :teams="teams" />
  <router-link
    to="/selection"
    class="btn btn-lg btn-primary btn-start"
    tag="button"
    @click="startQuiz"
    >Quiz starten</router-link
  >
  <Button text="TEst" @click="startQuiz"/>
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
    startQuiz() {
      
      console.log("Blin");
    },
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
  async unmounted() {
    console.log("Accessed Button");
    let bttn = document.getElementById("createTeam");
    bttn.classList.add("hidden");
  },
};
</script>

<style scoped>
</style>