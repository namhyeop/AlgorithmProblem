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

	int h, m;
	cin >> h >> m;

	int time = (60 * h + m) - 45;
	
	if (time >= 0)
		cout << time / 60 << " " << time % 60 << "\n";
	else
	{
		time = 1440 + time;
		cout << time / 60 << " " << time % 60 << "\n";
	}
}
