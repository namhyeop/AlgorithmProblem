#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int t;
int num[8001];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	vector<int> v;
	double sum = 0;
	for (int i = 0; i < t; i++)
	{
		double tmp;
		cin >> tmp;
		int inttmp =tmp;
		sum += tmp;
		num[inttmp + 4000]++;
		v.push_back(tmp);
	}
	
	cout << floor(sum / t + 0.5) << "\n";
	sort(v.begin(), v.end());
	cout << v[t / 2] << "\n";

	vector<int> minValue;
	
	int curMAX = 0;
	for (int i = 0; i <= 8000; i++)
	{
		if (num[i] > curMAX)
		{
			curMAX = num[i];
			minValue.clear();
			minValue.push_back(i - 4000);
		}
		else if (num[i] == curMAX)
		{
			minValue.push_back(i - 4000);
		}
	}

	if (minValue.size() == 1)
		cout << minValue[0] << "\n";
	else
		cout << minValue[1] << "\n";

	if (v.size() == 1)
		cout << 0 << '\n';
	else
	 cout << v[v.size() - 1] - v[0] << "\n";

	return 0;
}
