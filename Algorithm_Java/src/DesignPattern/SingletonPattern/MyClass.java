package DesignPattern.SingletonPattern;

public class MyClass {
    private int number;

    public MyClass() {
    }

    public MyClass(int number) {
        this.number = number;
    }

    public void method(){
        SingletonClass sc = SingletonClass.getInstance();
        sc.num = number;
    }
//    public int getNumber() {
//        return number;
//    }

}
