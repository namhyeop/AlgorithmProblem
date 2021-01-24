#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	
	vector<int> v(N,0);
	vector<int> dp(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	dp[0] = v[0];
	int ret = dp[0];
	for (int i = 1; i < N; i++)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		ret = max(ret, dp[i]);
	}

	cout << ret << "\n";

	return 0;
}
