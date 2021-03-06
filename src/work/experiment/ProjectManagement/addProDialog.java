package work.experiment.ProjectManagement;

/**
 * 点击添加按钮，添加学生个人信息
 * */
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import java.sql.*;
import javax.swing.event.*;
public class addProDialog extends JDialog implements ActionListener{

    JLabel jl1,jl2,jl3,jl4,jl5,jl6;
    JTextField jtf1,jtf2,jtf3,jtf4,jtf5,jtf6;
    JButton jb1,jb2;
    JPanel jp1,jp2,jp3;
    //    public static void main(String[] args) {
//        // TODO Auto-generated method stub
//
//    }
    public addProDialog(Frame owner, String title, boolean modal){
        super(owner,title,modal);



        jl1=new JLabel("  项目类型");
        jl2=new JLabel("  项目名称");
        jl3=new JLabel("  创建时间");
        jl4=new JLabel("  执行时间");
        jl5=new JLabel("  结束时间");

        jtf1=new JTextField(30);
        jtf2=new JTextField(30);
        jtf3=new JTextField(30);
        jtf4=new JTextField(30);
        jtf5=new JTextField(30);
        jtf6=new JTextField(30);

        jp1=new JPanel();
        jp2=new JPanel();
        jp3=new JPanel();
        jp1.setLayout(new GridLayout(6,1,5,5));
        jp2.setLayout(new GridLayout(6,1,5,5));
        jp1.add(jl1);
        jp1.add(jl2);
        jp1.add(jl3);
        jp1.add(jl4);
        jp1.add(jl5);
        jp1.add(jl6);

        jp2.add(jtf1);
        jp2.add(jtf2);
        jp2.add(jtf3);
        jp2.add(jtf4);
        jp2.add(jtf5);
        jp2.add(jtf6);

        jb1=new JButton("确定");
        jb1.addActionListener(this);

        jb2=new JButton("取消");
        jb2.addActionListener(this);
        jp3.add(jb1);
        jp3.add(jb2);

        this.add(jp1,BorderLayout.WEST);
        this.add(jp2,BorderLayout.EAST);
        this.add(jp3,BorderLayout.SOUTH);

        this.setSize(400,300);
        this.setLocation(200, 150);
        this.setVisible(true);
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);

    }
    @Override
    public void actionPerformed(ActionEvent arg0) {
        // TODO Auto-generated method stub
        if(arg0.getSource()==jb1){

            Connection conn=null;
            PreparedStatement ps=null;
            try{
                Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
                String url="jdbc:sqlserver://localhost:1433;databaseName=HIRO";
                conn=DriverManager.getConnection(url,"sa","1989");
                ps=conn.prepareStatement("insert into stu values (?,?,?,?,?,?)");
                ps.setString(1, this.jtf1.getText().trim());
                ps.setString(2, this.jtf2.getText().trim());

                ps.setString(3, this.jtf3.getText().trim());
                ps.setInt(4, Integer.parseInt(this.jtf4.getText().trim()));
                ps.setString(5, this.jtf5.getText().trim());
                ps.setString(6, this.jtf6.getText().trim());
                if(this.jtf1.getText().trim()!=null&&this.jtf2.getText().trim()!=null){
                    int i=ps.executeUpdate();
                    JOptionPane.showMessageDialog(null, "添加"+this.jtf2.getText().trim()+"成员成功");

                }else{
                    JOptionPane.showMessageDialog(null, "添加"+this.jtf2.getText().trim()+"成员失败");
                    return;
                }

            }catch(Exception e){
                e.printStackTrace();
            }finally{
                if(ps!=null){
                    try {
                        ps.close();
                    } catch (Exception e) {
                        // TODO Auto-generated catch block
                        e.printStackTrace();
                    }
                }
                if(conn!=null){
                    try {
                        conn.close();
                    } catch (SQLException e) {
                        // TODO Auto-generated catch block
                        e.printStackTrace();
                    }
                }
            }
            this.dispose();
        }
        if(arg0.getSource()==jb2){
            this.dispose();
        }
    }
}
