/*
webpack的配置文件
作用：指示 webpack 加载配置

所有构件工具都是基于nodejs 
模块化采用commonjs
*/
const {resolve} =require('path')
module.exports={
    //webpack 配置
    //1.入口文件
    entry:'./src/index.js',

    //输出
    output:{
        //文件名
        filename:'built.js',
        //输出路径 __dirname nodejs的变量，代表当前文件目录的绝对路径
        path:resolve(__dirname,'build')

    },
    module:{
        rules:[
            //详细loader的配置,不同资源配置不同loader
            {
                test:/\.css$/,
                use:[
                    //执行顺序，中上到下依次执行
                    //创建style标签，将js中的样式资源插入，添加到head
                    'style-loader',
                    // css文件以字符串形式编程commonjs模块加载到js，里面内容是样式字符串
                    'css-loader'
                ]
            },{
                test:/\.less$/,
                use:[
                    'style-loader',
                    'css-loader',
                    //less需要下载两个包  less和less-loader
                    'less-loader'
                ]
            }
           
        ]
    },
    plugins:[],
    mode:'production'
}