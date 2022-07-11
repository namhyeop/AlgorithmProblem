package Algorithm.Graph;

import java.util.*;
import java.io.*;

public class BOJ_1260 {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static int n, m, v;
    static ArrayList<Integer>[] adj;
    static boolean[] visited;
    static  void input(){
        n = scan.nextInt();
        m = scan.nextInt();
        v = scan.nextInt();
        adj = new ArrayList[n + 1];
        visited = new boolean[n + 1];
        for(int i = 1; i <= n; i++){
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            int x = scan.nextInt();
            int y = scan.nextInt();
            adj[x].add(y);
            adj[y].add(x);
        }
        for(int i = 1; i<= n; i++){
            Collections.sort(adj[i]);
        }
    }

    static void dfs(int start){
        visited[start] = true;
        sb.append(start).append(" ");
        for(int next : adj[start]){
            if(!visited[next]){
                visited[next] = true;
                dfs(next);
            }
        }
    }

    static void bfs(int start){
        visited[start] = true;
        Queue<Integer> q = new LinkedList<>();

        q.add(start);
        visited[start] = true;
        while(!q.isEmpty()){
            int cur = q.poll();
            sb.append(cur).append(" ");
            for (int next : adj[cur]) {
                if(!visited[next]){
                    visited[next] = true;
                    q.add(next);
                }
            }
        }
    }
    public static void main(String[] args) {
        input();
        System.out.println(1);
        dfs(v);
        sb.append("\n");
        for(int i = 1; i <= n; i++)
            visited[i] = false;
        bfs(v);
        System.out.println(sb);
    }

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;

        public FastReader(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while(st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt(){
            return Integer.parseInt(next());
        }

        long nextLong(){
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
}
