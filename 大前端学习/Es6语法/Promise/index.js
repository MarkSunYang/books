const fs = require('fs')

// fs.readFile('./resorce/study.md', (error, data) => {
//     if (error) throw error;
//     console.log(data.toString())
// })

// 使用promise 封装
const p = new Promise(function (resolve, reject) {
    fs.readFile('./resorce/study.md', (error, data) => {
        if (error) reject(error);
        resolve('promise '+data);
    })
})


p.then(function (value) {
    console.log(value.toString())
}, function (reasone) {
    console.log(reasone.toString())
})