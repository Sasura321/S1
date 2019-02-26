package work.experiment.ProjectManagement;

/*
 * 链接数据库语句和修改数据库表格命令，放回表格数据
 *
 * */
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Vector;
import javax.swing.table.AbstractTableModel;
public class ProModel extends AbstractTableModel {
    Vector rowData,columnName;

    Connection ct=null;
    PreparedStatement ps=null;
    ResultSet rs=null;
    public void getInit(String sql){
        if(sql.equals("")){
            sql="select * from pro";
        }
        try {
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
            String url="jdbc:sqlserver://localhost:1433;databaseName=HIRO";
            ct=DriverManager.getConnection(url,"sa","1989");
            ps=ct.prepareStatement(sql);
            rs=ps.executeQuery();

            columnName=new Vector();
            columnName.add("学号");
            columnName.add("名字");
            columnName.add("性别");
            columnName.add("年龄");
            columnName.add("籍贯");
            columnName.add("系别");

            rowData=new Vector();
            while(rs.next()){
                Vector hang=new Vector();//hang要放在循环里面，不然全部都是第一行的数据
                hang.add(rs.getString(1));
                hang.add(rs.getString(2));
                hang.add(rs.getString(3));
                hang.add(rs.getInt(4));
                hang.add(rs.getString(5));
                hang.add(rs.getString(6));
                rowData.add(hang);
            }
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }finally{
            try{
                if(rs!=null){
                    rs.close();
                }if(ps!=null){
                    ps.close();
                }if(ct!=null){
                    ct.close();
                }

            }catch(Exception e){
                e.printStackTrace();
            }
        }
    }

    public ProModel(String sql){
        this.getInit(sql);
    }


    public ProModel(){
        this.getInit("");
    }

    @Override//得到列数
    public int getColumnCount() {
        // TODO Auto-generated method stub
        return this.columnName.size();
    }

    @Override//重写getColumnName得到列名
    public String getColumnName(int column) {
        // TODO Auto-generated method stub
        return (String)this.columnName.get(column);
    }

    @Override//得到行数
    public int getRowCount() {
        // TODO Auto-generated method stub
        return this.rowData.size();
    }

    @Override//得到某行某列的数据
    public Object getValueAt(int arg0, int arg1) {
        // TODO Auto-generated method stub
        return ((Vector)this.rowData.get(arg0)).get(arg1);
    }

}
