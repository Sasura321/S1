package work.experiment.ProjectManagement;

import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import javax.swing.*;
public class ProjectManageSys extends JFrame implements ActionListener{
    //    JFrame jf;
//    Container container;
    JPanel jp1,jp2,jp3;
    JLabel label;
    JTextField name;
    JButton chaxun,shuaxin,jb1,jb2,jb3;//包括查询按钮和刷新按钮
    JTable jt;//表格
    JScrollPane jsp;//带滚动条


    Connection conn;//为删除按键提供变量
    PreparedStatement ps;
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        ProjectManageSys sms=new ProjectManageSys();
    }
    public ProjectManageSys(){
        // jf=new JFrame();
        // container=jf.getContentPane();


        jp1=new JPanel();
        jp2=new JPanel();
        jp3=new JPanel();
        //设置上面的用户名，查询栏
        label=new JLabel();
        label.setText("用户名");
        //label.setLayout(new FlowLayout());
        name=new JTextField(15);
        chaxun=new JButton();
        chaxun.setText("查询");
        chaxun.addActionListener(this);
        // chaxun.setActionCommand("chaxun");
        shuaxin=new JButton("刷新");
        shuaxin.addActionListener(this);
        jp1.add(label);
        jp1.add(name);
        jp1.add(chaxun);
        jp1.add(shuaxin);
        this.add(jp1,BorderLayout.NORTH);


        jt=new JTable();
        jsp=new JScrollPane();



        ProModel sm=new ProModel();
        jt=new JTable(sm);
        jsp=new JScrollPane(jt);
        jp2.add(jsp);
        this.add(jp2,BorderLayout.CENTER);

        //设置最下面一行
        jb1=new JButton("添加");
        jb1.addActionListener(this);
        jb2=new JButton("修改");
        jb2.addActionListener(this);
        jb3=new JButton("删除");
        jb3.addActionListener(this);
        jp3.add(jb1);
        jp3.add(jb2);
        jp3.add(jb3);
        this.add(jp3,BorderLayout.SOUTH);



        this.setVisible(true);
        this.setSize(500,300);
        this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        this.setTitle("项目信息管理系统");

    }
    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        if(e.getSource()==chaxun){

            String lookname;
            lookname=this.name.getText().trim();//得到用户输入的内容
            String sql="select * from PM where ProName='"+lookname+"'";//
            ProModel sm=new ProModel(sql);
            jt.setModel(sm);
            System.out.println("用户想查询"+lookname+"信息");



        }
        else if(e.getSource()==shuaxin){
            ProModel sm=new ProModel();
            jt.setModel(sm);
        }
        else if (e.getSource()==jb1){
            new addProDialog(this,"添加项目信息",true);


        }else if(e.getSource()==jb2){
            ProModel sm=new ProModel();

            //System. out .println("aaaa");
            int rownum =this.jt.getSelectedRow();
            if(rownum==-1) { //提示
                JOptionPane. showMessageDialog (this, "请选择一行");
                return;//代表不要再往下面走了,谁调用就返回给谁 }
                //显示修改对话框
            }
            new ProjectUpdateDialog(this,"修改对话框",true,sm,rownum);

        }else if(e.getSource()==jb3){



            int rownum=this.jt.getSelectedRow();
            if(rownum==-1){
                JOptionPane.showMessageDialog(this, "请选中需要删除的行");
                return;
            }
            ProModel sm=new ProModel();
            String stuId=(String) sm.getValueAt(rownum,0);
            String sql="delete from stu where stuId='"+stuId+"'";
            try {
                Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
                conn=DriverManager.getConnection("jdbc:sqlserver://localhost:1433;databaseName=HIRO","sa","1989");
                ps=conn.prepareStatement(sql);
                int i=ps.executeUpdate();
                if(i==1){
                    JOptionPane.showMessageDialog(null, "删除成功！");

                }else{
                    JOptionPane.showMessageDialog(null, "删除失败！");
                }

            } catch (Exception e1) {
                // TODO Auto-generated catch block
                e1.printStackTrace();
            }finally{
                if(ps!=null){
                    try {
                        ps.close();
                    } catch (SQLException e1) {
                        // TODO Auto-generated catch block
                        e1.printStackTrace();
                    }
                }
                if(conn!=null){
                    try {
                        conn.close();
                    } catch (SQLException e1) {
                        // TODO Auto-generated catch block
                        e1.printStackTrace();
                    }
                }
            }



        }
    }
}
