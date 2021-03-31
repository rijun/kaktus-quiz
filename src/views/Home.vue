<template>
  <AddTeam @add-team="addTeam" />
  <Teams :teams="teams" />
  <router-link to="/selection" class="btn btn-primary" tag="button"
    >Quiz starten"</router-link
  >
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
};
</script>