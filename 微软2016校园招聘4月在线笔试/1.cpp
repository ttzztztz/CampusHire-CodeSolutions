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

using namespace std;
vector<int> pages;
int N, P, W, H;

int solve(int S) {
    int answer = 0;
    const int charPerW = W / S, charPerH = H / S;
    for (int p : pages) {
        answer += p / charPerW;
        if (p % charPerW != 0) answer++;
    }

    if (answer % charPerH != 0) {
        return (answer / charPerH) + 1;
    } else {
        return answer / charPerH;
    }
}

int main() {
    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        cin >> N >> P >> W >> H;
        pages.resize(N);
        for (int i = 0; i < N; i++) cin >> pages[i];

        int left = 1, right = min(W, H);
        while (left <= right) {
            const int mid = (left + right) >> 1;

            if (solve(mid) <= P) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << right << endl;
    }
    return 0;
}