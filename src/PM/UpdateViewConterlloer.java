package PM;

import java.awt.Frame;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import javax.swing.table.*;


public class UpdateViewConterlloer extends UpdateView{

	private AdminService adminService=new AdminService();

	public UpdateViewConterlloer(){

		queryItem();


	}
	public UpdateViewConterlloer(Frame owner, boolean modal){

		super(owner,modal);
		//创建对象时展示数据
		queryItem();

	}


	@Override//查询方法
	public void queryItem() {
		// TODO Auto-generated method stub
		//定义表格头
		String[] thead={"项目编号","项目名称","创建时间","实施时间","完工时间","地点"};
		//adminService 查询服务
		ArrayList<Item> dataList= adminService.queryItem();
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

	@Override
	public void updateItem() {
		// TODO Auto-generated method stub
		String addNumber=addText1.getText();
		String addName=addText2.getText();
		String addTime1=addText3.getText();
		String addTime2=addText4.getText();
		String addTime3=addText5.getText();
		String addPlace=addText6.getText();

		boolean updataSuccess=adminService.updateItem(addNumber, addName, addTime1,addTime2,addTime3,addPlace);;
		//如果添加成功刷新表格
		if(updataSuccess){
			queryItem();}
		else{
			JOptionPane.showMessageDialog(this, "没有这个项目编号，请检查数据");}
	}
}

