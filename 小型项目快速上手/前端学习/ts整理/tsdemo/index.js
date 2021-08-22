"use strict";
console.log("hello");
// ts编译成 es5
var flag = true;
var Flag;
(function (Flag) {
    Flag[Flag["success"] = 1] = "success";
    Flag[Flag["error"] = 2] = "error";
})(Flag || (Flag = {}));
var c = Flag.error;
var num = 'str';
function run() {
    console.log('run');
}
run();
