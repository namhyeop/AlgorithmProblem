package javastudy.Calendar;

import java.util.Calendar;

public record CalendarExmple() {
    public static void main(String[] args) {
        /**
         *  Calendar : 일정관리, 인사관리, d입사정보
         *  Date -> JavaScripte
         *  Calendar -> java == Sptring framework
         *  Restful -> spring boot
         *  jaavcrigpti -> date
         */
        Calendar cal = Calendar.getInstance();

        /**
         *  오늘날짜 취득
         */
        int year = cal.get(Calendar.YEAR);
        int month = cal.get(Calendar.MONTH) + 1; //0 ~ 11
        int day = cal.get(Calendar.DATE);
        System.out.println("day = " + day);
        System.out.println("month = " + month);
        System.out.println("year = " + year);

        /**
         * 원하는 날짜 설정 예제
         */
        cal.set(Calendar.YEAR, 2022);
        cal.set(Calendar.MONTH, 8 - 1);
        cal.set(Calendar.DATE, 15);

        year = cal.get(Calendar.YEAR);
        month = cal.get(Calendar.MONTH) + 1; //0 ~ 11
        day = cal.get(Calendar.DATE);
        System.out.println("day = " + day);
        System.out.println("month = " + month);
        System.out.println("year = " + year);

        /**
         * am/pm 설정 확인 예제
         */
        String ampm = cal.get(Calendar.AM_PM) == 0 ? "오전" : "오후";
        System.out.println("am/pm = " + ampm);

        /**
         * 요일 출력 예제
         */
        int weekday = cal.get(Calendar.DAY_OF_WEEK); //1(일) ~7(토)
        switch (weekday){
            case 1:
                System.out.println("일요일");
                break;
            case 2:
                System.out.println("월요일");
                break;
            case 3:
                System.out.println("화요일");
                break;
            case 4:
                System.out.println("수요일");
                break;
            case 5:
                System.out.println("목요일");
                break;
            case 6:
                System.out.println("금요일");
                break;
            case 7:
                System.out.println("토요일");
                break;
        }

        /**
         * 달의 마지막날 설정 예제
         */
        year = cal.get(Calendar.YEAR);
        month = cal.get(Calendar.MONTH) + 1; //0 ~ 11
        day = cal.get(Calendar.DATE);
        int lastday = cal.getActualMaximum(Calendar.DAY_OF_MONTH);
        System.out.println("lastday = " + lastday);

    }
}
