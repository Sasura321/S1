package practive.bit.Demo2;

import java.util.Scanner;

// 图书接口
interface IBook {
    void sellBook();
}

// 漫画书
class Cartoon implements IBook {
    public void sellBook() {
        System.out.println("出售漫画书");
    }
}

// 文学书
class Literature implements IBook {
    public void sellBook() {
        System.out.println("出售文学书");
    }
}

// 杂志
class Magazine implements IBook {
    public void sellBook() {
        System.out.println("出售杂志");
    }
}

// 图书工厂接口
interface IBookFactory {
    IBook creatBook();
}

// 漫画书生产商
class CartoonFactory implements IBookFactory {
    public IBook creatBook() {
        return new Cartoon();
    }
}

// 文学书生产商
class LiteratureFactory implements IBookFactory {
    public IBook creatBook() {
        return new Literature();
    }
}

// 杂志生产商
class MagazineFactory implements IBookFactory {
    public IBook creatBook() {
        return new Magazine();
    }
}

public class Test {
    public static void main(String[] args) {
        IBookFactory factory = new CartoonFactory();
        IBook book = factory.creatBook();
        book.sellBook();
    }
}