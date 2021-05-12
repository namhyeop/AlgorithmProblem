#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

string s;
int maxRet = INT_MIN;
int minRet = INT_MAX;

void operate(string input, int sum)
{
	auto Calculator = [&](string str) -> int
	{
		int tmpValue = 0;
		for (int i = 0; i < sz(str); i++)
		if ((str[i] - '0') % 2 != 0)
			tmpValue++;
		return tmpValue;
	};

	if (sz(input) == 1)
	{
		maxRet = max(Calculator(s) + sum, maxRet);
		minRet = min(Calculator(s) + sum, minRet);
	}

	else if (sz(input) == 2)
		operate(to_string((input[0] - '0') + (input[1] - '0')), sum + Calculator(to_string((input[0] - '0') + (input[1] - '0'))));
	
	else if (sz(input) >= 3)
	{
		for (int i = 1; i < sz(input); i++)
		for (int j = i + 1; j < sz(input); j++)
			operate(to_string(stoi(input.substr(0, i)) + stoi(input.substr(i, j - i)) + stoi(input.substr(j))), sum + Calculator(to_string(stoi(input.substr(0, i)) + stoi(input.substr(i, j-i)) + stoi(input.substr(j)))));
	}
}

int main(void)
{
	fastio;
	cin >> s;

	operate(s, 0);
	cout << minRet << " " << maxRet << "\n";
}
