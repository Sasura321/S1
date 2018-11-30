package www.abnormal;

class AddException extends Exception{
    public AddException(String str){
        super(str);
    }
}

public class Test {

   /* public static void main (String[] args){

        try {
            System.out.println(div(10,0));
        } catch (Exception e) {
            e.printStackTrace();
        }
        System.out.println("div方法结束");
    }
    // public static int div(int x, int y) throws Exception{
    //    System.out.println(div(10,0));

    public static int div(int x, int y) throws Exception{
        return x/y;
    }
    */


   /*
    public static void main (String[] args){
        //自定义异常类
        int x = 1;
        int y = 2;
        int result = x + y;
        if(result == 2){
            try{
                throw new AddException("1+1不等于2");
            }catch(AddException e){
                e.printStackTrace();
            }
        }
    }
    */


   /*
    public static void main (String[] args){
        //数值转换异常
        String str = "100a";
        int num = Integer.parseInt(str);
        System.out.println(num);
    }
    */

    public static void main (String[] args){
        //断言
        int num = 10;
        assert num == 55 : "num应该为55！";
        System.out.println(num);
    }
}

