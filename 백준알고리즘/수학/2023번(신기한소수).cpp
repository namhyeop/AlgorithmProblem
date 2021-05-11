#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
int N;

void operate(int num, int len)
{
	auto idx = [&](int num)-> bool
	{
		if (num == 0 || num == 1)
			return false;

		for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
			return false;

		return true;
	};

	if (len == N)
	{
		cout << num << "\n";
		return;
	}

	for (int i = 1; i <= 9; i+= 2)
	if (idx(num * 10 + i))
		operate(num * 10 + i, len + 1);
}

int main(void)
{
	cin >> N;
	
	vector<int> v = { 2, 3, 5, 7 };
	
	for (int i = 0; i < v.size(); i++)
		operate(v[i], 1);
}
