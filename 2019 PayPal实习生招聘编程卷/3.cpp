#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
    map<int, int> appear;
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        appear[start]++;
        appear[end]--;
    }
 
    auto left = appear.begin(), right = appear.begin();
    right++;
    int current = 0, max_answer = 0;
    while (right != appear.end()) {
        current += left->second;
        max_answer = max(max_answer, current);
 
        left++;
        right++;
    }
 
    left = appear.begin(), right = appear.begin();
    right++, current = 0;
    while (right != appear.end()) {
        current += left->second;
        if (current == max_answer) {
            cout << left->first << " " << right->first << endl;
        }
 
        left++;
        right++;
    }
 
    return 0;
}