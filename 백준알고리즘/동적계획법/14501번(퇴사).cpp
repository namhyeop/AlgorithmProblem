#include<bits/stdc++.h>

using namespace std;

int Testcase;

int cache[16];
pair<int, int> arr[16];

int solve(int day)
{
	if (day == Testcase + 1)
		return 0;

	if (day > Testcase + 1)
		return INT_MIN;

	int &ret = cache[day];

	if (ret != -1)
		return ret;

	ret = 0;
	ret += max(arr[day].second + solve(day + arr[day].first), solve(day + 1));

	return ret;
}

int main()
{
	cin >> Testcase;

	for (int i = 1; i <= Testcase; i++)
		cin >> arr[i].first >> arr[i].second;
	//memset(cache, -1, sizeof(cache));
	fill(cache, cache + 16, -1);

	cout << solve(1) << "\n";

}
