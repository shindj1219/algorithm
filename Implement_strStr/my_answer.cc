#include <iostream>
#include <string>

class Solution {
  public:
    int strStr(std::string haystack, std::string needle) {
      auto h_len{haystack.length()};
      auto n_len{needle.length()};
      auto count{0};
      if(n_len == 0) {
        return 0;
      } else if(h_len == 0) {
        return -1;
      } else if(h_len < n_len) {
        return -1;
      }

      for(int index = 0; index < (h_len-n_len+1); ++index) {
        if(haystack[index] == needle[0]) {
          for(int found = 0; found < n_len; ++found) {
            if(haystack[index + found] == needle[found]) {
              ++count;
            } else {
              break;
            }
          }
          if(count == n_len) {
            return index;
          }
          count = 0;
        }
      }

      return -1;
    }
};

int main() {
  Solution s;

  std::string haystack{"abb"};
  std::string needle{"abaaa"};

  auto index{s.strStr(haystack, needle)};
  std::cout << "Result : " << index << std::endl;

  return 0;
}
