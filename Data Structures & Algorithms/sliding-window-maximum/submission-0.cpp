class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxele=INT_MIN;
        int n=nums.size();
         vector<int>ans;
        if(n<k){
            for(int i=0;i<n;i++){
                maxele=max(maxele,nums[i]);
            }
            ans.push_back(maxele);
            return ans;
        }
       
        unordered_map<int,int>m;
        priority_queue<int>q;
        for(int i=0;i<k;i++){
            maxele=max(maxele,nums[i]);
            m[nums[i]]++;
            q.push(nums[i]);
        }
        ans.push_back(maxele);
        for(int i=k;i<n;i++){
            m[nums[i-k]]--;
            m[nums[i]]++;
            q.push(nums[i]);
            while(!m[q.top()]){
                q.pop();
            }
            ans.push_back(q.top());
        }
        return ans;

        
    }
};
