#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
char grid[105][105];
int f[105][105][2];

const int dx[] = {0, 1};
const int dy[] = {1, 0};

bool pointValid(int i, int j) {
    return i >= 0 && j >= 0 && i < N && j < M;
}

// 0 -> right, 1 -> bottom
int dfs(int i, int j, int dir) {
    if (i == N - 1 && j == M - 1) return 0;
    if (!pointValid(i, j)) return 99999999;
    if (f[i][j][dir] != -1) return f[i][j][dir];

    int answer = 99999999;

    const int nx = i + dx[dir], ny = j + dy[dir];
    const int rx = i + dx[dir ^ 1], ry = j + dy[dir ^ 1];

    if (pointValid(nx, ny)) {
        if (grid[nx][ny] == '.') {
            answer = min(answer, dfs(nx, ny, dir));
            if (pointValid(rx, ry)) {
                if (grid[rx][ry] == '.') {
                    answer = min(answer, 1 + dfs(rx, ry, dir ^ 1));
                } else {
                    answer = min(answer, 2 + dfs(rx, ry, dir ^ 1));
                }
            }
        } else {
            answer = min(answer, 1 + dfs(nx, ny, dir));

            if (pointValid(rx, ry)) {
                if (grid[rx][ry] == '.') {
                    answer = min(answer, dfs(rx, ry, dir ^ 1));
                } else {
                    answer = min(answer, 1 + dfs(rx, ry, dir ^ 1));
                }
            }
        }
    } else if (pointValid(rx, ry)) {
        if (grid[rx][ry] == '.') {
            answer = min(answer, dfs(rx, ry, dir ^ 1));
        } else {
            answer = min(answer, 1 + dfs(rx, ry, dir ^ 1));
        }
    }

    return f[i][j][dir] = answer;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    memset(f, 0xff, sizeof f);

    int extra = 0;
    if (grid[0][0] == 'b') {
        grid[0][0] = '.';
        extra = 1;
    }
    cout << extra + dfs(0, 0, 0) << endl;
    return 0;
}