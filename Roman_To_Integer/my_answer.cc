#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
  public:
    int romanToInt(std::string s) {
      std::unordered_map<char, int> roman_map{{'I', 1},
                                              {'V', 5},
                                              {'X', 10},
                                              {'L', 50},
                                              {'C', 100},
                                              {'D', 500},
                                              {'M', 1000}};
      int pos{static_cast<int>(s.length())-1};
      char prev{' '};
      int result{0};
      while(pos >= 0) {
        auto cur_iter{roman_map.find(s[pos])};
        if(prev == ' ') {
          prev = cur_iter->first;
          result += cur_iter->second;
        } else {
          auto prev_iter{roman_map.find(prev)};
          if(cur_iter->second < prev_iter->second) {
            result -= cur_iter->second;
          } else {
            result += cur_iter->second;
          }
          prev = cur_iter->first;
        }
        pos--;
      }

      return result;
    }
};

int main() {
  Solution s;
  std::string input{"MCMXCIV"};
  auto result{s.romanToInt(input)};
  std::cout << "Result : " << result << std::endl;
  return 0;
}
