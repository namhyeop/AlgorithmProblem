#include<iostream>
#include<string>
#include<vector>

using namespace std;

string text;
string pattern;
vector<int> getPartialMatch(const string & N)
{
	int m = N.size();
	vector<int> pi(m, 0);
	//kmp로 자기 자신을 찾는다.
	//N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니까 1로 설정해줌
	int begin = 1, matched = 0;
	//비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록한다.
	while (begin + matched < m)
	{
		if (N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
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

//H는 text를 의미하고 N은 pattern을 의미하며 text에서 pattern이 존재하는지 찾을거임
vector<int> kmpSearch(const string& H, const string& N)
{
	int n = H.size(), m = N.size();
	vector<int> ret;
	vector<int> pi = getPartialMatch(N);

	int matched = 0;
	//만약 H가 가 N의 글자와 같다면
	for (int i = 0; i < n; i++)
	{
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched - 1];

		if (H[i] == N[matched])
		{
			matched++;
			if (matched == m)
			{
				ret.push_back(i - m + 2);
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}


int main(int argc, char * argv[])
{
	

	getline(cin,text);
	getline(cin, pattern);

	vector<int> ret = kmpSearch(text, pattern);

	cout << ret.size() << "\n";
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << "\n";

	return 0;
}
