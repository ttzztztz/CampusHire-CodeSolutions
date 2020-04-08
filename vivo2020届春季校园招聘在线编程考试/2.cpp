class Solution {
public:
    /**
     * 输入一个整形数值，返回一个整形值
     * @param n int整型 n>9
     * @return int整型
     */
    int solution(int n) {
        vector<int> digit;
        while (n > 1) {
            bool find = false;
            for (int i = 9; i >= 2; i--) {
                if (n % i == 0) {
                    n /= i;
                    digit.push_back(i);
                    find = true;
                    break;
                }
            }
             
            if (!find) return -1;
        }
         
        sort(digit.begin(), digit.end(), [](const auto& $1, const auto& $2)->bool {
            return $1 < $2;
        });
        int answer = 0;
        for (int i : digit) {
            answer *= 10;
            answer += i;
        }
        return answer;
    }
};