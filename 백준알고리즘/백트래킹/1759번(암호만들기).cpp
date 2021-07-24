#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 20;
int l, c; 
char arr[MAX];
vector<string> ret;
int main(void)
{
	fastio;
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> arr[i];
	sort(arr, arr + c);

	function<void(int, string, int, int)> DFS = [&](int pos, string str, int ja, int mo)
	{
		if (str.size() == l)
		{
			if (ja < 2 || mo < 1)
				return;
			ret.push_back(str);
			return;
		}
		
		for (int i = pos; i < c; i++)
		{
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			{
				str += arr[i];
				DFS(i + 1, str, ja, mo + 1);
				str.pop_back();
			}
			else
			{
				str += arr[i];
				DFS(i + 1, str, ja + 1, mo);
				str.pop_back();
			}
		}
	};

	DFS(0, "", 0, 0);

	for (auto ans : ret)
		cout << ans << "\n";
	return 0;
}

/*
#include<bits/stdc++.h>

using namespace std;

int L, C;
vector<char> v;
string ret;

bool isValid(string tmp)
{
	if (tmp.find("a") != -1 || tmp.find("e") != -1 || tmp.find("i") != -1 || tmp.find("o") != -1 || tmp.find("u") != -1)
	{
		int cnt = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			if ('b' <= tmp[i] && tmp[i] <= 'd'
				|| 'f' <= tmp[i] && tmp[i] <= 'h'
				|| 'j' <= tmp[i] && tmp[i] <= 'n'
				|| 'p' <= tmp[i] && tmp[i] <= 't'
				|| 'v' <= tmp[i] && tmp[i] <= 'z')
				cnt++;
		}
		
		if (cnt >= 2)
			return true;
		else
			return false;
	}
	return false;
}

void func(int level, int cnt)
{
	if (level == L)
	{
		if (isValid(ret))
			cout << ret << "\n";
		return;
	}

	for (int i = 0; i < C; i++)
	{
		if (level == 0 || i > cnt)
		{
			ret.push_back(v[i]);
			func(level + 1, i);
			ret.pop_back();
		}
	}	
}
int main(int argc, char *argv[])
{
	cin >> L >> C;

	v.resize(C);
	for (int i = 0; i < C; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	func(0,0);

}
*/
