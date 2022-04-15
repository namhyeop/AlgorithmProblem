#include <bits/stdc++.h>

using namespace std;

int n, m;
bool visited[100001];

bool isValid(int x){
    if(x >= 0 && x < 100001)
        return true;
    return false;
}

int pro(){
    queue<pair<int,int>> q;
    q.push({n, 0});

    while(!q.empty()){
        int curPos = q.front().first;
        int cost = q.front().second;
        q.pop();

        if(curPos == m){
            return cost;
        }

        int nextWokrPos1 = curPos + 1;
        int nextWokrPos2 = curPos - 1;
        int nextTPos1 = curPos * 2;

        if(isValid(nextWokrPos1) && !visited[nextWokrPos1]){
            q.push({nextWokrPos1, cost + 1});
            visited[nextWokrPos1] = true;
        }
        if(isValid(nextWokrPos2) && !visited[nextWokrPos2]){
            q.push({nextWokrPos2, cost + 1});
            visited[nextWokrPos2] = true;
        }
        if(isValid(nextTPos1) && !visited[nextTPos1]){
            q.push({nextTPos1, cost + 1});
            visited[nextTPos1] = true;
        }
    }
}
void input(){
    cin >> n >> m;
}

int main(){
    input();
    int answer = pro();
    cout << answer <<"\n";
}

//#include<bits/stdc++.h>
//#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
//#define pill pair<int,int>
//#define mp(X,Y) make_pair(X,Y)
//#define mt(X,Y) make_tuple(X,Y)
//#define mtt(X,Y,Z) make_tuple(X,Y,Z)
//#define ll long long
//#define sz(v) (int)(v).size()
//
//using namespace std;
//const int MAX = 100000;
//int n, k;
//bool visited[MAX + 1];
//
//int main(void)
//{
//	fastio;
//	cin >> n >> k;
//
//	queue<pair<int, int>> q;
//	q.push({ n, 0 });
//	visited[n] = true;
//	int minTime = INT_MIN;
//	int retcnt = 0;
//	while (!q.empty())
//	{
//		int cur = q.front().first;
//		int cnt = q.front().second;
//		q.pop();
//
//		visited[cur] = true;
//		if (cur == k)
//		{
//			if (minTime == INT_MIN)
//			{
//				minTime = cnt;
//				retcnt++;
//			}
//			else if(minTime == cnt)
//				retcnt++;
//			visited[cur] = false;
//			continue;
//		}
//
//		if (cur - 1 >= 0 && cur - 1 <= MAX && !visited[cur - 1])
//		{
//			q.push({ cur - 1, cnt + 1 });
//		}
//
//		if (cur + 1 >= 0 && cur + 1 <= MAX && !visited[cur + 1])
//		{
//			q.push({ cur + 1, cnt + 1 });
//		}
//		if (cur * 2 >= 0 && cur * 2 <= MAX && !visited[cur * 2])
//		{
//			q.push({ cur * 2, cnt + 1 });
//		}
//	}
//
//	cout << minTime << "\n";
//	cout << retcnt << "\n";
//}
