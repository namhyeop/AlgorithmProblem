package DesignPattern.FactoryPattern.weaponexample.user;

import DesignPattern.FactoryPattern.weaponexample.weapon.Bomb;
import DesignPattern.FactoryPattern.weaponexample.weapon.Dynamite;
import DesignPattern.FactoryPattern.weaponexample.weapon.Sword;
import DesignPattern.FactoryPattern.weaponexample.weapon.Weapon;

public class Btype implements AbstractItem{
    @Override
    public Weapon createWeapon() {
        return new Sword();
    }

    @Override
    public Bomb createBomb() {
        return new Dynamite();
    }
}
