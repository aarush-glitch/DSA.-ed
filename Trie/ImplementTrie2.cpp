#include <bits/stdc++.h> 
struct Node {
    Node* link[26];
    int cntEnd=0;
    int cntPref=0;

    bool containsKey(char ch) {
        return (link[ch-'a']!=nullptr);
    }

    Node* get(char ch) {
        return link[ch-'a'];
    }

    void put(char ch, Node* node) {
        link[ch-'a'] = node;
    }

    void incEnd() {cntEnd++;}
    void incPref() {cntPref++;}
    void deleteEnd() {cntEnd--;}
    void deletePref() {cntPref--;}

    int getEnd() {return cntEnd;}
    int getPref() {return cntPref;}
};

class Trie{
    private: Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->incPref();
        }
        node->incEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }
            else return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }
            else return 0;
        }
        return node->getPref();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0; i<word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->deletePref();
            }
            else return;
        }
        node->deleteEnd();
    }
};
