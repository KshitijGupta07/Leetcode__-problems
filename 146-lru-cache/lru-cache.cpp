class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* left;
        Node* right;
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }

    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    map<int,Node*>m;
    int count=0;
    LRUCache(int capacity) {
        head->right=tail;
        tail->left=head;
        count=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        int a=m[key]->val;
        Node* t=m[key];
        remove(t);
        insert(t);
          return a;
    }
    void insert(Node* t){
        Node* temp=head->right;
        t->right=temp;
        temp->left=t;
        t->left=head;
        head->right=t;

    }
    void remove(Node* t){
        Node* temp1=t->right;
        Node* temp2=t->left;
        temp1->left=temp2;
        temp2->right=temp1;
    }
    
    void put(int key, int value) {
         if(m.find(key)!=m.end()){
            Node* x=m[key];
            m.erase(key);
            remove(x);
         }
         if(m.size()==count){
             m.erase(tail->left->key);
             remove(tail->left);
         }
         insert(new Node(key,value));
         m[key]=head->right;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */