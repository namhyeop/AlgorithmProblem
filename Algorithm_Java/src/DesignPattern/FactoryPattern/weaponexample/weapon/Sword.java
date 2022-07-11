package DesignPattern.FactoryPattern.weaponexample.weapon;

public class Sword implements Weapon{
    @Override
    public void drawWeapon() {
        System.out.println("무기: Sword");
    }
}
