#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
 
using namespace std;
 
int main() {
    string s;
    cin >> s;
    unordered_map<char, int> appear;
    for (const char ch: s) appear[ch]++;
    const int N = s.size();
 
    int current = 0;
    unordered_set<char> appearSet;
    for (int i = 0; i < N; i++) {
        const char ch = s[i];
 
        appear[ch]--;
        appearSet.insert(ch);
        current++;
        bool ok = true;
        for (const char& p : appearSet) {
            if (appear[p] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << current << " ";
            current = 0;
            appearSet.clear();
        }
    }
 
    cout << endl;
    return 0;
}