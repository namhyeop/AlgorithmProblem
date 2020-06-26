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
