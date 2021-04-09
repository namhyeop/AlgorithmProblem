//#include<bits/stdc++.h>
//#define pill pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define ll long long
//
//using namespace std;
//const int MAX = 1e6 + 1;
//int n;
//int arr[MAX];
//int main(void)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//	vector<int> list; //Active list의 마지막 숫자의 값만 가지고 있는 배열
//	for (int i = 0; i < n; i++)
//	{
//		auto& a = arr[i];
//
//		if (list.size() == 0)
//			list.push_back(a);
//		else if (a < list[0])
//			list[0] = a;
//		else if (a > list.back())
//			list.push_back(a);
//		else
//		{
//			auto it = upper_bound(list.begin(), list.end(), a - 1);
//			*it = a;
//		}
//	}
//
//	cout << list.size() << "\n";
//
//	return 0;
//}
