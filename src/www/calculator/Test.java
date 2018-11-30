package www.calculator;

/*
利用接口做参数，写个计算器，能完成加减乘除运算。
（1）定义一个接口Compute含有一个方法int computer(int n, int m)。
（2）设计四个类分别实现此接口，完成加减乘除运算。
（3）设计一个类UseCompute，类中含有方法：public void useCom(Computer com, int one, int two)，
     此方法能够用传递过来的对象调用computer方法完成运算，并输出运算的结果。
（4）设计一个主类Test，调用UseCompute中的方法useCom来完成加减乘除运算
 */

interface Computer{
    int computer(int n, int m);
}

class Add implements Computer{
    @Override
    public int computer(int n, int m){
        return n + m;
    }
}

class Sub implements Computer{
    @Override
    public int computer(int n, int m){
        return n - m;
    }
}

class Mul implements Computer{
    @Override
    public int computer(int n, int m){
        return n * m;
    }
}

class Div implements Computer{
    @Override
    public int computer(int n, int m) {
        if (m != 0) {
            return n / m;
        } else {
            System.out.println("分母不能为零");
            return 0;
        }
    }
}

class UseCompute{
    public void usecom(Computer com,int n,int m) {
        System.out.println(com.computer(n, m));
    }
}
public class Test {
    public static void main(String[] args) {
        UseCompute useCompute = new UseCompute();
        useCompute.usecom(new Add(), 10, 20);
        useCompute.usecom(new Sub(), 10, 20);
        useCompute.usecom(new Mul(), 10, 20);
        useCompute.usecom(new Div(), 20, 10);
        useCompute.usecom(new Div(), 20, 0);
    }
}
