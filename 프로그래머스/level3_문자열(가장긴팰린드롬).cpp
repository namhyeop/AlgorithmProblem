#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int solution(string s)
{
	int answer = 1;

	for (int i = 1; i <= s.size(); i++)
	{
		int left = i - 1, right = i + 1;
		int evenRet = 0, oddRet = 1;

		bool flag1 = false, flag2 =false;
		while (left >= 0 && right <= s.size())
		{
			if (s[left] == s[right - 1])
				evenRet += 2;
			else
				flag1 = true;

			if (s[left--] == s[right++])
				oddRet += 2;
			else
				flag2 = true;

			if (flag1 && flag2)
				break;
		}

		int ret = evenRet > oddRet ? evenRet : oddRet;
		
		if (answer < ret)
			answer = ret;
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cout << solution("abaabc") << "\n";
	//cout << solution("abacde") << "\n";
}
