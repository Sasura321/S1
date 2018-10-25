public class test10_25{
    public static void main(String[] args){
        /*int i1 = 10;
        int i2 = 10;
        System.out.println(i1 == i2);*/

        String data = "15484212";
        isNumber(data);
    }
    
    public static boolean isNumber(String str){
        char[] data = str.toCharArray();
        for(int i = 0; i<data.length; i++){
            if(data[i]<'0' || data[i]>'9'){
                return false;
            }
        }
        return true;
    }
}