class LRUCache {
public:
    class Node{
        public:
        int val;
        int key;
        Node* prev;
        Node* next;
        Node(int key,int val){
            this->key=key;
            this->val=val;
        }

    };
    int count=0;
    map<int,Node*>m;
    Node* head= new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
        head->next=tail;
        count=capacity;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* curr=m[key];
        remove(curr);
        insert(curr);
        return curr->val;
    }
    void insert(Node* node){
        Node* temp=head->next;
        node->next=temp;
        temp->prev=node;
        node->prev=head;
        head->next=node;

    }
    void remove(Node* temp){
        Node* p=temp->prev;
        Node* n=temp->next;
        p->next=n;
        n->prev=p;
    }
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* c=m[key];
            m.erase(key);
            remove(c);
        }
        if(m.size()==count){
            m.erase(tail->prev->key);
            remove(tail->prev);
            
        }
        insert(new Node(key,value));
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */