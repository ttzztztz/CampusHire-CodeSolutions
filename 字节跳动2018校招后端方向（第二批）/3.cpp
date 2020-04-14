#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
int main() {
    int answer = 1;
 
    string s;
    int m;
    cin >> s >> m;
    unordered_map<char, vector<int>> hashmap;
    for (int i = 0; i < s.size(); i++) {
        hashmap[s[i]].push_back(i);
    }
 
    for (auto& p : hashmap) {
        const vector<int>& pos = p.second;
        vector<vector<int>> f(pos.size() + 5, vector<int>(pos.size() + 5, 9999999));
 
        for (int i = 0; i < pos.size(); i++) f[i][i] = 0;
        for (int i = 0; i + 1 < pos.size(); i++) f[i][i + 1] = pos[i + 1] - pos[i] - 1;
 
        for (int len = 3; len <= pos.size(); len++) {
            for (int i = 0; i + len - 1 < pos.size(); i++) {
                const int j = i + len - 1;
 
                f[i][j] = f[i + 1][j - 1] + pos[j] - pos[i] - (j - i);
            }
        }
 
        for (int len = 1; len <= pos.size(); len++) {
            for (int i = 0; i + len - 1 <= pos.size(); i++) {
                const int j = i + len - 1;
 
                if (f[i][j] <= m) {
                    answer = max(answer, len);
                }
            }
        }
    }
 
    cout << answer << endl;
    return 0;
}