package Algorithm.Dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class BOJ_1753 {

    static class edge{
        int v, dist;

        public edge(int v, int dist) {
            this.v = v;
            this.dist = dist;
        }
    }

    public static Comparator<edge> cmp = new Comparator<>(){
        @Override
        public int compare(edge o1, edge o2) {
            return o1.dist - o2.dist;
        }
    };

    static FastReader sc = new FastReader();

    static int v, e, k;
    static ArrayList<edge> edges[];
    static boolean visited[];

    static void input(){
        v = sc.nextInt();
        e = sc.nextInt();
        k = sc.nextInt();
        visited = new boolean[v + 1];
        edges = new ArrayList[v + 1];
        for(int i = 1; i <= v; i++) edges[i] = new ArrayList<edge>();
        for(int i = 0; i < e; i++){
            int x, y, z;
            x = sc.nextInt(); y = sc.nextInt(); z = sc.nextInt();
            edges[x].add(new edge(y, z));
        }
    }

    static int[] pro(int start){
        PriorityQueue<edge> pq = new PriorityQueue<>(Comparator.comparingInt((o1) -> o1.dist));
        int dist[] = new int[v + 1];
        for(int i  = 1; i <= v; i++) dist[i] = Integer.MAX_VALUE;
        dist[start] = 0;

        pq.add(new edge(start, 0));
        while(!pq.isEmpty()){
            edge cur = pq.poll();

            if(dist[cur.v] < cur.dist)
                continue;

            for(edge next : edges[cur.v]){
                int neighbor = next.v;
                int nextCost = next.dist + cur.dist;
                if(dist[neighbor] > nextCost){
                    pq.add(new edge(neighbor, nextCost));
                    dist[neighbor] = nextCost;
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) {
        input();
        int retDistArr[] = pro(k);
        for(int i = 1; i <= v; i++){
            if(retDistArr[i] != Integer.MAX_VALUE)
                System.out.println(retDistArr[i]);
            else
                System.out.println("INF");
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
            return st.nextToken();
        }

        Integer nextInt(){
            return Integer.parseInt(next());
        }
    }
}
