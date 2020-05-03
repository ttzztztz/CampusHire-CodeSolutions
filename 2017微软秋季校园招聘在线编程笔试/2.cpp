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

int main() {
    int N, M;
    string s;
    cin >> N >> s >> M;
    unordered_set<string> disabled;
    for (int _ = 0; _ < M; _++) {
        string t;
        cin >> t;
        disabled.insert(t);
        reverse(t.begin(), t.end());
        disabled.insert(t);
    }

    vector<int> f(N + 5), g(28, -1);
    int answer = 0;

    for (int i = 0; i < N; i++) {
        f[i] = 1;

        for (int j = 0; j < 26; j++) {
            const string cur = {s[i], char('a' + j)};
            if (disabled.count(cur)) continue;

            if (g[j] != -1) f[i] = max(f[i], f[g[j]] + 1);
        }

        g[s[i] - 'a'] = i;
        answer = max(answer, f[i]);
    }

    cout << N - answer << endl;
    return 0;
}