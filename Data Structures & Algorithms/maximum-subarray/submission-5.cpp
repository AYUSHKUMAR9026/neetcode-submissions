class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=INT_MIN;
        if(nums.size()==1){
            sum=nums[0];
            return sum;
        }
        int neg=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int x=sum+nums[i];
            if(nums[i]>x){
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
            
            
           
            if(x>sum){
                sum=x;
            }
            ans=max(ans,sum);
        }
        return ans;

    }
};
