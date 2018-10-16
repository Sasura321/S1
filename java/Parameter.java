/* 3.创建-一个带默认构造方法  (即无参构造)的类，在构造方法中打印一条消息"Hello Constructor";
再为这个类添加一一个重载构造方法，令其接收-一个字符串参数，
并在这个有参构造方法中把"Hello Constructor"和接收的参数一起打印出来。*/

class para
{
    //无参构造
    public para(){
        System.out.println("Hello Constructor");
    }
    //有参构造
    public para(String str){
        this();
        System.out.println(str);
    }
}

public class Parameter
{
    public static void main(String[] args){
        new para();
    }
}