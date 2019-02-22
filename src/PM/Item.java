package PM;

/**
 * 数据模型
 */

public class Item {
	//属性
	private  String number;
	private String name;
	private String time1;
	private String time2;
	private String time3;
	private String place;
	//构造
	public  Item(){
	}

	public Item(String number,String name,String time1,String time2,String time3,String place){
		super();
		this.setNumber(number);
		this.setName(name);
		this.setTime1(time1);
		this.setTime2(time2);
		this.setTime3(time3);
		this.setPlace(place);
	}
	public String getNumber() {
		return number;
	}
	public void setNumber(String number) {
		this.number = number;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getTime1() {
		return time1;
	}
	public void setTime1(String time1) {
		this.time1 = time1;
	}

	public String getTime2() {
		return time2;
	}
	public void setTime2(String time2) {
		this.time2 = time2;
	}
	public String getTime3() {
		return time3;
	}
	public void setTime3(String time3) {
		this.time3 = time3;
	}
	public String getPlace() {
		return place;
	}
	public void setPlace(String place) {
		this.place = place;
	}
}

