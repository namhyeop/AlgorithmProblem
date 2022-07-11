package DesignPattern.FactoryPattern.weaponexample.user;

import DesignPattern.FactoryPattern.weaponexample.weapon.Bomb;
import DesignPattern.FactoryPattern.weaponexample.weapon.Weapon;

public interface AbstractItem {
    public Weapon createWeapon();

    public Bomb createBomb();
}
