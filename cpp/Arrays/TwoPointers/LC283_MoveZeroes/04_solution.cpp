#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t num_size = nums.size();
        size_t reader = 0, writer = 0;
        while(writer < num_size && reader < num_size) {
            // find position where the first non-zero element will go
            if(nums[writer] != 0) {
                ++writer;
                continue;
            }
            // find first non-zero element
            reader = writer + 1;
            while(reader < num_size) {
                if(nums[reader] == 0) ++reader;
                else {
                    swap(nums[writer], nums[reader]);
                    ++reader; ++writer;
                    break;
                }
            }
        }
    }
};