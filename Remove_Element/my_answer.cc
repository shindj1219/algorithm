#include <iostream>
#include <vector>

class Solution {
  public:
    int removeElement(std::vector<int>& nums, int val) {
      for(auto iter = nums.begin(); iter != nums.end();) {
        if(*iter == val) {
          iter = nums.erase(iter);
        } else {
          ++iter;
        }
      }
      return nums.size();
    }
};

int main() {
  Solution s;
  std::vector<int> input{0,1,2,2,3,0,4,2};
  int value{2};
  auto result{s.removeElement(input, value)};
  std::cout << "Result : " << result << " nums = [";
  for(auto iter : input) {
    std::cout << iter << " ";
  }
  std::cout << "]" << std::endl;
  return 0;
}
