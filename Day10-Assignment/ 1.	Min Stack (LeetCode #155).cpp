struct StackComponent{
    int val;
    int min_val;

};

class MinStack {
public:
stack<StackComponent>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(!st.empty()){
            st.push({val,min(val,st.top().min_val)});

        }else{
            st.push({val,val});

        }
        
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
      if(st.empty())return -1;
      return st.top().val;
    }
    
    int getMin() {
       return st.top().min_val;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */