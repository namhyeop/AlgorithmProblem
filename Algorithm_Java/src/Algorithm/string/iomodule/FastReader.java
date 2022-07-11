package Algorithm.string.iomodule;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class FastReader {
    static BufferedReader br;
    static StringTokenizer st;

    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public String next(){
        while(st == null || !st.hasMoreElements()){
            try{
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public Integer nextInt(){
        return Integer.parseInt(next());
    }

    public Double nextDouble(){
        return Double.parseDouble(next());
    }

    public Long nextLong(){
        return Long.parseLong(next());
    }

    public String nextLine(){
        String str = "";
        try{
            str = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}
