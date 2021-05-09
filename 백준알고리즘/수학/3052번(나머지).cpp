#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp % 42);
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	cout << v.size() << "\n";
}
