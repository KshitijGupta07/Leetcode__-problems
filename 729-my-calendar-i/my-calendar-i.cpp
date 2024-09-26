class MyCalendar {
public:
 
 set<pair<int,int>>s;

 bool book(int start, int end) {
    if(s.size()==0){
        s.insert({start,end});
        return true;
    }
  auto upper=s.lower_bound({start,end});
  if(upper!=s.end()&&upper->first<end){
    return false;
  }
  if(upper!=s.begin()){
    auto previous=prev(upper);
    if(previous->second>start){
        return false;
    }
  }
  s.insert({start,end});
  return true;
}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */