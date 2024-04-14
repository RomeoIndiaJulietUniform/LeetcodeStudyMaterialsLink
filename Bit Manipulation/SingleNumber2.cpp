//better
class Solution {
public:
   
    Solution(){
        optimizer; 
    }


    int singleNumber(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i = 1 ; i < n ; i+= 3){

            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }

        }

        return nums[n-1];
        
    }
};




//optimal
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int one = 0;
        int two = 0;

        for(auto& it: nums){
            one = (one^it)&(~two);
            two = (two^it)&(~one);
        }


        return one;
        
    }
};