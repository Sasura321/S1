package 操作系统.PCB1;

import java.util.*;

class pcb{
    private String name;//进程名称
    private String status;//状态
    private int time;//要求运行时间
    private int priorty;//优先数

    //getXXX()和setXXX()方法
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getStatus() {
        return status;
    }
    public void setStatus(String status) {
        this.status = status;
    }
    public int getTime() {
        return time;
    }
    public void setTime(int time) {
        this.time = time;
    }
    public int getPriorty() {
        return priorty;
    }
    public void setPriorty(int priorty) {
        this.priorty = priorty;
    }
}

//实现类
class method{
    //创建一个对象
    ArrayList <pcb> al=new ArrayList<pcb>();
    public void input(){
        for(int i=0;i<5;i++){
            pcb p = new pcb();
            int n = i+1;
            p.setName("PCB-"+n);//线程名称
            //用random()实现随机数
            int n1=(int)(Math.random()*6);
            //保证生成的随机数不为0
            while(n1 == 0) {
                n1=(int)(Math.random()*6);
            }
            //用random()实现随机数
            int n2=(int)(Math.random()*6);
            //保证生成的随机数不为0
            while(n2 == 0) {
                n2=(int)(Math.random()*6);
            }
            p.setTime(n1);
            p.setPriorty(n2);
            p.setStatus("R");
            al.add(p);
        }
    }

    //获取优先权最大的进程
    public int getMax(List<pcb> li){
        int max=0;
        int i=0;
        int k=0;
        Iterator <pcb>it=li.iterator();
        while(it.hasNext()) {
            pcb p=(pcb)it.next();
            if(p.getPriorty()>max) {
                max=p.getPriorty();
                k=i;
            }
            i++;
        }
        return k;
    }

    //运行后进程优先权-1
    public void renew(pcb p){
        if(p.getPriorty()!=0)
            p.setPriorty(p.getPriorty()-1);
        else
            p.setPriorty(0);
    }

    //打印线程
    public void show(){
        Iterator <pcb> it=al.iterator();
        while(it.hasNext()){
            pcb p=it.next();
            System.out.println(""+p.getName()+"\t"+p.getTime()+"\t"+p.getPriorty()+"\t"+p.getStatus());
        }
        //System.out.println();
    }

    //运行线程的run()方法
    public void run(){
        //若“就绪”(R)状态的进程队列不为空，采用动态改变优先数的办法，进程每运行一次优先数就减“1”，
        // 进程运行一次后，若要求运行时间0，则再将它加入队列（按优先数大小插入，且置队首标志）；
        // 若要求运行时间=0，则把它的状态修改成“结束”（E），且退出队列，直到所有进程都成为“结束”状态
        while(al.size()!=0){
            int max=getMax(al);
            pcb p=al.get(max);

            //根据优先数判断进程
            if((p.getTime()-1)!=0){
                p.setStatus("R");
                p.setTime(p.getTime()-1);
                show();
                p.setStatus("R");
            }
            else{
                p.setStatus("R");
                p.setTime(p.getTime()-1);
                show();
                p.setStatus("R");
            }
            renew(p);
            al.set(max, p);
            if(p.getTime()<=0){
                System.out.println("---------------------------");
                System.out.println("进程"+p.getName()+"结束");
                al.remove(max);
            }
        }
    }
}

public class Test {
    public static void main(String[] args) {
        method me=new method();
        me.input();
        me.run();
        System.out.println("---------------------------");
    }
}
