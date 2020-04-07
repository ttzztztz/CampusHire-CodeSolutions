#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
vector<int> company, exercise;
vector<vector<int>> f;
int N;
 
const int Rest = 0, Exercise = 1, Work = 2;
 
int dfs(int i, int last) {
    if (i == N) return 0;
    if (f[i][last] != -1) return f[i][last];
 
    int answer = 99999999;
    if (company[i] && last != Work) {
        answer = min(answer, dfs(i + 1, Work));
    }
    if (exercise[i] && last != Exercise) {
        answer = min(answer, dfs(i + 1, Exercise));
    }
    answer = min(answer, 1 + dfs(i + 1, Rest));
    return f[i][last] = answer;
}
 
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        company.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        exercise.push_back(tmp);
    }
    f = vector<vector<int>>(N + 1, vector<int>(3, -1));
    cout << dfs(0, Rest) << endl;
    return 0;
}
