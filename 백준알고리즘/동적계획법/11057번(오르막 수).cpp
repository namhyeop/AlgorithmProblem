#include <bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int n;
int cache[MAX][MAX];
const int mod = 10007;
void input(){
    cin >> n;
}

void pro(){
    for(int i = 0; i <= 9; i++) cache[1][i] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= j; k++) {
                cache[i][j] += cache[i - 1][k];
                cache[i][j] %= mod;
            }
        }
    }

//    for(int i = 1; i <= n; i++){
//        for(int j = 0; j <= 9; j++){
//            cout << cache[i][j] <<" ";
//        }
//        cout <<"\n";
//    }
    int ret = 0;
    for(int i = 0; i <= 9; i++){
        ret += cache[n][i];
        ret %= mod;
    }
    cout << ret <<"\n";
}

int main(){
    input();
    pro();
}

///*
//길이가 i이고 첫 번째 자리의 수가 j인 갯수의 오르막 수를 저장하는 배열을 선언하고
//자리가 올라갈수록 cache[i -1][k]의 갯수만큼 더해준다.
//
//1,1,1,1,1,1,1,1,1,1
//10,9,8,7,6,5,4,3,2,1
//55,45,36,28,21,15,10,6,3,1
//..........................
//순으로 k의 범위만큼 더해주는 식을 찾아야 한다.
//*/
//
//#include<bits/stdc++.h>
//
//using namespace std;
//const int MAX = 1001;
//
//int cache[MAX][10];
//int n;
//int ret;
//
//int main()
//{
//	cin >> n;
//
//	for (int i = 0; i < 10; i++)
//		cache[1][i] = 1;
//
//	for (int i = 2; i <= n; i++)
//	for (int j = 0; j < 10; j++)
//	for (int k = j; k < 10; k++)
//	{
//		cache[i][j] = (cache[i][j] + cache[i - 1][k]) % 10007;
//	}
//
//	for (int i = 0; i < 10; i++)
//		ret = (ret + cache[n][i]) % 10007;
//
//	cout << ret << "\n";
//
//	return 0;
//}
/*
#include<iostream>
#include<cstring>

using namespace std;

int mod = 10007;
int cache[1001][10];
//i = 열의 위치 ex: cache[n][i] n행 i열의 배열을 채우겠다.
int write(int n, int i)
{
	int &ret = cache[n][i];
	
	if (ret != -1)
		return ret;

	ret = 0;

	for (int nexti = i; nexti < 10; nexti++)
		ret += write(n - 1, nexti) % mod;

	return ret;
}

int main(int argc, char*argv[])
{
	int n;
	int sum = 0;
	cin >> n;

	memset(cache, -1, sizeof(cache));

	for (int i = 0; i < 10; i++)
		cache[1][i] = 1;

	for (int i = 0; i < 10; i++)
		write(n, i);

	for (int i = 0; i < 10; i++)
		sum = (sum + cache[n][i]) % mod;

	cout << sum << endl;
	
	return 0;
}
*/
