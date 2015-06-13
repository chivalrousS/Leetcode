/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.
The class name of the Java function had been updated to MyStack instead of Stack.
*/
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(!topBuf.empty())
        {
            dataBuf.push(topBuf.front());
            topBuf.pop();
        }
        topBuf.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        topBuf.pop();
        if(dataBuf.size() < 1)
            return;
        int steps = dataBuf.size() - 1;

        while(steps > 0)
        {
            dataBuf.push(dataBuf.front());
            dataBuf.pop();
            --steps;
        }
        topBuf.push(dataBuf.front());
        dataBuf.pop();

    }

    // Get the top element.
    int top() {
        return topBuf.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return topBuf.empty() && dataBuf.empty();

    }
private:
    queue<int> topBuf;
    queue<int> dataBuf;
};
