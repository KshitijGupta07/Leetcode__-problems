class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int>mention(n,0);
        map<int,pair<int,int>>m;
        for(int i=0;i<n;i++){
            m[i]={0,0};
        }
        vector<pair<int,pair<string,string>>>v;
        for(int i=0;i<events.size();i++){
            v.push_back({stoi(events[i][1]),{events[i][0],events[i][2]}});
        }
      
        sort(v.begin(),v.end());
          for(int i=1;i<v.size();i++){
            if(v[i].first==v[i-1].first){
                if(v[i].second.first=="OFFLINE"&&v[i-1].second.first=="MESSAGE"){
                    swap(v[i],v[i-1]);
                }
            }
        }
        for(auto j:v){
            cout<<j.second.first<<endl;
        }
        for(int i=0;i<v.size();i++){
           if(v[i].second.first=="MESSAGE"){
              if(v[i].second.second=="ALL"){
                for(int j=0;j<n;j++){
                    mention[j]+=1;
                }
              }
              else if(v[i].second.second=="HERE"){
                for(auto j:m){
                    if(j.second.second<=v[i].first){
                        mention[j.first]+=1;
                    }
                }
              }
              else{
                    string x="";
                    for(int j=0;j<v[i].second.second.length();j++){
                        if(isdigit(v[i].second.second[j])){
                          x.push_back(v[i].second.second[j]);
                        }
                        else{
                            
                            if(x!=""){
                                
                                mention[stoi(x)]+=1;
                                x="";
                            }
                            
                        }
                    }
                     if(x!=""){
                        
                                mention[stoi(x)]+=1;
                                x="";
                            }

                 }
              
           }
           else{
                int a=stoi(v[i].second.second);
                int b=v[i].first;
                m[a]={b,b+60};
           }

        }
        return mention;
    }
};