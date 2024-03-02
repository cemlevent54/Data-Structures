#include<iostream>
using namespace std;
#include<iterator>
#include<list>
#include<vector>
#include<algorithm>


void orderUnion(list<int> l1, list<int> l2) {

    list<int> result;
    list<int>::iterator temp1 = l1.begin();
    list<int>::iterator temp2 = l2.begin();
    

    int size1 = l1.size();
    int size2 = l2.size();
    
    while(temp1 != l1.end()) {
        while(temp2 != l2.end()) {
            if(*temp1 < *temp2) {
                result.push_back(*temp1);
                temp1++;
            }
            else if(*temp2 < *temp1) {
                result.push_back(*temp2);
                temp2++;
            }
            else if(*temp1 == *temp2) {
                result.push_back(*temp2);
                temp1++;
                temp2++;
            }
            if(temp1 == l1.end()) {
                break;
            }
            else if(temp2 == l2.end()) {
                break;
            }
        }
        if(temp1 == l1.end()) {
            while(temp2 != l2.end()) {
                result.push_back(*temp2);
                temp2++;
            }
            break;
        }

        else if(temp2 == l2.end()) {
            while(temp1 != l1.end()) {
                result.push_back(*temp1);
                temp1++;
            }
            break;
        }
    }

    for(list<int>::iterator it = result.begin(); it != result.end(); it++) {
        cout << *it << " ";
    }

}

void orderArrayList(vector<int>& v1, vector<int>& v2) {
    vector<int> result;
    vector<int>::iterator temp1 = v1.begin();
    vector<int>::iterator temp2 = v2.begin();

    while(temp1 != v1.end() && temp2 != v2.end()) {
        if(*temp1 > *temp2) {
            result.push_back(*temp2);
            temp2++;
        }
        else if(*temp2 > *temp1) {
            result.push_back(*temp1);
            temp1++;
        }
        else if(*temp1 == *temp2) {
            result.push_back(*temp1);
            temp1++;
            temp2++;
        }
        if(temp1 == v1.end()) {
            break;
        }
        else if(temp2 == v2.end()) {
            break;
        }    
    }

    while(temp1 != v1.end()) {
        result.push_back(*temp1);
        temp1++;
    }

    while(temp2 != v2.end()) {
        result.push_back(*temp2);
        temp2++;
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }


}

bool isPalindrome(list<int> l) {
    list<int>::iterator temp1 = l.begin();
    list<int>::iterator temp2 = prev(l.end());

    bool flag = true;
    while(temp1 != l.end()) {
        if(*temp1 != *temp2) {
            flag = false;
            break;
        }
        temp1++;
        temp2--;
    }

    return flag;
}

template<typename T>
bool checkPalindrome(list<T> l) {
    int size = l.size();
    int counter; 

    if(size % 2 == 0) {
        counter = size / 2;
    }
    else if(size % 2 == 1) {
        counter = (size+1) / 2;
    }

    for(int i = 0; i < counter; i++) {
        if(l.size() == 1) {
            break;
        }
        else if(l.front() != l.back()) {
            return false;
        }
        else {
            l.pop_back();
            l.pop_front();
        }
    }
    
    return true;
}


int main() {   

    // list<int> l1,l2;

    // l1 = {0,1,2,3,4,5};
    // l2  = {2,4,8};

    // orderUnion(l1,l2);


    //-------------------

    // vector<int> v1, v2;
    // v1 = {0,5,6,8};
    // v2 = {1,2,3,4,7};

    // sort(v1.begin(),v1.end());
    // sort(v2.begin(),v2.end());

    // orderArrayList(v1,v2);

    //-------------------

    list<int> l;
    l = {1,2,3,3,2,1};

    cout << isPalindrome(l) << " " << checkPalindrome(l) << endl;

    list<char> l2;
    l2 = {'k','a','p','a','k'};
    cout << checkPalindrome(l2) << endl;
    


    return 0;
}