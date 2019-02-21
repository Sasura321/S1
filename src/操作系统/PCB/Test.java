package 操作系统.PCB;

class PCB implements  Runnable{
    String ID;
    int runtime;
    int pri;
    char state;

    public int maxPriProcess() {
        int max = -100;
        int key = 0;
        if (state == 'R') {
            return -1;
        } else {
            //从就绪进程中选取优先数最大的进程
            if ((max < pri) && (state == 'R')) {
                max = pri;
            }
        }

        if(state == 'E') {
            return -1;
        } else {
            return key;
        }
    }

    public void show() {
        System.out.println("\nID，pri，runtime，state");
        System.out.println(ID+"， "+ pri + "， "+ runtime+"， " + state);
        System.out.println("press any key to continue……");
        System.out.println("-------------------------------");
    }

    @Override
    public void run() {
        while(maxPriProcess() != -1) {
            state = 'R';
        }
        if(state == 'R') {
            pri = 1;
            runtime--;
        }
        if(runtime == 0) {
            state = 'E';
        } else {
            state = 'R';
        }
        show();

    }
}

public class Test {

    public static void main(String[] args) throws Exception{
        PCB mt = new PCB();
        Thread P1 = new Thread(mt, "P1");
        Thread P2 = new Thread(mt, "P2");
        Thread P3 = new Thread(mt, "P3");
        Thread P4 = new Thread(mt, "P4");
        Thread P5 = new Thread(mt, "P5");
        P1.start();
        Thread.sleep(1000);
        P2.start();
        Thread.sleep(1000);
        P3.start();
        Thread.sleep(1000);
        P4.start();
        Thread.sleep(1000);
        P5.start();
    }
}







