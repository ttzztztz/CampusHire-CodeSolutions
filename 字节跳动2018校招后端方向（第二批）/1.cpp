#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
 
using namespace std;
 
int N, Q;
 
int main() {
    cin >> N;
 
    unordered_map<int, vector<int>> hashmap;
    for (int i = 1; i <= N; i++) {
        int like;
        cin >> like;
        hashmap[like].push_back(i);
    }
    cin >> Q;
 
    for (int i = 0; i < Q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        const vector<int> &toBe = hashmap[k];
 
        auto it1 = lower_bound(toBe.begin(), toBe.end(), l);
        auto it2 = upper_bound(toBe.begin(), toBe.end(), r);
        cout << it2 - it1 << endl;
    }
    return 0;
}