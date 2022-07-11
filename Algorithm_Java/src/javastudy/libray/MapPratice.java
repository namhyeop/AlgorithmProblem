package javastudy.libray;

import Algorithm.Graph.FastReader;

import java.util.*;

/**
 * 1.숫자가 많은순
 * 2.숫자가 큰순
 */

/**
 5
 3 10
 2 5
 9 99
 8 99
 4 22
 */

public class MapPratice {
    static class dto implements Comparable<dto>{
        int a, b;

        @Override
        public int compareTo(dto other) {
            if(this.b != other.b){
                return this.b - other.b;
            }
            if(this.a != other.a){
                return this.a - other.a;
            }
            return 0;
        }

        public dto(int a, int b) {
            this.a = a;
            this.b = b;
        }


        public int getA() {
            return a;
        }

        public void setA(int a) {
            this.a = a;
        }

        public int getB() {
            return b;
        }

        public void setB(int b) {
            this.b = b;
        }
    }

    static FastReader scan = new FastReader();

    static int n;
    static ArrayList<dto> arr = new ArrayList<>();

    public static void main(String[] args) {
        Map<Integer, Integer> map2 = new HashMap<>();
        map2.put(1, 0);
        map2.put(1, 3);
        System.out.println("map2.get1 = " + map2.get(1));
        map2.put(1, map2.getOrDefault(1, 0) + 1);
        System.out.println("map2.get1 = " + map2.get(1));
        map2.put(2, map2.getOrDefault(2, 0) + 1);
        System.out.println("map2.get2 = " + map2.get(2));
//        input();
//        pro();
    }

    private static void pro() {
        printArr();
        Collections.sort(arr);
//        sortMethod1();
        printArr();
    }

    private static void sortMethod1() {
        Collections.sort(arr, new Comparator(){
            @Override
            public int compare(Object o1, Object o2) {
                //비교대상자가 뒤에 오면 오름차순
                //비교대상자가 앞에 오면 내림차순
                if(((dto) o1).b != ((dto)o2).b){
                    return ((dto) o1).b - ((dto) o2).b;
                }
                if(((dto) o1).a != ((dto)o2).a){
                    return ((dto) o1).a - ((dto) o2).a;
                }
                return 0;
            }
        });
    }

    private static void printArr() {
        for (dto dto : arr) {
            System.out.println("dto_a = " + dto.a + " dto_b = " + dto.b);
        }
        System.out.println("=============");
    }

    private static void input() {
        n = scan.nextInt();
        for(int i = 0; i< n; i++){
            int x , y;
            x = scan.nextInt();
            y = scan.nextInt();
            arr.add(new dto(x, y));
        }
    }

//    static Map<Integer, Integer> map = new HashMap<Integer, Integer>();

//    public static void main(String[] args) {
//        Integer arr[] = {4, 5, 6, 5, 4, 3};
//        for (int num : arr) {
//            map.put(num, map.getOrDefault(num, 0) + 1);
//        }
//        System.out.println("map = " + map);
//        List<Integer> list = new ArrayList<>();
//        list.addAll(map.keySet());
//        Collections.sort(list, new Comparator() {
//            //            @Override
//            public int compare(Object o1, Object o2) {
//                Object v1 = map.get(o1);
//                Object v2 = map.get(o2);
//                return ((Comparable) v1).compareTo(v2);
//            }
//        });
//        System.out.println("list = " + list);
//        Collections.reverse(list);
//        System.out.println("list = " + list);
//        Iterator iter = list.iterator();
//        while(iter.hasNext()){
//            int curNum = (int) iter.next();
//            for(int i = 0; i < map.get(curNum); i++){
//                System.out.print(curNum + " ");
//            }
//        }
//    }
}

