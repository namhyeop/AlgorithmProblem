package Algorithm.Dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ_1916 {

    static FasterReader sc = new FasterReader();
    static final int MAX = 1005;

    static class Info{
        int v;
        int dist;

        public Info(int v, int to) {
            this.v = v;
            this.dist = to;
        }
    }

    static int n, m, start, destination;
    static ArrayList<Info> edge[];
    static int dist[];

    static void input(){
           n =  sc.nextInt(); m = sc.nextInt();
           dist = new int[n + 1];
           edge = new ArrayList[n + 1];
           for(int i = 1; i<= n; i++){
                edge[i] = new ArrayList<>();
           }
           for(int i = 1; i <= m; i++){
               int from = sc.nextInt();
               int to =  sc.nextInt();
               int dist = sc.nextInt();
               edge[from].add(new Info(to, dist));
           }
           start = sc.nextInt(); destination = sc.nextInt();
    }

    static void pro(){
        for(int i = 1; i <= n; i++){
            dist[i] = Integer.MAX_VALUE;
        }

        PriorityQueue<Info> pq = new PriorityQueue<>(Comparator.comparingInt(o -> o.dist));
        pq.add(new Info(start, 0));

        while(!pq.isEmpty()){
            Info cur = pq.poll();

            if(dist[cur.v] < cur.dist)
                continue;

            for(Info next : edge[cur.v]){
                int neighbor = next.v;
                int nextDist = next.dist + cur.dist;

                if(dist[neighbor] > nextDist){
                    pq.add(new Info(neighbor, nextDist));
                    dist[neighbor] = nextDist;
                }
            }
        }
        System.out.println(dist[destination]);
    }

    public static void main(String[] args) {
        input();
        pro();
    }
    static class FasterReader{
        BufferedReader br;
        StringTokenizer st;

        public FasterReader() {
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
            return st.nextToken();
        }

        Integer nextInt(){
            return Integer.parseInt(next());
        }
    }
}
