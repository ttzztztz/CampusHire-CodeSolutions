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

typedef pair<int, int> PII;
vector<PII> pos = {
        {4, 2},
        {1, 1},
        {1, 2},
        {1, 3},
        {2, 1},
        {2, 2},
        {2, 3},
        {3, 1},
        {3, 2},
        {3, 3}
};

bool canReach(int i, int j) {
    const int iX = pos[i].first, iY = pos[i].second;
    const int jX = pos[j].first, jY = pos[j].second;

    if (i == j) return true;
    return (jX - iX >= 0) && (jY - iY >= 0);
}

string strMax(const string& $1, const string& $2) {
    if ($1.size() != $2.size()) {
        return $1.size() > $2.size() ? $1 : $2;
    }

    return $1 < $2 ? $2 : $1;
}

string f[505][15][2];
string cur;

string dfs(int index, int last, int isPrefix) {
    if (index == cur.size()) return "";
    if (!f[index][last][isPrefix].empty()) return f[index][last][isPrefix];

    string ans;
    for (int d = 0; d <= 9; d++) {
        if (!canReach(last, d)) continue;
        if (isPrefix && (d + '0') > cur[index]) continue;

        ans = strMax(ans, char('0' + d) + dfs(
                index + 1,
                d,
                isPrefix && (d + '0') == cur[index]
        ));
    }
    return f[index][last][isPrefix] = ans;
}

int main() {
    int T;
    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> cur;
        for (int i = 0; i <= 500; i++) {
            for (int j = 0; j <= 10; j++) {
                for (int k = 0; k <= 1; k++) {
                    f[i][j][k].clear();
                }
            }
        }

        cout << dfs(0, 1, 1) << endl;
    }
    return 0;
}