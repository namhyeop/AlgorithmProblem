package Algorithm.Graph;
import java.util.*;
import java.lang.reflect.Array;
import java.io.*;

public class BOJ_2667 {
    static StringBuilder sb = new StringBuilder();
    static FastReader scan = new FastReader();

    static int n, kind, groupCnt;
    static String[] board;
    static boolean visited[][];
    static int moveY[] = {-1,0,1,0};
    static int moveX[] = {0,1,0,-1};
    static void input(){
        n = scan.nextInt();
        visited = new boolean[n + 1][n + 1];
        board = new String[n + 1];
        for(int i = 0; i < n; i++){
            board[i] = scan.nextLine();
        }
    }

    static void DFS(int y, int x){
        groupCnt++;
        visited[y][x] = true;
        for(int i = 0; i < 4; i++){
            int ny = y + moveY[i];
            int nx = x + moveX[i];

            if(ny >= 0 && ny < n && nx >=0 && nx < n)
            if(!visited[ny][nx] && board[ny].charAt(nx) == '1'){
                DFS(ny, nx);
            }
        }
    }

    static void pro(){
        ArrayList<Integer> group = new ArrayList<>();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    if(board[i].charAt(j) == '1'){
                        kind++;
                        groupCnt = 0;
                        DFS(i, j);
                        group.add(groupCnt);
                    }
                }
            }
        }
        Collections.sort(group);
        sb.append(kind).append("\n");
        for (int integer : group) {
            sb.append(integer).append("\n");
        }
        System.out.println(sb.toString());
    }

    public static void main(String[] args) {
        input();
        pro();
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
                }catch (IOException e){
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
            String str ="";
            try{
                str = br.readLine();
            }catch (IOException e){
                e.printStackTrace();
            }
            return str;
        }
    }
}
