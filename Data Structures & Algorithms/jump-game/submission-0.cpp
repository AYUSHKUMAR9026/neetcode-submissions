class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxval=nums[0];
        int n=nums.size();
        if(n==1){
            return true;
        }
        
        for(int i=1;i<n;i++){
            if(maxval==0){
                return false;
            }
            maxval--;
            maxval=max(maxval,nums[i]);
        }
        return true;
         
        
    }
};
