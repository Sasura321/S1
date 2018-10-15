/*2.-一个斐波那契数列是由数字 1、1、2、3、5、8、13、21、34 等等组成的，
其中每一一个数字(从第三个数字起)都是前两个数字的和。创建-一个方法，接受一个整数参数，
并显示从第-一个元素开始总共由该参数指定的个数所构成的所有斐波那契数字。
例如，如果运行java Fibonacci 5(Fibonacci为类名)，那么输出应该是1、1、2、3、5。*/
import java.util.Scanner;
public class Fibonacci
{
    public static void main(String[] args){
        @SuppressWarnings("resource")
        Scanner in = new Scanner( System.in );
		int i = in.nextInt();
        for(int j=1; j<=i; j++){
            System.out.print(Fib(j)+"  ");
        }
    }

    public static int Fib(int i)
{
    if(i<=0){
        return 0;
    }
    else if(i<3){
        return 1;
    }
    else{
        return Fib(i-2)+Fib(i-1);
    }
}
}

