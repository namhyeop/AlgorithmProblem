#include<bits/stdc++.h>

using namespace std;
const int MAX = 3;

struct cube {
    int t1, t2;
    char board[6][MAX][MAX];

    cube() : board{} {}

    struct info {
        int face;
        int y;
        int x;
    };

    void init() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> board[4][i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 4; k++) {
                for (int j = 0; j < 3; j++) {
                    cin >> board[k][i][j];
                }
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> board[5][i][j];
            }
        }
    }

    void Swap(info a, info b, info c, info d) {
        int tmp = board[a.face][a.y][a.x];
        board[a.face][a.y][a.x] = board[b.face][b.y][b.x];
        board[b.face][b.y][b.x] = board[c.face][c.y][c.x];
        board[c.face][c.y][c.x] = board[d.face][d.y][d.x];
        board[d.face][d.y][d.x] = tmp;
    }

    void Rotate(const int face, const int dir) {
        if (face == 1) {
            dir == 1 ? clockwise(face, dir) : counterClockwise(face, dir);
            if (dir == 1) {
                Swap({4, 2, 0}, {0, 2, 2}, {5, 0, 2}, {2, 0, 0});
                Swap({4, 2, 1}, {0, 1, 2}, {5, 0, 1}, {2, 1, 0});
                Swap({4, 2, 2}, {0, 0, 2}, {5, 0, 0}, {2, 2, 0});
            } else {
                Swap({4, 2, 0}, {2, 0, 0}, {5, 0, 2}, {0, 2, 2});
                Swap({4, 2, 1}, {2, 1, 0}, {5, 0, 1}, {0, 1, 2});
                Swap({4, 2, 2}, {2, 2, 0}, {5, 0, 0}, {0, 0, 2});
            }
        } else if (face == 0) {
            dir == 1 ? clockwise(face, dir) : counterClockwise(face, dir);
            if (dir == 1) {
                Swap({ 4, 0, 0 }, { 3, 2, 2 }, { 5, 0, 0 }, { 1, 0, 0 });
                Swap({ 4, 1, 0 }, { 3, 1, 2 }, { 5, 1, 0 }, { 1, 1, 0 });
                Swap({ 4, 2, 0 }, { 3, 0, 2 }, { 5, 2, 0 }, { 1, 2, 0 });
            }
            else {
                Swap({ 4, 0, 0 }, { 1, 0, 0 }, { 5, 0, 0 }, { 3, 2, 2 });
                Swap({ 4, 1, 0 }, { 1, 1, 0 }, { 5, 1, 0 }, { 3, 1, 2 });
                Swap({ 4, 2, 0 }, { 1, 2, 0 }, { 5, 2, 0 }, { 3, 0, 2 });
            }

        } else if (face == 2) {
            dir == 1 ? clockwise(face, dir) : counterClockwise(face, dir);
            if (dir == 1) {
                Swap({ 4, 0, 2 }, { 1, 0, 2 }, { 5, 0, 2 }, { 3, 2, 0 });
                Swap({ 4, 1, 2 }, { 1, 1, 2 }, { 5, 1, 2 }, { 3, 1, 0 });
                Swap({ 4, 2, 2 }, { 1, 2, 2 }, { 5, 2, 2 }, { 3, 0, 0 });
            }
            else {
                Swap({ 4, 0, 2 }, { 3, 2, 0 }, { 5, 0, 2 }, { 1, 0, 2 });
                Swap({ 4, 1, 2 }, { 3, 1, 0 }, { 5, 1, 2 }, { 1, 1, 2 });
                Swap({ 4, 2, 2 }, { 3, 0, 0 }, { 5, 2, 2 }, { 1, 2, 2 });
            }

        } else if (face == 3) {
            dir == 1 ? clockwise(face, dir) : counterClockwise(face, dir);
            if (dir == 1) {
                Swap({ 4, 0, 0 }, { 2, 0, 2 }, { 5, 2, 2 }, { 0, 2, 0 });
                Swap({ 4, 0, 1 }, { 2, 1, 2 }, { 5, 2, 1 }, { 0, 1, 0 });
                Swap({ 4, 0, 2 }, { 2, 2, 2 }, { 5, 2, 0 }, { 0, 0, 0 });
            }
            else {
                Swap({ 4, 0, 0 }, { 0, 2, 0 }, { 5, 2, 2 }, { 2, 0, 2 });
                Swap({ 4, 0, 1 }, { 0, 1, 0 }, { 5, 2, 1 }, { 2, 1, 2 });
                Swap({ 4, 0, 2 }, { 0, 0, 0 }, { 5, 2, 0 }, { 2, 2, 2 });
            }

        } else if (face == 4) {
            dir == 1 ? clockwise(face, dir) : counterClockwise(face, dir);
            if (dir == 1) {
                Swap({ 0, 0, 0 }, { 1, 0, 0 }, { 2, 0, 0 }, { 3, 0, 0 });
                Swap({ 0, 0, 1 }, { 1, 0, 1 }, { 2, 0, 1 }, { 3, 0, 1 });
                Swap({ 0, 0, 2 }, { 1, 0, 2 }, { 2, 0, 2 }, { 3, 0, 2 });
            }
            else {
                Swap({ 0, 0, 0 }, { 3, 0, 0 }, { 2, 0, 0 }, { 1, 0, 0 });
                Swap({ 0, 0, 1 }, { 3, 0, 1 }, { 2, 0, 1 }, { 1, 0, 1 });
                Swap({ 0, 0, 2 }, { 3, 0, 2 }, { 2, 0, 2 }, { 1, 0, 2 });
            }
        } else if (face == 5) {
            dir == 1 ? clockwise(face, dir) : counterClockwise(face, dir);
            if (dir == 1) {
                Swap({ 0, 2, 0 }, { 3, 2, 0 }, { 2, 2, 0 }, { 1, 2, 0 });
                Swap({ 0, 2, 1 }, { 3, 2, 1 }, { 2, 2, 1 }, { 1, 2, 1 });
                Swap({ 0, 2, 2 }, { 3, 2, 2 }, { 2, 2, 2 }, { 1, 2, 2 });
            }
            else {
                Swap({ 0, 2, 0 }, { 1, 2, 0 }, { 2, 2, 0 }, { 3, 2, 0 });
                Swap({ 0, 2, 1 }, { 1, 2, 1 }, { 2, 2, 1 }, { 3, 2, 1 });
                Swap({ 0, 2, 2 }, { 1, 2, 2 }, { 2, 2, 2 }, { 3, 2, 2 });
            }
        }
    }

    void clockwise(const int face, const int dir) {
        int tmpboard[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmpboard[i][j] = board[face][i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[face][j][3 - i - 1] = tmpboard[i][j];
            }
        }
    }

    void counterClockwise(const int face, const int dir) {
        int tmpboard[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmpboard[i][j] = board[face][i][j];
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[face][i][j] = tmpboard[j][3 - i - 1];
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    for (int t = 1; t <= n; t++) {
        cube c;
        c.init();
        int cmd;
        cin >> cmd;
        for (int i = 0; i < cmd; i++) {
            int face, dir;
            cin >> face >> dir;
            c.Rotate(face, dir);
        }
        cout << "Scenario #" << t <<":" << "\n";
        for (int i = 0; i < 3; i++) {
            cout << "      ";
            for (int j = 0; j < 3; j++) {
                cout << c.board[4][i][j] << " ";
            }
            cout << "\n";
        }
        for (int i = 0; i < 3; i++) {
            for (int k = 0; k < 4; k++) {
                for (int j = 0; j < 3; j++) {
                    cout << c.board[k][i][j] << " ";
                }
            }
            cout << "\n";
        }
        for (int i = 0; i < 3; i++) {
            cout << "      ";
            for (int j = 0; j < 3; j++) {
                cout << c.board[5][i][j] << " ";
            }
            cout << "\n";
        }
        cout <<"\n";
    }
}