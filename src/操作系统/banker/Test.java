package 操作系统.banker;

import java.util.Arrays;
import java.util.Scanner;

public class Test {
    // 可利用资源向量Available
    static int[] Avaliable = null;
    // 用于存储预操作的完成度
    static boolean[] new_finish = null;
    // 用于保存最终的进程执行顺序,初始化为非法进程-1
    static int[] right = null;

    // 输入一维数组的方法
    public static int[] Init1(int[] num) {
        System.out.print("请输入数组长度：");
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        num = new int[len];
        System.out.print("数组中的元素为：");
        for (int i = 0; i <  len; i++) {
            num[i] = sc.nextInt();
        }
        return num;
    }

    // 输入二维数组的方法
    public static int[][] Init2(int[][] num) {
        System.out.print("请输入数组行的长度：");
        Scanner sc = new Scanner(System.in);
        int row = sc.nextInt();
        System.out.print("请输入数组列的长度：");
        int col = sc.nextInt();
        num = new int[row][col];
        for (int i = 0; i < row; i++) {
            System.out.print("二维数组中的第" + (i+1) + "列元素为：");
            for (int j = 0; j < col; j++) {
                num[i][j] = sc.nextInt();
            }
        }
        return num;
    }

    public static void main(String[] args){
        // 最大需求矩阵Max
        int[][] Max = {};
        System.out.println("定义最大需求矩阵Max二维数组......");
        Max = Init2(Max);
        // 当前系统可用资源量
        int[] Avaliable = {};
        System.out.println("定义系统可用资源量Avaliable一维数组......");
        Avaliable = Init1(Avaliable);
        // 需求矩阵Need, 每个进程运行还需资源量
        int[][] Need;//#
        Need = new int[Max.length][Max[0].length];
        // 分配矩阵Allocation, 每个进程已分配的资源量
        int[][] Allocation = {};
        System.out.println("定义分配矩阵Allocation二维数组......");
        Allocation = Init2(Allocation);
        // 用于第一深度预判的初始化
        boolean finish[];//#
        finish = new boolean[Max.length];
        // 获取每个进程运行时还需的资源量
        for (int i = 0; i < Max.length; i++) {
            for (int j = 0; j < Max[i].length; j++) {
                Need[i][j] = Max[i][j] - Allocation [i][j];
            }
        }
        // 创建递归深度
        int deep = 0;
        // 调用回溯递归算法
        right = new int[Max.length];
        deepCheck(Avaliable, Allocation, Need, finish, deep, right);
        int i = 0;

        // 查看最终的安全序列的值，看是否存在初始的非法进程，如果存在，则说明该案例不存在安全的进程执行顺序
        for (; i < right.length; i++) {
            if (right[i] == -1) {
                break;
            }
        }

        if (i < right.length) {
            System.out.println("该案例不存在安全的进程执行顺序");
            return;
        }

        // 打印安全的执行顺序
        System.out.println("该案例存在安全的进程，其安全的执行顺序为: ");
        for (int j = 0; j < right.length; j++) {
            System.out.print(right[j]+"\t");
        }
    }

    // 完全递归回溯查找安全顺序
    public static boolean deepCheck(int[] avaliable, int[][] allocation,int[][] need,
                                     boolean finish[], int deep,int right[]) {
        int j = 0;
        boolean flog = false;
        // 如果深度为进程的个数数说明已经查找到头了,说明上一深度的进程是安全节点。
        // 因为上一深度的进程满足了当前资源数大于或等于该进程运行所需的资源数，且为安全序列中最后一个节点。
        if (deep == need.length) {
            return true;
        }
        // 遍历所有节点进程开始查找,直到找到安全校验成功的的节点进程
        for (int i = 0; i < need.length; i++) {
            // 对于未被标记的进行校验，已被标记的为已被列为安全节点所以无需再进行校验
            if (!finish[i]) {
                // 判断当前的节点进程的剩余的资源量,是否满足运行所需的资源量
                for (j = 0; j < avaliable.length; j++) {
                    // 不满足
                    if (need[i][j] > avaliable[j]) {
                        break;
                    }
                }
                // 不满足则处理下一个节点进程
                if (j < avaliable.length) {
                    continue;
                } else {
                    // 满足情况
                    // 复制会被修改的前提条件，已便于当前进程校验不成功时，可以恢复前提条件，开始下一个节点进程的校验
                    Avaliable = Arrays.copyOf(avaliable, avaliable.length);
                    new_finish = Arrays.copyOf(finish, finish.length);
                    // 假设当前节点进程是可以校验成功的节点进程，修改该进程运行完毕后释放之前分配的进程。
                    for (j = 0; j < Avaliable.length; j++) {
                        Avaliable[j] += allocation[i][j];
                    }
                    // 假设标记当前为校验成功的安全节点进程，下一深度查找时会忽略此进程。
                    new_finish[i] = true;
                    // 增加深度
                    deep++;
                    // 以上假设为前提，进行下一深度的安全校验判断其他所剩余进程是否可以继续运行，而不造成死锁。
                    flog = deepCheck(Avaliable, allocation, need, new_finish, deep, right);
                    // 如果进行安全校验后为真，说明当前进程是我们要找的进程
                    if (flog) {
                        // 保存到最终进程执行序列的数组中
                        right[--deep] = i;
                        break;
                    }

                }
            }
        }

        // 安全校验成功
        if (flog) {
            return true;
        } else {
            // 安全校验失败
            // 清楚之前的假设标记
            new_finish[right[--deep]] = false;
            return false;
        }
    }
}