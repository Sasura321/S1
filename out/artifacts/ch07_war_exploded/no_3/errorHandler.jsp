<%--
  Created by IntelliJ IDEA.
  User: 28187
  Date: 2019/4/13
  Time: 21:59
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page isErrorPage="true" %>
<html>
<head>
    <title>处理错误</title>
</head>
<body>
请求不能被处理：<%=exception.getMessage()%><br>
请重试！
</body>
</html>
