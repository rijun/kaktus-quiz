// Starter-Code: Quiz.vue Component
<template>
  <div id="quiz-container">
    <h1 id="logo-headline">FRAGE</h1>
    <!-- div#correctAnswers -->
    <hr class="divider" />
    <div>
      <h1
        class="question"
        v-html="loading ? 'Loading...' : currentQuestion.question"
      ></h1>
      <form v-if="currentQuestion">
        <button
          v-for="answer in currentQuestion.answers"
          :index="currentQuestion.key"
          :key="answer"
          v-html="answer"
          @click.prevent="handleButtonClick"
        ></button>
        <!-- v-for loops through each answer and creates a button for each -->
      </form>
      <hr class="divider" />
    </div>
    <div id="account-info">
      {{ username }}
    </div>
    <!-- in the div of v-html is nothing allowed, not even comments -->
    <!-- Only the first question is displayed -->
  </div>
</template>

<script>
export default {
  name: "Question",
  data() {
    return {
      questions: [],
      loading: true,
      index: 0,
    };
  },
  props: ["username"],
  computed: {
    currentQuestion() {
      if (this.questions !== []) {
        return this.questions[this.index];
      }
      return null;
      //Keyword this usually refers to the Vue Component Instance, e.g. this.questions points
      //to the questions array in the data() function
    },
    score() {
      if (this.questions !== []) {
        // Here, we want to collect data in an object about the users statistics - later be emitted on an event when users finishes quiz
        return {
          allQuestions: this.questions.length,
          answeredQuestions: this.questions.reduce((count, currentQuestion) => {
            if (currentQuestion.userAnswer) {
              // userAnswer is set when user has answered a question, no matter if right or wrong
              count++;
            }
            return count;
          }, 0),
          correctlyAnsweredQuestions: this.questions.reduce(
            (count, currentQuestion) => {
              if (currentQuestion.rightAnswer) {
                // rightAnswer is true, if user answered correctly
                count++;
              }
              return count;
            },
            0
          ),
        };
      } else {
        return {
          allQuestions: 0,
          answeredQuestions: 0,
          correctlyAnsweredQuestions: 0,
        };
      }
    },
    correctAnswers() {
      if (this.questions && this.questions.length > 0) {
        let streakCounter = 0;
        console.log(streakCounter);
        this.questions.forEach(function (question) {
          if (!question.rightAnswer) {
            return;
          } else if (question.rightAnswer === true) {
            streakCounter++;
          }
        });
        return streakCounter;
      } else {
        return "--";
      }
    },
    pluralizeAnswer() {
      // For grammatical correctness
      return this.correctAnswers === 1 ? "Answer" : "Answers";
    },
    quizCompleted() {
      if (this.questions.length === 0) {
        return false;
      }
      /* Check if all questions have been answered */
      let questionsAnswered = 0;
      this.questions.forEach(function (question) {
        question.rightAnswer !== null ? questionsAnswered++ : null;
      });
      return questionsAnswered === this.questions.length;
    },
  },
  watch: {
    quizCompleted(completed) {
      /*
       * Watcher on quizCompleted fires event "quiz-completed"
       * up to parent App.vue component when completed parameter
       * returned by quizCompleted computed property true
       */
      completed &&
        setTimeout(() => {
          this.$emit("quiz-completed", this.score);
        }, 3000); // wait 3 seconds until button animation is over
    },
  },
  methods: {
    async fetchQuestions() {
      this.loading = true;
      let response = await fetch(
        "https://opentdb.com/api.php?amount=3&type=multiple"
      );
      //convert questions into json
      let jsonResponse = await response.json();
      let index = 0; // index is used to identify single answer
      //manipulate questions
      let data = jsonResponse.results.map((question) => {
        // put answers on question into single array
        question.answers = [
          question.correct_answer,
          ...question.incorrect_answers,
          /*The tree dots go to the existing object and get all its properties, copies these and then overwrite
            explicitly the other properties defined (https://oprea.rocks/blog/what-do-the-three-dots-mean-in-javascript) */
        ];
        /* Shuffle question.answers array */
        for (let i = question.answers.length - 1; i > 0; i--) {
          const j = Math.floor(Math.random() * (i + 1));
          [question.answers[i], question.answers[j]] = [
            question.answers[j],
            question.answers[i],
          ];
        }
        // mention in Step 1
        question.rightAnswer = null;
        question.key = index;
        index++;
        return question;
      });
      this.questions = data;
      this.loading = false;
    },

    handleButtonClick: function (event) {
      /* Find index to identiy question object in data */
      let index = event.target.getAttribute("index");
      let pollutedUserAnswer = event.target.innerHTML; // innerHTML is polluted with decoded HTML entities e.g ' from &#039;
      /* Clear from pollution with ' */
      let userAnswer = pollutedUserAnswer.replace(/'/, "&#039;");
      /* Set userAnswer on question object in data */
      this.questions[index].userAnswer = userAnswer;
      /* Set class "clicked" on button with userAnswer -> for CSS Styles; Disable other sibling buttons */
      event.target.classList.add("clicked");
      let allButtons = document.querySelectorAll(`[index="${index}"]`);
      for (let i = 0; i < allButtons.length; i++) {
        if (allButtons[i] === event.target) continue;
        allButtons[i].setAttribute("disabled", "");
      }
      /* Invoke checkAnswer to check Answer */
      this.checkAnswer(event, index);
    },

    checkAnswer: function (event, index) {
      let question = this.questions[index];
      if (question.userAnswer) {
        if (this.index < this.questions.length - 1) {
          setTimeout(
            function () {
              this.index += 1;
            }.bind(this),
            3000
          );
        }
        if (question.userAnswer === question.correct_answer) {
          /* Set class on Button if user answered right, to celebrate right answer with animation joyfulButton */
          event.target.classList.add("rightAnswer");
          /* Set rightAnswer on question to true, computed property can track a streak out of 10 questions */
          console.log("correct answer");
          this.questions[index].rightAnswer = true;

          //Here i will appoint the earned points to the team
          this.appointPoints();
        } else {
          /* Mark users answer as wrong answer */
          event.target.classList.add("wrongAnswer");
          this.questions[index].rightAnswer = false;
          /* Show right Answer */
          let correctAnswer = this.questions[index].correct_answer;
          let allButtons = document.querySelectorAll(`[index="${index}"]`);
          allButtons.forEach(function (button) {
            if (button.innerHTML === correctAnswer) {
              button.classList.add("showRightAnswer");
            }
          });
        }
      }
    },
    async appointPoints() {
      var id = "1";
      console.log("Blin");
      /* const res = await fetch(`http://localhost:5001/teams/`);

      const data = await res.json();

      console.log(data);
      for (var i = 0; i < data.length; i++) {
        console.log(data[i])
        if (data[i].id === id) {
          console.log("entered loop")
          data[i].name = "Cyka";
          console.log(data[i].points)
          break;
        }
      } */
      const toggleTeam = await this.fetchTeam(id);
      const updateTeam = { ...toggleTeam, points: toggleTeam.points + 100 };

      const res = await fetch(`http://localhost:5001/teams/${id}`, {
        method: "PUT", //PUT is used for modifying json
        headers: {
          "Content-type": "application/json",
        },
        body: JSON.stringify(updateTeam),
      });

      const data = await res.json();

      this.teams = this.teams.map((team) =>
        team.id === id ? { ...team, points: data.points } : team
      );
    },

    async fetchTeam(id) {
      const res = await fetch(`http://localhost:5001/teams/${id}`);

      const data = await res.json();

      return data;
    },
  },
  //Code inside mounted() runs after the Component has mounted
  mounted() {
    this.fetchQuestions();
  },
};
</script>

<style scoped>
#quiz-container {
  margin: 1rem auto;
  padding: 1rem;
  max-width: 750px;
  background-color: rgb(45, 48, 51);
}

#logo-headline {
  font-size: 3rem;
  padding: 0.5rem;
  color: rgb(5, 255, 44, 0.9);
  text-align: center;
}

.question {
  font-size: 1.3rem;
  padding: 0.7rem;
  color: snow;
}

.divider {
  margin: 0.5rem 0;
  border: 3px solid rgb(0, 204, 255);
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
  background-color: rgba(114, 114, 117, 0.3);
  color: snow;
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

@keyframes flashButton {
  0% {
    opacity: 1;
    transform: scale(1.01);
  }
  50% {
    opacity: 0.7;
    transform: scale(1.02);
  }
  100% {
    opacity: 1;
    transform: scale(1);
  }
}

button.clicked {
  pointer-events: none;
}

button.rightAnswer {
  animation: flashButton;
  animation-duration: 700ms;
  animation-delay: 200ms;
  animation-iteration-count: 3;
  animation-timing-function: ease-in-out;
  color: black;
  background: linear-gradient(
    210deg,
    rgba(4, 121, 50, 0.952),
    rgba(4, 121, 50, 0.952)
  );
}

button.wrongAnswer {
  color: black;
  background: linear-gradient(
    210deg,
    rgba(245, 4, 4, 0.699),
    rgba(245, 4, 4, 0.699)
  );
}

button.showRightAnswer {
  animation: flashButton;
  animation-duration: 700ms;
  animation-delay: 200ms;
  animation-iteration-count: 2;
  animation-timing-function: ease-in-out;
  color: black;
  background: linear-gradient(
    210deg,
    rgba(4, 121, 50, 0.952),
    rgba(4, 121, 50, 0.952)
  );
}
</style>
