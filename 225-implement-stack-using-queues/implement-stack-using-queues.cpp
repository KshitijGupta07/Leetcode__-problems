class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int a=q.size()-1;
        while(a>0){
            q.push(q.front());
            q.pop();
            a-=1;
        }
        int b=q.front();
           q.pop();
        return b;
        
    }
    
    int top() {
        int a=q.size()-1;
        while(a>0){
            q.push(q.front());
            q.pop();
            a-=1;
        }
        int b=q.front();
        q.push(b);
        q.pop();
        return b;
    }
    
    bool empty() {
        return q.empty();
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