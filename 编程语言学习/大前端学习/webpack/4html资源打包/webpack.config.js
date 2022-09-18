/*
loade: 1. 下载 2.使用
plugins： 1.下载 2.引入 3.使用
*/
const { resolve } = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')

module.exports = {
    //webpack 配置
    //1.入口文件
    entry: './src/index.js',

    //输出
    output: {
        //文件名
        filename: 'built.js',
        //输出路径 __dirname nodejs的变量，代表当前文件目录的绝对路径
        path: resolve(__dirname, 'build')

    },
    module: {
        rules: [

        ]
    },
    plugins: [
        //plugins的配置
        //html-webpack-plugin
        // 功能 默认会创建一个空的html。自动引入打包输出的所有资源
        // 需求，需要所有结构的html文件
        new HtmlWebpackPlugin({
            template: './src/index.html'
        })
    ],
    mode: 'production'
}