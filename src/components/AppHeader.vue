<template>
  <div>
    <nav class="navbar navbar-expand-lg navbar-light">
      <img class="navbar-image" src="../assets/Logo_rund.png" />
      <div>
        <router-link class="navbar-brand" @click="unhideButton" to="/"
          >Kaktus-Quiz</router-link
        >
        <button
          class="navbar-toggler"
          type="button"
          data-toggle="collapse"
          data-target="#navbarNavAltMarkup"
          aria-controls="navbarNavAltMarkup"
          aria-expanded="false"
          aria-label="Toggle navigation"
        >
          <span class="navbar-toggler-icon"></span>
        </button>
      </div>
      <Button type="button" text="Add Quiz" id="addJSON" class="addJSON" data-bs-toggle="modal" data-bs-target="#AddJson"/>
      <Button
        type="button"
        text="Team Erstellen"
        id="createTeam"
        class="generateTeam"
        data-bs-toggle="modal"
        data-bs-target="#teamCreator"
      />
      <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
        <div class="navbar-nav ml-auto">
          <div id="Button"></div>
        </div>
      </div>
    </nav>
  </div>
</template>

<script>
import Button from "./Buttons";
import AddTeam from "./AddTeam";
import AddJSON from "./AddJson";
export default {
  name: "AppHeader",
  props: {
    title: String,
    showAddTask: Boolean,
  },
  components: {
    Button,
    AddTeam,
    AddJSON,
  },
  methods: {
    unhideButton() {
      let bttn = document.getElementById("createTeam");
      bttn.classList.remove("hidden");
      console.log("added Button");
    },
  },
};
</script>

<style scoped>
.generateTeam {
  font-size: 20px;
  height: 50px;
  width: 200px;
  position: absolute;
  right: 50px;
}

.addJSON {
  font-size: 20px;
  height: 50px;
  width: 200px;
  position: absolute;
  right: 300px;
}
</style>
