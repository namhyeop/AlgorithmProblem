#include<bits/stdc++.h>

using namespace std;
const int MAX = 10001;
int n;
int proTime[MAX], indegree[MAX], ret[MAX];
vector<int> arr[MAX];

void input(){
    cin >> n;
    for(int t = 1; t<=n; t++){
        int time, task; cin >> time >> task;
        proTime[t] = time;
        for(int i  = 0; i < task; i++){
            int u; cin >> u;
            arr[u].push_back(t);
            indegree[t]++;
        }
    }
}

void pro(){
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indegree[i] == 0){
            q.push(i);
            ret[i] = proTime[i];
        }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int next : arr[cur]){
            indegree[next]--;
            ret[next] = max(ret[next], ret[cur] + proTime[next]);
            if(indegree[next] == 0) {
                q.push(next);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i<= n; i++)
        ans = max(ret[i], ans);
    cout << ans <<"\n";
}
int main(){
    input();
    pro();
}