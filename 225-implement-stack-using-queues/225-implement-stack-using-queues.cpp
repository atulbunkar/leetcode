class MyStack {
public:
     queue<int> front;
    queue<int> end; 
    int topp = -1; int size=0;
    
    MyStack() {
       
    }
    
    void push(int x) {
        topp = x;
        front.push(x);
        size++;
    }
    
    int pop() {
        size--;
        int n = size;
        int oldtopp = topp;
        
        while(n--){
            if(n==0)topp = front.front();
           end.push(front.front());
            front.pop();
        }
        front = end;
        while(!end.empty())end.pop();
        
       
        return oldtopp;
    }
    
    int top() {
        return topp;
    }
    
    bool empty() {
        return size<=0;
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