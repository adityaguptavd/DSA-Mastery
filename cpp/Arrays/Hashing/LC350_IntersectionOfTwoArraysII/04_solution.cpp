#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // create hashmap and result array
        unordered_map<int, size_t> freq;
        vector<int> intersection_result;
        // find minimum sized array and use that array to build hashmap
        auto hashmap_build_it = nums1.begin();
        auto hashmap_build_it_end = nums1.end();
        auto intersection_find_it = nums2.begin();
        auto intersection_find_it_end = nums2.end();
        if(nums1.size() > nums2.size()) {
            hashmap_build_it = nums2.begin();
            hashmap_build_it_end = nums2.end();
            intersection_find_it = nums1.begin();
            intersection_find_it_end = nums1.end();
        }
        // iterate to build hashmap
        while(hashmap_build_it != hashmap_build_it_end) {
            freq[*hashmap_build_it]++;
            ++hashmap_build_it;
        }
        // now iterate to find intersection/common element
        while(intersection_find_it != intersection_find_it_end) {
            auto key_it = freq.find(*intersection_find_it);
            if(key_it != freq.end() && key_it->second != 0) {
                key_it->second--;
                intersection_result.push_back(*intersection_find_it);
            }
            ++intersection_find_it;
        }
        return intersection_result;
    }
};