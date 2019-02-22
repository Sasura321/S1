package PM;

import javax.swing.*;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;

//import java.util.ArrayList;

/**
 * 数据驱动访问类
 */
//
public class AdminDao {
	//鑾峰彇鎵�鏈夋暟鎹�
	public ArrayList<Item> queryAllData(){
		Connection conn = null;
		Statement stmt = null;
		ResultSet rs = null;
		ArrayList<Item> list = new ArrayList<Item>();
		try{
			//鑾峰緱鏁版嵁鐨勮繛鎺�
			conn = JDBCUtils.getConnection();
			//鑾峰緱Statement 瀵硅薄
			stmt = conn.createStatement();
			//鍙戦�丼QL璇彞
			String sql = "SELECT * FROM PRO";
			rs = stmt.executeQuery(sql);
			//澶勭悊缁撴灉闆�
			while(rs.next()){
				Item projectItem = new Item();
				projectItem.setNumber(rs.getString("项目号编号"));
				projectItem.setName(rs.getString("项目名称"));
				projectItem.setTime1(rs.getString("创建时间"));
				projectItem.setTime2(rs.getString("实施时间"));
				projectItem.setTime3(rs.getString("完工时间"));
				projectItem.setPlace(rs.getString("地点"));
				list.add(projectItem);
			}
			return list;
		} catch (Exception e){
			e.printStackTrace();
		} finally {
			JDBCUtils.release(rs,stmt,conn);
		}
		return null;
	}

	//娣诲姞
	public void addItem(Item projectItem){
		Connection conn=null;
		Statement stmt=null;
		ResultSet rs=null;
		try{
			//鑾峰緱鏁版嵁鐨勮繛鎺�
			conn = JDBCUtils.getConnection();
			//鑾峰緱Statement瀵硅薄
			stmt = conn.createStatement();
			//鍙戦�丼QL璇彞
			String sql = "INSERT TNTO PRO(项目号编号,项目名称,创建时间,实施时间,完工时间,地点)"
					+"VALUES("+projectItem.getNumber()+",'"
					+projectItem.getName()+"','"
					+projectItem.getTime1()+"'"+
					projectItem.getTime2()+"'"+
					projectItem.getTime3()+"'"+
					projectItem.getPlace() +"')";
			int num = stmt.executeUpdate(sql);
			if(num>0){
				System.out.println("鎻掑叆鏁版嵁鎴愬姛!");
			}
		}catch(Exception e){
			e.printStackTrace();
		}finally{
			JDBCUtils.release(rs,stmt,conn);
		}
	}

	//鍒犻櫎鏁版嵁
	public void delItem(String delNum){
		Connection conn=null;
		Statement stmt=null;
		ResultSet rs=null;
		try{
			//鑾峰緱鏁版嵁鐨勮繛鎺�
			conn = JDBCUtils.getConnection();
			//鑾峰緱Statement瀵硅薄
			stmt = conn.createStatement();
			//鍙戦�丼QL璇彞
			String sql = "DELETE FROM PRO WHERE 项目号编号="+delNum;
			int num = stmt.executeUpdate(sql);
			if(num>0){
				System.out.println("鍒犻櫎鏁版嵁鎴愬姛!");
			}
		}catch(Exception e){
			e.printStackTrace();
		}finally{
			JDBCUtils.release(rs,stmt,conn);
		}
	}
}
