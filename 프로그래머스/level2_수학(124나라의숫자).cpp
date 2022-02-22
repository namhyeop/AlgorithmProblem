#include<bits/stdc++.h>

using namespace std;

string solution(int n) {
    string str = "412";
    string answer = "";

    while (n > 0) {
        answer += str[n % 3];
        if (n % 3 == 0) {
            n = (n / 3) - 1;
        } else {
            n = n / 3;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}