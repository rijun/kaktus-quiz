import { createRouter, createWebHistory } from 'vue-router'
import Home from '../views/Home'
import Selection from '../views/Selection'
import Question from '../views/Question'

const routes = [{
        path: '/selection',
        name: 'Selection',
        component: Selection
    },
    {
        path: '/',
        name: 'Home',
        component: Home
    },
    {
        path: '/question',
        name: 'Question',
        component: Question
    }
]

const router = createRouter({
    history: createWebHistory(process.env.BASE_URL),
    routes
})

export default router