package Algorithm.Graph;

import java.util.*;
import java.io.*;

public class BOJ_2644 {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int n, m, findPeople1, findPeople2;
    static ArrayList<Integer> arr[];
    static int dist[];

    static void input() {
        n = scan.nextInt();
        findPeople1 = scan.nextInt();
        findPeople2 = scan.nextInt();
        m = scan.nextInt();
        arr = new ArrayList[n + 1];
        dist = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int x = scan.nextInt();
            int y = scan.nextInt();
            arr[x].add(y);
            arr[y].add(x);
        }
    }

    static void pro() {
        BFS(findPeople1);
        System.out.println(dist[findPeople2]);
    }

    private static void BFS(int start) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            dist[i] = -1;
        }
        q.add(start);
        dist[start] = 0;
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int next : arr[cur]) {
                if (dist[next] != -1) {
                    continue;
                }
                q.add(next);
                dist[next] = dist[cur] + 1;
            }
        }
    }

    public static void main(String[] args) {
        input();
        pro();
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        FastReader(String s) throws FileNotFoundException {
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

        Long nextLong() {
            return Long.parseLong(next());
        }

        Double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextStr() {
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
