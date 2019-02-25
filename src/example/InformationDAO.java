package example;
import java.io.BufferedReader;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.sql.*;
import java.util.*;

//对于选课表的数据访问类

public class InformationDAO
{
	private Connection conn;//定义数据库连接对象

	public InformationDAO()throws ClassNotFoundException,SQLException
	{
		Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
		// 加载对应的jdbc驱动
		String url = "jdbc:sqlserver://localhost:1433; DatabaseName=EDUC";
		// 配置连接字符串
		String user = "sa";// sa超级管理员
		String password = "123456";// 密码
		conn = DriverManager.getConnection(url, user, password);
	}

	public boolean addPa(Inf inf) throws SQLException
	{
		Statement st=conn.createStatement();
		if(!rnoIsExist(inf.getRno()))
		{

			StringBuffer strSQL=new StringBuffer();
			strSQL.append("insert into hotelmanage values('");
			strSQL.append(inf.getRno());
			strSQL.append("','");
			strSQL.append(inf.getPname());
			strSQL.append("','");
			strSQL.append(inf.getPsex());
			strSQL.append("','");
			strSQL.append(inf.getPidcard());
			strSQL.append("')");
			st.execute(strSQL.toString());
			// 调用存储过程
			st.close();
			conn.close();
			return true;
		}
		else
		{
			return false;
		}
	}
	public boolean rnoIsExist(String rno)throws SQLException
	{
		boolean result=false;
		ArrayList<String> result1=new ArrayList<String>();
		Statement st=conn.createStatement();
		ResultSet rs=st.executeQuery("select rno from hotelmanage");
		while(rs.next())
		{
			result1.add(rs.getString(1));
		}
		for(int i=0;i<result1.size();i++)
		{
			if(rno==result1.get(i))
			{
				result=true;
				break;
			}
		}
		return result;
	}
	public void addpas(Inf[] infs)throws SQLException
	{
		if(infs.length>0)
		{
			for(int i=0;i<infs.length;i++)
			{
				addPa(infs[i]);
			}
		}
	}


	public  String findPasByRno(String rno)throws SQLException
	{

		StringBuffer result=new StringBuffer();
		String result1="";
		if(!rnoIsExist(rno)){
			Statement st = conn.createStatement();
			// 创建SQL语句执行对象
			ResultSet rs=st.executeQuery("select * from hotelmanage where rno='"+rno+"'");
			if(rs.next())
			{
				result.append(rs.getString("rno")+",");
				result1=rs.getString("pname").trim();
				result.append(result1+",");
				result.append(rs.getString("psex")+",");
				result.append(rs.getString("pidcard"));
				result1=result.toString();
			}

			return result1;
		}
		else
		{
			return "不存在此房间号";
		}
	}


	public ArrayList<String> findRnosByPname(String pname)throws SQLException
	{
		ArrayList<String> result=new ArrayList<String>();
		Statement st = conn.createStatement();
		// 创建SQL语句执行对象
		ResultSet rs=st.executeQuery("select rno from hotelmanage where pname='"+pname+"'");
		while(rs.next())
		{
			result.add(rs.getString(1));
		}
		return result;
	}


	public String getPidcardByRnoAndName(String rno,String pname)throws SQLException
	{
		String result="";
		Statement st = conn.createStatement();
		// 创建SQL语句执行对象
		ResultSet rs=st.executeQuery("select pidcard from hotelmanage where pname='"+pname+"' and rno='"+rno+"'");
		if(rs.next())
		{
			result=rs.getString(1);
		}
		return result;
	}
	public ArrayList<String>findAllPassengers() throws SQLException
	{
		ArrayList<String> result=new ArrayList<String>();
		Statement st = conn.createStatement();
		// 创建SQL语句执行对象
		ResultSet rs=st.executeQuery("select * from hotelmanage");
		while(rs.next())
		{
			StringBuffer sb=new StringBuffer();

			String rno=rs.getString("rno");
			sb.append(rno.trim()+",");
			String  pname=rs.getString("pname");
			sb.append(pname.trim()+",");
			String  psex=rs.getString("psex");
			sb.append(psex.trim()+",");
			String  pidcard=rs.getString("pidcard");
			sb.append(pidcard+" ");
			result.add(sb.toString());
		}

		return result;

	}
	public boolean deletePas(String rno) throws SQLException
	{
		if(!rnoIsExist(rno))
		{
			Statement st=conn.createStatement();
			StringBuffer strSQL=new StringBuffer();
			strSQL.append("delete  from hotelmanage where rno='");
			strSQL.append(rno);
			strSQL.append("'");
			st.execute(strSQL.toString());
			st.close();
			conn.close();
			return true;
		}
		else
		{
			return false;
		}
	}
	public void deletePass(Inf[] infs)throws SQLException
	{
		if(infs.length>0)
		{
			for(int i=0;i<infs.length;i++)
			{
				deletePas(infs[i].getRno());
			}
		}
	}
	public boolean updatePas(Inf inf) throws SQLException
	{
		if(!rnoIsExist(inf.getRno()))
		{
			Statement st=conn.createStatement();
			StringBuffer strSQL=new StringBuffer();
			strSQL.append("update hotelmanage set pidcard ='");
			strSQL.append(inf.getPidcard()+"' where rno='"+inf.getRno()+"'");
			strSQL.append("update hotelmanage set pname ='");
			strSQL.append(inf.getPname()+"' where rno='"+inf.getRno()+"'");
			strSQL.append("update hotelmanage set psex ='");
			strSQL.append(inf.getPsex()+"' where rno='"+inf.getRno()+"'");

			st.execute(strSQL.toString());
			st.close();
			conn.close();
			return true;
		}
		else
		{
			return false;
		}
	}
	public void updatePass(Inf[] infs)throws SQLException
	{
		if(infs.length>0)
		{
			for(int i=0;i<infs.length;i++)
			{
				updatePas(infs[i]);
			}
		}
	}
}
	
