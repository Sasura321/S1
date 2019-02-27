package practive.bit.Demo;

interface IFruit {
    public void eat();
}

class Apple implements IFruit {

    @Override
    public void eat() {
        System.out.println("eat an apple");
    }
}

class Peel implements IFruit {

    @Override
    public void eat() {
        System.out.println("eat a Peel");
    }
}

class FruitFactory {
    private FruitFactory(){}
    public static IFruit getInstance(String className) {
        IFruit fruit = null;
        try {
            Class<?> cls = Class.forName(className);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return fruit;
    }
}

public class Test {
    public static void main(String[] args) throws Exception {
        IFruit fruit = FruitFactory.getInstance("apple");
        fruit.eat();
    }
}
