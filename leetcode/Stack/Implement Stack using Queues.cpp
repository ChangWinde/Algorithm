//  225. Implement Stack using Queues
//  Implement the following operations of a stack using queues.
//  push(x) -- Push element x onto stack.
//  pop() -- Removes the element on top of the stack.
//  top() -- Get the top element.
//  empty() -- Return whether the stack is empty.
//  https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        flag = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(!flag)
            first.push(x);
        else
            second.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        return exchange();
    }
    
    /** Get the top element. */
    int top() {
        if(flag){
            return second.back();
        }else{
            return first.back();
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(first.empty()&&second.empty())
            return true;
        return false;
    }
    int exchange(){
        int n;
        int temp;
        if(!flag){
            n = first.size()-1;
            while(n--){
                second.push(first.front());
                first.pop();
            }
            temp = first.front();
            first.pop();
            flag = 1;
        }else{
            n = second.size()-1;
            while(n--){
                first.push(second.front());
                second.pop();
            }
            temp = second.front();
            second.pop();
            flag = 0;
        }
        return temp;
    }
private:
    queue<int> first;
    queue<int> second;
    bool flag;
    //flag = 0表示数据在first，反之则在second中
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */