package example;
import javax.swing.*;

import java.awt.Color;
import java.awt.event.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.ArrayList;
public class UpdatePasPanel extends JPanel implements ActionListener {
	JLabel rnoLabel;
	JLabel nameLabel;
	JLabel sexLabel;
	JLabel idcardLabel;
	JTextField rnoText;
	JTextField nameText;
	JTextField idcardText;
	JComboBox sexCom;
	JButton updateBt;
	JScrollPane scrollpane;
	JTable table;//展示旅社信息的表格
	private Connection conn;//定义数据库连接对象
	public UpdatePasPanel() throws ClassNotFoundException, SQLException
	{

		this.setLayout(null);
		this.setSize(1200,850);
		this.setBackground(Color.lightGray);
		this.init();
		this.refreshTable();
		this.setVisible(true);
		Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
		// 加载对应的jdbc驱动
		String url = "jdbc:sqlserver://localhost:1433; DatabaseName=EDUC";
		// 配置连接字符串
		String user = "sa";// sa超级管理员
		String password = "123456";// 密码
		conn = DriverManager.getConnection(url, user, password);
	}
	private void init()
	{
		rnoLabel=new JLabel("请输入房间号");
		rnoLabel.setSize(200,35);
		rnoLabel.setLocation(120,60);
		this.add(rnoLabel);
		rnoText=new JTextField();
		rnoText.setSize(250,35);
		rnoText.setLocation(330,60);
		this.add(rnoText);
		nameLabel=new JLabel("请输入姓名");
		nameLabel.setSize(200,35);
		nameLabel.setLocation(120, 105);
		this.add(nameLabel);
		nameText=new JTextField();
		nameText.setSize(250,35);
		nameText.setLocation(330, 105);
		this.add(nameText);
		sexLabel=new JLabel("请选择性别");
		sexLabel.setSize(200,35);
		sexLabel.setLocation(120, 150);
		this.add(sexLabel);
		sexCom=new JComboBox();
		sexCom.setSize(250,35);
		sexCom.setLocation(330,150);
//		sexCom.addItem("男");
//		sexCom.addItem("女");
		this.add(sexCom);
		idcardLabel=new JLabel("请输入身份证号");
		idcardLabel.setSize(200,35);
		idcardLabel.setLocation(120, 195);
		this.add(idcardLabel);
		idcardText=new JTextField();
		idcardText.setSize(250,35);
		idcardText.setLocation(330,195);
		this.add(idcardText);
		updateBt=new JButton("修改");
		updateBt.setSize(194,40);
		updateBt.setLocation(720, 300);
		updateBt.addActionListener(this);
		this.add(updateBt);
	}
	private void refreshTable() throws ClassNotFoundException, SQLException
	{
		String[] titles={"房间号","姓名","性别","身份证号"};
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
		scrollpane = new JScrollPane(table);
		scrollpane.setLocation(50,380);
		scrollpane.setSize(1000,400);
		this.add(scrollpane);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(!checkIsNull())
		{
			JOptionPane.showMessageDialog(this, "房间号或姓名或身份证号输入为空");
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
					Inf inf=new Inf(rnoText.getText().trim(),nameText.getText().trim(),sexCom.getSelectedItem().toString().trim(),idcardText.getText().trim());
					System.out.println(inf.getRno()+" "+inf.getPidcard());
					if(dao.updatePas(inf))
					{
						JOptionPane.showMessageDialog(this, "修改旅客记录成功！");
						rnoText.setText("");
						nameText.setText("");
						idcardText.setText("");
						refreshTable();
					}
					else
					{
						JOptionPane.showMessageDialog(this, "修改旅客记录失败！");
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
		if(rnoText.getText().trim().equals(""))
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
				if(idcardText.getText().trim().equals(""))
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
		if(rnoText.getText().trim().length()!=3)
		{
			result="房间号长度不是4";
		}
		else
		{
			boolean flag=true;
			if(flag)
			{
				for(int i=0;i<rnoText.getText().trim().length();i++)
				{
					char ch=rnoText.getText().trim().charAt(i);
					if(ch<'0'||ch>'9')
					{
						result="房间号中包含非数字字符";
						flag=false;
						break;
					}
				}
			}
			else
			{
				if(idcardText.getText().trim().length()!=18)
				{
					result="身份证号不是18位";
				}
				else
				{
					for(int i=0;i<idcardText.getText().trim().length();i++)
					{
						char ch=rnoText.getText().trim().charAt(i);
						if(ch<'0'||ch>'9')
						{
							result="身份证号中包含非数字字符";
							break;
						}
					}
				}
			}
		}
		return result;
	}

}
