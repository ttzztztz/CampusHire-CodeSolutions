#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <climits>
 
using namespace std;
 
int N;
vector<int> f;
vector<int> available;
 
int dfs(int u) {
    if (u == 0) return 0;
    if (u < 0) return 99999999;
    if (f[u] != -1) return f[u];
 
    int answer = 99999999;
    for (int v: available) {
        if (u >= v) answer = min(answer, 1 + dfs(u - v));
    }
    return f[u] = answer;
}
 
int main() {
    cin >> N;
    const int willCharge = 1024 - N;
    f = vector<int>(willCharge + 5, -1);
    available = {1, 4, 16, 64};
 
    cout << dfs(willCharge) << endl;
    return 0;
}