package PM;

import java.awt.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

/**
 * 查询项目信息的界面
 */

public class SelectView extends JDialog{
	private AdminService adminService=new AdminService();
	private JLabel tableLabel =new JLabel("项目信息列表"); //列表标题
	private JScrollPane tablePane =new JScrollPane();  //滚动视口
	protected JTable table=new JTable();

//	private JLabel Label2 =new JLabel("项目编号");//编号标题
//	private JLabel Label3 =new JLabel("项目名称");
//	protected JTextField addText1=new JTextField(6);//添加邮编文本框
//	protected JTextField addText2=new JTextField(6);

	//添加功能组件

	private JButton addBtn1 =new JButton("返回主页");//按钮
	/*
    protected JTextField updateNumberText=new JTextField(6);
    protected JTextField updateNameText=new JTextField(6);
    protected JTextField updateShengHuiLabel=new JTextField(6);*/
	//构造方法
	public SelectView()  {
		this(null,true);
	}
	public SelectView(Frame owner,boolean modal){
		super(owner,modal);
		this.init();
		this.addComponent();

		this.HoustListener();}
	private void init(){
		this.setTitle("查询界面");
		this.setSize(700, 400);
		Tool.center(this);
		//Tool.setTitleImage(this, "22.png");
		this.setResizable(false);//窗口固定
		queryItem();
	}
	//添加组件
	private void addComponent(){
		this.setLayout(null);//取消布局
		//表格标题
		tableLabel.setBounds(290, 20, 100, 25);
		this.add(tableLabel);
		//表格
		table.getTableHeader().setReorderingAllowed(false);//列不能移动
		table.getTableHeader().setResizingAllowed(false);//不可拉动表格
		table.setEnabled(false);
		tablePane.setBounds(50,50,500,200);
		tablePane.setViewportView(table);//视口装入表格
		this.add(tablePane);
		//字段标题

		//增加组件

//		Label2.setBounds(50,250,70,25);
//		Label3.setBounds(150,250,70,25);
//		this.add(Label2);
//		this.add(Label3);
//		addText1.setBounds(50,280,80,25);
//		addText2.setBounds(150,280,80,25);
//		this.add(addText1);
//		this.add(addText2);
		addBtn1.setBounds(265,280,90,30);
		this.add(addBtn1);
	}
	//监听
	private void HoustListener(){
		addBtn1.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				//System.exit(0);//退出程序
				JOptionPane.showMessageDialog(null, "返回主界面！");
				new View1();
				setVisible(false);

			}
		});

	}
	public void queryItem() {
		// TODO Auto-generated method stub
		//定义表格头
		String[] thead={"项目编号","项目名称","创建时间","实施时间","完工时间","地点"};
		//adminService 查询服务
		ArrayList<Item> dataList=adminService.queryItem();
		//调用list2Array,将查询到的集合转为数组
		String[][] tbody=list2Array(dataList);
		//将查询到的结果为table赋值
		TableModel dataModel=new DefaultTableModel(tbody,thead);
		table.setModel(dataModel);
	}

	public String[][] list2Array (ArrayList<Item> list) {
		//根据Item的model与集合数据定义JTable的数据二维数组
		String[][] tbody=new String[list.size()][6];
		for(int i=0;i<list.size();i++){
			Item item=list.get(i);
			tbody[i][0]=item.getNumber();
			tbody[i][1]=item.getName();
			tbody[i][2]=item.getTime1();
			tbody[i][3]=item.getTime2();
			tbody[i][4]=item.getTime3();
			tbody[i][5]=item.getPlace();
		}
		return tbody;
	}

}