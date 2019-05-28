<%--
  Created by IntelliJ IDEA.
  User: 28187
  Date: 2019/4/13
  Time: 21:48
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page errorPage="errorHandler.jsp" %>
<html>
<head>
    <title>获取名字</title>
</head>
<body>
    <%
        String name=request.getParameter("name");
        if(name == null) {
            throw new RuntimeException("没有指定name属性");
        }
    %>
    Hello <%=name%>
</body>
</html>
