<%--
  Created by IntelliJ IDEA.
  User: 28187
  Date: 2019/4/13
  Time: 22:27
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<body>
<%String username=(String)session.getAttribute("username"); %><!-- 获取保存在session范围在内的用户名 -->
您好！[<%=username %>],欢迎访问！<br>
<a href="exit.jsp">[退出]</a>
</body>
