package javastudy.Exception;

public class Exception1 {
    /*
     Exception은 error랑 같지않다.
     array의 인덱스 범위초과, 숫자에서 문자 변환중 발생하는 오류를 의미한다.

     try{
     }catch(예외클래스1 e){
        메시지를 출력
     }catch(예외클래스2 e){
        메시지를 출력
     }catch(예외클래스3 e){
        메시지를 출력
     }finally{
        예외 상관없이 무조건 실행
        rollback()이 가장 대표적 사례
     }

     void testmethod throws SQLException
     */

    public static void main(String[] args) {
//        int arr[] = {1, 2, 3};
//        try {
//            for (int i = 0; i < 4; i++) {
//                System.out.println("i = " + arr[i]);
//            }
//        }catch (ArrayIndexOutOfBoundsException e){
//            System.out.println("배열범위초과 = " + e);
//            System.out.println("========= ");
//            /**
//             * 예외출력방법
//             */
//            e.printStackTrace();
//            System.out.println("e = " + e.getMessage());
//        }finally{
//            System.out.println("always print sentencce");
//        }

        method();
    }

    static void method() throws IndexOutOfBoundsException{
        int arr[] = {1,2,3};
        for (int i = 0; i < 4; i++) {
            System.out.println("i = " + arr[i]);
        }
    }
}
