package Algorithm.Sort_Algorithm;
import java.util.*;
import java.io.*;

public class BOJ_1181 {
    public static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N;
    static ArrayList<String> arr;
    static String[] a;
    static void input(){
        N = scan.nextInt();
        arr = new ArrayList<String>();
        for(int i = 0; i < N; i++){
            arr.add(scan.next());
        }
    }

    static class MyComparator implements Comparator<String>{
        @Override
        public int compare(String o1, String o2) {
            if(o1.length() != o2.length()) return o1.length()- o2.length();
            return o1.compareTo(o2);
        }
    }

    static void pro(){
        Collections.sort(arr, new MyComparator());
        for(int i = 0; i < N; i++){
            if(i == 0 || arr.get(i).compareTo(arr.get(i - 1)) != 0){
                sb.append(arr.get(i)).append("\n");
            }
        }
        System.out.println(sb.toString());
    }

    public static void main(String[] args) {
        input();
        pro();
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public FastReader(String s) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(new File(s)));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
