#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int factorial(int num)
{
	int ret = 1;
	for (int i = 1; i <= num; i++)
		ret *= i;
	return ret;
}

int main()
{
	fastio;
	
	int n, k;
	cin >> n >> k;

	int a = factorial(n);
	int b = factorial(k);
	int c = factorial(n - k);

	int ret = a / (b * c);
	cout << ret << "\n";
}
