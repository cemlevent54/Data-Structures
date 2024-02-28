#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<iterator>

using namespace std;

#define table_size 2011

class Hashset {
public:
    unordered_map<int, int> um;

    Hashset() {
        um.reserve(table_size);
    }

    ~Hashset() {
        um.clear();
    }

    int hashfunc(int key) {
        return key % table_size;
    }

    void insert(int key, int value) {
        if (um.find(key) == um.end()) {
            um.emplace(key, value);
            cout << "Key " << key << " inserted with value " << value << endl;
        }
        else {
            cout << "Key " << key << " already exists. Cannot insert." << endl;
        }
    }

    void search(int key) {
        if (um.find(key) != um.end()) {
            cout << "Value at key " << key << ": " << um[key] << endl;
        }
        else {
            cout << "Key is not found" << endl;
        }
    }

    void remove(int key) {
        if (um.find(key) != um.end()) {
            um.erase(key);
            cout << "Key " << key << " removed" << endl;
        }
        else {
            cout << "Key " << key << " not found. Cannot remove." << endl;
        }
    }

    void print() {
        for (auto iter = um.begin(); iter != um.end(); iter++) {
            cout << iter->first << " " << iter->second << endl;
        }
    }
};

int main() {
    Hashset h;

    int choice, key, val;

    while (1) {
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Traverse" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }
        else if (choice == 1) {
            cout << "Insert key: ";
            std::cin >> key;
            cout << "Insert value: ";
            std::cin >> val;
            h.insert(key, val);
        }

        else if (choice == 2) {
            cout << "Search key: ";
            std::cin >> key;
            h.search(key);
        }

        else if (choice == 3) {
            cout << "Delete key: ";
            std::cin >> key;
            h.remove(key);
        }

        else if (choice == 4) {
            cout << "Traverse: " << endl;
            h.print();
        }

        else {
            cout << "Wrong choice! Try again" << endl;
        }
    }

    return 0;
}