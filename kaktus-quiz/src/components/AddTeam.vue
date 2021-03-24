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
            
          </div>
          <div class="modal-footer">
            <button
              type="button"
              class="btn btn-secondary"
              data-dismiss="modal"
            >
              Abbruch
            </button>
            <button type="button" class="btn btn-primary">
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
      text: "",
      day: "",
      reminder: false,
    };
  },
  methods: {
    onSubmit(e) {
      e.preventDefault();

      if (!this.text) {
        alert("Keine Teilnehmer ausgewählt");
        return;
      }

      const newTask = {
        text: this.text,
        day: this.day,
        reminder: this.reminder,
      };

      this.$emit("add-team", newTask);
      console.log(newTask);

      (this.text = ""), (this.day = ""), (this.reminder = false);
    },
  },
};
</script>

<style scoped>

</style>