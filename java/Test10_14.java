class Persion{
    public String name;
    public int age;
    public void play(){
        System.out.println(name+"玩撒");
    }
    public void sleep(){
        System.out.println(name+"睡觉");
    }
    public void work(){
        if(age<18){
            System.out.println(name+"学习");
        }else{
            System.out.println(name+"工作");
        }
    }
}

public class Test10_14
{
    public static void main(String[] args){
        Persion per1 = new Persion();
        per1.name = "zhang";
        per1.age = 15;
        per1.work();
    }
}