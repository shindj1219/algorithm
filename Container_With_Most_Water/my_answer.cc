#include <iostream>
#include <vector>

class Solution {
  public:
    int maxArea(std::vector<int>& height) {
      int max{0};
      int left{0};
      int right(height.size()-1);
      while(left < right) {
        int area{std::min(height[left], height[right]) * (right - left)};
        max = max < area ? area : max;
        if(height[left] < height[right]) {
          ++left;
        } else {
          --right;
        }
      }
      return max;
    }
};

int main() {
  Solution s;
  std::vector<int> heights{1,8,6,2,5,4,8,3,7};
  auto max{s.maxArea(heights)};
  std::cout << "Result : " << max << std::endl;
  return 0;
}
