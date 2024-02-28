#include<iostream>
using namespace std;
#include<stack>
#include<bits/stdc++.h>
#include<queue>

class Stacklist {
    private:
    int capacity;
    int noofitems;

    public:
    stack<int> s;
    stack<int> s2;
    stack<int> orgstack;
    Stacklist(int cap = 0) {
        this->capacity = cap;
        this->noofitems = 0;
    }

    int scapacity() {
        return s.size();
    }

    bool isEmpty() {
        return s.empty();
    }

    void push(int data) {
        s.push(data);
    }

    void pop() {
        s.pop();
    }

    int topval() {
        return s.top();
    }

    int findMin() {
        stack<int> normalstack = s;
        int min = s.top();

        while(!normalstack.empty()) {            
            if(min > normalstack.top()) {
                min = normalstack.top();
            }
            normalstack.pop();
        }

        return min;
    }
    


    int findMax() {
            stack<int> normalstack = s;
            int max = s.top();

        while(!normalstack.empty()) {            
                if(max < normalstack.top()) {
                    max = normalstack.top();
                }
                normalstack.pop();
        }

            return max;
    }



    void print() {
        stack<int> normalStack = s;
        while(!normalStack.empty()) {
            cout << normalStack.top() << " ";
            normalStack.pop();
        }
        cout << endl;
    }

    void reverseprint() {
        int val;
        stack<int> s2 = s;
        stack<int> reverseStack;
        
        while(!s2.empty()) {
            val = s2.top();
            reverseStack.push(val);
            s2.pop();
        }

        while(!reverseStack.empty()) {
            cout << reverseStack.top() << " ";
            reverseStack.pop();
        }

        cout << endl;
    }

    

    

    
};

stack<int> sortStack(stack<int> normalstack) {
    stack<int> tempstack;

    while(!normalstack.empty()) {
        int temp = normalstack.top();
        normalstack.pop();

        // top < temp 
        while(!tempstack.empty() && tempstack.top() < temp) {
            normalstack.push(tempstack.top());
            tempstack.pop();
        }
        tempstack.push(temp);
    }

    return tempstack;
}


bool isPalindrome(string word) {
    queue<char> qw;
    stack<char> sw;
    for(int i = 0; i < word.size(); i++) {
        qw.push(word[i]);
        sw.push(word[i]);
    }

    bool flag = true;
    while(!qw.empty() && !sw.empty()) {
        if(qw.front() != sw.top()) {
            flag = false;
            break;
        }
        qw.pop();
        sw.pop();
    }

    return flag;
}





int main() {

    // Stacklist s1(0);
    // cout << s1.isEmpty() << endl;
    // s1.push(5);
    // cout << s1.isEmpty() << endl;
    // s1.pop();
    // cout << s1.isEmpty() << endl;
    // s1.push(6);
    // s1.push(7);
    // s1.push(8);
    // cout << s1.scapacity() << endl;
    // s1.print();

    // s1.reverseprint();

    Stacklist s2;
    s2.push(6);
    s2.push(5);
    s2.push(7);
    s2.print();
    int min = s2.findMin();
    int max = s2.findMax();
    
    cout << s2.findMin() << " " << s2.findMax() << endl; 
    stack<int> s1 = sortStack(s2.s);
    Stacklist sortedstack; 

    while(!s1.empty()) {
        sortedstack.push(s1.top());
        s1.pop();
    }

    sortedstack.print();
    sortedstack.reverseprint();

    string w = "hello";
    cout << isPalindrome(w) << endl;


    
    
    
    






    return 0;
}