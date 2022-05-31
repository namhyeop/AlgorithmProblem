#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll dp[1000001];
int t;
const ll MAX = 1e9 + 9;

void input() {
    cin >> t;
}

void preprocess() {
    dp[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        dp[i] += dp[i - 1]; //마지막에 1을 더하는 경우의 수
        if(i - 2 >= 0) dp[i] += dp[i - 2]; //마지막에 2를 더하는 경우의 수
        dp[i] %= MAX;
        if(i - 3 >= 0) dp[i] += dp[i - 3]; //마지막에 3을 더하는 경우의 수
        dp[i] %= MAX;
    }
}

void pro() {
    preprocess();
    while(t-- ){
        int num; cin >> num;
        int ret = 0;
        for(int mid = 1; mid <= 3; mid++){ // 가운데에 mid를 더하는 경우
            if(num - mid >= 0 &&(num - mid) % 2 == 0) {
                ret += dp[(num - mid) / 2];
                ret %= MAX;
            }
        }
        //짝수 개를 더하는 경우(사실상 위에서 mid가 0인 경우. 즉, foor loop를 0부터 시작해도 된다
        if(num % 2 == 0){
            ret += dp[num / 2];
            ret %= MAX;
        }
        cout << ret <<'\n';
    }
}

int main() {
    input();
    pro();
}