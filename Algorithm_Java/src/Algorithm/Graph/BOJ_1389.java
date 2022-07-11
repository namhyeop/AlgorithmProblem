package Algorithm.Graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

import static java.lang.Double.min;
import static java.lang.Double.parseDouble;

public class BOJ_1389 {
    static int n, m;
    static ArrayList<Integer> edge[];
    static FastReader scan = new FastReader();
    static int dist[];

    public static void main(String[] args) {
        input();
        pro();
    }

    private static void pro() {
        int curPeople = 1;
        int minValue = BFS(1);
        for (int i = 2; i <= n; i++) {
            int curSum = 0;
            BFS(i);
//            int bfs = BFS(i);
//            if(bfs < minValue){
//                curPeople = i;
//                minValue = bfs;
//            }
            for (int j = 1; j <= n; j++) {
                curSum += dist[j];
            }
            if (minValue > curSum) {
                minValue = curSum;
                curPeople = i;
            }
        }
        System.out.println(curPeople);
    }

    private static void input() {
        n = scan.nextInt();
        m = scan.nextInt();
        edge = new ArrayList[n + 1];
        dist = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            edge[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int x = scan.nextInt();
            int y = scan.nextInt();
            edge[x].add(y);
            edge[y].add(x);
        }
    }

    private static int BFS(int start) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        for (int i = 1; i <= n; i++) {
            dist[i] = -1;
        }
        dist[start] = 0;

        int sum = 0;
        while (!q.isEmpty()) {
            int cur = q.poll();
            sum += dist[cur];
            for (int next : edge[cur]) {
                if (dist[next] == -1) {
                    dist[next] = dist[cur] + 1;
                    q.add(next);
                }
            }
        }
        return sum;
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
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
