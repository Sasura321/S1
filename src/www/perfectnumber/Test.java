package www.perfectnumber;

/*
一个数如果恰好等于它的因子之和，这个数就称为 "完数 "。例如6=1＋2＋3.编程 找出1000以内的所有完数
 */
public class Test {
    public static void main(String[] args){
        int perNum = 0;
        int num = 0;
        for(perNum = 1; perNum <= 1000; perNum++){
            num = 0;
            for(int i = 1; i < perNum; i++){
                if(perNum % i == 0){
                    num += i;
                }
            }
            if(num == perNum){
                System.out.println(num );
            }
        }
    }
}
/*
interface InterfaceA {
    String S = "good ";
    void f();
}

abstract class ClassA {
    abstract void g();
}

class ClassB extends ClassA implements InterfaceA {
    void g() {
        System.out.print(S); //good
    }

    public void f() {
        System.out.print(" "+ S);//good good
    }
}
public class Test {
    public static void main(String[] args) {
        ClassA a = new ClassB();
        InterfaceA b = new ClassB();
        a.g();
        b.f();
    }
*/