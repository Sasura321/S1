package work.experiment.ProjectManagement;

/*
 * 修改已经存在的学生信息
 * */
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.sql.*;
public class ProjectUpdateDialog extends JDialog implements ActionListener{
    //定义我需要的swing组件
    JLabel jl1, jl2,jl3, jl4, jl5 ,jl6;
    JButton jb1,jb2;
    JTextField jtf1,jtf2,jtf3,jtf4,jtf5,jtf6;
    JPanel jp1,jp2,jp3;

    //构造函数 Frame 代表父窗口口,title 代表窗口的名字,model指定是模式窗口,还是非模式的窗口
    public ProjectUpdateDialog(Frame owner, String title, boolean model, ProModel sm, int rownum) {
        super(owner,title, model); //调用父类构造 方法,达到模式对话框效果
        jl1=new JLabel("  学号");
        jl2=new JLabel("  姓名");
        jl3=new JLabel("  性别");
        jl4=new JLabel("  年龄");
        jl5=new JLabel("  籍贯");
        jl6=new JLabel("  系别");

        jtf1=new JTextField(30);
        jtf2=new JTextField(30);
        jtf3=new JTextField(30);
        jtf4=new JTextField(30);
        jtf5=new JTextField(30);
        jtf6=new JTextField(30);
        //初始化数据

        jtf1.setText((String)sm.getValueAt(rownum, 0)); //setEditable设置指定的 boolean 变量，以指 示此 文本控件 是否应该为可编辑的
        jtf1.setEditable(false);
        jtf2.setText((String)sm.getValueAt(rownum, 1));
        jtf2.setEditable(false);
        jtf3.setText((String)sm.getValueAt(rownum, 2));
        jtf4.setText(sm.getValueAt(rownum, 3)+"");
        jtf5.setText((String)sm.getValueAt(rownum, 4));
        jtf6.setText((String)sm.getValueAt(rownum, 5));

        jb1=new JButton ("修改");
        jb2=new JButton ("取消");
        jp1=new JPanel();
        jp2=new JPanel();
        jp3=new JPanel();
        //设置布局
        jp1.setLayout(new GridLayout(6,1,5,5));
        jp2.setLayout(new GridLayout(6,1,5,5));
        //添加组件
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

        jp3.add(jb1);
        jp3.add(jb2);
        this.add(jp1,BorderLayout.WEST);
        this.add(jp2,BorderLayout.CENTER);
        this.add(jp3,BorderLayout.SOUTH);
        //注册监听
        jb1.addActionListener(this);
        jb2.addActionListener(this); //展现
        this.setSize(400,300); //
        this.setLocation(200,150);
        this.setVisible(true);
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        if(e.getSource()==jb1) { //对用户点击添加按钮后的响应动作 //连接数据库
            Connection ct =null;
            PreparedStatement ps =null;
            try {
                //加载驱动
//                Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
//                String url="jdbc:sqlserver://localhost:1433;databaseName=HIRO";

                Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
                String url="jdbc:sqlserver://localhost:1433;databaseName=HIRO";
                ct=DriverManager.getConnection(url,"sa","1989");

                //预编译的都是通过添加参数的方式来赋值
                System.out.println("已连接数据库");
                ps=ct.prepareStatement("update stu set stuName=?,stuSex=?,stuAge=?,stuJg=?,stuDept =? where stuId=?");
                ps.setString(1, this.jtf2.getText());
                ps.setString(2, this.jtf3.getText());
                ps.setString(3, this.jtf4.getText()); //
                ps.setInt(3,Integer.parseInt(this.jtf4.getText()));
                ps.setString(4, this.jtf5.getText());
                ps.setString(5, this.jtf6.getText());
                ps.setString(6, this.jtf1.getText());

                int i=ps.executeUpdate();
                if(i==1) {
                    System.out.print("修改成功ok");
                } else {
                    System.out.print("修改失败"); }
            } catch (Exception e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            } finally {
                try { ps.close(); ct.close();
                } catch (SQLException e1) {
                    // TODO Auto-generated catch block
                    e1.printStackTrace();
                }
            }
            //关闭对话框,关闭添加对话框
            this.dispose();
        } else if(e.getSource() == jb2) {
            dispose();
        }
    }
}
