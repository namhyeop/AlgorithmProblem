#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(int argc, char * argv[])
{
	int Testcase;
	int scope;
	queue<int> q[21];
	long long count = 0;
	cin >> Testcase;
	cin >> scope;
	for (int i = 0; i < Testcase; i++)
	{
		string name;
		cin >> name;
		int length = name.size();

		while(!q[length].empty() && i - q[length].front() > scope) //i == 내가 넣을려는 이름의 현재 위치
			q[length].pop();

		count += q[length].size();
		q[length].push(i);
	}

	cout << count << endl;

	return 0;
}

/*시간 초과
int main(int argc, char * argv[])
{
	int Testcase;
	int scope;
	int count = 0;
	cin >> Testcase;
	cin >> scope;

	vector<pair<int,string>> v;
	for (int i = 0; i < Testcase; i++)
	{
		string name;
		cin >> name;
		v.push_back({ i, name });
	}

	for (int i = 0; i < Testcase; i++)
	for (int j = i + 1; (j <= i + scope) && (j < Testcase); j++)
	{
		if (v[i].second.size() == v[j].second.size())
			count++;
	}

	cout << count << endl;

	return 0;
	CYNTHIA
	CYNTHIA
	LLOYD
	STEVIE
	CYNTHIA
	CYNTHIA
	CYNTHIA
	}*/
