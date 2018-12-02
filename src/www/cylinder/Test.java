package www.cylinder;

/*3.按如下要求编写Java程序：
（1）定义接口A，里面包含值为3.14的常量PI和抽象方法double area()。
（2）定义接口B，里面包含抽象方法void setColor(String c)。
（3）定义接口C，该接口继承了接口A和B，里面包含抽象方法void volume()。
（4）定义圆柱体类Cylinder实现接口C，该类中包含三个成员变量：底圆半径radius、
圆柱体的高height、颜色color。
（5）创建主类来测试类Cylinder
*/

interface A{
    public static final double PI = 3.14;
    double area();
}

interface B{
    void setColor(String c);
}

interface C extends A, B{
    void volume();
}

class Cylinder implements C{
    double radius;
    double height;
    String color;

    public Cylinder(double radius, double height, String color){
        this.radius = radius;
        this.height = height;
        this.color = color;
    }

    public double area(){
        System.out.println("圆柱体的底面积为："+(2*PI*radius));
        return 2*PI*radius;
    }

    public void setColor(String c){
        System.out.println(c);
    }

    public void volume(){
        System.out.println("圆柱体的体积为："+(area()*height));
    }
}

public class Test {
    public static void main(String[] args){
        Cylinder cylinder = new Cylinder(1, 2, "red");
        cylinder.area();
        cylinder.setColor("red");
        cylinder.volume();
    }
}
