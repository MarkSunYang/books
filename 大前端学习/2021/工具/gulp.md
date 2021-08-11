gulp 是一个基于流的自动化构建工具，具有易于使用、构建快速、插件高质和易于学习的特点，常用于轻量级的工程中。

全局安装 gulp:

$ npm install --global gulp
在项目中引入依赖:

$ npm install --save-dev gulp
在项目根目录下创建名为 gulpfile.js 的文件:

const gulp = require('gulp');

// default 表示一个任务名，为默认执行任务
gulp.task('default', function() {
  // 放置默认的任务代码
})