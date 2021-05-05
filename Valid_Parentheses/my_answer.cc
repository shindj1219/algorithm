#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

class Solution {
  public:
    bool isValid(std::string s) {
      std::unordered_map<char, char> pair_map{{')', '('},
                                              {'}', '{'},
                                              {']', '['}};
      std::stack<char> brace_stack;
      for(int index = 0; index < s.length(); ++index) {
        if(s.at(index) == '(' || s.at(index) == '{' || s.at(index) == '[') {
          brace_stack.push(s.at(index));
        } else {
          if(brace_stack.empty()) {
            return false;
          }
          auto found{pair_map.find(s.at(index))};
          if(found != pair_map.end()) {
            if(found->second == brace_stack.top()) {
              brace_stack.pop();
            } else {
              return false;
            }
          } else {
            return false;
          }
        }
      }
      if(!brace_stack.empty()) {
        return false;
      }
      return true;
    }
};

int main() {
  Solution s;
  std::string input{"]"};
  auto result{s.isValid(input)};
  std::cout << std::boolalpha << "Result : " << result << std::endl;
  return 0;
}
