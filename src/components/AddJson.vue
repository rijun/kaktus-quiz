<template>
  <div
    class="modal fade"
    id="AddJson"
    tabindex="-1"
    role="dialog"
    aria-labelledby="exampleModalLabel"
    aria-hidden="true"
  >
    <div class="modal-dialog" role="document">
      <div class="modal-content">
        <div class="modal-header">
          <h5 class="modal-title" id="exampleModalLabel">
            Neuen Fragensatz importieren
          </h5>
          <button
            type="button"
            class="btn-close"
            data-bs-dismiss="modal"
            aria-label="Close"
          ></button>
        </div>
        <div class="modal-body drag-area">
          <div class="icon">
            <i class="fas fa-images"></i>
          </div>
          <span class="header">Drag & Drop</span>
          <span class="header">or <span class="button">browse</span></span>
          <input type="file" hidden />
        </div>
        <div class="modal-footer">
          <button
            type="button"
            class="btn btn-secondary"
            data-bs-dismiss="modal"
          >
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
  mounted() {
    ondragenter =
      "document.getElementById('output').textContent = ''; event.stopPropagation(); event.preventDefault();";
    ondragover = "event.stopPropagation(); event.preventDefault();";
    ondrop = "event.stopPropagation(); event.preventDefault()";
    dodrop(Event);

    function dodrop(event) {
      var dt = event.dataTransfer;
      var files = dt.files;

      for (var i = 0; i < files.length; i++) {
        output(
            files[i].name
        );
      }
    }

    function output(text) {
      document.getElementById("output").textContent += text;
      //dump(text);
    }
  },
};
</script>

<style scoped>
.header {
  background-color: white;
}

.inputHeader {
  font-size: 18px;
  margin-bottom: 3px;
  margin-left: 3px;
  text-decoration: underline;
  text-align: left;
}

.drag-area {
  border: 3px dashed #e0eafc;
  display: flex;
  align-items: center;
  justify-content: center;
  flex-direction: column;
  margin: 10px auto;
}

.drag-area .icon {
  font-size: 50px;
  color: #1683ff;
}

.drag-area .header {
  font-size: 20px;
  font-weight: 500;
  color: #34495e;
}

.drag-area .support {
  font-size: 12px;
  color: gray;
  margin: 10px 0 15px 0;
}

.drag-area .button {
  font-size: 20px;
  font-weight: 500;
  color: #1683ff;
  cursor: pointer;
}

.drag-area.active {
  border: 2px solid #1683ff;
}

.drag-area img {
  width: 100%;
  height: 100%;
  object-fit: cover;
}
</style>
