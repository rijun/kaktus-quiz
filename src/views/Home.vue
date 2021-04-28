<template>
  <AddTeam @add-team="addTeam" />
  <Teams :teams="teams" />
  <router-link
    to="/selection"
    class="btn btn-lg btn-primary btn-start"
    tag="button"
    @click="selectTeam"
    >Quiz starten</router-link
  >
</template>

<script>
import Button from "../components/Buttons";
import AddTeam from "../components/AddTeam";
import Teams from "../components/Teams";
import { onBeforeMount } from "vue";

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
      weatherDataList: [],
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

    async selectTeam() {
      //here I am fetching all the data from the teams json file
      fetch("http://localhost:5001/teams")
        .then((response) => response.json())
        .then((data) => (this.weatherDataList = data));
      //here i am going through the json and save all IDs in an array
      let idList = [];
      this.weatherDataList.forEach((teamID) => {
        idList.push(teamID.id);
      });
      //here i am generating a random number and select array position
      var obj_keys = Object.keys(idList);
      var ran_key = obj_keys[Math.floor(Math.random() * obj_keys.length)];
      var id = idList[ran_key];
      console.log("SELECTED " + id);
    
      //map allows to manipulate the array and return the array
      const toggleTeam = await this.fetchTeam(id);
      const updateTeam = { ...toggleTeam, turn: !toggleTeam.turn };

      const res = await fetch(`http://localhost:5001/teams/${id}`, {
        method: "PUT", //PUT is used for modifying json
        headers: {
          "Content-type": "application/json",
        },
        body: JSON.stringify(updateTeam),
      });

      const data = await res.json();

      this.teams = this.teams.map((team) =>
        team.id === id ? { ...team, turn: data.turn } : team
      );
    },

    async fetchTeams() {
      const res = await fetch("http://localhost:5001/teams");

      const data = await res.json();

      return data;
    },
    async fetchTeam(id) {
      const res = await fetch(`http://localhost:5001/teams/${id}`);

      const data = await res.json();

      return data;
    },
  },
  async created() {
    this.teams = await this.fetchTeams();
  },
  //this function hides create team button
  async unmounted() {
    console.log("Accessed Button");
    let bttn = document.getElementById("createTeam");
    bttn.classList.add("hidden");
  },
};
</script>
