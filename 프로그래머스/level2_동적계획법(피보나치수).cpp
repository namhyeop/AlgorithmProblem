#include <bits/stdc++.h>

using namespace std;
#define ll long long
int cache[100001];

int solution(int n) {
    int answer = 0;
    cache[0] = 0;
    cache[1] = 1;
    for (int i = 2; i <= n; i++) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % 1234567;
    }

    answer = cache[n] % 1234567;

    return answer;
}

int main() {
    cout << solution(100000) << "\n";

}