package www.exception;

/*
1).定义一个MulException类继承Exception类，要求两数相乘等于100报错，在主类中定义一个方法，在方法中抛出此异常，在主方法观察结果。
2).定义一个DivException类继承RuntimeException类，要求两数相除等于2报错，在主类中定义一个方法，在方法中抛出此异常，在主方法观察结果
 */

class MulException extends Exception {
    public MulException(String m) {
        super(m);
    }
}

class DivException extends RuntimeException {
    public DivException(String d) {
        super(d);
    }
}

public class Test {
    public static void testMulException(double a, double b) {
        try {
            if(a * b == 100) {
                throw new MulException("两数相乘不能等于100！");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void testDivException(double a, double b) {
        try {
            if(a/b == 2) {
                throw new DivException("两数相除不能等于2！");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        testMulException(10,10);
        testDivException(4,2);
    }
}
