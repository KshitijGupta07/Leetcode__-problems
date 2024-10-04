class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int start=0;
        int end=skill.size()-1;
        int sum=skill[start]+skill[end];
       
        long long ans=0;
    ans+=skill[start]*skill[end];
       start=start+1;
        end=end-1;
        while(start<end){
          
        cout<<start<<" "<<end<<endl;
            if(skill[start]+skill[end]!=sum){
                return -1;
            }
            else{
                ans+=skill[start]*skill[end];
            }
                 start=start+1;
        end=end-1;
            
           
        }
        return ans;

    }
};