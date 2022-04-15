#include <bits/stdc++.h>

using namespace std;
const int MAX = 205;

struct State{
    int X[3];
    State(int x, int y, int z){
        X[0] = x, X[1] = y, X[2] = z;
    }
    State(int tmpX[]){
        for(int i = 0; i < 3; i++){
            X[i] = tmpX[i];
        }
    }
    State move(int from, int to, int Limit[]){
        State res(X);
        if(X[from] + X[to] <= Limit[to]){
            res.X[to] = res.X[from] + res.X[to];
            res.X[from] = 0;
        }else{
            res.X[from] -= Limit[to] - res.X[to];
            res.X[to] = Limit[to];
        }
        return res;
    }
};

bool possible[MAX];
bool visited[MAX][MAX][MAX];
int Limit[3];
queue<State> q;

bool isVisited(State s) {return visited[s.X[0]][s.X[1]][s.X[2]];}
void checkVisited(State s) {visited[s.X[0]][s.X[1]][s.X[2]] = true;}
void pro(){
    q.push(State(0,0,Limit[2]));
    checkVisited(State(0,0,Limit[2]));

    while(!q.empty()){
        State cur = q.front();
        q.pop();
        if(cur.X[0] == 0)
            possible[cur.X[2]] = true;
        for(int from = 0; from < 3; from++){
            for(int to = 0; to < 3; to++){
                if(from == to)
                    continue;
                State nxt = cur.move(from, to, Limit);
                if(isVisited(nxt)){
                    continue;
                }
                checkVisited(nxt);
                q.push(nxt);
            }
        }
    }
    for(int i = 0; i <= 200; i++){
        if(possible[i])
            cout << i <<" ";
    }
}

void input(){
    cin >> Limit[0] >> Limit[1] >> Limit[2];
}

int main(){
    input();
    pro();
}