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