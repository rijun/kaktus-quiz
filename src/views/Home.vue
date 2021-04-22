<template>
  <AddTeam @add-team="addTeam" />
  <Teams :teams="teams" />
  <router-link
    to="/selection"
    class="btn btn-lg btn-primary btn-start"
    tag="button"
    >Quiz starten</router-link
  >
  <button v-on:click="selectTeam">Get Weather Data</button>
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
      weatherDataList: [],
    };
  },
  methods: {
    selectTeam() {
      //here I am fetching all the data from the teams json file
      fetch("http://localhost:5001/teams")
        .then((response) => response.json())
        .then((data) => (this.weatherDataList = data));
      //here i am going through the json and save all IDs in an array
      let idList = [];
      this.weatherDataList.forEach((teamID) => {
        console.log(teamID.id);
        idList.push(teamID.id);
      });
      //here i am generating a random number and select array position
      var obj_keys = Object.keys(idList);
      var ran_key = obj_keys[Math.floor(Math.random() * obj_keys.length)];
      let selectedID = idList[ran_key];
      console.log("SELECTED " + selectedID);

      /*  const toggleTask = await this.fetchTask(id);
      const updateTask = { ...toggleTask, reminder: !toggleTask.reminder };

      const res = await fetch(`api/tasks/${id}`, {
        method: "PUT",
        headers: {
          "Content-type": "application/json",
        },
        body: JSON.stringify(updateTask),
      });

      const data = await res.json();

      this.tasks = this.tasks.map((task) =>
        task.id === id ? { ...task, reminder: data.reminder } : task
      ); */
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