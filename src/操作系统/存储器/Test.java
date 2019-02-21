package 操作系统.存储器;

//用Node来模拟内存的当前状态
class Node1 {
    int start;
    int size;
    boolean state;
    int jobNo;

    public Node1() {
    }

    public Node1(int start, int size, boolean state, int jobNo) {
        this.start = start;
        this.size = size;
        this.state = state;
        this.jobNo = jobNo;
    }

    // 打印Node类
    public void print() {
        if (this != null) {
            System.out.println(this.start + "\t\t" + this.size + "\t\t" + this.state + "\t\t" + this.jobNo);
        }
    }

    //Link.java
    //用Link类来模拟链接各个内存，并添加作业
    static class Link {
        public void addJob(int size, int jobNo, Node1 a[]) {
            for (int i = 0; i < a.length; i++) {
                //当前内存有内容时
                if (a[i] != null) {
                    //判断是否符合条件
                    if (size < a[i].size && a[i].state == false) {
                        //当前内存分配大小
                        a[i].size = a[i].size = size;
                        //当下一块内存还没有适用时
                        if (a[i + 1] == null) {
                            //适用该内存
                            a[i + 1] = new Node1(size + a[i].start, size, true, jobNo);
                        } else {
                            //当下一块内存已经被适用，那么继续寻找下一块还没有被适用的内存
                            for (int j = i + 1; j < a.length - 1; j++) {
                                if (a[j] == null) {
                                    a[j] = new Node1(size + a[j - 1].start, size, true, jobNo);
                                    //当找到为别适用的内存及填入内容后跳出循环
                                    break;
                                }
                            }
                        }
                    }
                    //打印输出当前Link中各个内存块的使用情况
                    a[i].print();
                }
            }
        }

        public void delete(Node1 a[], int jobNo) {
            //删除某一个进程，当该进程被删除后，进程所在内存的状态变为false
            for (int i = 0; i < a.length; i++) {
                if (a[i] != null) {
                    if (a[i].jobNo == jobNo) {
                        a[i].state = false;
                        a[i].jobNo = 0;
                    }
                    if (a[i] != null) {
                        a[i].print();
                    }
                }
            }
        }

        public void back(Node1 a[]) {
            //进行状态为false的内存的回收删除内存状态为false的内存节点。并将该节点与起始点结合
            for (int i = 1; i < a.length; i++) {
                if (a[i] != null) {
                    if (a[i].state == false) {
                        a[0].size = a[0].size + a[i].size;
                        a[i] = null;
                    }
                }
            }
            for (int j = 0; j < a.length; j++) {
                if (a[j] != null) {
                    a[j].print();
                }
            }
        }
    }
}


public class Test{
    public static void main(String args[]){
        Node1 jobArray[] = new Node1 [70];
        jobArray[0]=new Node1(0, 25, false,0);
        Node1.Link l = new Node1.Link();
        System. out . println("------------最初的内存------------");
        System. out.println( "起始位置"+"\t"+"大小" +"\t\t"+"状杰"+"\t\t"+"工作号");
        jobArray[0]. print();

        System. out . println("----------増加第1个作止后------------");
        System. out.println( "起始位置"+"\t"+"大小" +"\t\t"+"状杰"+"\t\t"+"工作号");
        l. addJob(4, 1, jobArray);

        System. out . println("----------増加第2个作止后--------------");
        System. out.println( "起始位置"+"\t"+"大小" +"\t\t"+"状杰"+"\t\t"+"工作号");
        l.addJob(10,3, jobArray);

        System. out. println("---------刪除作出2后------------");
        System. out.println( "起始位置"+"\t"+"大小" +"\t\t"+"状杰"+"\t\t"+"工作号");
        l. delete(jobArray ,2);

        System. out . println("-----------添加作止4后--------------");
        System. out.println( "起始位置"+"\t"+"大小" +"\t\t"+"状杰"+"\t\t"+"工作号");
        l.addJob(5,4, jobArray);
    }
}


