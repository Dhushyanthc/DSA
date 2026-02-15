#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class MinStack {
public:
    vector<int> st;
    vector<int> str;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);

        if (str.empty()) 
        {str.push_back(val);
        } else
        {
            str.push_back(min(val, str.back()));
        }
    }
    
    void pop() {
        st.pop_back();
        str.pop_back();
        
    }
    
    int top() {
        return st.back();
        
    }
    
    int getMin() {
        return str.back();
    }
};

int main() {
    MinStack* obj = new MinStack();
    
    // Test push operations
    cout << "Testing MinStack Operations:" << endl;
    cout << "---------------------------" << endl;
    
    obj->push(5);
    cout << "push(5) - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    obj->push(3);
    cout << "push(3) - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    obj->push(7);
    cout << "push(7) - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    obj->push(2);
    cout << "push(2) - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    // Test top operation
    cout << "\nTesting top(): " << obj->top() << endl;
    
    // Test getMin operation
    cout << "Testing getMin(): " << obj->getMin() << endl;
    
    // Test pop operations
    cout << "\nTesting pop() operations:" << endl;
    cout << "-------------------------" << endl;
    
    obj->pop();
    cout << "After pop() - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    obj->pop();
    cout << "After pop() - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    obj->pop();
    cout << "After pop() - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    // Add more elements to test
    obj->push(10);
    cout << "\npush(10) - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    obj->push(1);
    cout << "push(1) - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    obj->push(4);
    cout << "push(4) - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    cout << "\nFinal state - Top: " << obj->top() << ", Min: " << obj->getMin() << endl;
    
    delete obj;
    return 0;
}
