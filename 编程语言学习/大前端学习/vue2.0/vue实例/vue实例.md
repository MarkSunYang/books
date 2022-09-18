vue 实例的原型

v.$mount('#root') //挂载

var vm = new Vue({
            el: '#app',

            //对象式
            data: {
               name:'1234'
            },

        })


        //函数式 
        data(){

            vue帮调用
             return {

            }
        }
       