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
    const dropArea = document.querySelector(".drag-area");
    const dragText = document.querySelector(".header");

    let button = dropArea.querySelector(".button");
    let input = dropArea.querySelector("input");

    let file;

    button.onclick = () => {
      input.click();
    };

    // when browse
    input.addEventListener("change", function() {
      file = this.files[0];
      dropArea.classList.add("active");
      displayFile();
    });

    // when file is inside drag area
    dropArea.addEventListener("dragover", (event) => {
      event.preventDefault();
      dropArea.classList.add("active");
      dragText.textContent = "Release to Upload";
      // console.log('File is inside the drag area');
    });

    // when file leave the drag area
    dropArea.addEventListener("dragleave", () => {
      dropArea.classList.remove("active");
      // console.log('File left the drag area');
      dragText.textContent = "Drag & Drop";
    });

    // when file is dropped
    dropArea.addEventListener("drop", (event) => {
      event.preventDefault();
      // console.log('File is dropped in drag area');

      file = event.dataTransfer.files[0]; // grab single file even of user selects multiple files
      // console.log(file);
      displayFile();
    });

    function displayFile() {
      let fileType = file.type;
      // console.log(fileType);

      let validExtensions = ["image/jpeg", "image/jpg", "image/png"];

      //if (validExtensions.includes(fileType)) {
        // console.log('This is an image file');
        let fileReader = new FileReader();

        fileReader.onload = () => {
          let fileURL = fileReader.result;
          // console.log(fileURL);
          let imgTag = `<img src="${fileURL}" alt="">`;
          dropArea.innerHTML = imgTag;
        };
        fileReader.readAsDataURL(file);
      /* } else {
        alert("This is not an Image File");
        dropArea.classList.remove("active");
      } */
    }
  },
};
</script>

<style scoped>
.header{
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
