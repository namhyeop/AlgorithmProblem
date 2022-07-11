package DesignPattern.FactoryPattern.animalExample;

public class Dog implements Animal{
    @Override
    public void printDescript() {
        System.out.println("개 개 개");
    }

    public void dogMethod(){
        System.out.println("으르르르르릉 으르르르르머");
    }
}
