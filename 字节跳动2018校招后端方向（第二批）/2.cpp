#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
int n, m, c;
unordered_map<int, vector<int>> hashmap;
 
int main() {
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            int color;
            cin >> color;
 
            hashmap[color].push_back(i);
        }
    }
 
    int answer = 0;
    for (auto &p : hashmap) {
        vector<int> colorAllAppear = p.second;
        const int N = colorAllAppear.size();
        for (int i = 0; i < N; i++) colorAllAppear.push_back(n + colorAllAppear[i]);
 
        for (int i = 1; i < N * 2; i++) {
            if (colorAllAppear[i] - colorAllAppear[i - 1] + 1 <= m) {
                answer++;
                break;
            }
        }
    }
    cout << answer << endl;
    return 0;
}