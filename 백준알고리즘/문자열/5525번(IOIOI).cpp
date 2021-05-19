//#include<bits/stdc++.h> 시간초과
//#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//#define pill pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define ll long long
//#define sz(v) (int)(v).size()
//
//using namespace std;
//string OI = "OI";
//
//int main(void)
//{
//	fastio;
//	
//	int n, m;
//	string input;
//	cin >> n >> m >> input;
//
//	string tarOI = "I";
//
//	for (int i = 0; i < n; i++)
//		tarOI = tarOI + OI;
//	
//	int cnt = 0;
//
//	int start = input.find("IOI", 0);
//	while (start)
//	{
//		int next = input.find("IOI", start);
//		if (next != -1)
//		{
//			cnt++;
//		}
//		start = next + 1;
//		
//	}
//
//	cout << cnt << "\n";
//}

#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int ret = 0;

int main(void)
{
	fastio;
	int n, m;
	string s;
	cin >> n >> m >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			int zeroCnt = 0;
			while (s[i] == 'I' && s[i + 1] == 'O')
			{
				i += 2;
				zeroCnt++;
				if (s[i] == 'I' && zeroCnt == n)
				{
					zeroCnt--;
					ret++;
				}
			}
		}
	}
	cout << ret << "\n";
	return 0;
}
