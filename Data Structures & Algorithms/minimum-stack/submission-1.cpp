class MinStack {
public:
    stack<int> s;
    stack<int> minim;
    MinStack() {
    }
    
    void push(int val) {
        int elem = minim.empty() ? INT_MAX : minim.top();
        s.push(val);
        minim.push(min(val, elem));
    }
    
    void pop() {
        s.pop();
        minim.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minim.top();
    }
};
