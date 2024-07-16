#include <iostream>
#include <vector>

class Solution {
public:
  int searchInsert(std::vector<int>& nums, int target) {
    int index = 0;
    for(auto& iter : nums) {
      if(iter < target) {
        ++index;
      } else {
        break;
      }
    }  
    return index;
  }
};

int main() {
  std::vector v1{1,3,5,6};
  Solution s;
  
  int result = s.searchInsert(v1, 5);
  std::cout << "result : " << result << std::endl;

  result = s.searchInsert(v1, 2);
  std::cout << "result : " << result << std::endl;

  result = s.searchInsert(v1, 7);
  std::cout << "result : " << result << std::endl;

  return 0;
}
