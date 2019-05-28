<%--
  Created by IntelliJ IDEA.
  User: 28187
  Date: 2019/4/13
  Time: 22:23
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<html>
<head>
    <title>收集用户登录信息</title>
</head>
<body>
<form action="deal.jsp" name="form1" method="post">
    用户名: <input name="username" type="text" id="name" style="width:120px"><br>
    密&nbsp;&nbsp;&nbsp;码: <input name="pwd" type="password" id="pwd" style="width:120px"><br>
    <br>
    <input type="submit" name="Submit" value="登录"/>
</form>
</body>
</html>
