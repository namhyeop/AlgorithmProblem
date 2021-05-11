#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()
#define int __int128
using namespace std;

int conv[128];
int lim = 1ULL << 63;

int32_t main(void)
{
	fastio;

	string a, b;
	cin >> a >> b;

	vector<tuple<uint64_t, uint64_t, uint64_t>> ans;

	for (int i = 0; i < 10; i++) // 1부터 z까지의 파싱작업
		conv[i + '0'] = i;
	for (int i = 0; i < 26; i++)
		conv[i + 'a'] = i + 10;

	int a_mn = 0;
	int b_mn = 0;

	for (const auto& i : a)//a와 b에서 사용가능한 최대값 찾아주기
		a_mn = max(a_mn, conv[i] + 1);
	for (const auto& i : b)
		b_mn = max(b_mn, conv[i] + 1);
	for (int i = a_mn; i <= 36; i++)//위에서 찾은 최대값 기준으로 진법 탐색하기. 예를 들어 567이 있으면 최대값은 7인데 이 말은 최소8진법이라는 의미임
	for (int j = b_mn; j <= 36; j++)
	{
		if (i == j)
			continue;
		//진법 계산
		auto Calc = [&](string &s, int base) -> int
		{
			int ret = 0;

			for (int i = 0; i < s.size(); i++)
			{
				ret = base * ret + conv[s[i]];
				if (ret >= lim)
					return -1;
			}
			return ret;
		};

		int t1 = Calc(a, i);
		int t2 = Calc(b, j);
		if (t1 != -1 && t1 == t2)
			ans.push_back({ t1, i, j });
	}

	if (ans.empty())
		cout << "Impossible" << "\n";
	else if (ans.size() > 1)
		cout << "Multiple" << "\n";
	else
	for (auto [a, b, c] : ans)
		cout << a << ' ' << b << ' ' << c << "\n";
}
