/*
    index.js webpack 入口七点文件

    1. 开发环境生成 
        webpack ./src/index.js -o ./build/ --mode=development

    
    2. 生产环境
    webpack ./src/index.js -o ./build/built.js --mode=production
    */

import data from './data.json'
import './style.css'

console.log(data)