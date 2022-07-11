package Algorithm.Graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class BOJ_5567 {
    static FastReader scan = new FastReader();

    static int n, m;
    static ArrayList<Integer> arr[];

    public static void main(String[] args) {
        input();
        pro();
    }

    private static void pro(){
        int ret = BFS(1);
        System.out.println(ret);
    }

    private static int BFS(int start){
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        int dist[] = new int[n + 1];
        for(int i = 1; i <= n; i++)
            dist[i] = -1;
        dist[start] = 0;

        int cnt = 0;
        while(!q.isEmpty()){
            int cur = q.poll();
            if(dist[cur] >= 1 && dist[cur] <= 2)
                cnt++;
            if(dist[cur] == 2)
                continue;
            for(int next : arr[cur]){
                if(dist[next] == -1){
                    q.add(next);
                    dist[next] = dist[cur] + 1;
                }
            }
        }
        return cnt;
    }
    private static void input() {
        n = scan.nextInt();
        m = scan.nextInt();
        arr = new ArrayList[n + 1];
        for(int i = 0; i <= n; i++){
            arr[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            int x = scan.nextInt();
            int y = scan.nextInt();
            arr[x].add(y);
            arr[y].add(x);
        }
    }

    static class FastReader{
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next(){
            while(st == null || !st.hasMoreElements()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (IOException e){
                    e.printStackTrace();
                }
            }
            return st. nextToken();
        }

        int nextInt(){
            return Integer.parseInt(next());
        }
    }
}
