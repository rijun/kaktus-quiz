// Starter-Code: Quiz.vue Component
<template>
  <div id="quiz-container">
    <h1 id="logo-headline">FRAGE</h1>
    <!-- div#correctAnswers -->
    <div>
      <h1 v-html="loading ? 'Loading...' : currentQuestion.question"></h1>
      <form v-if="currentQuestion">
        <button
        v-for="answer in currentQuestion.answers" 
        :index="currentQuestion.key"
        :key="answer"
        :v-html="answer"
        @click.prevent="handleButtonClick"
        ></button> <!-- v-for loops through each answer and creates a button for each -->
      </form>

      <hr class="divider" />
    </div>
    <!-- in the div of v-html is nothing allowed, not even comments -->
    <!-- Only the first question is displayed -->

    <hr class="divider" />
  </div>
</template>

<script>
export default {
  name: "Question",
  data() {
    return {
      questions: [],
      loading: true,
      index: 0
    };
  },
  computed: {
    currentQuestion() {
      if (this.questions !== []) {
        return this.questions[this.index];
      }
      return null;
    }
  },
    //Keyword this usually refers to the Vue Component Instance, e.g. this.questions points
    //to the questions array in the data() function 
  methods: {
    async fetchQuestions() {
      this.loading = true;
      //fetch questions
      let response = await fetch(
        "https://opentdb.com/api.php?amount=10&category=9"
      );
      //convert questions into json
      let jsonResponse = await response.json();
      //manipulate questions
      let data = jsonResponse.results.map((question) => {
        question.answers = [
          question.correct_answer,
          /* ...question.incorrect_anwser, */
          /*The tree dots go to the existing object and get all its properties, copies these and then overwrite
            explicitly the other properties defined (https://oprea.rocks/blog/what-do-the-three-dots-mean-in-javascript) */
        ];
        return question;
      });
      //put data on question property
      this.questions = data;
      this.loading = false;
      console.log(data);
    },
  },
  //Code inside mounted() runs after the Component has mounted
  mounted() {
    this.fetchQuestions();
  },
};
</script>

<style scoped>
body {
  background-color: white;
}
#quiz-container {
  margin: 1rem auto;
  padding: 1rem;
  max-width: 750px;
}

#logo-headline {
  font-size: 3rem;
  padding: 0.5rem;
  color: #f50057;
  text-align: center;
}

#logo-crown {
  display: block;
  width: 40%;
  margin: 0 auto;
}

@media only screen and (max-width: 500px) {
  #logo-crown {
    width: 30%;
  }

  #logo-headline {
    font-size: 1.8rem;
  }
}

h1 {
  font-size: 1.3rem;
  padding: 0.7rem;
}

.divider {
  margin: 0.5rem 0;
  border: 3px solid rgba(102, 255, 166, 0.7);
  border-radius: 2px;
  box-shadow: 3px 5px 5px rgba(0, 0, 0, 0.3);
}

form {
  display: flex;
  flex-direction: row;
  flex-wrap: wrap;
  justify-content: center;
}

button {
  font-size: 1.1rem;
  box-sizing: border-box;
  padding: 1rem;
  margin: 0.3rem;
  width: 47%;
  background-color: rgba(100, 100, 100, 0.3);
  border: none;
  border-radius: 0.4rem;
  box-shadow: 3px 5px 5px rgba(0, 0, 0, 0.2);
}

button:hover:enabled {
  transform: scale(1.02);
  box-shadow: 0 3px 3px 0 rgba(0, 0, 0, 0.14), 0 1px 7px 0 rgba(0, 0, 0, 0.12),
    0 3px 1px -1px rgba(0, 0, 0, 0.2);
}

button:focus {
  outline: none;
}

button:active:enabled {
  transform: scale(1.05);
}

</style>
