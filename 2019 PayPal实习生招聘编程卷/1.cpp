#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<vector<int>> f;
 
int dfs(int K, int H) {
    if (K == 1) return H;
    if (H == 0) return 0;
    if (f[K][H] != -1) return f[K][H];
 
    int left = 1, right = H;
    while (right - left > 1) {
        const int mid = (left + right) >> 1;
 
        const int f1 = dfs(K - 1, mid - 1), f2 = dfs(K, H - mid);
        if (f1 < f2) {
            left = mid;
        } else if (f1 > f2) {
            right = mid;
        } else {
            left = right = mid;
        }
    }
 
    return f[K][H] = 1 + min(
            max(dfs(K - 1, left - 1), dfs(K, H - left)),
            max(dfs(K - 1, right - 1), dfs(K, H - right))
    );
}
 
int main() {
    int K, H;
    cin >> K >> H;
    f = vector<vector<int>>(K + 5, vector<int>(H + 5, -1));
 
    cout << dfs(K, H) << endl;
    return 0;
}