#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freqNums2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for (int num : nums2) {
            freqNums2[num]++;
        }
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        freqNums2[oldVal]--;

        nums2[index] += val;

        freqNums2[nums2[index]]++;
    }

    int count(int tot) {
        int res = 0;
        for (int num : nums1) {
            int target = tot - num;
            if (freqNums2.count(target)) {
                res += freqNums2[target];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */