<%@ page import="static jdk.nashorn.internal.objects.NativeMath.log" %>
<%@ page import="java.io.*" %>
<%--
  Created by IntelliJ IDEA.
  User: 28187
  Date: 2019/4/11
  Time: 21:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%!
    int count = 0;
    String dbPath;
    public void jspInit() {
        try {
            dbPath = getServletContext().getRealPath("/WEB-INF/counter.db");
            FileInputStream fis = new FileInputStream(dbPath);
            DataInputStream dis = new DataInputStream(fis);
            count = dis.readInt();
            dis.close();
        } catch (Exception e) {
            log("Error loading persistent counter",e);
        }
    }
%>
<html>
<head>
    <title>计数器</title>
</head>
<body>
<%count++;%>
Welcome! You are <%= count %> th visitor(s).
</body>
</html>
<%!
    public void jspDestory() {
        try {
            FileOutputStream fos = new FileOutputStream(dbPath);
            DataOutputStream dos = new DataOutputStream(fos);
            dos.writeInt(count);
            dos.close();
        } catch (IOException e) {
            log("Error loading persistent counter",e);
        }
    }
%>
