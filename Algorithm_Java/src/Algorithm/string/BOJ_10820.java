package Algorithm.string;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_10820 {
    static FastReader scan = new FastReader();
    static ArrayList<String> arr = new ArrayList<>();

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

    public static void logic(String inputStr){
        int upperAlphaCnt = 0, lowerAlphaCnt = 0, numCnt = 0, emptyCnt = 0;
        for(int i = 0; i < inputStr.length(); i++){
            if('A' <= inputStr.charAt(i) && 'Z' >= inputStr.charAt(i)){
                upperAlphaCnt++;
            }else if('a' <= inputStr.charAt(i) && 'z' >= inputStr.charAt(i)){
                lowerAlphaCnt++;
            }else if('0' <= inputStr.charAt(i) && '9' >= inputStr.charAt(i)){
                numCnt++;
            }else
                emptyCnt++;
        }
        System.out.println(lowerAlphaCnt + " " + upperAlphaCnt + " " + numCnt + " " + emptyCnt);
    }

    public static void main(String[] args) throws IOException {
        String inputStr = null;
        while((inputStr = scan.nextLine()) != null){
            logic(inputStr);
        }
    }
}