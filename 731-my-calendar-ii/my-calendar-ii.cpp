class MyCalendarTwo {
public:
  vector<pair<int,int>>doubleregion;
  vector<pair<int,int>>bookregion;
    MyCalendarTwo() {
        
    }
    bool check(int a,int b,int c,int d){
        return max(a,c)<min(b,d);
    }
    bool book(int start, int end) {
        for(auto j:doubleregion){
            if(check(j.first,j.second,start,end)){
                return false;
            }
            
        }
        for(auto j:bookregion){
            if(check(j.first,j.second,start,end)){
                doubleregion.push_back({max(j.first,start),min(j.second,end)});
            }
        }
        bookregion.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */