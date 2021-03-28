#include<bits/stdc++.h>

using namespace std;

int n;
int goalValue;
int arr[101];
int cache[100001]; //i번째 숫자를 만들때 가장 최소의 갯수로 숫자를 만드는 갯수를 저장하는 DP

int main(void)
{
	cin >> n;
	cin >> goalValue;
	
	cache[0] = 0;
	for (int i = 1; i <= goalValue; i++)
		cache[i] = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cache[arr[i]] = 1;
	}

	for (int i = 1; i <= goalValue; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//이미 최소로 만들 수 있는 경우에는 다음 비교를 진행한다.
			if (cache[i] == 1)
				break;
			//i번째 금액이 기존의 동전보다 가격이 작아 만들수 없거나 기존의 동전으로는 만들수 없는 금액일 경우 다음 비교를 진행한다.
			else if (i - arr[j] < 0 || cache[i - arr[j]] == INT_MAX)
				continue;
			else
				cache[i] = min(cache[i], 1 + cache[i - arr[j]]);
		}
	}

	if (cache[goalValue] == INT_MAX)
		cout << -1 << "\n";
	else
		cout << cache[goalValue] << "\n";
	return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int maxCoin;
int k;
int cache[101][10001];
int undivide = numeric_limits<int>::max()-100000; //100000을 안더하면 26행에서 1을 더해주면 max에서 오버플로우가 생겨 -의 최대값이 되버림

vector<int> v;

int count(int n , int k)
{
	if (n == maxCoin)
		return (k == 0 ? 0 : undivide);
	
	int &ret = cache[n][k];
	if (ret != -1)
		return ret;

	ret = count(n + 1, k);
	if (k >= v[n])
		ret = min(ret, count(n, k - v[n]) + 1);

	return ret;
}

int main(int argc, char *argv[])
{

	cin >> maxCoin;
	cin >> k;
	
	for (int i = 0; i < 101; i++)
	for (int j = 0; j < 10001; j++)
		cache[i][j] = -1;
	
	for (int i = 0; i < maxCoin; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	int result = count(0, k);

	if (result == undivide)
		cout << "-1" << endl;
	else
		cout << result << endl;

	return 0;
}
*/
