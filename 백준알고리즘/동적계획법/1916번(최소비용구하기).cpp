#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int n, m;
const int MAX = 101;
string cache[MAX][MAX];

string bigNumAdd(string num1, string num2)
{
	long long sum = 0;
	string result;

	while (!num1.empty() || !num2.empty() || sum)
	{
		if (!num1.empty())
		{
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty())
		{
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

string com(int n, int r)
{
	if (n == r || r == 0)
		return "1";

	string &ret = cache[n][r];

	if (ret != "")
		return ret;

	ret = bigNumAdd(com(n - 1, r - 1), com(n - 1, r));
	return ret;
}

int main(void)
{
	fastio;
	cin >> n >> m;

	string ret = com(n, m);
	cout << ret << '\n';
}
