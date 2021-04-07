#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int n, k;
vector<string> v;

bool cmp(string a, string b)
{
	if (a + b > b + a)
		return true;
	return false;
}

int maxValue = INT_MIN;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		string num;
		cin >> num;
		v.push_back(num);

		if (maxValue < stoi(num))
			maxValue = stoi(num);
	}

	for (int i = 0; i < n - k; i++)
		v.push_back(to_string(maxValue));

	sort(v.begin(), v.end(), cmp);	

	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	
	return 0;
}
