package javastudy.Lambda;

import java.util.ArrayList;

public class LambdaCapturering {
    private final static int testValue1 = 10;
    static ArrayList<Integer> testA = new ArrayList<>();

    /**
     * 바디 외부 변수 참조
     */
    public static void test() {
        int testValue4 = 123;
        /**
         * 전역 변수 사용 가능
         */
        final Runnable ex1 = () -> System.out.println(testValue1); ex1.run();
        /**
         * 지역 변수 사용 가능
         */
        final Runnable ex2 = () -> System.out.println(testValue4); ex2.run();
    }

    /**
     * 람다 캡쳐링 제약 조건 예시
     * 1.지역변수는 final로 선언돼이었야한다.
     * 2.final로 선언된지 않은 지역변수는 final처럼 동작해야한다 -> 값의 재할당이 일어나면 안된다는 의미.
     */
    public static void test2() {
        final int testValue3 = 30;
        int testValue5 = 40;
        final Runnable r1 = () -> {
            /**
             * 지역변수는 값의 재할당 불가능
             */
//            testValue5 = 50;
            System.out.println("testValue5 = " + testValue5);
            testA.add(10);
            testA.add(20);
            testA.add(30);
        };
        r1.run();

        final Runnable r3 = () -> {
            /**
             * collection 재할당 불가능
             */
            testA.add(10);
            testA.add(20);
            testA.add(30);
            for (Integer integer : testA) {
                System.out.println("integer = " + integer);
            }
        };
        r3.run();
//        /**
//         * final로 선언된 지역변수 사용 가능
//         */
//        final Runnable r2 = () -> {
//            System.out.println("testValue3 = " + testValue3);
//        };
//        r2.run();
//
//        /**
//         * final로 선언되어지었지 않지만만생성과 동시 변수값을 초기화했으므로 사용 가능 (권장 X)
//         */
//        final Runnable r3 = () -> {
//            System.out.println("testValue3 = " + testValue3);
//        };
//        r3.run();
    }


    public static void main(String[] args) {
        int testValue6 = 20;
        test();
        test2();
    }
}
