struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL); 
    }
    void put(char ch){
        links[ch-'a'] = new Node(); 
    }
    Node* getlink(char ch){
        return links[ch-'a']; 
    }
    void setEnd(){
        flag = true; 
    }
}; 

class Trie {
private: Node* root;

public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* varan = root; 

        for(int i=0; i<word.size(); ++i){
            if(!varan->containsKey(word[i])){
                varan->put(word[i]); 
            }
            varan = varan->getlink(word[i]); 
        }
        varan->setEnd(); 
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* varan = root;
        for(int i=0; i<word.size(); ++i){
            if(!varan->containsKey(word[i])){
                return false; 
            }
            varan = varan->getlink(word[i]); 
        }
        return varan->flag; 
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* varan = root;
        for(int i=0; i<prefix.size(); ++i){
            if(!varan->containsKey(prefix[i])){
                return false; 
            }
            varan = varan->getlink(prefix[i]); 
        }
        return true; 
    }
};
