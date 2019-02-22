package PM;

import java.util.ArrayList;

/**
 * 增删查改服务
 */

public class AdminService {
	private AdminDao adminDao=new AdminDao();

	//查询服务
	public ArrayList<Item> queryItem(){
		//调用DAO层的获取方法
		ArrayList<Item> data =adminDao.queryAllData();
		return data;
	}

	//添加服务
	public boolean addItem(String number,String name,String time1,String time2,String time3,String place){
		//调用DAO层的获取方法
		ArrayList<Item> data =adminDao.queryAllData();
		//输入邮编与所有数据比较
		for (int i=0;i<data.size();i++){
			Item item =data.get(i);
			//重复添加失败
			if(number.equals(item.getNumber() )){
				return false;
			}
		}
		//如果没有重复
		Item thisItem=new Item(number,name,time1,time2,time3,place);
		adminDao.addItem(thisItem);
		return true;

	}

	//修改服务
	public boolean updateItem(String number,String name,String time1,String time2,String time3,String place){
		//调用DAO层的获取方法获取全部数据
		ArrayList<Item> data =adminDao.queryAllData();
		for (int i=0;i<data.size();i++){
			Item item =data.get(i);
			//邮编相同可以更新
			if(number.equals(item.getNumber() )){
				//调用DAO删除指定数据
				//adminDao.addProjectItem(number);

				Item thisItem=new Item(number,name,time1,time2,time3,place);

				adminDao.addItem(thisItem);//添加数据
				return true;
			}
		}   return false;//项目编号编不同不修改数据
	}

	public boolean delItem(String delNumbel){
		//调用DAO层的获取方法获取全部数据
		ArrayList<Item> data =adminDao.queryAllData();
		for (int i=0;i<data.size();i++){
			Item item =data.get(i);
			//如果相同则删除
			if(delNumbel.equals(item.getNumber() )){
				adminDao.delItem(delNumbel);
				return true;

			}
		}
		return false;//项目编号不同则不删除
	}
}
