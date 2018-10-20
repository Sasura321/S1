using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;

public class RedisHelper
{
    private static readonly object Locker = new object();
    private static ConnectionMultiplexer _redis;
    private const string CONNECTTIONSTRING = "127.0.0.1:6379,DefaultDatabase=3";
    public const string REDIS_SET_KET_SUCCESS = "set_success_ip";
    private static ConnectionMultiplexer Manager
    {
        get
        {
            if (_redis == null)
            {
                lock (Locker)
                {
                    if (_redis != null) return _redis;
                    _redis = GetManager();
                    return _redis;
                }
            }
            return _redis;
        }
    }
    private static ConnectionMultiplexer GetManager(string connectionString = null)
    {
        if (string.IsNullOrEmpty(connectionString))
        {
            connectionString = CONNECTTIONSTRING;
        }
        return ConnectionMultiplexer.Connect(connectionString);
    }
    public static void AddRequestOk(string key, string value, bool isSuccess)
    {
        var db = Manager.GetDatabase();
        if (isSuccess)
            db.ListLeftPush(key, value);
        else
            db.ListLeftPush(key, value);
    }
    public static List<string> GetProxy()
    {
        List<string> result = new List<string>();
        var db = Manager.GetDatabase();
        var values = db.SetMembers(REDIS_SET_KET_SUCCESS);
        foreach (var value in values)
        {
            result.Add(value.ToString());
        }
        return result;
    }
    public static bool InsertSet(string value)
    {
        var db = Manager.GetDatabase();
        return db.SetAdd(REDIS_SET_KET_SUCCESS, value);
    }
    public static bool RemoveSetValue(string value)
    {
        var db = Manager.GetDatabase();
        return db.SetRemove(REDIS_SET_KET_SUCCESS, value);
    }
}

//namespace _01
//{
//class Program
//    {
//        //存放所有抓取的代理
//        public static List<proxy> masterPorxyList = new List<proxy>();
//        //代理IP类
//        public class proxy
//        {
//            public string ip;

//            public string port;
//            public int  speed;

//            public proxy(string pip,string pport,int pspeed)
            
//            {
//                this.ip = pip;
//                this.port = pport;
//                this.speed = pspeed;
//             }


//        }
//       //抓去处理方法
//        static void getProxyList(object pageIndex)
//        {

//            string urlCombin = "https://blog.csdn.net/qq_40933663/article/details/82792308" + pageIndex.ToString();
//            string catchHtml = catchProxIpMethord(urlCombin, "UTF8");
            

//            HtmlAgilityPack.HtmlDocument doc = new HtmlAgilityPack.HtmlDocument();
//           doc.LoadHtml(catchHtml);


//           HtmlNode table = doc.DocumentNode.SelectSingleNode("//div[@id='wrapper']//div[@id='body']/table[1]");

//           HtmlNodeCollection collectiontrs = table.SelectNodes("./tr");   

 
           
//               for (int i = 0; i < collectiontrs.Count; i++)
//               {
//                   HtmlAgilityPack.HtmlNode itemtr = collectiontrs[i];


//                   HtmlNodeCollection collectiontds = itemtr.ChildNodes;
//                   //table中第一个是能用的代理标题，所以这里从第二行TR开始取值
//                   if (i>0)
//                   {
//                       HtmlNode itemtdip = (HtmlNode)collectiontds[3];

//                       HtmlNode itemtdport = (HtmlNode)collectiontds[5];

//                       HtmlNode itemtdspeed = (HtmlNode)collectiontds[13];
 
//                       string ip = itemtdip.InnerText.Trim();
//                       string port = itemtdport.InnerText.Trim();


//                       string speed = itemtdspeed.InnerHtml;
//                       int beginIndex = speed.IndexOf(":", 0, speed.Length);
//                       int endIndex = speed.IndexOf("%", 0, speed.Length);

//                       int subSpeed = int.Parse(speed.Substring(beginIndex + 1, endIndex - beginIndex - 1));
//                       //如果速度展示条的值大于90,表示这个代理速度快。
//                     if (subSpeed > 90)
//                        {
//                            proxy temp = new proxy(ip, port, subSpeed);
                            
//                            masterPorxyList.Add(temp);
//                            Console.WriteLine("当前是第:" + masterPorxyList.Count.ToString() + "个代理IP");
//                       }
                    
//                      }
//               }
//        }

//        //抓网页方法
//        static string catchProxIpMethord(string url,string encoding )
//        {

//            string htmlStr = "";
//            try
//            {
//                if (!String.IsNullOrEmpty(url))
//                {
//                    WebRequest request = WebRequest.Create(url);    
//                    WebResponse response = request.GetResponse();           
//                    Stream datastream = response.GetResponseStream(); 
//                    Encoding ec = Encoding.Default;
//                    if (encoding == "UTF8")
//                    {
//                        ec = Encoding.UTF8;
//                    }
//                    else if (encoding == "Default")
//                    {
//                        ec = Encoding.Default;
//                    }
//                    StreamReader reader = new StreamReader(datastream, ec);
//                    htmlStr = reader.ReadToEnd();               
//                    reader.Close();
//                    datastream.Close();
//                    response.Close();
//                }
//            }
//            catch { }
//            return htmlStr;
//        }


//      static void Main(string[] args)
//         {
//             //多线程同时抓15页
//             for (int i = 1; i <= 15; i++)
//             {
                
                  
//                 ThreadPool.QueueUserWorkItem(getProxyList, i);
//             }
//             Console.Read();
//         }

//    }
//}