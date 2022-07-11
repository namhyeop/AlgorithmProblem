package Algorithm.Graph;

import java.io.*;
import java.util.StringTokenizer;

public class FastReader {
    static BufferedReader br;
    static StringTokenizer st;

    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public FastReader(String s) throws FileNotFoundException{
        br = new BufferedReader(new FileReader(new File(s)));
    }

    String next(){
        while(st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public int nextInt(){
        return Integer.parseInt(next());
    }

    Long nextLong(){
        return Long.parseLong(next());
    }

    double nextDouble(){
        return Double.parseDouble(next());
    }

    String nextLine(){
        String str = "";
        try{
            str = br.readLine();
        }catch (IOException e){
            e.printStackTrace();
        }
        return str;
    }
}
