class MyStack {
public:
queue<int>p;
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        p.push(x);
    }
    
    int pop() {
        while(p.size()>1){
            
            q.push(p.front());
            p.pop();
        }
        cout<<"end"<<endl;
        int a=p.front();

        p.pop();
        while(q.size()>0){
            p.push(q.front());
            q.pop();
        }
        return a;
    }
    
    int top() {
        while(p.size()>1){
            q.push(p.front());
            p.pop();
        }
        cout<<"NO"<<endl;
        int a=p.front();
        q.push(a);
        p.pop();
        while(q.size()>0){
            p.push(q.front());
            q.pop();
        }
        return a;
    }
    
    bool empty() {
        if(p.size()==0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */