package PM;

import java.sql.*;

public class JDBCUtils {
    public static Connection getConnection() throws SQLException,ClassNotFoundException {
        Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
        String url = "jdbc:sqlserver://localhost:1433; DatabaseName=EDUC";
        // 数据库的用户名与密码，需要根据自己的设置
        String username = "sa";
        String password = "123456";
        Connection conn = DriverManager.getConnection(url, username, password);
        return conn;
    }

    // 关闭数据库连接，释放资源
    public static void release(Statement stmt, Connection conn) {
        if(stmt != null) {
            try {
                stmt.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
            stmt = null;
        }
        if( conn != null) {
            try{
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
            conn = null;
        }

        }

        public static void release(ResultSet rs,Statement stmt, Connection conn) {
            if(rs != null) {
                try {
                    rs.close();
                } catch (SQLException e) {
                    e.printStackTrace();
                }
                rs = null;
            }
            release(stmt, conn);
        }
}
