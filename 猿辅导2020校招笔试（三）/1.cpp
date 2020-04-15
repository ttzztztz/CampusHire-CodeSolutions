#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
 
int N, M;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
 
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
 
bool pointValid(int i, int j) {
    return i >= 0 && j >= 0 && i < N && j < M;
}
 
void dfs(int i, int j, int dir) {
    cout << matrix[i][j] << " ";
    visited[i][j] = true;
 
    if (pointValid(i + dx[dir], j + dy[dir]) && !visited[i + dx[dir]][j + dy[dir]]) {
        visited[i + dx[dir]][j + dy[dir]] = true;
        dfs(i + dx[dir], j + dy[dir], dir);
    } else {
        for (int k = 1; k < 4; k++) {
            const int next_dir = (dir + k) % 4;
 
            const int nx = i + dx[next_dir], ny = j + dy[next_dir];
            if (pointValid(nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(nx, ny, next_dir);
                break;
            }
        }
    }
}
 
int main() {
    cin >> N >> M;
 
    matrix = vector<vector<int>>(N, vector<int>(M, 0));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
 
    dfs(0, 0, 0);
    cout << endl;
    return 0;
}