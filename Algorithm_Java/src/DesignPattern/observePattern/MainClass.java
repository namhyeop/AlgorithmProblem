package DesignPattern.observePattern;

import DesignPattern.observePattern.observer.ObserverA;

public class MainClass {
    /**
     * Objserver: 정찰 OR 감시
     */
    public static void main(String[] args) {
        MyClass cls = new MyClass();
        cls.addObserver(new ObserverA());
        cls.notifyObservers("password:abc123");
    }
}
