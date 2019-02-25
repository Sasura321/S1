package example;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

import javax.swing.*;
public class MainFrm extends JFrame implements ActionListener{

	JMenuBar bar;
	JMenu menu;
	JMenuItem[] items;
	JPanel panel;

	public MainFrm()
	{
		this.setSize(1200,900);
		this.setTitle("项目信息管理系统");//标题
		this.setLocationRelativeTo(null);
		this.setLayout(null);
		this.initMenu();
		this.setVisible(true);
	}

	private void initMenu()//基础操作选项
	{
		bar=new JMenuBar();
		menu=new JMenu("操作");
		items=new JMenuItem[4];
		String[] menuNames={"增加","删除","查询","修改"};
		for(int i=0;i<menuNames.length;i++)
		{
			items[i]=new JMenuItem(menuNames[i]);
			items[i].addActionListener(this);
			menu.add(items[i]);
		}
		bar.add(menu);
		this.setJMenuBar(bar);

	}
	//添加监听器
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		JMenuItem item=(JMenuItem)e.getSource();
		if(panel!=null)
		{
			this.remove(panel);
		}
		if(item.getText().equals("增加"))
		{
			try {
				panel=new AddPassengerPanel();//进入增加信息界面
			} catch (ClassNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			} catch (SQLException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			panel.setLocation(20,20);
			this.add(panel);
			this.repaint();
		}
		else
		{
			if(item.getText().equals("删除"))
			{

				panel=new DeletePasPanel();
				panel.setLocation(20,20);
				this.add(panel);
				this.repaint();

			}
			else
			{
				if(item.getText().equals("查询"))
				{
					panel=new FindPasPanel();
					panel.setLocation(20,20);
					this.add(panel);
					this.repaint();
				}
				else
				{
					try {
						panel=new UpdatePasPanel();
					} catch (ClassNotFoundException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					} catch (SQLException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
					panel.setLocation(20,20);
					this.add(panel);
					this.repaint();

				}

			}
		}
	}

}
