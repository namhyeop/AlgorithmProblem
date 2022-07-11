package DesignPattern.FactoryPattern.animalExample;

/**
 * MainClass
 */

import java.util.ArrayList;
import java.util.List;

/**
 * Factory: Object 공장을 의미, 원하는 Object를 생성하기 위한 Pattern
 * animal : interface를 의미
 * animal 인터페이스를 사용해서 상황에 맞게 필요한 객체를 반환한다.
 */
public class MainClass {
    public static void main(String[] args) {
        Animal ani = null;
        List<Animal> list = new ArrayList<Animal>();
        ani = AnimalFactory.create("야옹이");
        list.add(ani);

        ani = AnimalFactory.create("황소");
        list.add(ani);

        ani = AnimalFactory.create("멍멍이");
        list.add(ani);

        for (Animal animal : list) {
            animal.printDescript();
            if (animal instanceof Cat) {
                ((Cat) animal).catMethod();
            } else if(animal instanceof Dog){
                ((Dog) animal).dogMethod();
            } else if(animal instanceof Cow){
                ((Cow) animal).cowMethod();
            }
        }
        /*ani.printDescript();
        Cat cat = (Cat)ani;
        cat.catMethod();*/
    }
}
