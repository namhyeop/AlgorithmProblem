#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;

	vector<double> v;
	double ret = 0;
	for (int i = 0; i < t; i++)
	{
		double tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	double maxValue = *max_element(v.begin(), v.end());
	
	vector<double> newv;
	for (auto i : v)
		ret += i / maxValue * 100;
	
	cout << ret / v.size() << "\n";
}
