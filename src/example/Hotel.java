package example;
import javax.swing.*;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public  class Hotel extends JFrame implements ActionListener{


    JTextField text; //用户登录文本框
    JTextField text2;//密码输入文本框

    JButton bt1;//用户名按钮
    JButton bt2;//密码按钮
    JButton [] bt=new JButton[2];//登录组

    MainFrm fr;

    public Hotel()
    {
        this.setSize(500,400);
        this.setTitle("项目信息管理系统登录");
        this.setLayout(null);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        bt1=new JButton("用户名");
        bt1.setSize(100,30);
        bt1.setLocation(60,90);
        this.add(bt1);//添加用户名按钮

        text=new JTextField();
        text.setSize(200,30);
        text.setLocation(180,90);
        this.add(text);

        bt2=new JButton("密 码");
        bt2.setSize(100,30);
        bt2.setLocation(60,145);
        this.add(bt2);//添加密码按钮

        text2=new JTextField();
        text2.setSize(200,30);
        text2.setLocation(180,145);
        this.add(text2);

        bt[0]=new JButton("登录");
        bt[0].setSize(80,30);
        bt[0].setLocation(60,230);
        bt[0].addActionListener(this);
        this.add(bt[0]);

        bt[1]=new JButton("退出");
        bt[1].setSize(80,30);
        bt[1].setLocation(300,230);
        this.add(bt[1]);
        bt[1].addActionListener(this);

        this.setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        if((!text.getText().equals("sa"))&&(!text2.getText().equals("123456")))//判断账号密码是否正确
        {
            JOptionPane.showMessageDialog(this,"账号出错");
        }
        else
        {
            for(int i=0;i<bt.length;i++)
            {
                if(bt[i].getText().equals("登录"))
                    fr=new MainFrm();//正常登录，进入操作界面
            }
        }



    }

}