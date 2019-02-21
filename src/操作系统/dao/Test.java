package 操作系统.dao;

import java.util.Scanner;

class PCB {
    String ID;
    int runtime;
    int pri;
    char state;

    public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public int getRuntime() {
        return runtime;
    }

    public void setRuntime(int runtime) {
        this.runtime = runtime;
    }

    public int getPri() {
        return pri;
    }

    public void setPri(int pri) {
        this.pri = pri;
    }

    public char getState() {
        return state;
    }

    public void setState(char state) {
        this.state = state;
    }

    @Override
    public String toString() {
        return "PCB{" +
                "ID=" + ID +
                ", runtime=" + runtime +
                ", pri=" + pri +
                ", state=" + state +
                '}';
    }
}

public class Test {
    static int num = 5;
    static PCB[] pcblist = new PCB[num];

    public static void init(){
        for(int i = 0; i < num; i++) {
            System.out.println("PCB"+i+": ID pri runtime");
            Scanner in=new Scanner(System.in); //使用Scanner类定义对象
            String a = in.next();
            int b = in.nextInt();
            int c = in.nextInt();
            pcblist[i].state = 'R';
            String d = in.next();//接收回车符
        }
    }

    public static int maxPriProcess() {
        int max = -100;
        int key = 0;
        for(int i = 0; i < num; i++) {
            if (pcblist[i].state == 'r') {
                return -1;
            } else {
                //从就绪进程中选取优先数最大的进程
                if ((max < pcblist[i].pri) && (pcblist[i].state == 'R')) {
                    max = pcblist[i].pri;
                    key = i;
                }
            }
        }
        if(pcblist[key].state == 'F') {
            return -1;
        } else {
            return key;
        }
    }

    public static void show() {
        System.out.println("\nID pri runtime state");
        System.out.println("-------------------------------");
        for(int i = 0; i<num; i++) {
            System.out.println(pcblist[i].ID+"， "+pcblist[i].pri+"， "+pcblist[i].runtime+"， "+pcblist[i].state);
        }
        System.out.println("press any key to continue……");
    }

    public static void run() {
        int t = 0;
        for(int i = 0; i < num; i++) {
            while(maxPriProcess() != -1) {
                pcblist[maxPriProcess()].state = 'R';
            }
            for(int j = 0; j < num; j++) {
                if(pcblist[j].state == 'R') {
                    pcblist[j].pri = 1;
                    pcblist[i].runtime--;
                }
                if(pcblist[i].runtime == 0) {
                    pcblist[i].state = 'E';
                } else {
                    pcblist[i].state = 'R';
                }
                show();
                Scanner in=new Scanner(System.in); //使用Scanner类定义对象
                String d = in.next();//接收回车符
            }
        }
    }

    public static void main(String[] args) throws Exception{
        init();
        run();
    }
}






