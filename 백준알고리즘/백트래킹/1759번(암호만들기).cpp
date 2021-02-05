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
