package PM;

import java.awt.*;
import javax.swing.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public  class View1 extends JFrame {
	//组件
	private JButton btn1 = new JButton("查询项目");
	private JButton btn2 = new JButton("增加项目");
	private JButton btn3 = new JButton("删除项目");
	private JButton btn4 = new JButton("修改项目");

	//构造函数
	public View1(){
		this.init();
		this.addComponent();
		this.AddListener();
		setVisible(true);


	}

	private void init() {
		this.setTitle("项 目 信 息 管 理 系 统");//标题
		this.setSize(1000, 600);
		Tool.center(this);
		Tool.setTitleImage(this, "22.png");
		this.setResizable(false);//窗口固定
	}

	//添加组件
	private void addComponent(){
		BackgroundPanel bgp; //自定义的背景类
		//重新绘制背景图片
		bgp=new BackgroundPanel((new ImageIcon("3.jpg")).getImage()); //参数是一个Image对象,
		bgp.setBounds(0,0,1000,600);
		this.add(bgp);
		JPanel btnPanel=new JPanel();
		//清除布局
		btnPanel.setLayout(null);
		this.add(btnPanel);
		//定义边界位置
		btn1.setBounds(10, 30, 120,50);
		btn2.setBounds(10, 130, 120,50);
		btn3.setBounds(10, 230, 120,50);
		btn4.setBounds(10, 330, 120,50);
		//将按钮添加到JPanel
		btnPanel.add(btn1);
		btnPanel.add(btn2);
		btnPanel.add(btn3);
		btnPanel.add(btn4);
	}

	class BackgroundPanel extends JPanel
	{
		Image im;
		public BackgroundPanel(Image im)
		{
			this.im=im;
			this.setOpaque(true);
			//设置控件不透明,若是false,那么就是透明
		}
		//Draw the background again,继承自Jpanle,是Swing控件需要继承实现的方法,而不是AWT中的Paint()
		public void paintComponent(Graphics g)       //绘图类,详情可见博主的Java 下 java-Graphics
		{
			super.paintComponents(g);
			g.drawImage(im,0,0,this.getWidth(),this.getHeight(),this);  //绘制指定图像中当前可用的图像。图像的左上角位于该图形上下文坐标空间的 (x, y)。图像中的透明像素不影响该处已存在的像素

		}
	}

	//四个按钮的监听
	@SuppressWarnings("unused")
	private void AddListener(){
		btn1.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new SelectView().setVisible(true);
				setVisible(false);
			}
		});

		btn2.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new AddViewController().setVisible(true);
				setVisible(false);
			}
		});

		btn3.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new DelViewConterlloer().setVisible(true);
				setVisible(false);
			}
		});
		btn4.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new UpdateViewConterlloer().setVisible(true);
				setVisible(false);
			}
		});
	}
}

