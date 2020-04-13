#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
 
using namespace std;
 
int N;
vector<vector<int>> matrix;
vector<vector<int>> f;
 
int dfs(int u, int state) {
    if (state == (1 << N) - 1) return matrix[u][0];
    if (f[u][state] != -1) return f[u][state];
 
    int answer = numeric_limits<int>::max();
    for (int v = 0; v < N; v++) {
        if (!(state & (1 << v))) {
            answer = min(answer, matrix[u][v] + dfs(v, state | (1 << v)));
        }
    }
    return f[u][state] = answer;
}
 
int main() {
    cin >> N;
 
    matrix = vector<vector<int>>(N + 5, vector<int>(N + 5, 0));
    f = vector<vector<int>>(N + 1, vector<int>((1 << N) + 5, -1));
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
 
    cout << dfs(0, 1) << endl;
    return 0;
}