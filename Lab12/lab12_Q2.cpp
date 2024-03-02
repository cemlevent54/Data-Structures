#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<iterator>
#include<string>

using namespace std;

class mapOfWords {
public:
	std::unordered_map<string, int> um;

	mapOfWords() {
		um.reserve(100);
	}

	~mapOfWords() {
		um.clear();
	}

	void add(string s, int val) {
		if (um.count(s) != 0) {
			cout << s << " is already existed." << endl;
		}
		else {
			um.emplace(s, val);
		}
	}

	void search(string s) {
		if (um.count(s) != 0) {
			cout << s << " : " << um[s] << endl;
		}
		else {
			cout << s << " is not found" << endl;
		}
	}

	void remove(string s) {
		um.erase(s);
	}

	void print() {
		for (auto& iter: um) {
			cout << iter.first << " " << iter.second << endl;
		}
	}


};


int main() {
	mapOfWords m;
	int choice, val;
	string s;

	while (1) {
		cout << "1. Insert" << endl;
		cout << "2. Search" << endl;
		cout << "3. Delete" << endl;
		cout << "4. Traverse" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice == 0) {
			break;
		}

		else if (choice == 1) {
			cout << "key: ";
			cin >> s;
			cout << "val: ";
			cin >> val;
			m.add(s, val);
		}

		else if (choice == 2) {
			cout << "search: ";
			cin >> s;
			m.search(s);
		}

		else if (choice == 3) {
			cout << "delete key: ";
			cin >> s;
			m.remove(s);
		}

		else if (choice == 4) {
			cout << "map: " << endl;
			m.print();
		}
	}

	return 0;
}