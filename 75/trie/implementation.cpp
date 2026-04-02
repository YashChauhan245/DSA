https://leetcode.com/problems/implement-trie-prefix-tree/description/


class Trie {
public:

    //structure 
    struct trieNode { 
        trieNode *children[26]; 
        bool isEndOfWord; 
    };
    
    //new node function 
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndOfWord = false;
        
        for (int i = 0; i < 26; i++) {
			newNode->children[i] = NULL;
		}
        
        return newNode;
    }
    
    /** Initialize data structure  */
    trieNode* root;
    
    Trie() {
        root = getNode();
    }
    
    /* Insert */
    void insert(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; //index of current char
            if (!crawler->children[index]) //if no node in current indx of crawlpointer 
                crawler->children[index] = getNode(); //make new node 
            
            crawler = crawler->children[index]; //crawl ++
        }
        
        crawler->isEndOfWord = true; //mark true for last char
    }
    
    /*Search */
    bool search(string word) {
        trieNode *crawler = root; 
        
        for (int i = 0; i < word.length(); i++) { 
            int index = word[i] - 'a'; 
            if (!crawler->children[index]) 
                return false; 
            crawler = crawler->children[index]; 
        }
        return (crawler != NULL && crawler->isEndOfWord); 
    }
    
    /* starts with */
    bool startsWith(string prefix) {
        trieNode *crawler = root;
        int i = 0;
        for (; i < prefix.length(); i++) { 
            int index = prefix[i] - 'a'; 
            
            if (!crawler->children[index]) 
                return false; 
            
            crawler = crawler->children[index]; 
        }
        if(i==prefix.length())
            return true;
        return false;
    }
};

