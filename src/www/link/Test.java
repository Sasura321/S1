package www.link;

interface ILink{
    /**
     * 链表增加节点操作
     * @param data 节点内容
     * @return
     */

    boolean add(Object data);
    /**
     * 判断指定内容节点在链表中是否存在
     * @param data 要判断的内容
     * @return
     */

    boolean contains(Object data);
    /**
     * 删除指定节点内容
     * @param data
     * @return
     */
    Object remove(Object data);

    /**
     * 根据指定下标修改节点内容
     * @param index 索引下标
     * @param newData 替换后的内容
     * @return 替换之前的节点内容
     */
    Object set(int index, Object newData);

    /**
     * 根据指定下标修改节点内容
     * @param index 索引下标
     * @return
     */
    Object get(int index);

    /**
     * 链表清空
     */
    void clear();

    /**
     * 将链表转为数组
     * @return 返回所有的节点内容
     */
    Object[] toArray();

    /**
     * 链表长度
     * @return
     */
    int size();

    /**
     * 遍历链表
     */
    //void printLink();
}
/*
class LinkImpl implements ILink{

}


public class Test {
    public static void main (String[] args){
        ILink link = new LinkImpl();
        link.add("火车头");
        link.add("车厢1");
        link.add("车厢2");
        link.add("车厢3");
        link.printLink();
    }
}
***/
