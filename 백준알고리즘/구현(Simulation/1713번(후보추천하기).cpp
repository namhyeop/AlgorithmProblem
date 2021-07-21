#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 101;
int n, k;
int apprance[MAX];
vector<pair<int, int>> v;

int main(void)
{
	fastio;
	cin >> n >> k;

	//등장순서, 사진
	v.resize(n, { 0, 0 });
	for (int i = 0; i < k; i++)
	{
		int num;
		cin >> num;
		apprance[num]++;

		bool replaceFlag = false;
		for (int j = 0; j < n; j++)
		{
			if (v[j].second == 0)
			{
				v[j].second = num;
				v[j].first = i;
				replaceFlag = true;
				break;
			}
			else if (v[j].second == num)
			{
				replaceFlag = true;
				break;
			}
		}

		if (!replaceFlag)
		{
			int idx = 0;
			for (int j = 1; j < n; j++)
			{
				if (apprance[v[j].second] == apprance[v[idx].second])
				{
					if (v[j].first < v[idx].first)
						idx = j;
				}
				else if (apprance[v[j].second] < apprance[v[idx].second])
					idx = j;
			}
			apprance[v[idx].second] = 0;
			v[idx].first = i;
			v[idx].second = num;
		}
	}

	vector<int> ret;
	for (int i = 0; i < n; i++)
		ret.push_back(v[i].second);
	sort(ret.begin(), ret.end());
	for (auto num : ret)
		cout << num << " ";
}
