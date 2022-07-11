package DesignPattern.SingletonPattern;

/**
 * MyClass의 숫자를 youClass의 변수에 값을 설정한다.
 * 단, 싱글톤패턴을 활용해 값을 설정하는 예제이다.
 */
public class MainClass {

    public static void main(String[] args) {
        final MyClass mycls = new MyClass(123);
        YouClass youcls = new YouClass();

        /*
        int n = mycls.getNumber();
        youcls.setTag(n);
        */

        /**
         * 싱글톤 미적용
         */
        System.out.println(youcls.toString());
        System.out.println(SingletonClass.getInstance());
        System.out.println(SingletonClass.getInstance());

        /**
         * 싱글톤 적용, 싱글톤을 활용해서 mycls의 값을 youcls에 적용
         */
        mycls.method();
        youcls.func();
        System.out.println(youcls.toString());

        HeClass hc = new HeClass();
        hc.proc();
        System.out.println(hc.toString());
    }
}
