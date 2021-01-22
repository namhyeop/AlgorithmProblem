#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;

	ll sumValue = 0;
	vector<ll> v;

	for (int i = 0; i < N; i++)
	{
		ll tmp;
		cin >> tmp;
		sumValue += tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	ll ret = 0;
	for (int i = 0; i < N - 1; i++)
	{
		ll tmpSumvalue = sumValue - v[i];
		sumValue = tmpSumvalue;
		ret += tmpSumvalue * v[i];
	}

	cout << ret << "\n";

	return 0;
}
