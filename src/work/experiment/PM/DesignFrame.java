package work.experiment.PM;

import java.awt.*;
import java.awt.event.ActionListener;

import javax.swing.*;

public class DesignFrame extends JFrame {

    //菜单
    JMenuBar jb;
    JMenu jm;
    JMenuItem jt1;
    JMenuItem jt2;

    //窗体上的控件
    JLabel lb1;
    JLabel lb2;
    JLabel lb3;
    JTextField tf1;
    JTextField tf2;
    JButton jb1;
    JButton jb2;

    public DesignFrame()
    {
        InitFrame();
    }

    private void InitFrame()
    {
        //InitMenu();


        lb3 = new JLabel("工  程 项  目  信  息   管  理  系  统 ");
        lb3.setSize(230, 50);//230  50
        lb3.setLocation(85, 30);//100 30
        this.add(lb3);


        lb1 = new JLabel("用户名:");
        lb1.setSize(50, 25);
        lb1.setLocation(90, 90);
        this.add(lb1);

        tf1 = new JTextField();
        tf1.setSize(120, 25);
        tf1.setLocation(140, 90);
        this.add(tf1);

        lb2 = new JLabel("密    码:");
        lb2.setSize(50, 25);
        lb2.setLocation(90, 120);
        this.add(lb2);

        tf2 = new JTextField();
        tf2.setSize(120, 25);
        tf2.setLocation(140, 120);
        this.add(tf2);

        jb1 = new JButton("登陆");
        jb1.setSize(60, 30);
        jb1.setLocation(100, 170);
        this.add(jb1);

        jb2 = new JButton("退出");
        jb2.setSize(60, 30);
        jb2.setLocation(190, 170);
        this.add(jb2);

        this.setSize(350, 300);
        this.setLayout(null);
        this.setTitle("项目信息管理系统");
        this.setLocation(400, 100);
        this.setVisible(true);
    }

}

