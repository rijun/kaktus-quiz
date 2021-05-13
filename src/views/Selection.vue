<template>
  <div class="container">
    <div class="row justify-content-center">
            <router-link :to="{ name: 'Question', params: { difficulty: 'easy', category: 'history' }}" class="btn question col-3">Geschichte - Einfach</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'easy', category: 'physics' }}" class="btn question col-3">Physik - Einfach</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'easy', category: 'film' }}" class="btn question col-3">Film & Gaming - Einfach</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'easy', category: 'world' }}" class="btn question col-3">Um die Welt - Einfach</router-link>
        </div>
        <div class="row justify-content-center">
            <router-link :to="{ name: 'Question', params: { difficulty: 'hard', category: 'history' }}" class="btn question col-3">Geschichte - Schwer</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'hard', category: 'physics' }}" class="btn question col-3">Physik - Schwer</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'hard', category: 'film' }}" class="btn question col-3">Film & Gaming - Schwer</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'hard', category: 'world' }}" class="btn question col-3">Um die Welt - Schwer</router-link>
        </div>
        <div class="row justify-content-center">
            <router-link :to="{ name: 'Question', params: { difficulty: 'easy', category: 'knowledge' }}" class="btn question col-3">Allgemeinwissen - Einfach</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'easy', category: 'politics' }}" class="btn question col-3">Politik - Einfach</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'easy', category: 'sport' }}" class="btn question col-3">Sport - Einfach</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'easy', category: 'questionmark' }}" class="btn question col-3">? - Einfach</router-link>
        </div>
        <div class="row justify-content-center">
            <router-link :to="{ name: 'Question', params: { difficulty: 'hard', category: 'knowledge' }}" class="btn question col-3">Allgemeinwissen - Schwer</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'hard', category: 'politics' }}" class="btn question col-3">Politik - Schwer</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'hard', category: 'sport' }}" class="btn question col-3">Sport - Schwer</router-link>
            <router-link :to="{ name: 'Question', params: { difficulty: 'hard', category: 'questionmark' }}" class="btn question col-3">? - Schwer</router-link>
        </div>
  </div>
</template>

<script>
import Button from "../components/Buttons";
import Selection from "../views/Question";

export default {
  name: "Selection",
  components: {
    Button,
    Selection,
  },
  methods:{
    changeRoute() {
      console.log("Disabled")
      let bttn = this.button;
      bttn.classList.add("disabled");
      console.log("route disabled");
      router.push({ path: "./selection", params: { difficulty: this.dificulty, category: this.category }});
    }

  }
};
</script>

<style scoped>
.question {
  background-color: darkblue;
  color: white;
  text-align: center;
  font-size: 20px;
  border: 2px solid white;
  display: -webkit-flex;
  display: -ms-flexbox;
  display: flex;
  flex-direction: column;
  height: 10rem;
  justify-content: center;
}
</style>
