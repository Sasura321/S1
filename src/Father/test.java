/*1.定义一个Father和Child类，并进行测试。 要求如下：
1）Father类为外部类，类中定义一个私有的String类型的属性name，name的值为“zhangjun”。
2）Child类为Father类的内部类，其中定义一个introFather()方法，方法中调用Father类的name属性。
3）定义一个测试类Test，在Test类的main()方法中，创建Child对象，并调用introFather ()方法。*/

package Father;

class Father{
    String name = "zhang jun";
    class Child{
        public void introFather(){
            System.out.println("爸爸的名字是："+name);
        }
    }

}

public class test {
    public static void main(String[] args){
        Father.Child child = new Father().new Child();
        child.introFather();
    }
}
