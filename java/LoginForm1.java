import javax.swing.*;
import java.awt.*;

public class LoginForm1 extends JFrame{//�̳д�����

	private JLabel label1;
	private JLabel label2;//�����ǩ����
	private JTextField text1;
	private JTextField text2;//�����ı������
	private JButton bt1;
	private JButton bt2;//���尴ť����
	
	
	public LoginForm1()
	{
		this.setSize(400, 300);//���ô���Ĵ�С
		this.setTitle("��¼����");//���ô������
		//�����ؼ�
		label1=new JLabel("�û���");
		label2=new JLabel("��    ��");
		text1=new JTextField();
		text2=new JTextField();
		bt1=new JButton("��¼");
		bt2=new JButton("�˳�");
		
		//������Ĳ��ַ�ʽ��Ϊ������
		this.setLayout(new FlowLayout());
		
		this.add(label1);
		this.add(text1);
		this.add(label2);
		this.add(text2);
		this.add(bt1);
		this.add(bt2);
		
		
		this.setVisible(true);//���ô���ɼ�
	}
}
