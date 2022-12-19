class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> input,output;
    void push(int x) {
      input.push(x); 
    }
    
    int pop() {
        if(!output.empty()){
            int l=output.top();
            output.pop();
            return l;
        }
        else{
            while(!input.empty()){
                output.push(input.top());input.pop();
            }
            int l=output.top();
            output.pop();
            return l;
        }
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        else{
            while(!input.empty()){
                output.push(input.top());input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() {
        if(!input.empty() || !output.empty()){return false;}
        return true;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */