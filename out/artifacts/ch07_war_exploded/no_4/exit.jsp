<%--
  Created by IntelliJ IDEA.
  User: 28187
  Date: 2019/4/13
  Time: 22:28
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<body>
<%
    session.invalidate();//销毁session
    response.sendRedirect("login.jsp");//重定向页面
%>
</body>
