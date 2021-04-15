#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

string solution(string number, int k) {
	string answer = "";

	int idx = -1;
	for (int i = 0; i < number.size() - k; i++)
	{
		char maxAlpha = '0';
		for (int j = idx + 1; j <= i + k; j++)
		{
			if (maxAlpha < number[j])
			{
				maxAlpha = number[j];
				idx = j;
			}
		}
		answer += maxAlpha;
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string test = "1231234";
	int k = 3;

	string ret = solution(test, k);
	cout << ret << "\n";
}
