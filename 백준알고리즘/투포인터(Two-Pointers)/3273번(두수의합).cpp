//#include<bits/stdc++.h>
//
//using namespace std;
//
//int n;
//int m;
//vector<int> v;
//int ret = 0;
//
//int main()
//{
//	cin >> n;
//	v.resize(n);
//
//	for (int i = 0; i < n; i++)
//		cin >> v[i];
//
//	cin >> m;
//	sort(v.begin(), v.end());
//
//	int left = 0;
//	int right = n - 1;
//
//	while (1)
//	{
//		if (left >= right)
//			break;
//		if (v[left] + v[right] == m)
//		{
//			left++;
//			right--;
//			ret++;
//		}
//		else if (v[left] + v[right] > m)
//			right--;
//		else
//			left++;
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e5 + 1;
int n, x;
int arr[MAX];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cin >> x;
    sort(arr + 1, arr + n + 1);
    int cnt = 0;

    for(int l = 1, r = n; l < r;){
        if(arr[l] + arr[r] > x){
            r--;
        }else if(arr[l] + arr[r] == x){
            cnt++;
            l++;
        }else{
            l++;
        }
//        cout << l <<" " <<r <<"\n";
    }
    cout << cnt <<"\n";
}
