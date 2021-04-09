<template>
    <button :style="{background: color }" class="btn btn-primary">{{ text }}</button>
</template>

<script>
export default {
    name: 'Button',
    props: {
        text: String,
        color: String
    },
    methods: {
        onClick(){
            console.log("Cyka Blyat")
            this.$emit('btn-click')
        }
    }
}
</script>