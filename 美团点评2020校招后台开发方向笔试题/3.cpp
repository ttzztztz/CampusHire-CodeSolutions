#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits>
 
using namespace std;
 
int N;
double matrix[20][20];
double f[15][(1 << 13) + 5];
bool used[15][(1 << 13) + 5];
 
double dfs(int i, int state) {
    if (i == N) return f[i][state] = 0.0;
    if (used[i][state]) return f[i][state];
 
    double answer = -9999999.0;
    for (int j = 0; j < N; j++) {
        if (!(state & (1 << j))) {
            answer = max(answer, matrix[i][j] + dfs(i + 1, state | (1 << j)));
        }
    }
 
    used[i][state] = true;
    return f[i][state] = answer;
}
 
vector<int> answer;
 
bool dfs2(int i, int state) {
    if (i == N) return true;
 
    for (int j = 0; j < N; j++) {
        if (!(state & (1 << j)) && f[i][state] == f[i + 1][state | (1 << j)] + matrix[i][j]) {
            answer.push_back(j);
            if (dfs2(i + 1, state | 1 << j)) return true;
            answer.pop_back();
        }
    }
 
    return false;
}
 
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
 
    printf("%.2f\n", dfs(0, 0));
 
    dfs2(0, 0);
    for (int i = 0; i < answer.size(); i++) {
        cout << (i + 1) << " " << (answer[i] + 1) << endl;
    }
    return 0;
}