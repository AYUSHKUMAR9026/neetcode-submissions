class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                m[bills[i]]++;
            }
            else if(bills[i]==10){
                if(!m[5]){
                    return false;
                }
                else{
                    m[bills[i]]++;
                    m[5]--;
                }
            }
            else{
                if(!m[5]){
                    return false;
                }
                else if(!m[10]&&m[5]<3){
                    return false;
                }
                else{
                    if(m[10]){
                        m[10]--;
                        m[5]--;
                    }
                    else{
                        m[5]-=3;
                    }
                }
            }
        }
        return true;

        
    }
};