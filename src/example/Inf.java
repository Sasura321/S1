package example;
//该类的一个对象表示数据表中的一条住房记录
public class Inf {

	private String number;
	private String name;
	private String time1;
	private String time2;
	public void setRno(String number) {
		this.number = number;
	}
	public String getRno() {
		return number;
	}
	public void setPname(String name) {
		this.name = name;
	}
	public String getPname() {
		return name;
	}
	public void setPsex(String time1) {
		this.time1 = time1;
	}
	public String getPsex() {
		return time1;
	}
	public void setPidcard(String time2) {
		this.time2 = time2;
	}
	public String getPidcard() {
		return time2;
	}

	public Inf()
	{

	}
	public Inf(String number,String name,String psex,String time2)
	{
		this.number=number;
		this.name=name;
		this.time1=time1;
		this.time2=time2;
	}
}

