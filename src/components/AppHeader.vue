<template>
  <div>
      <nav class="navbar navbar-expand-lg navbar-light">
        <img
          class="navbar-image"
          src="https://kaktus-cloud.ddns.net/images/Logo_rund.png"
        />
        <div>
          <div class="text-center">
            <p class="navbar-brand">Kaktus-Quiz</p>
          </div>
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
        <Button text="Team Erstellen" class="generateTeam" data-toggle="modal" data-target="#myModal"/>
        <p id="replaceButton">HIII</p>
        <div class="collapse navbar-collapse" id="navbarNavAltMarkup">
          <div class="navbar-nav ml-auto">
            <div id="Button"></div>
          </div>
        </div>
      </nav>
  </div>
</template>

<script>
import Button from './Buttons';
import AddTeam from './AddTeam';
export default {
  name: "AppHeader",
    props: {
        title: String,
        showAddTask: Boolean,
    },
    components: {
        Button,
        AddTeam,
    }
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
</style>
