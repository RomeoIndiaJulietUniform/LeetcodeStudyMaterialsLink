class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int xortemp = 0;

        for(auto& it: nums){
            xortemp ^= it;
        }

        return xortemp;
        
    }
};


// Time complexity: O(n)
// Space complexity: O(1)