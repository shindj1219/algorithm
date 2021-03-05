#include <vector>
#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        bool is_even{false};
        auto total_size{nums1.size() + nums2.size()};
        float median_index{0.0f};
        if(total_size % 2 == 0) {
            is_even = true;
            median_index = (total_size/2.0f) - 1;
        } else {
            is_even = false;
            median_index = total_size/2.0f;
        }
        
        auto num1_iter{nums1.begin()};
        auto num2_iter{nums2.begin()};
        double result{0};
        int current_pos{0};
        while(num1_iter!=nums1.end() && num2_iter!=nums2.end()) {
            if(current_pos >= median_index) {
                break;
            }
            if(num1_iter < num2_iter) {
                num1_iter++;
            } else {
                num2_iter++;
            }
            ++current_pos;
        }
        
        if(num1_iter!=nums1.end() && num2_iter!=nums2.end()) {
            if(is_even) {
                result = (*num1_iter + *num2_iter) / 2.0f;
            } else {
                result = (*num1_iter < *num2_iter) ? *num1_iter : *num2_iter;
            }
        } else if(num1_iter == nums1.end()) {
            for(current_pos;current_pos==median_index;++current_pos) {
                num2_iter++;
            }
            if(is_even) {
                result = (*num2_iter + *(++num2_iter)) / 2.0f;
            } else {
                result = *num2_iter;
            }
        } else {
            for(current_pos;current_pos==median_index;++current_pos) {
                num1_iter++;
            }
            if(is_even) {
                result = (*num1_iter + *(++num1_iter)) / 2.0f;
            } else {
                result = *num1_iter;
            }
        }
        return result;
    }
};

int main() {
  std::vector<int> v1{};
  std::vector<int> v2{2,3};
  Solution s;
  auto result{s.findMedianSortedArrays(v1, v2)};
  std::cout << result << std::endl;
  return 0;
}
