//2. 递归实现20! 
public class Factorial
{
    public static long Factor(int n){
        if(n == 1){
            return 1;
        }
        else{
        return n*Factor(n-1);
        }
    }
    public static void main(String[] args){
        System.out.print(Factor(20));
    }
}