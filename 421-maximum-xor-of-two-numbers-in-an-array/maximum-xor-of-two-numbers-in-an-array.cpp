class Solution {
public:
   class TrieNode{
      private:
      TrieNode* ch[2];
      bool isend;
      public:
      TrieNode(){
        for(int i=0;i<2;i++){
            ch[i]=NULL;
        }
        isend=false;
      }
      TrieNode* get(int c){
        return ch[c];
      }
      void set(int b,TrieNode* t){
         ch[b]=t;
      }
      void put(){
        isend=true;
      }
      bool check(){
        return isend;
      }
   };
   class Trie{
      private:
       TrieNode* root;
       public:
       Trie(){
       root=new TrieNode();
       }
       void insert(int a){
             TrieNode* temp=root;
             for(int i=31;i>=0;i--){
                if(temp->get((a>>i)&1)==NULL){
                    temp->set((a>>i)&1,new TrieNode());
                }
                temp=temp->get((a>>i)&1);
        
             }
             temp->put();

       }
       int search(int a){
             TrieNode* temp=root;
             int count=0;
             int ans=0;
              for(int i=31;i>=0;i--){
                if(temp->get(1-((a>>i)&1))!=NULL){
                    ans=ans+pow(2,i);
                    temp=temp->get(1-((a>>i)&1));
                }
                else{
                temp=temp->get((a>>i)&1);
                }
                
             }
             return ans;
       }

   };

    int findMaximumXOR(vector<int>& nums) {
        Trie* t=new Trie();
        Trie* temp=t;
        for(int i=0;i<nums.size();i++){
               temp->insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,temp->search(nums[i]));
        }
        return ans;
    }
};