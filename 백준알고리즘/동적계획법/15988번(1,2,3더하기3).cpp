#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll dp[1000001];
int t;
const ll MAX = 1e9 + 9;
int main() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 1000001; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MAX;
    }
    cin >> t;
    while(t--) {
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }
}

//#include<bits/stdc++.h>
//
//using namespace std;
//const int MAX = 1e6;
//const int mod = 1e9 + 9;
//int n;
//
//long long cache[MAX + 1];
//
//int main()
//{
//	int Testcase;
//	cin >> Testcase;
//
//	cache[1] = 1;
//	cache[2] = 2;
//	cache[3] = 4;
//	for (int i = 4; i <= MAX; i++)
//		cache[i] = (cache[i - 1] + cache[i - 2] + cache[i - 3]) % mod;
//
//	while (Testcase--)
//	{
//		int tmp;
//		cin >> tmp;
//		cout << cache[tmp] << "\n";
//	}
//}
