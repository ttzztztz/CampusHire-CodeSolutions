#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
int f[25][25];
string P, T;
int N, M;
 
int dfs(int i, int j) {
    if (i == N) return j >= M;
    if (j == M) return i >= N;
    if (f[i][j] != -1) return f[i][j];
 
    int isMatch = 0;
    if (P[i] == '*') {
        isMatch |= dfs(i + 1, j);
        isMatch |= dfs(i, j + 1);
        isMatch |= dfs(i + 1, j + 1);
    } else {
        if (P[i] == '?' || P[i] == T[j]) {
            isMatch = dfs(i + 1, j + 1);
        }
    }
    return f[i][j] = isMatch;
}
 
int main() {
    memset(f, 0xff, sizeof(f));
    cin >> P >> T;
    N = P.size(), M = T.size();
 
    if (dfs(0, 0)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}