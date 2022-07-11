package javastudy.generic;

public class Mainclass {
    /**
     * generic : 자료형의 변수
     *
     */
    public static void main(String[] args) {
        Box<Integer> box = new Box<>(123);
        System.out.println(box.getTemp());

        Box<String> sbox = new Box<>("hello");
        System.out.println(sbox.getTemp());

        BoxMap<String, Integer> bmap = new BoxMap<>("kinnamhyeop", 961229);
        System.out.println(bmap.getName());
        System.out.println(bmap.getValue());
    }
}

class Box<T>{
    T temp;

    public Box(T temp) {
        this.temp = temp;
    }

    public T getTemp() {
        return temp;
    }
}

class BoxMap<K, V>{
    K name;
    V value;

    public BoxMap(K nmae, V value) {
        this.name = nmae;
        this.value = value;
    }

    public K getName() {
        return name;
    }

    public void setName(K name) {
        this.name = name;
    }

    public V getValue() {
        return value;
    }

    public void setValue(V value) {
        this.value = value;
    }
}