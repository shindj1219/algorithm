#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

class Solution {
  public:
    int reverse(int x) {
      auto max{std::pow(2,31)-1};
      auto min{std::pow(-2,31)};
      if(x > max || x < min) {
        return 0;
      }
      bool is_negative{false};
      if(x < 0) {
        is_negative = true;
      }
      std::string temp{std::to_string(x)};
      std::reverse(temp.begin(), temp.end());
      auto result{std::stol(temp)};
      if(is_negative == true) {
        result = result * (-1);
      }
      if(result > max || result < min) {
        return 0;
      }
      return static_cast<int>(result);
    }
};

int main() {
  Solution s;
  auto result{s.reverse(1534236469)};
  std::cout << "Result : " << result << std::endl;
  return 0;
}
