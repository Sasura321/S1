package work.experiment.sort;

/*
* 二．定义一个类，该类中包含以下几个方法（静态）：
	1.实现两个字符串数组的逆序排序，输出结果为字符串数组；
	2.求两个整形数组的交集；
	3.求两个浮点型数组的并集；
 */

public class Test{
    //逆序排序
    public static void Sort(String[] str) {
        String tmp;
        for(int i= 0;i<str.length;i++) {
            for(int j=0;j<str.length-i-1;j++) {
                if(str[j].compareTo(str[j+1])>0) {
                    tmp = str[j+1];
                    str[j+1]=str[j];
                    str[j]=tmp;
                }
            }
        }
    }

    //1.实现两个字符串数组的逆序排序，输出结果为字符串数组；
    public static void Reverse(String str1[],String str2[])
    {
        String []tmp = new String[str1.length+str2.length];
        int i=0;
        int k=0;

        while(i<str1.length) {
            tmp[k]=str1[i];
            i++;
            k++;
        }

        int j= 0;
        while(j<str2.length) {
            tmp[k]= str2[j];
            j++;
            k++;
        }

        Sort(tmp);
        for(int n= 0; n<tmp.length; n++) {
            System.out.print(tmp[n] + " ");
        }
    }

    //2.求两个整形数组的交集；
    public static void Intersection(int[] m,int[] n) {
        for(int i=0; i<m.length; i++) {
            for(int j=0; j<n.length; j++) {
                if(m[i] == n[j]) {
                    System.out.print(m[j]);
                }
                if(m[j]!=n[j]) {
                    System.out.print(m[j]);
                    System.out.print(n[j]);
                }
            }
        }
    }

    //主方法
    public static void main(String[] args) {
        String[] str1 = {"ar","nt","ey","su","yi"};
        String[] str2 = {"cff","add","sum"};

        System.out.print("1.实现两个字符串数组的逆序排序，输出结果为字符串数组：");
        Reverse(str1, str2);
        System.out.println();

        //2.
        int[] m = {1,2,3,4,5,6,7};
        int[] n = {4,5,6,7,8,9,10};
        System.out.print("2.求两个整形数组的交集：");
        //Method2.Intersection(m,n);
    }
}
