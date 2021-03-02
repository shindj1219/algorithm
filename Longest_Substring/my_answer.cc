class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      int max_length{0};
      std::string temp;
      std::vector<char> char_arr;

      while(!s.empty()) {
        auto c{s.at(0)};
        for(auto iter = char_arr.begin(); iter!=char_arr.end(); iter++) {
          if(*iter == c) {
            if(max_length < temp.length()) {
              max_length = temp.length();
            }
            char_arr.erase(char_arr.begin(), iter);
            auto find{temp.find(c)};
            temp = temp.substr(find+1);
            break;
          }
        }
        char_arr.emplace_back(c);
        temp += c;

        s = s.substr(1);
      }

      if(max_length < temp.length()) {
        max_length = temp.length();
      }

      return max_length;
    }
};
