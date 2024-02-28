#include<iostream>
using namespace std;
#define no_letters 26

// tries

class TrieNode {
    public:
    TrieNode* children[no_letters];
    bool isEndofWord;

    TrieNode() {
        for(int i = 0; i < no_letters; i++) {
            children[i] = NULL;
        }
        isEndofWord = false;
    }
};

class Trie {
    private:
    TrieNode *root[no_letters];

    void deleteNodes(TrieNode* ptr) {
        if(ptr == NULL) return;
        for(int i = 0; i < no_letters; i++) deleteNodes(ptr->children[i]);
        delete ptr;
    }

    public:
    Trie() {
        for(int i = 0; i < no_letters;i++) root[i] = NULL;
    }

    ~Trie() {
        for(int i = 0; i < no_letters; i++) deleteNodes(root[i]);
    }

    TrieNode* getNode(void) {
        TrieNode* node = new TrieNode();
        node->isEndofWord = false;

        for(int i = 0; i < no_letters; i++) {
            node->children[i] = NULL;
        }

        return node;
    }


    void insert(TrieNode* root, string word) {
        TrieNode* node = root;

        for(uint32_t i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(!node->children[index]) node->children[index] = getNode();
            node = node->children[index];
        }

        node->isEndofWord = true;
    }

    

    bool search(TrieNode* root, string word) {
        TrieNode* node = root;

        for(int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if(!node->children[index]) return false;
            node = node->children[index];
        }

        return (node != NULL && node->isEndofWord);
    }

    

    bool isEmpty(TrieNode* root) {
        for(int i = 0; i < no_letters; i++) {
            if(root->children[i]) return false;
        }
        return true;
    }


    TrieNode* remove(TrieNode* root, string word, int depth = 0) {
        if(!root) {
            return NULL;
        }

        if(depth == word.size()) {
            if(root->isEndofWord) {
                root->isEndofWord = false;
            }
            if(isEmpty(root)) {
                delete root;
                root = NULL;
            }

            return root;
        }

        int index = word[depth] - 'a';
        root->children[index] = remove(root->children[index],word,depth+1);

        if(isEmpty(root) && root->isEndofWord == false) {
            delete root;
            root = NULL;
        }

        return root;
    } 
    
    
    

};


int main() {

    Trie *trie = new Trie();

    string keys[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" };

    TrieNode* root = trie->getNode();
    

    trie->insert(root,keys[0]);
    trie->insert(root,keys[1]);
    bool result = trie->search(root,keys[0]);
    cout<<result<<endl;
    root = trie->remove(root,keys[0]);
    result = trie->search(root,keys[0]);
    cout<<result<<endl;
    
    return 0;
}