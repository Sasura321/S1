package practive.bit.Demo1;

import java.lang.reflect.Method;

class Person{
    private String name;
    private int age;

    public String getName(){
        return name;
    }
    public void setName(){
        this.name = name;
    }
    public int getAge(){
        return age;
    }
    public void setAge(){
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person{"+
                "name='"+name+"\'"+
                ",age="+age +
                "}";
    }
}

public class Test {
    public static void main(String[] args) throws Exception {
        Class<?> cls = Person.class;
        Person per = (Person) cls.newInstance();
        Method setMethod = cls.getMethod("setName",String.class);

    }
}
