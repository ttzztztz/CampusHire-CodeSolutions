#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> data;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        data.push_back(tmp);
    }
 
    vector<int> answer(N, 1);
    vector<int> stk;
    for (int i = 0; i < N; i++) {
        answer[i] += stk.size();
 
        while (!stk.empty() && data[stk.back()] <= data[i]) stk.pop_back();
        stk.push_back(i);
    }
 
    stk.clear();
    for (int i = N - 1; i >= 0; i--) {
        answer[i] += stk.size();
 
        while (!stk.empty() && data[stk.back()] <= data[i]) stk.pop_back();
        stk.push_back(i);
    }
 
    for (int i : answer) cout << i << " ";
    cout << endl;
    return 0;
}
