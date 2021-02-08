#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	int Testcase;
	cin >> Testcase;

	for (int t = 0; t < Testcase; t++)
	{
		string s;
		cin >> s;

		int result = 0;

		int i = 0;
		int j = s.length() - 1;
		while (i < j)
		{
			if (s[i] == s[j]) //틀리지 않는 부분까지 반복
			{
				i++;
				j--;
				continue;
			}

			if (s[i + 1] != s[j] && s[i] != s[j - 1]) //틀린 부분에서 한 칸 앞에 인덱스와도 같지 않다면 펠린드롬이 X
			{
				result = 2;
				break;
			}

			int k = 0;
			bool validPalin = false;
			while (k < 2 && validPalin == false) //세미펠린드롬인지 확인하는 구문
			{
				int start = i;
				int end = j;
				k == 0 ? start++ : end--;

				validPalin = true;
				
				int a = start;
				int b = end;
				while (a < b)
				{
					if (s[a] != s[b])
					{
						validPalin = false;
						break;
					}
					a++;
					b--;
				}
				k++;
			}

			if (validPalin)
				result = 1;
			else
				result = 2;

			break;
			i++;
			j--;
		}
		cout << result << "\n";
	}
	return 0;
}
