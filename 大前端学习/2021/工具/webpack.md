webpack 是一个现代 JavaScript 应用程序的静态模块打包器 (module bundler) 。当 webpack 处理应用程序时，它会递归地构建一个依赖关系图 (dependency graph) ，其中包含应用程序需要的每个模块，然后将所有这些模块打包成一个或多个 bundle 。

webpack 主要有四个核心概念:

## 入口 (entry)
入口会指示 webpack 应该使用哪个模块，来作为构建其内部依赖图的开始。进入入口起点后，webpack 会找出有哪些模块和库是入口起点（直接和间接）依赖的。在 webpack 中入口有多种方式来定义

const config = {
  entry: "./src/main.js"
}

const config = {
  app: "./src/main.js",
  vendors: "./src/vendors.js"
}


## 输出 (output)

输出 (output): output 属性会告诉 webpack 在哪里输出它创建的 bundles ，以及如何命名这些文件，默认值为 ./dist:
const config = {
  entry: "./src/main.js",
  output: {
    filename: "bundle.js",
    path: path.resolve(__dirname, 'dist')
  }
}

## loader
loader 让 webpack 可以去处理那些非 JavaScript 文件（ webpack 自身只理解 JavaScript ）。loader 可以将所有类型的文件转换为 webpack 能够有效处理的模块，例如，开发的时候使用 ES6 ，通过 loader 将 ES6 的语法转为 ES5 

## 插件 (plugins)

loader 被用于转换某些类型的模块，而插件则可以做更多的事情。包括打包优化、压缩、定义环境变量等等。插件的功能强大，是 webpack 扩展非常重要的利器，可以用来处理各种各样的任务。使用一个插件也非常容易，只需要 require() ，然后添加到 plugins 数组中。