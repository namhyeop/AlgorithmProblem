#include <bits/stdc++.h>

using namespace std;
const int MAX  = 1001;
int testcase;
int k, m, p;
int indegree[MAX];
vector<int> arr[MAX];
int prevarr[MAX], maxCnt[MAX];
void input(){
    cin >> k >> m >> p;

    for(int i = 1; i <= m; i++) {arr[i].clear(); indegree[i] = prevarr[i] = 0;};

    for(int i = 0; i < p; i++){
        int s, e; cin >> s >> e;
        arr[s].push_back(e);
        indegree[e]++;
    }
}

void pro(int tnum){
    queue<int> q;
    for(int i = 1; i <= m; i++){
        if(indegree[i] == 0) {
            q.push(i);
            prevarr[i] = 1;
            maxCnt[i] = 1;
        }
    }

    int ans = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(maxCnt[cur] >= 2) prevarr[cur]++;
        ans = max(ans, prevarr[cur]);
        for(int next : arr[cur]){
            indegree[next]--;
            if(indegree[next] == 0) {
                q.push(next);
            }
            if(prevarr[next] == prevarr[cur])
                maxCnt[next]++;
            else if(prevarr[next] < prevarr[cur]){
                prevarr[next] = prevarr[cur];
                maxCnt[next] = 1;
            }
        }
    }
    cout << tnum + 1 <<" " << ans <<"\n";
}
int main(){
    cin >> testcase;
    for(int t = 0; t < testcase; t++){
        input();
        pro(t);
    }
}