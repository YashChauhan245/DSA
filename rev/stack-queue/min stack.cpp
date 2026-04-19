https://leetcode.com/problems/min-stack/description/


class MinStack {
    stack<int>mainstack;
    stack<int>minstack;
public:
    MinStack() {
    }
    
    void push(int val) {
        mainstack.push(val);
        if (minstack.empty()) {
            minstack.push(val);
        } 
        else {
            minstack.push(min(val, minstack.top()));
        }
    }
    
    void pop() {
        mainstack.pop();
        minstack.pop();
    }
    
    int top() {
        return mainstack.top();     
    }
    
    int getMin() {
        return minstack.top();
    }
};

