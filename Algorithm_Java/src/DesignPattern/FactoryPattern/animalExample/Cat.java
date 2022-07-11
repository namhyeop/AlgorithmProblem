package DesignPattern.FactoryPattern.animalExample;

public class Cat implements Animal{
    @Override
    public void printDescript() {
        System.out.println("yawong ywong이에용!");
    }

    public void catMethod(){
        System.out.println("야옹야옹");
    }
}
