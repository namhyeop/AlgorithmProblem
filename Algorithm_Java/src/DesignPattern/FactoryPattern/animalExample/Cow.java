package DesignPattern.FactoryPattern.animalExample;

public class Cow implements Animal{
    @Override
    public void printDescript() {
        System.out.println("흑우 흑우!");
    }

    public void cowMethod(){
        System.out.println("음머 음머");
    }
}
