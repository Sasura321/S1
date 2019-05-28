<%--
  Created by IntelliJ IDEA.
  User: 28187
  Date: 2019/4/13
  Time: 23:23
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta charset="GB18030">
    <title>Insert title here</title>
</head>
<body>
<%
    int i = 0;
    synchronized (application) {
        if (application.getAttribute("times") == null) {
            i = 1;
        } else {
            i = Integer.parseInt((String) application.getAttribute("times"));
        }
        application.setAttribute("time", Integer.toString(i));
    }
%>
<table>
    <tr>
        <td align="center" style="color: cornflowerblue">欢迎访问</td>
    </tr>
    <tr>
        <td>您是第 <font color="red"><%=i %></font> 位访问本网站的游客</td>

    </tr>
</table>
</body>
</html>
