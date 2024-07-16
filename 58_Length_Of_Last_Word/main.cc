#include <iostream>
#include <string>

class Solution {
public:
  int lengthOfLastWord(std::string s) {
    int length = 0;
    bool found = false;
    for(int index = s.length()-1; index != -1; --index) {
      if(s[index] == ' ' && found == true) {
        break;
      } else if(s[index] == ' ' && found == false) {
        continue;
      } else if(s[index] != ' ') {
        ++length;
        found = true;
      }
    }
    return length;
  }
};

int main() {
  std::string str1 = "Hello World";
  std::string str2 = "   fly me   to   the moon  ";
  std::string str3 = "luffy is still joyboy";
  std::string str4 = "a";
  Solution s;
  
  int result = s.lengthOfLastWord(str1);
  std::cout << "result : " << result << std::endl;

  result = s.lengthOfLastWord(str2);
  std::cout << "result : " << result << std::endl;

  result = s.lengthOfLastWord(str3);
  std::cout << "result : " << result << std::endl;

  result = s.lengthOfLastWord(str4);
  std::cout << "result : " << result << std::endl;

  return 0;
}
