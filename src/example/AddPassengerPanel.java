package example;
import java.awt.Color;

import java.awt.event.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ArrayList;
import javax.swing.*;

public class AddPassengerPanel extends JPanel implements ActionListener {
	JLabel numberLabel;
	JLabel nameLabel;
	JLabel time1Label;
	JLabel time2Label;
	JTextField numberText;
	JTextField nameText;
	JTextField time1Text;
	JComboBox time2Com;
	JButton addBt;
	JScrollPane scrollPane;
	JTable table;
	private Connection conn;//定义数据库连接对象
	public AddPassengerPanel()throws ClassNotFoundException,SQLException
	{
		this.setSize(1200,850);
		this.setLayout(null);
		this.setBackground(Color.GRAY);
		this.init();
		this.refreshTable();
		this.setVisible(true);

	}
	public void init()
	{
		numberLabel=new JLabel("项目编号");
		numberLabel.setSize(200,35);
		numberLabel.setLocation(120,60);
		this.add(numberLabel);
		numberText=new JTextField();
		numberText.setSize(250,35);
		numberText.setLocation(330,60);
		this.add(numberText);
		nameLabel=new JLabel("请输入项目名称");
		nameLabel.setSize(200,35);
		nameLabel.setLocation(120, 105);
		this.add(nameLabel);
		nameText=new JTextField();
		nameText.setSize(250,35);
		nameText.setLocation(330, 105);
		this.add(nameText);
		time1Label=new JLabel("请输入实施时间");
		time1Label.setSize(200,35);
		time1Label.setLocation(120, 150);
		this.add(time1Label);
		time2Com=new JComboBox();
		time2Com.setSize(250,35);
		time2Com.setLocation(330,150);
		this.add(time2Com);
		time2Label=new JLabel("请输入完成时间");
		time2Label.setSize(200,35);
		time2Label.setLocation(120, 195);
		this.add(time2Label);
		time1Text=new JTextField();
		time1Text.setSize(250,35);
		time1Text.setLocation(330,195);
		this.add(time1Text);
		addBt=new JButton("添加");
		addBt.setSize(192,40);
		addBt.setLocation(720,300);
		addBt.addActionListener(this);
		this.add(addBt);
	}

	private void refreshTable() throws ClassNotFoundException, SQLException
	{
		String[] titles={"项目编号","项目名称","实施时间","完成时间"};
		InformationDAO dao=new InformationDAO();
		ArrayList<String> stus=dao.findAllPassengers();
		Object[][] objs=new Object[stus.size()][4];

		for(int i=0;i<stus.size();i++)
		{
			String[] strs=stus.get(i).split(",");
			objs[i][0]=strs[0];
			objs[i][1]=strs[1];
			objs[i][2]=strs[2];
			objs[i][3]=strs[3];
			System.out.println(strs[0]);

		}
		this.removeAll();
		this.init();
		table=new JTable(objs,titles);
		table.setSize(1000,400);
		scrollPane = new JScrollPane(table);
		scrollPane.setLocation(50,380);
		scrollPane.setSize(1000,400);
		this.add(scrollPane);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(!checkIsNull())
		{
			JOptionPane.showMessageDialog(this, "项目编号或项目名称输入为空");
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
					Inf inf=new Inf(numberText.getText().trim(),nameText.getText().trim(),time2Com.getSelectedItem().toString().trim(),time1Text.getText().toString().trim());
					if(dao.addPa(inf))
					{
						JOptionPane.showMessageDialog(this, "添加项目信息成功！");
						numberText.setText("");
						nameText.setText("");
						time1Text.setText("");
						refreshTable();
					}
					else
					{
						JOptionPane.showMessageDialog(this, "添加项目信息失败！");
					}
					refreshTable();
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
			return false;
		}
		else
		{
			if(nameText.getText().trim().equals(""))
			{
				return false;
			}
			else
			{
				if(time1Text.getText().trim().equals(""))
				{
					return false;
				}
			}

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

				}
			}
		}

//		if(idCardText.getText().trim().length()!=18)
//		{
//			result="身份证号不是18位";
//		}
//		else
//		{
//			for(int i=0;i<idCardText.getText().trim().length();i++)
//			{
//				char ch=idCardText.getText().trim().charAt(i);
//				if(ch<'0'||ch>'9')
//				{
//					result="身份证号中包含非数字字符";
//					break;
//				}
//			}
//		}
		return result;
	}

}