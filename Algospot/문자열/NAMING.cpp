#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> getPartialMatch(const string &N)
{
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;

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
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
//s의 접두사도 되고 접미사도 되는 문자열들의 길이를 반환한다.
vector<int> getPrefixSuffix(const string& s)
{
	vector<int> ret, pi = getPartialMatch(s);
	int k = s.size();
	while (k > 0)
	{
		ret.push_back(k);
		k = pi[k - 1];
	}
	return ret;
}

int main(int argc, char*argv[])
{
	string father;
	string mother;

	cin >> father;
	cin >> mother;
	string sum = father + mother;

	vector<int> ret = getPrefixSuffix(sum);
	
	for (int i = ret.size()-1; i >= 0; i--)
		cout << ret[i] << " ";
	cout << endl;
	return 0;
}
