package calculator;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Test extends JFrame implements ActionListener{

    //声明在窗体中的所有控件
    JTextField text;
    JPanel panel1;//面板1，上面有3个按钮
    JPanel panel2;//面板2，上面有3个按钮
    JPanel panel3;//面板3，上面有(10*3)个按钮
    JPanel panel4;//面板4，上面有9个按钮
    JPanel panel5;//面板5，上面有5个按钮

    JButton[] bts1;//包含3个按钮的数组
    JButton[] bts2;//包含3个按钮的数组
    JButton[] bts3;//包含(10*3)个按钮的数组
    JButton[] bts4;//包含9个按钮的数组
    JButton[] bts5;//包含5个按钮的数组

    JButton bt1;
    JButton bt2;
    JButton bt3;
    JButton bt4;


    public Test()
    {
        this.setSize(670, 347);   //(355,347 )
        this.setTitle("计算器");
        this.setLayout(null);

        text=new JTextField();
        text.setSize(635, 50);   //320
        text.setLocation(10, 10);
        this.add(text);


        panel1=new JPanel();
        panel1.setSize(313, 30);
        panel1.setLocation(13, 70);
        //panel1.setBackground(Color.red);
        bts1=new JButton[3];
        String[] strs1 = {"度","弧度","梯度"};
        panel1.setLayout(new GridLayout(1,3,3,3));
        for(int i=0;i<bts1.length;i++)
        {
            bts1[i]=new JButton(strs1[i]);
            panel1.add(bts1[i]);
           bts1[i].addActionListener(this);
        }
        this.add(panel1);

        panel2=new JPanel();
        panel2.setSize(320, 30);
        panel2.setLocation(328, 70);
        //panel1.setBackground(Color.red);
        bts2=new JButton[5];
        String[] strs2={"MC","MR","MS","M+","M-"};
        panel2.setLayout(new GridLayout(1,5,3,3));
        for(int i=0;i<bts2.length;i++)
        {
            bts2[i]=new JButton(strs2[i]);
            panel2.add(bts2[i]);
            bts2[i].addActionListener(this);
        }
        this.add(panel2);

        panel3=new JPanel();
        panel3.setSize(635, 111);//610 108
        panel3.setLocation(10, 103);//33
        bts3=new JButton[30];
        String[] strs3={"  ","Inv","In","(",")","←","CE","C","+-","√",
                        "Int","sinh","sin","x^2","n!","7","8","9","/","%",
                        "dms","cosh","cos","x^y","y√x","4","5","6","*","1/x",
                        };
        panel3.setLayout(new GridLayout(3,10,3,3));
        for(int i=0; i<bts3.length; i++)
        {
            bts3[i]=new JButton(strs3[i]);
            panel3.add(bts3[i]);
            bts3[i].addActionListener(this);
        }
        this.add(panel3);

        panel4=new JPanel();
        panel4.setSize(570, 33);
        panel4.setLocation(10, 220);
        //panel1.setBackground(Color.red);
        bts4=new JButton[9];
        String[] strs4={"π","tanh","tan","x^3","3√x","1","2","3","-"};
        panel4.setLayout(new GridLayout(1,9,3,3));
        for(int i=0;i<bts4.length;i++)
        {
            bts4[i]=new JButton(strs4[i]);
            panel4.add(bts4[i]);
            bts4[i].addActionListener(this);
        }
        this.add(panel4);

        panel5=new JPanel();
        panel5.setSize(320, 33);
        panel5.setLocation(10, 256);
        //panel1.setBackground(Color.red);
        bts5=new JButton[5];
        String[] strs5={"F-E","Exp","Mod","log","10^x"};
        panel5.setLayout(new GridLayout(1,5,3,3));
        for(int i=0;i<bts5.length;i++)
        {
            bts5[i]=new JButton(strs5[i]);
            panel5.add(bts5[i]);
            bts5[i].addActionListener(this);
        }
        this.add(panel5);

        bt1=new JButton("0");
        bt1.setSize(120, 33);
        bt1.setLocation(331, 256);
        bt1.addActionListener(this);
        this.add(bt1);

        bt2=new JButton(".");
        bt2.setSize(60, 33);
        bt2.setLocation(455, 256);
        bt2.addActionListener(this);
        this.add(bt2);

        bt3=new JButton("+");
        bt3.setSize(60, 33);
        bt3.setLocation(517, 256);
        bt3.addActionListener(this);
        this.add(bt3);

        bt4=new JButton("=");
        bt4.setSize(60, 70);
        bt4.setLocation(580, 220);
        bt4.addActionListener(this);
        this.add(bt4);

        this.setVisible(true);
    }

    public void actionPerformed(ActionEvent e)
    {
        JButton bt=(JButton)e.getSource();
        text.setText(text.getText()+bt.getText());
    }


    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Test Test=new Test();
    }

}
