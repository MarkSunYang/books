### vue-class-component

1. methods可以直接声明为类成员方法
2. computed属性可以声明为类属性访问器
3. data数据可以声明为类属性
4. data render 和所有Vue生命周期挂钩也可以直接声明为类成员方法，但不能在实例本身上调用它们。在声明自定义方法时，应避免使用这些保留名称。


### vue-class-component
这个组件完全依赖于vue-class-component.它具备以下几个属性:
@Component (完全继承于vue-class-component)
@Emit
@Inject
@Provice
@Prop
@Watch
@Model
Mixins (在vue-class-component中定义);
