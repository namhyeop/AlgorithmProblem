#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;

string s;
string tmp;

bool isValid(string &s)
{
	return equal(s.begin(), s.end(), s.rbegin());
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int Testcase;
	cin >> Testcase;

	while (Testcase--)
	{
		cin >> s;
		bool palinFlag = true;
	
		bool flag = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != 'a')
			{
				flag = true;
				break;
			}
		}

		if (flag == false)
		{
			cout << "NO" << "\n";
			continue;
		}

		//맨앞 예외처리
		tmp.clear();
		tmp += s;
		tmp += 'a';
		if (isValid(tmp) == false)
		{
			cout << "YES" << "\n";
			cout << tmp << "\n";
			palinFlag = false;
		}
		if (palinFlag == false)
			continue;
		
		for (int i = 0; i <= s.length(); i++)
		{
			string tmp = s.substr(0, i) + 'a' + s.substr(i, s.length());
			cout << s.substr(0, i) << " " << s.substr(i, s.length()) <<"\n";
			if (isValid(tmp) == false)
			{
				cout << "YES" << "\n";
				cout << tmp << "\n";
				palinFlag = false;
				break;
			}
		}

		if (palinFlag == false)
			continue;

		cout << "NO" << "\n";
	}
	return 0;
}

