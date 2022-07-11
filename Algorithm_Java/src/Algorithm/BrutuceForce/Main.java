//import java.io.*;
//import java.util.StringTokenizer;
//
//public class Main {
//    static StringBuilder sb = new StringBuilder();
//
//    static void input(){
//        Graph.FastReader scan = new Graph.FastReader();
//        N = scan.nextInt();
//        M = scan.nextInt();
//        selected = new int[M + 1];
//        visited = new boolean[N + 1];
//    }
//
//    static int N, M;
//    static int[] selected;
//    static boolean[] visited;
//
//    static void rec_func(int k){
//        if(k == M + 1){
//            for(int i = 1; i <= M; i++){
//                sb.append(selected[i]).append(' ');
//            }
//            sb.append("\n");
//        }else {
//            for (int i = selected[k - 1] + 1; i <= N; i++) {
//                selected[k] = i;
//                rec_func( k + 1);
//                selected[k] = 0;
//            }
//        }
//    }
//
//    public static void main(String[] args) throws IOException {
//        input();
////        System.out.println(visited[0]);
//        rec_func(1);
//        System.out.println(sb.toString());
//    }
//
//    static class Graph.FastReader{
//        BufferedReader br;
//        StringTokenizer st;
//
//        public Graph.FastReader(){
//            br = new BufferedReader(new InputStreamReader(System.in));
//        }
//
//        public Graph.FastReader(String s) throws FileNotFoundException{
//            br = new BufferedReader(new FileReader(new File(s)));
//        }
//
//        String next(){
//            while(st == null || !st.hasMoreElements()){
//                try{
//                    st = new StringTokenizer(br.readLine());
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            return st.nextToken();
//        }
//
//        int nextInt() {
//            return Integer.parseInt(next());
//        }
//
//        long nextLong(){
//            return Long.parseLong(next());
//        }
//
//        double nextDouble(){
//            return Double.parseDouble(next());
//        }
//
//        String nextLine(){
//            String str = "";
//            try{
//                str = br.readLine();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//            return str;
//        }
//    }
//}

//14888번
//import java.io.*;
//import java.util.StringTokenizer;
//
//public class Main{
//    static StringBuilder sb = new StringBuilder();
//
//    static void input(){
//        Graph.FastReader scan = new Graph.FastReader();
//
//        N = scan.nextInt();
//        nums = new int[N + 1];
//        operators = new int[5];
//
//        for(int i = 1; i <= N; i++){
//            nums[i] = scan.nextInt();
//        }
//        for(int i = 1; i <= 4; i++){
//            operators[i] = scan.nextInt();
//        }
//        max = Integer.MIN_VALUE;
//        min = Integer.MAX_VALUE;
//    }
//
//    static int N, max, min;
//    static int[] nums, operators;
//
//    static int calculator(int arg1, int operator, int arg2){
//        if(operator == 1){
//            return arg1 + arg2;
//        }
//        else if(operator == 2){
//            return arg1 - arg2;
//        }
//        else if(operator == 3){
//            return arg1 * arg2;
//        }
//        else
//            return arg1 / arg2;
//    }
//
//    static void rec_func(int k, int value){
//        if(k == N){
//            max = Math.max(max, value);
//            min = Math.min(min, value);
//        }else {
//            for (int cand = 1; cand <= 4; cand++) {
//                if (operators[cand] > 0) {
//                    operators[cand]--;
//                    rec_func(k + 1, calculator(value, cand, nums[k + 1]));
//                    operators[cand]++;
//                }
//            }
//        }
//    }
//
//    public static void main(String[] args) {
//        input();
//        rec_func(1, nums[1]);
//        sb.append(max).append("\n").append(min);
//        System.out.println(sb.toString());
//    }
//
//    static class Graph.FastReader{
//        BufferedReader br;
//        StringTokenizer st;
//
//        public Graph.FastReader(){
//            br = new BufferedReader(new InputStreamReader(System.in));
//        }
//
//        public Graph.FastReader(String s) throws FileNotFoundException{
//            br = new BufferedReader(new FileReader(new File(s)));
//        }
//
//        String next(){
//            while(st == null || !st.hasMoreElements()){
//                try{
//                    st = new StringTokenizer(br.readLine());
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            return st.nextToken();
//        }
//
//        int nextInt(){
//            return Integer.parseInt(next());
//        }
//
//        long nextLong(){
//            return Long.parseLong(next());
//        }
//
//        double nextDouble(){
//            return Double.parseDouble(next());
//        }
//
//        String nextLine(){
//            String str = "";
//            try{
//                str = br.readLine();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//            return str;
//        }
//    }
//}

//9663번
//import java.io.*;
//import java.util.StringTokenizer;
//
//public class Main{
//    static StringBuilder sb = new StringBuilder();
//
//    static void input(){
//        Graph.FastReader scan = new Graph.FastReader();
//
//        N = scan.nextInt();
//        col = new int[N + 1];
//    }
//
//    static int N,answer;
//    static int[] col;
//
//    static boolean isValid(int r1, int c1, int r2, int c2){
//        if(c1 == c2) return true;
//        else if(r1 + c1 == r2 + c2) return true;
//        else if(r1 - c1 == r2 - c2) return true;
//        return false;
//    }
//    static void rec_func(int row){
//        if(row == N){
//            answer++;
//            return;
//        }
//        for(int c = 0; c < N; c++){
//            boolean flag = true;
//            for(int j = 0; j < row; j++){
//                if(isValid(row, c, j, col[j])){
//                    flag = false;
//                    break;
//                }
//            }
//            if(flag){
//                col[row] = c;
//                rec_func(row + 1);
//                col[row] = 0;
//            }
//        }
//    }
//
//    public static void main(String[] args) {
//        input();
//        rec_func(0);
//        System.out.println(answer);
//    }
//
//    static class Graph.FastReader{
//        BufferedReader br;
//        StringTokenizer st;
//
//        public Graph.FastReader(){
//            br = new BufferedReader(new InputStreamReader(System.in));
//        }
//
//        public Graph.FastReader(String s) throws FileNotFoundException{
//            br = new BufferedReader(new FileReader(new File(s)));
//        }
//
//        String next(){
//            while(st == null || !st.hasMoreElements()){
//                try{
//                    st = new StringTokenizer(br.readLine());
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            return st.nextToken();
//        }
//
//        int nextInt(){
//            return Integer.parseInt(next());
//        }
//
//        long nextLong(){
//            return Long.parseLong(next());
//        }
//
//        double nextDouble(){
//            return Double.parseDouble(next());
//        }
//
//        String nextLine(){
//            String str = "";
//            try{
//                str = br.readLine();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//            return str;
//        }
//    }
//}

//1825번
//import java.io.*;
//import java.util.StringTokenizer;
//
//public class Main{
//    static StringBuilder sb = new StringBuilder();
//
//    static void input(){
//        Graph.FastReader scan = new Graph.FastReader();
//
//        N = scan.nextInt();
//        col = new int[N + 1];
//    }
//
//    static int N,answer;
//    static int[] col;
//
//    static boolean isValid(int r1, int c1, int r2, int c2){
//        if(c1 == c2) return true;
//        else if(r1 + c1 == r2 + c2) return true;
//        else if(r1 - c1 == r2 - c2) return true;
//        return false;
//    }
//    static void rec_func(int row){
//        if(row == N){
//            answer++;
//            return;
//        }
//        for(int c = 0; c < N; c++){
//            boolean flag = true;
//            for(int j = 0; j < row; j++){
//                if(isValid(row, c, j, col[j])){
//                    flag = false;
//                    break;
//                }
//            }
//            if(flag){
//                col[row] = c;
//                rec_func(row + 1);
//                col[row] = 0;
//            }
//        }
//    }
//
//    public static void main(String[] args) {
//        input();
//        rec_func(0);
//        System.out.println(answer);
//    }
//
//    static class Graph.FastReader{
//        BufferedReader br;
//        StringTokenizer st;
//
//        public Graph.FastReader(){
//            br = new BufferedReader(new InputStreamReader(System.in));
//        }
//
//        public Graph.FastReader(String s) throws FileNotFoundException{
//            br = new BufferedReader(new FileReader(new File(s)));
//        }
//
//        String next(){
//            while(st == null || !st.hasMoreElements()){
//                try{
//                    st = new StringTokenizer(br.readLine());
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            return st.nextToken();
//        }
//
//        int nextInt(){
//            return Integer.parseInt(next());
//        }
//
//        long nextLong(){
//            return Long.parseLong(next());
//        }
//
//        double nextDouble(){
//            return Double.parseDouble(next());
//        }
//
//        String nextLine(){
//            String str = "";
//            try{
//                str = br.readLine();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//            return str;
//        }
//    }
//}

//1759번
//import java.io.*;
//import java.util.Arrays;
//import java.util.StringTokenizer;
//
//public class Main {
//    static StringBuilder sb = new StringBuilder();
//
//    static void input() {
//        Graph.FastReader scan = new Graph.FastReader();
//
//        M = scan.nextInt();
//        N = scan.nextInt();
//        chars = new char[N + 1];
//        selected = new int[M + 1];
//        String[] tokens = scan.nextLine().split(" ");
//        for (int i = 1; i <= N; i++) {
//            chars[i] = tokens[i - 1].charAt(0);
//        }
//    }
//
//    static int N, M;
//    static char[] chars;
//    static int[] selected;
//
//    static boolean isVowel(char x) {
//        return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
//    }
//
//    static void rec_func(int k) {
//        if (k == M + 1) {
//            int vowel = 0, consonant = 0;
//            for (int i = 1; i <= M; i++) {
//                if (isVowel(chars[selected[i]])) {
//                    vowel++;
//                } else {
//                    consonant++;
//                }
//            }
//            if (vowel >= 1 && consonant >= 2) {
//                for (int i = 1; i <= M; i++) {
//                    sb.append(chars[selected[i]]);
//                }
//                sb.append("\n");
//            }
//        } else {
//            for (int cand = selected[k - 1] + 1; cand <= N; cand++) {
//                selected[k] = cand;
//                rec_func(k + 1);
//                selected[k] = 0;
//            }
//        }
//    }
//
//    public static void main(String[] args) {
//        input();
//        Arrays.sort(chars, 1, N + 1);
//        rec_func(1);
//        System.out.println(sb.toString());
//    }
//
//    static class Graph.FastReader {
//        BufferedReader br;
//        StringTokenizer st;
//
//        public Graph.FastReader() {
//            br = new BufferedReader(new InputStreamReader(System.in));
//        }
//
//        public Graph.FastReader(String s) throws FileNotFoundException {
//            br = new BufferedReader(new FileReader(new File(s)));
//        }
//
//        String next() {
//            while (st == null || !st.hasMoreElements()) {
//                try {
//                    st = new StringTokenizer(br.readLine());
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            return st.nextToken();
//        }
//
//        int nextInt() {
//            return Integer.parseInt(next());
//        }
//
//        long nextLong() {
//            return Long.parseLong(next());
//        }
//
//        double nextDouble() {
//            return Double.parseDouble(next());
//        }
//
//        String nextLine() {
//            String str = "";
//            try {
//                str = br.readLine();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//            return str;
//        }
//    }
//}

//10825번
//import java.io.*;
//        import java.util.Arrays;
//        import java.util.StringTokenizer;
//
//public class Main {
//    static StringBuilder sb = new StringBuilder();
//    static Graph.FastReader scan = new Graph.FastReader();
//
//    static class Elem implements Comparable<Elem>{
//        public String name;
//        public int korean, english, math;
//
//        @Override
//        public int compareTo(Elem other){
//            if(korean != other.korean)
//                return other.korean - korean;
//            if(english != other.english)
//                return english - other.english;
//            if(math != other.math)
//                return other.math - math;
//            return name.compareTo(other.name);
//        }
//    }
//
//    static int N;
//    static Elem[] a;
//
//    static void input(){
//        N = scan.nextInt();
//        a = new Elem[N];
//        for(int i = 0; i < N; i++){
//            a[i] = new Elem();
//            a[i].name = scan.next();
//            a[i].korean = scan.nextInt();
//            a[i].english = scan.nextInt();
//            a[i].math = scan.nextInt();
//        }
//    }
//
//    static void pro(){
//        Arrays.sort(a);
//        for(int i = 0; i < N; i++){
//            sb.append(a[i].name).append("\n");
//        }
//        System.out.println(sb.toString());
//    }
//    public static void main(String[] args) {
//        input();
//        pro();
//    }
//
//    static class Graph.FastReader {
//        BufferedReader br;
//        StringTokenizer st;
//
//        public Graph.FastReader() {
//            br = new BufferedReader(new InputStreamReader(System.in));
//        }
//
//        public Graph.FastReader(String s) throws FileNotFoundException {
//            br = new BufferedReader(new FileReader(new File(s)));
//        }
//
//        String next() {
//            while (st == null || !st.hasMoreElements()) {
//                try {
//                    st = new StringTokenizer(br.readLine());
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            return st.nextToken();
//        }
//
//        int nextInt() {
//            return Integer.parseInt(next());
//        }
//
//        long nextLong() {
//            return Long.parseLong(next());
//        }
//
//        double nextDouble() {
//            return Double.parseDouble(next());
//        }
//
//        String nextLine() {
//            String str = "";
//            try {
//                str = br.readLine();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//            return str;
//        }
//    }
//}

//1015-수열정렬
//import java.io.*;
//        import java.util.Arrays;
//        import java.util.StringTokenizer;
//
//public class Main {
//    static StringBuilder sb = new StringBuilder();
//    static Graph.FastReader scan = new Graph.FastReader();
//
//    static class Elem implements Comparable<Elem>{
//        public int num, idx;
//
//        @Override
//        public int compareTo(Elem other){
//            return num - other.num;
//        }
//    }
//
//    static int N;
//    static int[] P;
//    static Elem[] B;
//
//    static void input(){
//        N = scan.nextInt();
//        B = new Elem[N];
//        P = new int[N];
//        for(int i = 0; i < N; i++){
//            B[i] = new Elem();
//            B[i].num = scan.nextInt();
//            B[i].idx = i;
//        }
//    }
//
//    static void pro(){
//        Arrays.sort(B);
//        for(int i = 0; i < N; i++){
//            P[B[i].idx] = i;
//        }
//        for(int i = 0; i < N; i++){
//            sb.append(P[i]).append(' ');
//        }
//        System.out.println(sb.toString());
//    }
//
//    public static void main(String[] args) {
//        input();
//        pro();
//    }
//
//    static class Graph.FastReader {
//        BufferedReader br;
//        StringTokenizer st;
//
//        public Graph.FastReader() {
//            br = new BufferedReader(new InputStreamReader(System.in));
//        }
//
//        public Graph.FastReader(String s) throws FileNotFoundException {
//            br = new BufferedReader(new FileReader(new File(s)));
//        }
//
//        String next() {
//            while (st == null || !st.hasMoreElements()) {
//                try {
//                    st = new StringTokenizer(br.readLine());
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            return st.nextToken();
//        }
//
//        int nextInt() {
//            return Integer.parseInt(next());
//        }
//
//        long nextLong() {
//            return Long.parseLong(next());
//        }
//
//        double nextDouble() {
//            return Double.parseDouble(next());
//        }
//
//        String nextLine() {
//            String str = "";
//            try {
//                str = br.readLine();
//            } catch (IOException e) {
//                e.printStackTrace();
//            }
//            return str;
//        }
//    }
//}