package www.array;

//数组课堂代码

public class Test {
    public static void main (String[] args){
        /*
        //x相当于C源的数组指针
        int[] x = new int[3];
        x[0] = 10;
        x[1] = 20;
        x[2] = 30;

        //引用传递
        int[] temp = x;
        temp[2] = 50;
        System.out.println(x[2]);
        */

        int[][] data = new int[][]
        {
            {1,2},{3,4,5},{6,7,8,9}
        };
        for(int x=0; x<data.length; x++){
            for(int y=0; y<data[x].length; y++){
                System.out.print(data[x][y]+"、");

            }
        }
    }
}
