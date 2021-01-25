#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int dp[5001][5001];

int main(int argc, char *argv[])
{
	int n;
	string str;
	string reverseStr;

	cin >> n >> str;

	//펠린드롬의 특성상 주어진 스트링과  이 스트링을 뒤집은 스트링이 있다면
	//두 스트링의 공통된 최장 부분문자열의 길이를 알고 있따면 답을 구할 수 있다.
	reverseStr = str;
	reverse(reverseStr.begin(), reverseStr.end());

	int len = str.length();

	for (int i = 0; i < len; i++)
	{
		for (int k = 0; k < len; k++)
		{
			if (str[i] == reverseStr[k])
			{
				dp[i + 1][k + 1] = dp[i][k] + 1;
			//	cout << dp[i + 1][k + 1] << " " << i << " " << k << "\n";
			}
			else
				dp[i + 1][k + 1] = max(dp[i + 1][k], dp[i][k + 1]);
			/*디버깅작업
			cout << i << " " << k << "\n";
			for (int i = 0; i < len+1; i++)
			{
				for (int k = 0; k < len+1; k++)
					cout << dp[i][k] << " ";
				cout << "\n";
			}*/
		}
		//cout << "\n";
	}

	cout << n - dp[len][len];

	return 0;
}
