package Algorithm.Graph.swea;

import Algorithm.Graph.FastReader;

public class SWEA_14178 {
    static FastReader sc = new FastReader();

    static int T;
    public static void main(String[] args) {
        input();
    }

    private static void input() {
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            pro(t);
        }
    }

    private static void pro(int curTestTime) {
        int N = sc.nextInt();
        int D = sc.nextInt();

        int ret = search(N, D);
        System.out.println("#" + curTestTime + " "  + ret);
    }

    private static int search(int N, int D) {
        int minSpray = 0;
        int maxSpray = N + 1;

        while(minSpray + 1 < maxSpray){
            int mid = (minSpray + maxSpray) / 2;
            if(isValid(N, mid, D)){
                maxSpray = mid;
            }else{
                minSpray = mid;
            }
        }
        return maxSpray;
    }

    private static boolean isValid(int N, int spray, int d) {
        int coverArea = (spray * d) * 2 + spray;
        if(coverArea >= N){
            return true;
        }
        else {
            return false;
        }
    }
}