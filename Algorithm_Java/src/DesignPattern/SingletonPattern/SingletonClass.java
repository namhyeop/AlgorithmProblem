package DesignPattern.SingletonPattern;

public class SingletonClass {
    private static SingletonClass sc = null;
    public int num;

    private SingletonClass() {
    }

    public static SingletonClass getInstance(){
        if(sc == null){
            sc = new SingletonClass();
        }
        return sc;
    }
}
