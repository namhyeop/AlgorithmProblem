package DesignPattern.FactoryPattern.weaponexample.weapon;

public class Dynamite implements Bomb {
    @Override
    public void drawBomb() {
        System.out.println("폭탄 : Dynamite");
    }
}
