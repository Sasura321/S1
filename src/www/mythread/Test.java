package www.mythread;

class Mythread implements Runnable{
    private Object object;
    private boolean flag;

    public Mythread(Object object, boolean flag){
        this.object = object;
        this.flag = flag;
    }
    public void waitMethod(){
        synchronized (object){
            System.out.println("wait方法开始.."+Thread.currentThread().getName());
            try{
                object.wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            System.out.println("wait方法结束.."+Thread.currentThread());
        }
    }
    public void notifyMethod(){
        synchronized (object){
            System.out.println("notify方法开始.."+Thread.currentThread().getName());
        }
    }

    @Override
    public void run() {

    }
}

public class Test{

}
