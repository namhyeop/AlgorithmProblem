package Algorithm.Graph;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_18404 {
    static FastReader scan = new FastReader();
    static StringBuilder sb = new StringBuilder();

    static int n, m, ky, kx;
    static int my[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    static int mx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    static int dist[][];

    private static void input() {
        n = scan.nextInt();
        m = scan.nextInt();
        ky = scan.nextInt();
        kx = scan.nextInt();
        dist = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = -1;
            }
        }
    }

    private static void pro() {
        BFS();
        while (m-- > 0) {
            int ty = scan.nextInt();
            int tx = scan.nextInt();
            sb.append(dist[ty][tx]).append(" ");
        }
        System.out.println(sb.toString());
    }

    static void BFS() {
        Queue<dto> q = new LinkedList<>();
        q.add(new dto(ky, kx));
        dist[ky][kx] = 0;

        while (!q.isEmpty()) {
            dto cur = q.poll();
            for (int d = 0; d < 8; d++) {
                int ny = cur.y + my[d];
                int nx = cur.x + mx[d];
                if (ny >= 1 && ny <= n && nx >= 1 && nx <= n) {
                    if (dist[ny][nx] == -1) {
                        q.add(new dto(ny, nx));
                        dist[ny][nx] = dist[cur.y][cur.x] + 1;
                    }
                }
            }
        }

    }

    public static void main(String[] args) {
        input();
        for (int i = 0; i < m; i++) {
            pro();
        }
    }

    static class dto {
        int y, x;

        public dto(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public String next() {
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
