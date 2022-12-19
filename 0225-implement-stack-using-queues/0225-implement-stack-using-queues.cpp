class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q;
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int l=q.front();
        q.pop();
        return l;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(!q.empty()){return false;}
        return true;
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