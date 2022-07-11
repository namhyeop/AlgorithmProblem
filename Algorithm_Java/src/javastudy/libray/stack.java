package javastudy.libray;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;

public class stack {
    static Stack<Integer> stack;
    public static void main(String[] args) {
        stack = new Stack<>();

        stack.push(1);
        stack.push(5);
        stack.push(6);
        Integer pop = stack.pop();
        System.out.println("pop = " + pop);
        Integer pop1 = stack.pop();
        System.out.println("pop = " + pop1);
        Integer pop2 = stack.pop();
        System.out.println("pop = " + pop2);
    }
}
