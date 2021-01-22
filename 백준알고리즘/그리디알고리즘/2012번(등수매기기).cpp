#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
//자료형 조심하기
int main(int argc, char *argv[])
{
	ll N;
	cin >> N;

	vector<ll> v;
	vector < pair < ll, ll>> v1;
	for (int i = 0; i < N; i++)
	{
		ll tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++)
		v1.push_back({ i, v[i-1] });


	ll ret = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		ret += abs(v1[i].first - v1[i].second);
		//cout << ret <<"--"<< "\n";
	}
	cout << ret << "\n";

	return 0;
}
