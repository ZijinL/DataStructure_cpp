// leetcode 225
// 

# include <iostream>
# include <queue>
using namespace std;

class MyStack {
private:
queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int length = que.size();
        int top = que.back();
        for (int i=0; i < length-1; i++)
        {
            que.push(que.front());
            que.pop();
        }
        que.pop();
        return top;
    }
    
    /** Get the top element. */
    int top() {
        return que.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
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

int main()
{

}