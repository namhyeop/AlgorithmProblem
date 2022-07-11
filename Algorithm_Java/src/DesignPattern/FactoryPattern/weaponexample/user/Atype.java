package DesignPattern.FactoryPattern.weaponexample.user;

import DesignPattern.FactoryPattern.weaponexample.weapon.Bomb;
import DesignPattern.FactoryPattern.weaponexample.weapon.C4;
import DesignPattern.FactoryPattern.weaponexample.weapon.Gun;
import DesignPattern.FactoryPattern.weaponexample.weapon.Weapon;

public class Atype implements AbstractItem{
    @Override
    public Weapon createWeapon() {
        return new Gun();
    }

    @Override
    public Bomb createBomb() {
        return new C4();
    }
}
