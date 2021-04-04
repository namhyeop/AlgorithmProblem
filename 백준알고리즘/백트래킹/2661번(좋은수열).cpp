#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;

int n;
string s;
bool visited[81];

void search(char c, int level)
{

	if (level -1 == n)
	{
		cout << s << "\n";
		exit(0);
	}

	s += c;
	for (int i = 1; i <= level / 2; i++)
	{
		string a = s.substr(level - i, i);
		string b = s.substr(level - i * 2, i);

		if (a == b)
		{
			s.pop_back();
			return; 
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		search(i+'0',level + 1);
	}
	s.pop_back();
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= 3; i++)
		search(i+'0',1);


}
