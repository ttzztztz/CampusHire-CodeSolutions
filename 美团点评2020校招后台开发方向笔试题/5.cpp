#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
#include <unordered_set>
 
using namespace std;
 
vector<vector<int>> edge;
vector<int> inDegree;
 
void addEdge(char start, char end) {
    int $1 = start - 'a', $2 = end - 'a';
    inDegree[$2]++;
    edge[$1].push_back($2);
}
 
int main() {
    edge = vector<vector<int>>(26, vector<int>{});
    inDegree = vector<int>(26, 0);
 
    vector<string> all;
    unordered_set<char> allChar;
    string tmp;
    while (cin >> tmp) {
        for (const char ch : tmp) {
            allChar.insert(ch);
        }
        all.push_back(tmp);
    }
    const int N = all.size();
 
    for (int i = 0; i < N - 1; i++) {
        const string& s1 = all[i], s2 = all[i + 1];
        int ptr = 0;
        while (ptr < s1.size() && ptr < s2.size() && s1[ptr] == s2[ptr]) {
            ptr++;
        }
 
        if (ptr < s1.size() && ptr < s2.size()) {
            addEdge(s1[ptr], s2[ptr]);
        }
    }
 
    vector<char> answer;
    deque<int> q;
    for (int i = 0; i < 26; i++) {
        if (!allChar.count(i + 'a')) continue;
        if (inDegree[i] == 0) q.push_front(i);
    }
 
    if (q.size() != 1) {
        cout << "invalid" << endl;
        exit(0);
    }
 
    while (!q.empty()) {
        int i = q.front();
        q.pop_front();
        answer.push_back(i + 'a');
 
        for (int v : edge[i]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push_back(v);
            }
        }
    }
 
    if (answer.size() != allChar.size()) {
        cout << "invalid" << endl;
        exit(0);
    }
 
    for (const char ch : answer) cout << ch;
    cout << endl;
    return 0;
}