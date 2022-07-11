package javastudy.libray;

import Algorithm.Graph.FastReader;

import java.util.*;

/**
 6
 4 5 6 5 4 3
 */
public class MapPratice2 {
    static int n;
    static Integer arr[];
    static FastReader scan = new FastReader();
    static HashMap<Integer, Integer> m;

    public static void main(String[] args) {
        input();
        pro();
    }

    private static void pro() {
        m = new HashMap<>();
        for(int i = 0; i < n; i++){
            m.put(arr[i], m.getOrDefault(arr[i], 0) + 1);
        }
        List<Integer> list = new ArrayList<>();
        list.addAll(m.keySet());
        Arrays.stream(arr).sorted(new cmp()).forEach((cur) -> System.out.print(cur + " "));
    }

    private static void input() {
        n = scan.nextInt();
        arr = new Integer[n];
        for(int i = 0; i < n; i++){
            arr[i] = scan.nextInt();
        }
    }

    static class cmp implements Comparator<Integer>{
        @Override
        public int compare(Integer o1, Integer o2) {
            Integer integerA = m.get(o1);
            Integer integerB = m.get(o2);
            if(integerA != integerB)
                return integerA - integerB;
            return o1 - o2;
        }
    }
}
