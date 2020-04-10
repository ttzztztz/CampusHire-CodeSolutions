#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <unordered_map>
 
using namespace std;
 
typedef pair<double, double> PDD;
vector<int> parent;
double d;
int N;
 
void init() {
    parent = vector<int>(N + 1);
    for (int i = 0; i <= N; i++) parent[i] = i;
}
 
int findParent(int u) {
    if (u == parent[u]) {
        return u;
    } else {
        return parent[u] = findParent(parent[u]);
    }
}
 
double distSquare(PDD& $1, PDD& $2) {
    return ($1.first - $2.first) * ($1.first - $2.first) + ($1.second - $2.second) * ($1.second - $2.second);
}
 
void merge(int u, int v) {
    const int pU = findParent(u), pV = findParent(v);
    if (pU != pV) {
        parent[pU] = pV;
    }
}
 
int main() {
    cin >> d >> N;
    d *= d;
 
    init();
    vector<PDD> all;
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        all.emplace_back(x, y);
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double dist = distSquare(all[i], all[j]);
            if (dist - d <= 1e-6) {
                merge(i, j);
            }
        }
    }
 
    vector<vector<int>> answer;
    unordered_map<int, int> groupToIndex;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        const int p = findParent(i);
        if (!groupToIndex.count(p)) {
            groupToIndex[p] = cnt++;
            answer.emplace_back();
        }
 
        answer[groupToIndex[p]].push_back(i);
    }
 
    cout << "[";
    for (int i = 0; i < answer.size(); i++) {
        cout << "[";
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j];
 
            if (j != answer[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i != answer.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}