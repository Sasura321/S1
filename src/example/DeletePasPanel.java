package example;
import java.awt.Color;
import java.awt.event.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import javax.swing.*;
public class DeletePasPanel extends JPanel implements ActionListener {

	JLabel number;
	JTextField numberText;
	JButton delBt;
	private Connection conn;//定义数据库连接对象
	public DeletePasPanel()
	{
		this.setSize(1200,850);
		this.setLayout(null);
		this.setBackground(Color.lightGray);
		this.init();
		this.setVisible(true);
	}
	public void init()
	{
		number=new JLabel("请输入项目编号");
		number.setSize(90,30);
		number.setLocation(300,300);
		this.add(number);

		numberText=new JTextField();
		numberText.setSize(200,30);
		numberText.setLocation(420,300);
		this.add(numberText);
		delBt=new JButton("删除");
		delBt.setSize(150,45);
		delBt.setLocation(650,500);
		delBt.addActionListener(this);
		this.add(delBt);

	}
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(!checkIsNull())
		{
			JOptionPane.showMessageDialog(this, "项目编号为空");
		}
		else
		{
			if(!checkInput().equals(""))
			{
				JOptionPane.showMessageDialog(this, checkInput());
			}
			else
			{
				try {

					InformationDAO dao = new InformationDAO();
					if(dao.deletePas(numberText.getText().trim()))
					{
						JOptionPane.showMessageDialog(this, "删除成功");
					}
					else
					{
						JOptionPane.showMessageDialog(this, "删除失败");
					}
				} catch (SQLException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				} catch (ClassNotFoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
			}

		}
	}
	private boolean checkIsNull()
	{
		boolean flag=true;
		if(numberText.getText().trim().equals(""))
		{
			flag=false;
		}
		return flag;
	}
	private String checkInput()
	{
		String result="";
		if(numberText.getText().trim().length()!=3)
		{
			result="项目编号长度不是4";
		}
		else
		{
			for(int i=0;i<numberText.getText().trim().length();i++)
			{
				char ch=numberText.getText().trim().charAt(i);
				if(ch<'0'||ch>'9')
				{
					result="项目编号中包含非数字字符";
					break;
				}
			}
		}
		return result;
	}

}
