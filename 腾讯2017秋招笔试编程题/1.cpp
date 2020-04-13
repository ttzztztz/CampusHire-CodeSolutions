#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
 
using namespace std;
 
string s;
 
long long dfs(string& current) {
    if (current > s) return 0;
    if (current.size() == 4) return 1;
 
    long long answer = 1;
    for (char ch = 'a'; ch <= 'y'; ch++) {
        current += ch;
        answer += dfs(current);
        current.pop_back();
    }
    return answer;
}
 
int main() {
    cin >> s;
 
    string state;
    cout << dfs(state) - 2 << endl;
 
    return 0;
}