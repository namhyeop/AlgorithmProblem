#include<bits/stdc++.h>

using namespace std;

int n;
int cnt;
vector<pair<int, int>> v;
//level은 어떤 계란으로 칠 것을 의미하는 변수
//i는 몇 번째 계란을 칠 것인지를 의미하는 변수
int break_egg(int level)
{
	if (level == n)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		if (v[i].first <= 0)
			cnt++;
		return cnt;
	}
	
	if (v[level].first <= 0)
		return break_egg(level + 1);

	bool check = false;
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (level == i)
			continue;
		if (v[i].first <= 0) //비교대상이 이미 깨져 있다면
			continue;
		check = true;

		v[level].first -= v[i].second;
		v[i].first -= v[level].second;

		ret = max(ret, break_egg(level + 1));

		v[level].first += v[i].second;
		v[i].first += v[level].second;
	}

	if (!check)
		return break_egg(level + 1);

	return ret;
}

int main(int argc, char *argv[])
{
	cin >> n;

	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	cout <<	break_egg(0) << "\n";

}
