package javastudy.libray;

import Algorithm.Graph.FastReader;

import java.util.Collections;
import java.util.PriorityQueue;

/**
 2 3 5
 3 4 1
 2 8 3
 5 9 10
 5 12 3
 */
public class priorityQueuePratice {
    static class Dto implements Comparable<Dto>{
        int a;
        int b;
        int c;

        public Dto(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        @Override
        public int compareTo(Dto other){
            if(this.a != other.a){
                return this.a - other.a;
            }
            if(this.b != other.b){
                return this.b - other.b;
            }
            if(this.c != other.c){
                return this.c - other.c;
            }
            return 0;
        }

        @Override
        public String toString() {
            return "Dto{" +
                    "a=" + a +
                    ", b=" + b +
                    ", c=" + c +
                    '}';
        }
    }
    static FastReader scan = new FastReader();
    static PriorityQueue<Integer> pq1;
    static PriorityQueue<Dto> pq2;
    public static void main(String[] args) {
        pq1 = new PriorityQueue<>(Collections.reverseOrder());
        pq2 = new PriorityQueue<>();
        for(int i = 0; i < 10; i++){
            pq1.add(i);
        }

//        for (Integer integer : pq1) {
//            System.out.println(integer);
//        }
//        System.out.println("====== " );
//        while(!pq1.isEmpty()){
//            Integer peek = pq1.peek();
//            pq1.remove();
//            System.out.println("peek = " + peek);
//        }
        for(int i = 0; i < 5; i++){
            int a = scan.nextInt();
            int b = scan.nextInt();
            int c = scan.nextInt();
            pq2.add(new Dto(a, b, c));
        }

        while(!pq2.isEmpty()){
            Dto poll = pq2.poll();
            System.out.println("poll = " + poll);
        }
    }
}
