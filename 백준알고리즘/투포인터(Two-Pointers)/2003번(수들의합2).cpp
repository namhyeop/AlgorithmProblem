//#include<bits/stdc++.h>
//#define MAX 10001
//using namespace std;
//
//int n;
//int m;
//int arr[MAX];
//
//int main(int argc, char *argv[])
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//
//	int ret = 0;
//	int sum = 0;
//	int low = 0;
//	int high = 0;
//
//	while (1)
//	{
//		if (sum >= m)
//		{
//			sum -= arr[low];
//			low++;
//		}
//		else if (high == n)
//		{
//			break;
//		}
//		else
//		{
//			sum += arr[high];
//			high++;
//		}
//
//		if (sum == m)
//			ret++;
//	}
//
//	cout << ret << "\n";
//
//	return 0;
//}
//

#include <bits/stdc++.h>

using namespace std;
const int MAX = 10001;
int n, m;
int arr[MAX];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int ans = 0;
    int sum = 0;

    int r = 0;
    for(int l = 1; l <= n; l++){
        sum -= arr[l - 1];
        cout << sum <<"\n";
        while(r + 1 <= n && sum < m) {
            sum += arr[++r];
        }
        if(sum == m) {
            ans++;
        }
    }
    cout << ans <<"\n";
}