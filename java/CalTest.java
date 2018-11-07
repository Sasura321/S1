import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class CalTest extends JFrame implements ActionListener{
	
	//�����ڴ����е����пؼ�
	JTextField text;
	JPanel panel1;//���1��������20����ť
	JPanel panel2;//���2��������4����ť
	JButton[] bts1;//����20����ť������
	JButton[] bts2;//����4����ť������
	JButton bt1;
	JButton bt2;
	JButton bt3;
	JButton bt4;
	
	
	public CalTest()
	{
		this.setSize(355,347);
		this.setTitle("������");
		this.setLayout(null);
		
		text=new JTextField();
		text.setSize(320, 50);
		text.setLocation(10, 10);
		this.add(text);
		
		panel1=new JPanel();
		panel1.setSize(320, 150);
		panel1.setLocation(10, 70);
		//panel1.setBackground(Color.red);
		bts1=new JButton[20];
		String[] strs1={"MC","MR","MS","M+","M-","��","CE","C","+-","��","7","8","9","/","%","4","5","6","*","1/x"};
		panel1.setLayout(new GridLayout(4,5,3,3));
		for(int i=0;i<bts1.length;i++)
		{
			bts1[i]=new JButton(strs1[i]);
			panel1.add(bts1[i]);
		}
		this.add(panel1);
		
		panel2=new JPanel();
		panel2.setSize(255, 33);
		panel2.setLocation(10, 223);
		//panel1.setBackground(Color.red);
		bts2=new JButton[4];
		String[] strs2={"1","2","3","-"};
		panel2.setLayout(new GridLayout(1,4,3,3));
		for(int i=0;i<bts2.length;i++)
		{
			bts2[i]=new JButton(strs2[i]);
			panel2.add(bts2[i]);
			bts2[i].addActionListener(this);
		}
		
		
		bt1=new JButton("0");
		bt1.setSize(125, 33);
		bt1.setLocation(10, 260);
		this.add(bt1);
		
		bt2=new JButton(".");
		bt2.setSize(60, 33);
		bt2.setLocation(138, 260);
		this.add(bt2);
		
		bt3=new JButton("+");
		bt3.setSize(60, 33);
		bt3.setLocation(203, 260);
		this.add(bt3);
		
		bt4=new JButton("=");
		bt4.setSize(60, 70);
		bt4.setLocation(266, 223);
		this.add(bt4);
		
		this.add(panel2);
		
		
		
		
		
		
		
		
		this.setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e)
	{
		JButton bt=(JButton)e.getSource();
		text.setText(text.getText()+bt.getText());
	}

}
