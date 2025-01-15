class Solution {
public:
   struct Node{
     Node* links[2];
      bool contains(int bit){
        return links[bit]!=NULL;
      }
      void put(int bit,Node* node){
        links[bit]=node;
      }
      Node* get(int bit){
        return links[bit];
      }
   };
   class trie{
    public:
       Node* root;
       trie(){
        root =new Node();
       }
       public:
       void insert(int a){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(a>>i)&1;
            if(node->contains(bit)==false){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
       }
       public:
       int max(int a){
         Node* node=root;
         int ans=0;
         for(int i=31;i>=0;i--){
            int bit=(a>>i)&1;
            if(node->contains(1-bit)){
                   ans=ans|(1<<i);
                node=node->get(1-bit);
            }
            else{
                 node=node->get(bit);
            }
         }
         return ans;
       }
   };
    int findMaximumXOR(vector<int>& nums) {
        trie t;
        for(auto j:nums){
            t.insert(j);
        }
        int ans=0;
        for(auto j:nums){
             ans=max(ans,t.max(j));
        }
        return ans;
    }
};