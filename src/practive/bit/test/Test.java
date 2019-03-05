package practive.bit.test;


class MyThread extends Thread { // 线程主体类
    private String title ;
    public MyThread(String title) {
        this.title = title;
    }
    @Override
    public void run() { // 所有线程从此处开始执行
        for (int i = 0; i < 10 ; i++) {
            System.out.println(this.title+",i = " + i);
        }
    }
}

public class Test{
    public static void main(String[] args) {
        MyThread myThread1 = new MyThread("thread1") ;
        MyThread myThread2 = new MyThread("thread2") ;
        MyThread myThread3 = new MyThread("thread3") ;
        myThread1.start();
        myThread2.start();
        myThread3.start();
    }
}
