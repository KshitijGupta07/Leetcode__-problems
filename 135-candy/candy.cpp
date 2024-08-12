class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1){
            return 1;
        }
        map<int,int>m;
        int n=ratings.size();
        for(int i=0;i<n;i++){
            m[i]=1;
        }
        for(int i=1;i<n-1;i++){
            if(ratings[i]<ratings[i-1]){
                 if(m[i]<m[i-1]){
                    continue;
                 }
                 else{
                    m[i-1]+=(m[i]-m[i-1]+1);
                 }
            }
            if(ratings[i]>ratings[i-1]){
                if(m[i]>m[i-1]){
                    continue;
                }
                else{
                    m[i]+=(m[i-1]-m[i]+1);
                }
            }
            if(ratings[i]>ratings[i+1]){
                if(m[i]>m[i+1]){
                  continue;
            }
            else{
                m[i]+=(m[i+1]-m[i]+1);
            }
            }
            if(ratings[i]<ratings[i+1]){
                if(m[i]<m[i+1]){
                    continue;
                }
                else{
                    m[i+1]+=(m[i]-m[i+1]+1);
                }
            }

        }
        int ans=0;
        cout<<ratings[0]<<" "<<ratings[1]<<endl;
        cout<<m[0]<<" "<<m[1]<<endl;
        for(int i=n-2;i>=1;i--){
            if(ratings[i]>ratings[i+1]){
                if(m[i]>m[i+1]){
                    continue;
                }
                else{
                    m[i]+=(m[i+1]-m[i]+1);
                }
            }
            if(ratings[i]<ratings[i+1]){
                if(m[i]<m[i+1]){
                    continue;
                }
                else{
                    m[i+1]+=(m[i]-m[i+1]+1);
                }
            }
            if(ratings[i]>ratings[i-1]){
                if(m[i]>m[i-1]){
                    continue;
                }
                else{
                    m[i]+=(m[i-1]-m[i]+1);
                }
            }
            if(ratings[i]<ratings[i-1]){
                if(m[i]<m[i-1]){
                    continue;
                }
                else{
                    m[i-1]+=(m[i]-m[i-1]+1);
                }
            }
        }
        if(ratings[0]>ratings[1]){
            if(m[0]<=m[1]){
                m[0]+=(m[1]-m[0]+1);
            }
        }
        if(ratings[0]<ratings[1]){
            if(m[0]>=m[1]){
                m[1]+=(m[0]-m[1]+1);
            }
        }
        if(ratings[n-1]>ratings[n-2]){
            if(m[n-2]>=m[n-1]){
                 m[n-1]+=(m[n-2]-m[n-1]+1);
            }
        }
        if(ratings[n-1]<ratings[n-2]){
            if(m[n-1]>=m[n-2]){
                m[n-2]+=(m[n-1]-m[n-2]+1);
            }
        }
        for(auto j:m){
           cout<<j.first<<" "<<j.second<<endl;
            ans+=j.second;
        }
        return ans;
    }
};