class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        map<string,bool>present;
        sort(folder.begin(),folder.end());
        for(int i=0;i<folder.size();i++){
            if(folder[i].length()==2){
                ans.push_back(folder[i]);
                present[folder[i]]=true;
            }
            else{
                bool signal=false;
                string x="";
                for(int j=0;j<folder[i].length();j++){
                    if(j!=0&&folder[i][j]=='/'){
                        if(present[x]==true){
                            signal=true;
                            break;
                        }
                        
                    }
                    
                    x.push_back(folder[i][j]);
                    
                    
                }
                if(signal==false){
                    ans.push_back(folder[i]);
                    present[folder[i]]=true;
                }
            }



        }
        return ans;
        
    }
};