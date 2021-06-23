<template>
  <div class="container">
    <div class="row justify-content-center">
            <router-link :to="{ name: 'Question', params: { variant: 'first',  category: 'history' }}" class="btn question col-3">Geschichte / Politik 1</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'second', category: 'history' }}" class="btn question col-3">Geschichte / Politik 2</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'first',  category: 'film' }}"    class="btn question col-3">Film 1</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'second', category: 'film' }}"    class="btn question col-3">Film 2</router-link>
        </div>
        <div class="row justify-content-center">
            <router-link :to="{ name: 'Question', params: { variant: 'first',  category: 'music' }}"   class="btn question col-3">Musik 1</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'second', category: 'music' }}"    class="btn question col-3">Musik 2</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'first',  category: 'gaming' }}"  class="btn question col-3">Gaming 1</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'second', category: 'gaming' }}"  class="btn question col-3">Gaming 2</router-link>
        </div>
        <div class="row justify-content-center">
            <router-link :to="{ name: 'Question', params: { variant: 'first',  category: 'world' }}"   class="btn question col-3">Um die Welt 1</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'second', category: 'world' }}"   class="btn question col-3">Um die Welt 2</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'first',  category: 'general' }}" class="btn question col-3">Allgemeinwissen 1</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'second', category: 'general' }}" class="btn question col-3">Allgemeinwissen 2</router-link>
        </div>
        <div class="row justify-content-center">
            <router-link :to="{ name: 'Question', params: { variant: 'first',  category: 'tech' }}"    class="btn question col-3">Technik 1</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'second', category: 'tech' }}"    class="btn question col-3">Technik 2</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'first',  category: 'science' }}" class="btn question col-3">Naturwissenschaften 1</router-link>
            <router-link :to="{ name: 'Question', params: { variant: 'second', category: 'science' }}" class="btn question col-3">Naturwissenschaften 2</router-link>
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
      router.push({ path: "./selection", params: { difficulty: this.variant, category: this.category }});
    },

    async test() {
      console.log("somethjing")
    }

  },
  /* async unmounted() {
    console.log('changed page')
    let selection = document.getElementById('test');
    selection.classList.add('disabled')
  } */
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
