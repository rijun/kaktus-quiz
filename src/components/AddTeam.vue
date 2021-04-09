<template>
  <form @submit="onSubmit" class="add-form">
    <!-- <div class="form-control">
      <label>Task</label>
      <input type="text" v-model="text" name="text" placeholder="Add Task" />
    </div>
    <div class="form-control">
      <label>Day & Time</label>
      <input
        type="text"
        v-model="day"
        name="day"
        placeholder="Add Day & Time"
      />
    </div>
    <div class="form-control form-control-check">
      <label>Set Reminder</label>
      <input type="checkbox" v-model="reminder" name="reminder" />
    </div>

    <input type="submit" value="Save Task" class="btn btn-block" /> -->
    <div
      class="modal fade"
      id="myModal"
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
              class="close"
              data-dismiss="modal"
              aria-label="Close"
            >
              <span aria-hidden="true">&times;</span>
            </button>
          </div>
          <div class="modal-body">
            <p class="inputHeader">Teamnamen eingeben:</p>
            <input class="form-control" type="text" id="teamName" v-model="name" name="name" />
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
            <button
              type="button"
              class="btn btn-secondary"
              data-dismiss="modal"
            >
              Abbruch
            </button>
            <button
              type="button"
              id="Send"
              class="btn btn-success"
              data-dismiss="modal"
              v-on:click="submitted()"
            >
              Team erstellen
            </button>
          </div>
        </div>
      </div>
    </div>
  </form>
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
      var name = document.getElementById('teamName').value;
      var color = document.getElementById('teamColor').value;
      if (!this.name) {
        alert("Keinen Namen vergeben");
        return;
      }

      const newTeam = {
        name: name,
        color: color,
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