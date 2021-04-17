#include <iostream>
#include <string>
#include <algorithm>

class Solution {
  public:
    bool isPalindrome(int x) {
      if(x < 0) {
        return false;
      }
      auto num_str{std::to_string(x)};
      auto tmp_str{num_str};
      std::reverse(num_str.begin(), num_str.end());
      if(num_str == tmp_str) {
        return true;
      } else {
        return false;
      }
    }
};

int main() {
  Solution s;
  auto result{s.isPalindrome(10)};
  std::cout << "Result : " << result << std::endl;
  return 0;
}
