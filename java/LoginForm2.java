import javax.swing.*;
import java.awt.*;

public class LoginForm2 extends JFrame{//�̳д�����

	private JLabel label1;
	private JLabel label2;//�����ǩ����
	private JTextField text1;
	private JTextField text2;//�����ı������
	private JButton bt1;
	private JButton bt2;//���尴ť����
	
	
	public LoginForm2()
	{
		this.setSize(400, 230);//���ô���Ĵ�С
		this.setTitle("��¼����");//���ô������
		this.setLayout(null);
		//�������Ĭ�ϲ��ַ�ʽ����Ϊ�޲��ַ�ʽ
		//�����ؼ�
		label1=new JLabel("�û���");
		label1.setSize(80, 30);
		label1.setLocation(60,30);
		
		label2=new JLabel("��    ��");
		label2.setSize(80, 30);
		label2.setLocation(60,75);
		
		text1=new JTextField();
		text1.setSize(170, 30);
		text1.setLocation(140,30);
		
		
		text2=new JTextField();
		text2.setSize(170, 30);
		text2.setLocation(140,75);
		
		bt1=new JButton("��¼");
		bt1.setSize(90, 30);
		bt1.setLocation(90,130);
		
		bt2=new JButton("�˳�");
		bt2.setSize(90, 30);
		bt2.setLocation(190,130);
		
	
		
		
		this.add(label1);
		this.add(text1);
		this.add(label2);
		this.add(text2);
		this.add(bt1);
		this.add(bt2);
		
		
		this.setVisible(true);//���ô���ɼ�
	}
}
