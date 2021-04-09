#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int ret[3];
vector<int> solution(vector<int> answers)
{
	vector<int> answer;
	vector<int> arr[3];
	arr[0] = { 1, 2, 3, 4, 5 };
	arr[1] = { 2, 1, 2, 3, 2, 4, 2, 5 };
	arr[2] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0, k = 0; j < answers.size(); j++,k++)
		{
			if (k == arr[i].size())
				k = 0;

			if (answers[j] == arr[i][k])
				ret[i]++;
		}

		if (answer.empty())
			answer.push_back(i + 1);
		else if (ret[i] > ret[answer.front() -1])
		{
			answer.pop_back();
			answer.push_back(i + 1);
		}
		else if (ret[i] == ret[answer.front() - 1])
			answer.push_back(i + 1);
	}
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> answers;
	answers.push_back(1);
	answers.push_back(3);
	answers.push_back(2);
	answers.push_back(4);
	answers.push_back(2);

	vector<int> ret = solution(answers);
	
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}
