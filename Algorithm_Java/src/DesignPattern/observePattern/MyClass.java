package DesignPattern.observePattern;

import java.util.Observable;

public class MyClass extends Observable {
    private String password;
    private String perArg = null;

    //일반 메서드
    @Override
    public void notifyObservers(Object arg) {
        String str = (String)arg;

        //변수의 값에 변화가 없을 경우 null
        if(str.equals(perArg)) return;

        perArg = str;
        setChanged(); // reset
        super.notifyObservers(arg);
        clearChanged();
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
