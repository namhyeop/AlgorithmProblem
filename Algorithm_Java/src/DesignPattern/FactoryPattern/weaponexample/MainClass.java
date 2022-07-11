package DesignPattern.FactoryPattern.weaponexample;

import DesignPattern.FactoryPattern.weaponexample.user.AbstractItem;
import DesignPattern.FactoryPattern.weaponexample.user.Atype;
import DesignPattern.FactoryPattern.weaponexample.user.Btype;

import java.util.ArrayList;

/**
 * animalExample을 응용 버전
 */
public class MainClass {
    public static void main(String[] args) {
//        Person person = new Person();
//        person.create(new Atype());
//        person.m_weapon.drawWeapon();
//        person.m_bomb.drawBomb();

        ArrayList<Person> list = new ArrayList<>();
        AbstractItem item = null;

        Person person = new Person();
        item = new Atype();
        person.create(item);
        list.add(person);

        person = new Person();
        item = new Btype();
        person.create(item);
        list.add(person);

        for (Person p : list) {
            p.m_weapon.drawWeapon();
            p.m_bomb.drawBomb();
        }
    }
}
