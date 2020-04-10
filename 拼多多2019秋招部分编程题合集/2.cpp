#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
int N, total;
vector<int> allTree;
vector<int> answer;
 
bool dfs(int i, int last) {
    if (i == total) return true;
 
    const int rest = total - i;
    for (int j = 0; j < N; j++) {
        if (rest % 2 == 0 && allTree[j] * 2 > rest) {
            return false;
        }
        if (rest % 2 == 1 && allTree[j] * 2 > rest + 1) {
            return false;
        }
    }
 
    for (int j = 0; j < N; j++) {
        if (last == j || allTree[j] == 0) continue;
 
        allTree[j]--;
        answer.push_back(j);
        if (dfs(i + 1, j)) return true;
        answer.pop_back();
        allTree[j]++;
    }
 
    return false;
}
 
int main() {
    cin >> N;
    allTree.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> allTree[i];
        total += allTree[i];
    }
 
    dfs(0, -1);
    if (answer.empty()) cout << "-" << endl;
    else {
        for (int i : answer) cout << (i + 1) << " ";
        cout << endl;
    }
    return 0;
}