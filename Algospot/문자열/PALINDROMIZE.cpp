#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<int> getPartialMatch(const string &N)
{
	int m = N.size();
	vector<int> pi(m, 0);
	//KMP로 자기 자신을 찾는다
	//N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니까 안됨!
	int begin = 1, matched = 0;
	//비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분일치 모두 기록한다.
	while (begin + matched < m)
	{
		if (N[begin + matched] == N[matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		//일치하지 않고
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

//a의 접미사이면서 b의 접두사인 문자열의 최대 길이를 구한다
int maxOverlap(const string &a, const string &b)
{
	int n = a.size(), m = b.size();
	//reverse input에 대해서 getPartialMatch를 실행
	vector<int> pi = getPartialMatch(b);
	//begin=mathced=0에서부터 시작
	int begin = 0, matched = 0;

	while (begin < n)
	{
		//만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
		if (matched < m && a[begin + matched] == b[matched])
		{
			++matched;
			if (begin + matched == n)
				return matched;
		}
		//글자가 같지 않으면 getPartialMatch와 동일하게
		else
		{
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return 0;
}

int main(int argc, char * argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		string input;
		cin >> input;
		string reverse_input = input;
		reverse(reverse_input.begin(), reverse_input.end());

		int result = input.length() * 2 - maxOverlap(input, reverse_input);
		
		cout << result << endl;
	}
	return 0;
}
