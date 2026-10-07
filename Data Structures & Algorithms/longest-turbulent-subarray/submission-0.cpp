class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int sign=1;
        int count=0;
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                if(sign==0){
                    count+=1;
                    
                }
                else{
                    count=1;
                }
                sign=1;
            }
            else if(arr[i]<arr[i+1]){
                if(sign==1){
                    count+=1;
                    
                }
                else{
                    count=1;
                }
                sign=0;
            }
            else{
                count=0;
                sign=-1;
            }
            ans=max(ans,count);
        }
        return ans+1;
        
    }
};