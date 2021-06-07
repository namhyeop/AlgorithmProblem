#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int n, s;
vector<int> arr;
int sum[100001];
int main(void)
{
	fastio;
	cin >> n >> s;
	
	arr.resize(n+1);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int low = 0;
	int high = 0;
	int sum = arr[0];
	int minValue = INT_MAX;
	
	while (low <= high && high < n)
	{
		if (sum < s)
			sum += arr[++high];
		else if (sum == s)
		{
			minValue = min(minValue, (high - low + 1));
			sum += arr[++high];
		}
		else if (sum > s)
		{
			minValue = min(minValue, high - low + 1);
			sum -= arr[low++];
		}
	}

	if (minValue == INT_MAX)
	{
		cout << "0" << "\n";
	}
	else
		cout << minValue << "\n";
}
