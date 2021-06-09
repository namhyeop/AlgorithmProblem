#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1001;
int t;
ll arrA[MAX];
ll arrB[MAX];

int main(void)
{
	fastio;
	cin >> t;
	int aNum, bNum;
	cin >> aNum;
	for (int i = 0; i < aNum; i++)
		cin >> arrA[i];
	cin >> bNum;
	for (int j = 0; j < bNum; j++)
		cin >> arrB[j];

	vector<ll> v1, v2;

	for (int i = 0; i < aNum; i++)
	{
		int sum = arrA[i];
		v1.push_back(sum);
		for (int j = i + 1; j < aNum; j++)
		{
			sum += arrA[j];
			v1.push_back(sum);
		}
	}

	for (int i = 0; i < bNum; i++)
	{
		int sum = arrB[i];
		v2.push_back(sum);
		for (int j = i + 1; j < bNum; j++)
		{ 
			sum += arrB[j];
			v2.push_back(sum);
		}
	}
	sort(v2.begin(), v2.end());

	ll ans = 0;
	for (auto item : v1)
	{
		int diff = t - item;
		auto ub = upper_bound(v2.begin(), v2.end(), diff); 
		auto lb = lower_bound(v2.begin(), v2.end(), diff);
		ans += ub - lb;
	}
	cout << ans;
}
