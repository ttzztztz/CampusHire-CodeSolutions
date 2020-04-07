#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
 
using namespace std;
typedef pair<int, int> PII;
 
int N, L;
vector<PII> all;
 
int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        all.emplace_back(l, r);
    }
 
    sort(all.begin(), all.end());
    int answer = 0, left = 0;
    for(int ptr = 0, nxt = 0; left < L && ptr < N; answer++, left = nxt) {
        while (ptr < N && all[ptr].first <= left) {
            nxt = max(nxt, all[ptr].second);
            ptr++;
        }
 
        if (nxt == left) {
            cout << -1 << endl;
            exit(0);
        }
    }
 
    if (left < L) {
        cout << -1 << endl;
        exit(0);
    }
    cout << answer << endl;
    return 0;
}
