#include <bits/stdc++.h>

using namespace std;

int dp[1001][2];
int t;
int main() {
    dp[0][0] = 1;
    dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 1;
    for (int i = 3; i <= 40; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    cin >> t;
    while (t--) {
        int num; cin >> num;
        cout << dp[num][0] << " " << dp[num][1] << "\n";
    }
}

//#include<bits/stdc++.h>
//
//using namespace std;
//
//int cache[41];
//int main(void)
//{
//	int Testcase;
//	cin >> Testcase;
//
//	cache[1] = 1;
//	cache[0] = 0;
//
//	for (int i = 2; i <= 41; i++)
//	{
//		cache[i] = cache[i - 2] + cache[i - 1];
//	}
//
//	for (int i = 0; i < Testcase; i++)
//	{
//		int n;
//		cin >> n;
//
//		if (n == 0)
//			cout << 1 << " " << 0 << "\n";
//		else if (n == 1)
//			cout << 0 << " " << 1 << "\n";
//		else
//			cout << cache[n - 1] << " " << cache[n] << "\n";
//	}
//	return 0;
//}
