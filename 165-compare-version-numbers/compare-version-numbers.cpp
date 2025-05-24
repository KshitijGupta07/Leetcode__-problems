class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>temp1;
        string t1="";
        for(int i=0;i<version1.length();i++){
            if(version1[i]=='.'){
                 temp1.push_back(stoi(t1));
                 t1="";
            }
            else{
                t1.push_back(version1[i]);
            }
        }
        temp1.push_back(stoi(t1));
        for(auto j:temp1){
            cout<<j<<" ";
        }
        cout<<endl;
         vector<int>temp2;
        string t2="";
        for(int i=0;i<version2.length();i++){
            if(version2[i]=='.'){
                 temp2.push_back(stoi(t2));
                 t2="";
            }
            else{
                t2.push_back(version2[i]);
            }
        }
        temp2.push_back(stoi(t2));
        for(auto j:temp2){
            cout<<j<<" ";
        }
        int i=0;
        int j=0;
        while(i<temp1.size()&&j<temp2.size()){
            if(temp1[i]>temp2[j]){
                return 1;
            }
            else if(temp1[i]<temp2[j]){
                return -1;
            }
            i++;
            j++;
        }
        while(i<temp1.size()){
            if(temp1[i]>0){
                return 1;
            }
            i++;
        }
        while(j<temp2.size()){
            if(temp2[j]>0){
                return -1;
            }
            j++;
        }
        return 0;
    }
};