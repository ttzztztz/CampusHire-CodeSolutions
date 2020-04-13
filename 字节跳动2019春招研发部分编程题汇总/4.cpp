#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <tuple>
 
using namespace std;
 
typedef pair<int, int> PII;
typedef tuple<int, int, int> TII;
 
bool isEqual(const TII &$1, const TII &$2) {
    return get<0>($1) == get<0>($2) && get<1>($1) == get<1>($2);
}
 
int main() {
    int N;
    cin >> N;
    for (int _ = 0; _ < N; _++) {
        int M;
        cin >> M;
        int answer = 0;
        vector<TII> prev;
 
        for (int i = 0; i < M; i++) {
            int cnt;
            cin >> cnt;
            vector<TII> current;
            for (int j = 0; j < cnt; j++) {
                int x, y;
                cin >> x >> y;
                current.emplace_back(x, y, 1);
            }
 
            for (auto &t1 : current) {
                for (auto &t2 : prev) {
                    if (isEqual(t1, t2)) {
                        get<2>(t1) += get<2>(t2);
                    }
                }
 
                answer = max(get<2>(t1), answer);
            }
 
            prev = current;
        }
 
        cout << answer << endl;
    }
    return 0;
}