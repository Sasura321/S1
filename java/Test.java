// 1.创建一个Test类，包含有一个public权限的int型成员变量
//与一个char类型的成员变量，观察在main方法中的初始值。

class Persion{
    public int num;
    public String fruit;
    public void number(){
        System.out.println(fruit+"的数量是："+num);
    }
} 

public class Test
{
    public static void main(String[] args){
        Persion x = new Persion();
        x.num = 100;
        x.fruit = "apple";
        x.number();
        
        Persion y = new Persion();
        y.num = 200;
        y.fruit = "peach";
        y.number();
    }
}
