<template>
  <div
    class="modal fade"
    id="teamCreator"
    tabindex="-1"
    role="dialog"
    aria-labelledby="exampleModalLabel"
    aria-hidden="true"
  >
    <div class="modal-dialog" role="document">
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="exampleModalLabel">
            Neues Team erstellen
          </h5>
          <button
            type="button"
            class="btn-close"
            data-bs-dismiss="modal"
            aria-label="Close"
          ></button>
        </div>
        <div class="modal-body">
          <p class="inputHeader">Teamnamen eingeben:</p>
          <input
            class="form-control"
            type="text"
            id="teamName"
            v-model="name"
            name="name"
          />
          <br />
          <p class="inputHeader">Teamfarbe auswählen</p>
          <input
            class="form-control colorPicker"
            type="color"
            id="teamColor"
            name="color"
            v-model="color"
          />
        </div>
        <div class="modal-footer">
          <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">
            Abbruch
          </button>
          <button
            type="button"
            id="Send"
            class="btn btn-success"
            data-bs-dismiss="modal"
            v-on:click="submitted()"
          >
            Team erstellen
          </button>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: "AddTeam",
  data() {
    return {
      name: "",
      color: "",
    };
  },
  methods: {
    submitted() {
      var name = document.getElementById("teamName").value;
      var color = document.getElementById("teamColor").value;
      var points = 0;
      if (!this.name) {
        alert("Keinen Namen vergeben");
        return;
      }

      const newTeam = {
        name: name,
        color: color,
        points: points,
        turn: false,
      };

      this.$emit("add-team", newTeam);
      console.log(newTeam);

      (this.name = ""), (this.color = "");
    },
  },
};
</script>

<style scoped>
.inputHeader {
  font-size: 18px;
  margin-bottom: 3px;
  margin-left: 3px;
  text-decoration: underline;
  text-align: left;
}

.colorPicker {
  padding: 0 0 0 0;
}
</style>