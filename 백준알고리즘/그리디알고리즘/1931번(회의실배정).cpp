#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;

pair<int,int> arr[MAX];
int n;

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].second >> arr[i].first;

	sort(arr, arr + n);

	int ret = 0;
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		if (cur > arr[i].second)
			continue;

		ret++;
		cur = arr[i].first;
	}
	
	cout << ret << "\n";

	return 0;
}

/*
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct table{
	int startValue;
	int finishValue;
};

bool cmp(table f, table s)
{
	if (f.finishValue == s.finishValue)
		return f.startValue < s.startValue;
	else
		return f.finishValue < s.finishValue;
}

int main(int argc, char *argv[])
{	
	int maxTimeTable;
	cin >> maxTimeTable;
	
	vector<table>t(maxTimeTable);
	for (int i = 0; i < maxTimeTable; i++)
	{
		cin >> t[i].startValue >> t[i].finishValue;
	}
	
	sort(t.begin(), t.end(), cmp);
	
	//for (int i = 0; i < maxTimeTable; i++)
	//cout << t[i].startValue <<" "<< t[i].finishValue  << endl;

	int count = 0;
	int now = 0;

	for (int i = 0; i < t.size(); i++)
	{
		if (now <= t[i].startValue)
		{
			now = t[i].finishValue;
			count++;
		}

	}

	cout << count;

}
*/
