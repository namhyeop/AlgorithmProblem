package DesignPattern.FactoryPattern.weaponexample;

import DesignPattern.FactoryPattern.weaponexample.user.AbstractItem;
import DesignPattern.FactoryPattern.weaponexample.weapon.Bomb;
import DesignPattern.FactoryPattern.weaponexample.weapon.Weapon;

public class Person {
    public Weapon m_weapon;
    public Bomb m_bomb;

    public void create(AbstractItem ai){
        m_weapon = ai.createWeapon();
        m_bomb = ai.createBomb();
    }
}
