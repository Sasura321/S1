package www.link;
/*
//定义车厢（节点）结构
class Node{
    private Object data; // 节点数据
    private Node next;   // 指向下一个节点


    public Node(Object data){
        this.data = data;
    }

    public Object getData(){
        return data;
    }

    public Object setData(Object data){
        this.data = data;
    }

    public Object getNext(){
        return next;
    }

    public Object setNext(Node next){
        this.next = next;
    }
}

public class TestNew {
    public static void main (String[] args){
        // 数组一旦定义，长度一定
        //Object[] data = new Object[3];
        Node head = new Node("车厢头");
        Node first = new Node("车厢1");
        Node second = new Node("车厢2");
        Node last = new Node("车厢3");
        head.setNext(first);
        first.setNext(second);
        second.setNext(last);
        printLink(head);
    }

    public static void printLink(Node node){
        if(node != null){
            System.out.println(node.getData());
            //node = node.getNext();
            printLink(node);
        }
    }
}

*/