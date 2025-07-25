class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int c=0;
        int ans=0;
        unordered_set<int>m;
        for(auto j:nums){
            m.insert(j);
        }
        for(auto j:m){
            if(m.find(j-1)==m.end()){
                ans=1;
                
            
            while(m.find(j+ans)!=m.end()){
                
                    ans++;
                
                }
                c=max(ans,c);
                
            }
            
        }
        return c;
    }
};