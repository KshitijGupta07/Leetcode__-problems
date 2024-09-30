class CustomStack {
public:
vector<int>array;
int a;
    CustomStack(int maxSize) {
        array.clear();
        a=maxSize;
    }
    
    void push(int x) {
        if(array.size()<a){
            array.push_back(x);
        }
    }
    
    int pop() {
        if(array.size()==0){
            return -1;
        }
        int a=array[array.size()-1];
        array.pop_back();
        return a;
    }
    
    void increment(int k, int val) {
        int n=array.size();
        for(int i=0;i<min(k,n);i++){
            array[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */