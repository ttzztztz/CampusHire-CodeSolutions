#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // freopen("./case.txt", "r", stdin);
    typedef long long ll;

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll target;
    cin >> target;

    ll ans = 0;
    const int mod = 1e9+7;

    vector<vector<int>> pref(n + 1, vector<int>(31, 0));
    for (int i = 1; i <= n; i++) {
        for (int k = 30; k >= 0; k--) {
            pref[i][k] = pref[i - 1][k] + ((arr[i - 1] & (1 << k)) ? 1 : 0);
        }
    }

    // [x, i] > target
    // ans += (n - t)
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i - 1;
        while (l <= r) {
            const int mid = (l + r) / 2;
            int cur = 0;
            for (int k = 30; k >= 0; k--) {
                if (pref[i][k] - pref[mid][k] > 0) cur |= (1 << k);
            }

            if (cur > target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans = (ans + max(0, i - r - 1)) % mod;
    }

    cout << ans << endl;
    return 0;
}