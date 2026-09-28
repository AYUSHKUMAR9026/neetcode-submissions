class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int maxprofit=0;
        int n=prices.size();
        int minval=INT_MAX;
        for(int i=0;i<n;i++){
            if(prices[i]<minval){
                minval=prices[i];
            }
            else{
                profit=prices[i]-minval;
                maxprofit=max(maxprofit,profit);
            }
        }
        return maxprofit;
        
    }
};
