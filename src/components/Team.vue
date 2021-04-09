<template>
    <h3>{{team.name}}</h3>
</template>

<script>
export default {
    name: 'Team',
    props: {
        team: Object
    }
}
</script>