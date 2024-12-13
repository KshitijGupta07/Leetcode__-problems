class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        for(int i=0;i<nums.size();i++){
              p.push({nums[i],i});
        }
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[i]=0;
        }
        long long ans=0;
        while(p.empty()==false){
            pair<int,int>top=p.top();
            p.pop();
            int index=top.second;
            int element=top.first;
            if(m[index]!=-1){
                ans+=element;
                m[index]=-1;
                if(index==0){
                    m[index+1]=-1;
                }
                else if(index==nums.size()-1){
                    m[index-1]=-1;
                }
                else{
                          m[index+1]=-1;
                           m[index-1]=-1;
                }
            }


        }
        return ans;
    }
};