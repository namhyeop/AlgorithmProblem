//package javastudy.Exception;
//
//import java.util.Calendar;
//import java.util.Scanner;
//
//public class CalenderSubject {
//    static void makeHangleDay(int num){
//        int weekday = num; //1(일) ~7(토)
//        switch (weekday){
//            case 1:
//                System.out.println("일요일");
//                break;
//            case 2:
//                System.out.println("월요일");
//                break;
//            case 3:
//                System.out.println("화요일");
//                break;
//            case 4:
//                System.out.println("수요일");
//                break;
//            case 5:
//                System.out.println("목요일");
//                break;
//            case 6:
//                System.out.println("금요일");
//                break;
//            case 7:
//                System.out.println("토요일");
//                break;
//        }
//    }
//
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        int year = sc.nextInt();
//        int month = sc.nextInt();
//        int day = sc.nextInt();
//
//        Calendar cal = Calendar.getInstance();
//        cal.set(Calendar.YEAR, year);
//        cal.set(Calendar.MONTH,month);
//        cal.set(Calendar.DATE, day);
//        int monthTest = cal.get(Calendar.MONTH); //0 ~ 11
//        int DayTest = cal.get() ; //0 ~ 11
//        System.out.println("DayTest = " + DayTest);
//        System.out.println("monthTest = " + monthTest);
//        Calendar makeMinimumDayCal = Calendar.getInstance();
//        makeMinimumDayCal.set(Calendar.YEAR, year);
//        makeMinimumDayCal.set(Calendar.MONTH, month - 1);
//        makeMinimumDayCal.set(Calendar.DATE, 1);
//
//        int minDay = makeMinimumDayCal.get(Calendar.DATE);
//        int maxDay = cal.getActualMaximum(cal.DAY_OF_MONTH);
//        System.out.println(makeMinimumDayCal.get(Calendar.DAY_OF_WEEK));
//        makeHangleDay(makeMinimumDayCal.get(Calendar.DAY_OF_WEEK));
//        System.out.println("maxDay = " + maxDay);
//        System.out.println("minDay = " + minDay);
//    }
//}
