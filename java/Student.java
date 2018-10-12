import java.util.Scanner;

public class Student
{
    public static void main(String[] args){
    	System.out.print("输入学生学号：");
    	@SuppressWarnings("resource")
		Scanner s = new Scanner(System.in);
    	String id = null;
    	id = s.next();
       // Scanner snr = new Signer(System.in);
       // String id = snr.nextLine();

        int year = Integer.parseInt(id.substring(0,4));
        String institution = id.substring(4,6);

        //学院处理
        switch(institution)
        {
            case "01":
                System.out.println("此学生是"+ institution.replace("01","轻工科学与工程学院")+"学院"+year+"级学生");
                break;
            case "02":
                System.out.println("此学生是"+ institution.replace("02","材料科学与工程学院")+"学院"+year+"级学生");
                break;
            case "03":
                System.out.println("此学生是"+ institution.replace("03","环境科学与工程学院")+"学院"+year+"级学生");
                break;
            case "04":
                System.out.println("此学生是"+ institution.replace("04","食品与生物工程学院")+"学院"+year+"级学生");
                break;
            case "05":
                System.out.println("此学生是"+ institution.replace("05","机电工程学院")+"学院"+year+"级学生");
                break;
            case "06":
                System.out.println("此学生是"+ institution.replace("06","电气与信息工程学院")+"学院"+year+"级学生");
                break;
            case "07":
                System.out.println("此学生是"+ institution.replace("07","经济与管理学院")+"学院"+year+"级学生");
                break;
            case "08":
                System.out.println("此学生是"+ institution.replace("08","化学与化工学院")+"学院"+year+"级学生");
                break;
            case "09":
                System.out.println("此学生是"+ institution.replace("09","设计与艺术学院")+"学院"+year+"级学生");
                break;
            case "10":
                System.out.println("此学生是"+ institution.replace("10","文理学院")+"学院"+year+"级学生");
                break;
            case "11":
                System.out.println("此学生是"+ institution.replace("11","职业教育师范学院")+"学院"+year+"级学生");
                break;
            default:
                System.out.println("非法字符");
                break;
        }
    }
}



