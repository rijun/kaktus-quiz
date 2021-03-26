<template>
  <div class="container">
    <div class="row justify-content-around">
      <div class="col-3 addedTeam" :key="team.id" v-for="team in teams">
        <h2 class="teamName">{{ team.name }}</h2>
        <h4 class="teamPoints">Punktestand: {{ team.points}}</h4>
        <label>Teamfarbe:</label>
        <p class="teamColor" :style="{background: team.color }"></p>
      </div>
    </div>
  </div>
</template>

<script>
import Team from "./Team";

export default {
  name: "Teams",
  props: {
    teams: Array,
  },
  components: {
    Team,
  },
};
</script>

<style scoped>
.addedTeam {
  border-radius: 15px;
  border: 2px solid black;
  color: black;
  background-color: whitesmoke;  
}

.teamName{
  text-decoration: underline;
  margin-bottom: 50px;
}

.colorLabel {
  margin-top: 50px;
  text-align: left;
}

.teamColor {
  border-radius: 10px;
  border: 4px solid black;
  margin: 0px 30px 50px 30px;
  padding: 20px; 
  width: auto;
  height: auto;  
}

</style>