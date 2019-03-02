package practive.bit.Starbucks;

/*
星巴克咖啡冲泡法
1. 将水煮沸
2. 用沸水冲泡咖啡
3. 将咖啡倒进杯子
4. 加糖和牛奶

星巴克茶冲泡法
1. 将水煮沸
2. 用沸水浸泡茶叶
3. 把茶倒进杯子
4. 加柠檬
 */

//class Coffee {
//    /*
//    咖啡冲泡法（算法）
//     */
//    void prepareRecipe() {
//        boilWater();
//        brewCoffeeGrings();
//        pourInCup();
//        addSugarAndMilk();
//    }
//    /**
//     * 将水煮沸
//     */
//    // 重复代码
//    public void boilWater() {
//        System.out.println("Boiling Water");
//    }
//    /**
//     * 冲泡咖啡
//     */
//    public void brewCoffeeGrings() {
//        System.out.println("Dripping Coffee through filter");
//    }
//    /**
//     * 把咖啡倒进杯子中
//     */
//    // 重复代码
//    public void pourInCup() {
//        System.out.println("Pouring into cup");
//    }
//    /**
//     * 加糖和牛奶
//     */
//    public void addSugarAndMilk() {
//        System.out.println("Adding Sugar and Milk");
//    }
//}
//
//class Tea {
//    /*
//   茶类冲泡法（算法）
//    */
//    void prepareRecipe() {
//        boilWater();
//        steepTeaBag();
//        pourInCup();
//        addLemon();
//    }
//    /**
//     * 将水煮沸
//     */
//    public void boilWater() {
//        System.out.println("Boiling Water");
//    }
//    /**
//     * 冲泡茶
//     */
//    public void steepTeaBag() {
//        System.out.println("Steeping the tea");
//    }
//    /**
//     * 把茶倒进杯子中
//     */
//    public void pourInCup() {
//        System.out.println("Pouring into cup");
//    }
//    /**
//     * 加柠檬
//     */
//    public void addLemon() {
//        System.out.println("Adding Lemon");
//    }
//}


import java.util.Scanner;

/**
 * 咖啡因饮料是一个抽象类
 */
//abstract class CaffeineBeverage {
//    /**
//     * 现在用同一个prepareRecipe()方法处理茶和咖啡。
//     * 声明为final的原因是我们不希望子类覆盖这个方法!
//     */
//    final void prepareRecipe() {
//        boilWater();
//        brew();
//        pourInCup();
//        addCondiments();
//    }
//    /**
//     * 咖啡和茶处理这些方法不同，因此这两个方法必须被声明为抽象，留给子类实现
//     */
//    abstract void brew();
//    abstract void addCondiments();
//    void boilWater() {
//        System.out.println("Boiling water");
//    }
//    void pourInCup() {
//        System.out.println("Pouring into cup");
//    }
//}
//
//class Tea extends CaffeineBeverage {
//    void brew() {
//        System.out.println("Steeping the tea");
//    }
//    void addCondiments() {
//        System.out.println("Adding Lemon");
//    }
//}
//class Coffee extends CaffeineBeverage {
//    void brew() {
//        System.out.println("Dripping Coffee through filter");
//    }
//    void addCondiments() {
//        System.out.println("Adding Sugar and Milk");
//    }
//}


/*
超类实现
 */
abstract class CaffeineBeverage {
    final void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        //询问顾客是否需要加料
        if(customerWantsCondiments()) {
            addCondiments();
        }
    }

    abstract void brew();

    abstract void addCondiments();

    void boilWater() {
        System.out.println("Boilint water");
    }

    void pourInCup() {
        System.out.println("Pouring into cup");
    }

    /**
     * 钩子方法
     * 超类中通常是默认实现
     * 子类可以选择性的覆写此方法
     * @return
     */
    boolean customerWantsCondiments() {
        return true;
    }
}

/*
子类实现
 */
class Coffee extends CaffeineBeverage {
    void brew() {
        System.out.println("Dripping Coffee through filter");
    }

    void addCondiments() {
        System.out.println("Add Sugar and Milk");
    }

    /**
     * 子类覆写了钩子函数，实现自定义功能
     * @return
     */
    public boolean customerWantsCondiments() {
        String answer = getUserInput();
        if(answer.equals("y")) {
            return true;
        }else {
            return false;
        }
    }
    private String getUserInput() {
        String answer = null;
        System.out.println("您想要在咖啡中加入牛奶或糖吗 (y/n)?");
        Scanner scanner = new Scanner(System.in);
        answer = scanner.nextLine();
        return answer;
    }
}

class Tea extends CaffeineBeverage {
    void brew() {
        System.out.println("Steeping the tea");
    }

    void addCondiments() {
        System.out.println("Adding Lemon");
    }
}

public class Test {
    public static void main(String[] args) {
        CaffeineBeverage tea = new Tea();
        CaffeineBeverage coffee = new Coffee();
        System.out.println("\nMaking tea...");
        tea.prepareRecipe();
        System.out.println("\nMaking Coffee");
        coffee.prepareRecipe();
    }
}
