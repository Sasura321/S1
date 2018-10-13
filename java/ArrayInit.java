//4. 使用数组静态初始化方式初始化一个大小为10的整型数组并输出。
public class ArrayInit
{
    public static void main(String[] args){
        int[] Array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int i = 0;
        for(i=0; i<10 ;i++){
            System.out.print(Array[i]+"  ");
        }
    }
}