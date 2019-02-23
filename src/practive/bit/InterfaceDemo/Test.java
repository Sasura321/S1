package practive.bit.InterfaceDemo;

import javax.swing.*;

interface IMessage {
    public static final String MSG = "I am a biter";
    public abstract void prrint();
}

interface INews {
    public abstract String getNews();
}

class MessageImpl implements IMessage,INews {

    @Override
    public void prrint() {
        System.out.println(IMessage.MSG);
    }

    @Override
    public String getNews() {
        return IMessage.MSG;
    }
}

public class Test {
    public static void main(String[] args) {
        IMessage m = new MessageImpl();
        m.prrint();
        INews n = (INews)m;
        System.out.println(n.getNews());
    }
}
