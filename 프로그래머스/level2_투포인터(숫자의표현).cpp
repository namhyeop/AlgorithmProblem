#include<bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;

    int cur1 = 1;
    int cur2 = cur1 + 1;
    int curValue = 1;

    while(cur1 <= n){
        if(curValue >= n){
            curValue -= cur1;
            cur1++;
        }
        else{
            curValue += cur2;
            cur2++;
        }
        if(curValue == n)
            answer++;
    }
    return answer;
}

int main() {
    solution(15);
}

//잘못된 풀이. 아니 구간합 아닌가? ㅅㅂ? 왜 안되지???
//#include<bits/stdc++.h>
//
//using namespace std;
//const int MAX = 10005;
//int dp[MAX];
//
//int solution(int n) {
//    int answer = 0;
//
//    for (int i = 1; i <= n; i++) {
//        dp[i] = dp[i - 1] + i;
//    }
//
//    for (int i = 0; i <= n; i++) {
//        for (int j = i + 1; j <= n; j++) {
//            int value = dp[j] - dp[i];
//            if (value == n)
//                answer++;
//        }
//    }
//
//    return answer;
//}