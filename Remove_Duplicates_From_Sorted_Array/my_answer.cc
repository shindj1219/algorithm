#include <iostream>
#include <vector>

class Solution {
  public:
    int removeDuplicates(std::vector<int>& nums) {
      if(nums.size() == 0) {
        return 0;
      }
      for(auto iter = nums.begin(); iter != nums.end()-1;) {
        if(*iter == *(iter+1)) {
          nums.erase((iter+1));
        } else {
          ++iter;
        }
      }
      return nums.size();
    }
};

int main() {
  Solution s;

  std::vector<int> input{0,0,1,1,1,2,2,3,3,4};
  auto result{s.removeDuplicates(input)};
  std::cout << "Result : " << result << ", nums = [";
  for(auto iter : input) {
    std::cout << iter << " ";
  }
  std::cout << "]" << std::endl;
  return 0;
}
