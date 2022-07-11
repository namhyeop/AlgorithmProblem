package Algorithm.Sort_Algorithm;

import java.io.*;
import java.util.*;

public class BOJ_11652 {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int N;
    static long[] a;

    static void input(){
        N = scan.nextInt();
        a = new long[N + 1];
        for(int i = 1; i<= N; i++){
            a[i] = scan.nextLong();
        }
    }

    static void pro(){
        Arrays.sort(a, 1, N + 1);
        long mode = a[1];
        int modeCnt = 1, curCnt = 1;
        for(int i = 2; i <= N; i++){
            if(a[i - 1] == a[i])
                curCnt++;
            else
                curCnt = 1;

            if(curCnt > modeCnt){
                modeCnt = curCnt;
                mode = a[i];
            }
        }
        sb.append(mode);
    }
    public static void main(String[] args) {
        input();
        pro();
        System.out.println(sb.toString());
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
