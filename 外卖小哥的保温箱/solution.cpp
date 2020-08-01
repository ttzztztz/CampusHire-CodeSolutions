#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
typedef pair<int, int> PII;

int N;
int f[10005], g[10005];
vector<PII> all;
int sum = 0, total = 0;

int main() {
    cin >> N;
    all.resize(N);
    for (int i = 0; i < N; i++) (cin >> all[i].first), sum += all[i].first;
    for (int i = 0; i < N; i++) (cin >> all[i].second), total += all[i].second;

    memset(f, 0x3f, sizeof f);
    int k = 999999, mx = 0;

    f[0] = g[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = total; j >= 0; j--) {
            const int prev = max(0, j - all[i].second);

            if (f[prev] + 1 < f[j]) {
                f[j] = f[prev] + 1;
                g[j] = g[prev] + all[i].first;
            } else if (f[prev] + 1 == f[j]) {
                g[j] = max(g[j], g[prev] + all[i].first);
            }
        }
    }

    for (int i = sum; i <= total; i++) {
        if (f[i] < k) {
            k = f[i];
            mx = g[i];
        } else if (f[i] == k) {
            mx = max(mx, g[i]);
        }
    }

    cout << k << " " << (sum - mx) << endl;
    return 0;
}