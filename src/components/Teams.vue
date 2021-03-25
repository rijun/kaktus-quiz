<template>
  <div>
    <div :key="team.id" v-for="team in teams">
      <h3>{{ team.name }} </h3>
    </div>
  </div>
</template>

<script>
import Team from './Team'

export default {
  name: "Teams",
  props: {
    teams: Array,
  },
  components: {
      Team
  }
};
</script>