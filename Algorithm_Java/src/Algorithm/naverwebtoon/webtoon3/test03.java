package Algorithm.naverwebtoon.webtoon3;

import java.io.IOException;

public class test03 {
    static FastReader scan = new FastReader();
    static int testNum;

    public static void main(String[] args) throws IOException {
        testNum = scan.nextInt();

        int t = 0;
        while(t < testNum) {
            String inputStr = scan.nextLine();
            int lastPos = inputStr.length() - 1;
            String retStr = "";

            for (int pos = 0; pos < inputStr.length(); pos++) {
                if (pos != 0 && pos != lastPos) {
                    if (inputStr.charAt(pos) != 'x') {
                        retStr += String.valueOf(inputStr.charAt(pos));
                    }
                } else {
                    retStr += String.valueOf(inputStr.charAt(pos));
                }
            }
            System.out.println(retStr);
            t++;
        }
    }
}

