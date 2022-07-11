package Algorithm.Graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.sql.Array;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_2251 {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int Limit[];
    static boolean possible[];
    static boolean visited[][][];
    static final int MAX = 205;

    static class State{
        int X[];
        State(int []tmp){
            X = new int[3];
            for(int i = 0; i < 3; i++){
                X[i] = tmp[i];
            }
        }

        State move(int from, int to, int[] Limit){
            int nx[] = new int[]{X[0], X[1], X[2]};
            if(X[from] + X[to] <= Limit[to]){
                nx[to] = nx[from] + nx[to];
                nx[from] = 0;
            }else{
                nx[from] -= Limit[to] - nx[to];
                nx[to] = Limit[to];
            }
            return new State(nx);
        }
    };

    public static  void BFS(int x1, int x2, int x3){
        Queue<State> q = new LinkedList<>();
        visited[x1][x2][x3] = true;
        q.add(new State(new int[]{x1, x2, x3}));
        while(!q.isEmpty()){
            State st = q.poll();
            if(st.X[0] == 0)
                possible[st.X[2]] = true;
            for(int from = 0; from < 3; from++){
                for(int to = 0; to < 3; to++){
                    if(from == to)
                        continue;
                    State nxt = st.move(from, to, Limit);

                    if(!visited[nxt.X[0]][nxt.X[1]][nxt.X[2]]){
                        visited[nxt.X[0]][nxt.X[1]][nxt.X[2]] = true;
                        q.add(nxt);
                    }
                }
            }
        }

    }
    public static  void pro(){
        BFS(0, 0, Limit[2]);
        for(int i = 0; i <= 200; i++){
            if(possible[i]){
                sb.append(i).append(" ");
            }
        }
        System.out.println(sb);
    }

    public static void input(){
        Limit = new int[3];
        for(int i = 0; i < 3; i++)
            Limit[i] = scan.nextInt();
        visited = new boolean[MAX][MAX][MAX];
        possible = new boolean[MAX];
    }

    public static void main(String[] args) {
        input();
        pro();
    }
    static class FastReader{
        BufferedReader bf;
        StringTokenizer st;

        public FastReader(){
            bf = new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while(st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(bf.readLine());
                }catch (IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt(){
            return Integer.parseInt(next());
        }

        double nextDouble(){
            return Double.parseDouble(next());
        }

        long nextLong(){
            return Long.parseLong(next());
        }

        String nextLine(){
            String str = "";
            try{
                str = bf.readLine();
            }catch (IOException e){
                e.printStackTrace();
            }
            return str;
        }
    }
}
