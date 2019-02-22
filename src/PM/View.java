package PM;

import java.awt.*;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

//主窗口
public abstract class View extends JFrame {
	//组件
	//private JLabel titleLabel =new JLabel(new ImageIcon("2.jpg"));
	private JButton btn = new JButton("登陆");
	//构造函数
	public View(){
		this.init();
		this.addComponent();
		this.addListener();

	}
	private void init() {
		this.setTitle("项 目 信 息 管 理 系 统");//标题
		this.setSize(610, 410);
		Tool.center(this);
		//Tool.setTitleImage(this, "22.png");
		this.setResizable(false);//窗口固定
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE );//退出程序
	}
	//添加组件
	private void addComponent(){

		//窗体上的控件
		JLabel lb1;
		JLabel lb2;
		JLabel lb3;
		JTextField tf1;
		JTextField tf2;
		JButton jb;

		lb3 = new JLabel("工  程 项  目  信  息   管  理  系  统 ");
		lb3.setBounds(200, 60, 200, 50);
		this.add(lb3);

		lb1 = new JLabel("用户名:");
		lb1.setBounds(210, 120, 50, 25);
		this.add(lb1);

		tf1 = new JTextField();
		tf1.setBounds(260, 120, 120, 25);
		this.add(tf1);

		lb2 = new JLabel("密    码:");
		lb2.setBounds(210, 160, 50, 25);
		this.add(lb2);

		tf2 = new JTextField();
		tf2.setBounds(260, 160, 120, 25);
		this.add(tf2);

		jb = new JButton("退出");
		jb.setBounds(310, 200, 60, 30);
		this.add(jb);
//		this.add(this.ti,BorderLayout.NORTH);
//		JPanel bt=new JPanel();
//		//清除布局
//		bt.setLayout(null);
//		bt.add(btn);

		//窗口使用默认布局 北区放入图片
		//this.add(this.titleLabel,BorderLayout.NORTH);
		JPanel btnPanel=new JPanel();
		//清除布局
		btnPanel.setLayout(null);
		this.add(btnPanel);
		//定义边界位置
		btn.setBounds(220, 200, 60,30);
		//将按钮添加到JPanel
		btnPanel.add(btn);
	}

	private void addListener(){
		btn.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new View1();
				setVisible(false);
			}
		});

	}
}
