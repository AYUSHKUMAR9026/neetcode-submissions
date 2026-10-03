class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>m;
        int maxval=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            maxval=max(maxval,nums[i]);
        }
        for(int i=1;i<maxval;i++){
            if(!m[i]){
                return i;
            }
        }
        return maxval+1;

        
    }
};