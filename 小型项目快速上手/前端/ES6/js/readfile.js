const fs = require('fs')



//使用Promise 封装
const p = new Promise((res, rej) => {

    fs.readFile('./锄禾.md', (err, data) => {
        if (err) rej(err);
        res(data);
    })
});

p.then(function (value) {
    console.log(value)
},
    function (reason) {
        console.log(reason)
    });