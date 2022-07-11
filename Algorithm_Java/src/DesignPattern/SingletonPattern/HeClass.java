package DesignPattern.SingletonPattern;

public class HeClass {
    private int number;

    public void proc(){
        SingletonClass sc = SingletonClass.getInstance();
        number = sc.num;
    }

    @Override
    public String toString() {
        return "HeClass{" +
                "number=" + number +
                '}';
    }
}
