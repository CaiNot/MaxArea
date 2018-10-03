#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int len_1 = height.size() - 1;
        int value = 0, lessH = 0;
        for (int i = 0; i < len_1; i++) {
            for (int j = len_1; j > i; j--) {
                if (height[i] <= height[j]) {
                    value = max(value, height[i] * (j - i));
                    break;
                } else {
                    value = max(value, height[j] * (j - i));
                }
            }
        }
        return value;
    }

    int betterMaxArea(vector<int> &height) {
        int result = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            int h = min(height[i], height[j]);
            result = max(result, h * (j - i));
            while (i < j && h == height[i])i++;
            while (i < j && h == height[j])j--;
        }
        return result;
    }
};

int main() {
    vector<int> height = {9, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    cout << s.betterMaxArea(height) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}