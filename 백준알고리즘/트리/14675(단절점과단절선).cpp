//#include<bits/stdc++.h>
//using namespace std;
//
//const int MAX = 1e5 + 1;
//int N;
//vector<int> v[MAX];
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//
//	cin >> N;
//	for (int i = 1; i < N; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		
//		v[a].push_back(b);
//		v[b].push_back(a);
//	}
//	
//	int query;
//	cin >> query;
//
//	while (query--)
//	{
//		int a, b;
//		cin >> a >> b;
//
//		if (a == 1)
//		{
//			if (v[b].size() >= 2)
//				cout << "yes" << "\n";
//			else
//				cout << "no" << "\n";
//		}
//		else
//			cout << "yes" << "\n";
//	}
//
//	return 0;
//}
