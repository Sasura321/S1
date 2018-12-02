package www.commodity;

class Goods {
    private String goodsName;
    private  int count;
    public synchronized void set(String goodsName) {
        if(count>0){
            System.out.println("商品有库存");
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        this.goodsName = goodsName;
        this.count++;
        System.out.println(Thread.currentThread().getName()
                    +"生产" + goodsName+toString());
        //唤醒等待消费的线程
        notify();
    }
    //消费商品方法
    public synchronized void get(){
        if(count == 0){
            System.out.println("商品买完了");
            try {
                //等待商品生产
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        this.count--;
        System.out.println(Thread.currentThread().getName()
                +"消费" + goodsName+toString());
        notify();
    }
    public String toString() {
        return "Goods{" + "goodsName='" + goodsName+"\'"+",count="+count+"'}";
    }
}

//消费者线程
class  Consumer implements Runnable{
    private Goods goods;

    public  Consumer(Goods goods){
        this.goods = goods;
    }
    @Override
    public void run() {
        goods.get();
    }
}

//生产者线程
class Producer implements Runnable{
    private Goods goods;

    public Producer(Goods goods){
        this.goods = goods;
    }

    @Override
    public void run() {
        goods.get();
    }
}

public class Test {
    public static void main(String[] args){
        Goods con = new Goods();
        //Thread thread = new Thread(Consumer);
    }
}
