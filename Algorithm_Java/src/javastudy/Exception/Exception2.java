package javastudy.Exception;

public class Exception2 {
    public static void main(String[] args) {
        //NullPoniterException
        String str = null;
        try{
            System.out.println(str.length());
        }catch(NullPointerException e){
            System.out.println("str은 null이다.");
        }

        //ArrayOIndexoutOfBoundException
        int arr[] = {1, 2, 3};
        try {
            for (int i = 0; i < 4; i++) {
                System.out.println(arr[i]);
            }
        }catch (ArrayIndexOutOfBoundsException e){
            System.out.println("arr에 null이 포함되어있다.");
        }

        //NumberFormatException
        try{
            int i = Integer.parseInt("12a34");
        }catch(NumberFormatException e){
//            e.printStackTrace();
            System.out.println("숫자가 아닙니다");
        }
    }
}
