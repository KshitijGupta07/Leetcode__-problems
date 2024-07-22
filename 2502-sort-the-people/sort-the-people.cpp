class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
         map<int,string>m;
         for(int i=0;i<heights.size();i++){
                 m[heights[i]]=names[i];
         }
         int i=0;
         for(auto j:m){
            names[i]=j.second;
            i++;
         }
         reverse(names.begin(),names.end());
         return names;

    }
};