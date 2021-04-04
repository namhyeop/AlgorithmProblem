#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;
const int MAX = 1e5 + 1;
int n;
int arr[MAX];
vector<int> v;
vector<int> diff;

int GCD(int y, int x)
{
	if (x == 0)
		return y;
	return GCD(x, y%x);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		if (i != 0)
			diff.push_back(v[i] - v[i - 1]);
	}

	int gcdValue = diff[0];
	for (int i = 1; i < diff.size(); i++)
		gcdValue = GCD(gcdValue, diff[i]);

	int len = v[n - 1] - v[0];
	int cnt = len / gcdValue;
	cnt -= n - 1;//사이에 있는 가로수 이므로 한 개를 더 빼줘야함
	cout << cnt << "\n";

	return 0;
}
