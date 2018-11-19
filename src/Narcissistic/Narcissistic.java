package Narcissistic;

//打印出所有的 "水仙花数 "，所谓 "水仙花数 "是指一个三位数，其各位数字立方和等于该数本身。
// 例如：153是一个 "水仙花数 "，因为153=1的三次方＋5的三次方＋3的三次方。

import org.jetbrains.annotations.Contract;

public class Narcissistic {
    public static int Cube(int x){
        return (x*x*x);
    }

    public static void main(String[] args){
        int num = 100;
        while(num<1000){
            int a = num/100;
            int b = num/10%10;
            int c = num%10;
            if(Cube(a)+Cube(b)+Cube(c) == num){
                System.out.print(num+"、");
            }
            num++;
        }
    }
}

