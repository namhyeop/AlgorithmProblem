#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int main()
{
	fastio;
	
	int t;
	cin >> t;
	while (t--)
	{
		int H, W, N;
		cin >> H >> W >> N;

		int frontNum = N % H;
		if (frontNum == 0)
			frontNum = H;
		int secondNum = 1 + N / H;
		if (frontNum == H)
			secondNum -= 1;

		string ret;
		if (secondNum < 10)
			ret = to_string(frontNum) + '0' + to_string(secondNum);
		else
			ret = to_string(frontNum) + to_string(secondNum);
		cout << ret << "\n";
	}
}
