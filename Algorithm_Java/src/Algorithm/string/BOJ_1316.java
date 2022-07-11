package Algorithm.string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class BOJ_1316 {
    static FastReader scan = new FastReader();
    static ArrayList<String> arr = new ArrayList<>();
    static Map<String, Boolean> visited = new HashMap<>();

    static class FastReader {
        static BufferedReader br;
        static StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        public Integer nextInt() {
            return Integer.parseInt(next());
        }

        public Double nextDouble() {
            return Double.parseDouble(next());
        }

        public Long nextLong() {
            return Long.parseLong(next());
        }

        public String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

    public static Boolean isGroup(String str){
        String cur = "";
        visited.clear();
        for(int i = 0; i < str.length(); i++){
            if(visited.getOrDefault(String.valueOf(str.charAt(i)), false) && (i > 0 && str.charAt(i - 1) != str.charAt(i))){
                return false;
            }
            visited.put(String.valueOf(str.charAt(i)), true);
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        int testNum = scan.nextInt();
        int retCnt = 0;
        for(int t = 0; t < testNum; t++){
            String str = scan.nextLine();
            if(isGroup(str))
                retCnt++;
        }
        System.out.println(retCnt);
    }
}