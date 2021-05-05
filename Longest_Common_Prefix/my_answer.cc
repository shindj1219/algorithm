#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
  public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
      if(strs.size() <= 1) {
        return strs[0];
      }

      std::string prefix;
      auto min{std::min(strs[0].length(), strs[1].length())};
      for(auto index = 0; index < min; ++index) {
        if(strs[0].at(index) == strs[1].at(index)) {
          prefix += strs[0].at(index);
        } else {
          break;
        }
      }

      for(auto index = 2; index < strs.size(); ++index) {
        min = std::min(prefix.length(), strs[index].length());
        std::string temp;
        for(auto iter = 0; iter < min; ++iter) {
          if(prefix.at(iter) == strs[index].at(iter)) {
            temp += prefix.at(iter);
          } else {
            break;
          }
        }
        prefix = temp;
      }

      return prefix;
    }
};

int main() {
  Solution s;
  std::vector<std::string> input{"dog", "racecar", "car"};
  auto result{s.longestCommonPrefix(input)};
  std::cout << "Result : " << result << std::endl;
  return 0;
}
