package example;
import java.awt.Color;
import java.awt.HeadlessException;
import java.awt.event.*;
import java.sql.SQLException;

import javax.swing.*;
public class FindPasPanel extends JPanel implements ActionListener {

	JLabel label;
	JTextField number;
	JButton findBt;

	public FindPasPanel()
	{
		this.setSize(1200,850);
		this.setLayout(null);
		this.setBackground(Color.GRAY);
		this.init();
		this.setVisible(true);
	}

	private void init()
	{
		label=new JLabel("项目编号");
		label.setSize(90,30);
		label.setLocation(300,300);
		this.add(label);

		number=new JTextField();
		number.setSize(200,30);
		number.setLocation(420,300);
		this.add(number);

		findBt=new JButton("查询");
		findBt.setSize(150,45);
		findBt.setLocation(650,500);
		findBt.addActionListener(this);
		this.add(findBt);

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(!checkIsNull())
		{
			JOptionPane.showMessageDialog(this, "输入的项目编号为空");
		}
		else
		{
			if(!checkInput().equals(""))
			{
				JOptionPane.showMessageDialog(this, checkInput());
			}
			else
			{
				try{
					InformationDAO dao = new InformationDAO();
					String st=dao.findPasByRno(number.getText().trim());
					JOptionPane.showMessageDialog(this,st);
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
		if(number.getText().trim().equals(""))
		{
			flag=false;
		}
		return flag;
	}
	private String checkInput()
	{
		String result="";
		if(number.getText().trim().length()!=3)
		{
			result="项目编号的长度不是4";
		}
		else
		{
			for(int i=0;i<number.getText().trim().length();i++)
			{
				char ch=number.getText().trim().charAt(i);
				if(ch>'9'||ch<'0')
				{
					result="项目编号包含非数字字符";
				}
			}
		}
		return result;
	}
}
