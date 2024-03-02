#include<iostream>
using namespace std;
#include<vector>
#include <bits/stdc++.h>

template <typename T>
class ArrayList {
    private:
    int capacity;
    int noofitems;

    public:
    vector<int> a;

    ArrayList(int cap = 0) {
        this->capacity = cap;
        this->noofitems = 0;
    }
    
    void insertionSort(std::vector<int>& a) {
        int n = a.size();
        for (int i = 1; i < n; ++i) {
            int key = a[i];
            int j = i - 1;

            
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
    }

    void insertionSort() {
        insertionSort(a);
    }

    void bubbleSort(std::vector<int>& a) {
        int n = a.size();

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }

    void bubbleSort() {
        bubbleSort(a);
    }

    int size() {
        return a.size(); 
    }

    void print() {
        // insertionSort(a);
        for (const auto& i : a) cout << i << " ";
        cout << endl;
    }

    void append(const T& data) {
        a.push_back(data);
    }


    void printreverse(const vector<T>& a) {
        for (auto it = a.rbegin(); it != a.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    void printreverse() {
        printreverse(a);
    }

    void insertNthPos(int pos,const T& data) {
        a.insert(a.begin() + pos - 1,data);
    }

    int indexOf(int data) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == data) {
                return i;
            }
        }
        return -1;
    }

    int lastIndexOf(int data) {
        for(int i = a.size() - 1; i >= 0; i--) {
            if(a[i] == data) {
                return i;
            }
        }
        return -1;
    }

    void removeValue(int index) {
        a.erase(a.begin() + indexOf(index) - 2);
    }

    void setValue(int pos, int data) {
        a.at(pos - 1) = data;
    }

    bool contains(int data) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == data) {
                return true;
            }
        }
        return false;
    }

    bool isEmpty() {
        return a.empty();
    }

    void clear() {
        a.clear();
    }

    


    
    

};


int main() {

    ArrayList<int> l(5);
    for(int i = 0; i < 5; i++) {
        l.append(i+1);
    }

    l.print();
    l.printreverse();
    l.append(6);
    l.append(7);
    l.print();
    l.printreverse();
    l.append(8);
    l.insertNthPos(3,9);
    l.print();
    l.append(9);
    cout << l.indexOf(9) << " " << l.lastIndexOf(9) << endl;
    l.print();
    l.removeValue(4);
    l.print();
    l.setValue(3,15);
    l.print();
    l.bubbleSort();
    l.print();
    l.insertionSort();
    l.print();



    return 0;
} 