class Solution {
public:
  int shortest(unordered_map<string,vector<string>>&m,string beginWord,string endWord,vector<string>&wordList){
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<>>p;
        p.push({0,beginWord});
        unordered_map<string,int>distance;
        for(auto j:wordList){
            distance[j]=INT_MAX;
        }
        distance[endWord]=INT_MAX;
        distance[beginWord]=0;
        while(p.empty()==false){
            pair<int,string>top=p.top();
            p.pop();
            int d=top.first;
            string to=top.second;
            for(auto j:m[to]){
                if(distance[j]>distance[to]+1){
                    distance[j]=distance[to]+1;
                    p.push({distance[j],j});
                }
            }
        }
        return distance[endWord];

  }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>>m;
        int n=wordList.size();
        bool signal=false;
        for(auto j:wordList){

            if(j==endWord){
                signal=true;
            }
        }
        if(signal==false){
            return 0;
        }
        
        for(int j=0;j<wordList.size();j++){
              int x=0;
               int y=0;
               int count=0;
               while(x<wordList[j].length()&&y<endWord.length()){
                if(wordList[j][x]!=beginWord[y]){
                    count++;
                }
                x++;
                y++;
               }
               if(count==1){
                 m[beginWord].push_back(wordList[j]);
                    m[wordList[j]].push_back(beginWord);
               }
            }
        

        for(int j=0;j<wordList.size();j++){
              int x=0;
               int y=0;
               int count=0;
               while(x<wordList[j].length()&&y<endWord.length()){
                if(wordList[j][x]!=endWord[y]){
                    count++;
                }
                x++;
                y++;
               }
               if(count==1){
                 m[endWord].push_back(wordList[j]);
                    m[wordList[j]].push_back(endWord);
               }
            }
             for(int j=0;j<wordList.size();j++){
               int x=0;
               int y=0;
               int count=0;
               while(x<wordList[j].length()&&y<endWord.length()){
                if(wordList[j][x]!=endWord[y]){
                    count++;
                }
                x++;
                y++;
               }
               if(count==1){
                 m[endWord].push_back(wordList[j]);
                    m[wordList[j]].push_back(endWord);
               }
             
                
            }
            
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i){
                    continue;
                }
                  int x=0;
               int y=0;
               int count=0;
               while(x<wordList[j].length()&&y<endWord.length()){
                if(wordList[j][x]!=wordList[i][y]){
                    count++;
                }
                x++;
                y++;
               }
               if(count==1){
                 
                    m[wordList[i]].push_back(wordList[j]);
               }
            }
        }
        for(auto j:m){
            cout<<j.first<<" :";
            for(auto k:j.second){
                cout<<k<<" ";
            }
            cout<<endl;
        }
        int ans=shortest(m,beginWord,endWord,wordList);
        if(ans==INT_MAX){
            return 0;
        }
        return ans+1;
    }
};