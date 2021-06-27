import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
import "bootstrap/dist/js/bootstrap.min.js"
import "bootstrap/dist/css/bootstrap.min.css"
import "../public/style.css"

const app = createApp(App);
getQuestions();
app.use(router).mount('#app');

async function getQuestions() {
    await fetch("http://localhost:5002/questions")
        .then(response => response.json())
        .then(data => {
            app.config.globalProperties.questionData = data;
        })
        .catch(error => console.error(error));
}