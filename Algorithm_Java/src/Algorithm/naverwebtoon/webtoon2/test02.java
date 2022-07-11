package Algorithm.naverwebtoon.webtoon2;

import java.util.*;

/**
 * * 문자열 내에서 반복되지 않는 문자를 찾기 (대소문자 구분 없음)
 * * qwfpnouYfqoapwuyfvoqpowueofyWro
 */


public class test02 {
    static HashMap<String, Integer> visited = new HashMap<>();
    static FastReader sc = new FastReader();
    static int AlphaCountArr[] = new int[26];
    public static void main(String[] args) {
        String inputStr = sc.nextLine();

        for(int i = 0; i < inputStr.length(); i++){
            countAlpha(inputStr, i);
            if('A' <= inputStr.charAt(i) && 'Z' >= inputStr.charAt(i)){
                AlphaCountArr[inputStr.charAt(i) - 'A']++;
            }
            else if('a' <= inputStr.charAt(i) && 'z' >= inputStr.charAt(i)){
                AlphaCountArr[inputStr.charAt(i) - 'a']++;
            }
        }

        for(int i = 0; i < inputStr.length(); i++){
            if(inputStr.charAt(i) >= 'A' && inputStr.charAt(i) <= 'Z') {
                if (AlphaCountArr[inputStr.charAt(i) - 'A'] == 1){
                    System.out.print(inputStr.charAt(i));
                }
            }else{
                if (AlphaCountArr[inputStr.charAt(i) - 'a'] == 1){
                    System.out.print(inputStr.charAt(i));
                }
            }
        }
    }

    private static void countAlpha(String inputStr, int alphaPos) {
        visited.put(String.valueOf(inputStr.charAt(alphaPos)),
                visited.getOrDefault(visited.get(String.valueOf(inputStr.charAt(alphaPos))),
                        0) + 1);
    }
}
