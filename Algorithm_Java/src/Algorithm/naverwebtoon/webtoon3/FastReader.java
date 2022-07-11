package Algorithm.naverwebtoon.webtoon3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class FastReader {
    static BufferedReader br;
    static StringTokenizer st;

    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }

    public String next() throws IOException {
        while(st == null || !st.hasMoreElements()){
            try{
                st = new StringTokenizer(br.readLine());
            }catch (Exception e){
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public Integer nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    public String nextLine(){
        String str = "";
        try{
            str = br.readLine();
        }catch (Exception e){
            e.printStackTrace();
        }
        return str;
    }
}
