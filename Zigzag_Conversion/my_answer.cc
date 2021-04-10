#include <string>
#include <iostream>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
      std::string temp[numRows];
      int current{0};
      int sumval{1};
      for(int index = 0; index < s.length(); index++) {
        temp[current] += s[index];
	current = current + sumval;
	if(current >= numRows - 1) {
	  current = numRows - 1;
	  sumval = -1;
	} else if(current <= 0) {
	  current = 0;
	  sumval = 1;
	}
      }

      std::string result;
      for(int index = 0; index < numRows; index++) {
        result += temp[index];
      }
      return result;   
    }
};

int main() {
  Solution s;
  auto result{s.convert("AB", 1)};
  std::cout << "Result : " << result << std::endl;
  return 0;
}
