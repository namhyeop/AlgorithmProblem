#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(int argc, char *argv[])
{
	ll L;
	ll N;
	ll oldman;
	ll trainer;
	ll x, c;

	cin >> L >> N >> oldman >> trainer;

	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;

	sort(v.begin(), v.end(), greater<>());

	ll current = 0;
	ll ret = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (current < v[i].second)
		{
    //oldman - trainer = 쉬는시간, 시작되는 초에서 현재 초를 빼준다음 현재 Xi만큼 곱해줘야함,
    //이후 current는 뒤쳐지면 안되기 때문에 갱신해줘야한다.
			ret += (oldman - trainer) * (v[i].second - current) * v[i].first;
			current = v[i].second;
		}
	}

	cout << ret << "\n";
	return 0;
}
