#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int n, m;
vector<string> v1;
vector<string> v2;
vector<string> ret;

int main(void)
{
	fastio;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		v1.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		string tmp;
		cin >> tmp;
		v2.push_back(tmp);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int idx1 = 0 , idx2 = 0;
	int size = 0;
	if (v1.size() > v2.size())
		size = v1.size();
	else
		size = v2.size();

	while (idx1 != size  && idx2 != size)
	{
		if (v1[idx1] == v2[idx2])
		{
			ret.push_back(v1[idx1]);
			idx1++;
			idx2++;
		}
		else if (v1[idx1] > v2[idx2])
		{
			idx2++;
		}
		else
			idx1++;
	}
	
	cout << ret.size() << "\n";
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";

	return 0;
}
