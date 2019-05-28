<%--
  Created by IntelliJ IDEA.
  User: 28187
  Date: 2019/4/13
  Time: 23:30
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=gb2312">
    <title>显示停留时间-www.jbxue.com</title>
</head>
<body>
<form name="form1" method="post" action="">
    <center>
        <p><font size="5" color="#0000FF">您在本站已停留：</font></p>
        <p>
            <input name="textarea" type="text" value="">
        </p>
    </center>
    <script language="javascript">
        var second=0;
        var minute=0;
        var hour=0;
        window.setTimeout("interval();",1000);
        function interval()
        {
            second++;
            if(second==60)
            {
                second=0;minute+=1;
            }
            if(minute==60)
            {
                minute=0;hour+=1;
            }
            document.form1.textarea.value = hour+"时"+minute+"分"+second+"秒";
            window.setTimeout("interval();",1000);
        }
    </script>
</form>
</body>
</html>
