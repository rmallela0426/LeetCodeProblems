
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 211: Design and Search Words Data Structure
 *
 * Design a data structure that supports adding new words and finding if a string matches any
 * previously added string.
 *
 * Implement the WordDictionary class:
 *    WordDictionary() Initializes the object.
 *    void addWord(word) Adds word to the data structure, it can be matched later.
 *    bool search(word) Returns true if there is any string in the data structure that matches
 *                     word or false otherwise. word may contain dots '.' where dots can be
 *                     matched with any letter.
 *
 * Example:
 * Input: ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 *        [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output: [null,null,null,null,false,true,true,true]
 * Explanation:
 *    WordDictionary wordDictionary = new WordDictionary();
 *    wordDictionary.addWord("bad");
 *    wordDictionary.addWord("dad");
 *    wordDictionary.addWord("mad");
 *    wordDictionary.search("pad"); // return False
 *    wordDictionary.search("bad"); // return True
 *    wordDictionary.search(".ad"); // return True
 *    wordDictionary.search("b.."); // return True
 *
 * Constraints:
 * 1 <= word.length <= 500
 * word in addWord consists lower-case English letters.
 * word in search consist of  '.' or lower-case English letters.
 * At most 50000 calls will be made to addWord and search.
*/
class WordDictionary {
    // Definition of a Trie Node
    struct TrieNode {
        // tells Whether the word ends here or not
        bool isWord = false;
        // Holds the pointers of their children as there are only
        // only 26 lower case letters, the size of the vector is 26            
        vector<TrieNode*> children{ vector<TrieNode*>(26, NULL) };
    };

    // Pointers to store the root and curr nodes
    TrieNode* root;
    TrieNode* curr;

    bool dfs(TrieNode* node, string& word, int idx) {
        // Checck if we are done with all chars in the word
        if (idx >= word.length()) {
            // return true if the word ends here
            return node->isWord;
        }

        // Check if the current char is '.' or not
        if (word[idx] == '.') {
            // Current char is '.' which matches to any char
            // Traverse all the children 
            for (auto& child : node->children) {
                // Check if this Child is available or not
                if (child) {
                    // Child is present try to check if this matches to
                    // the search word or not
                    // Perform a dfs with the next char
                    if (dfs(child, word, idx + 1)) {
                        // Search word is found, return true
                        return true;
                    }
                }
            }
        }
        else {
            // Check if there is a word starting with this char
            if (!node->children[word[idx] - 'a']) {
                // No child is available with this char
                return false;
            }

            // There is a word with current char, perform a dfs
            return dfs(node->children[word[idx] - 'a'], word, idx + 1);
        }

        return false;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        // Allocate the root
        root = new TrieNode();
    }

    void addWord(string word) {
        // Assign root to curr
        curr = root;

        // Traverse each char of the word and build a Trie
        for (char& ch : word) {
            // Check if there is already a children
            if (!curr->children[ch - 'a']) {
                // No child with current char, create one
                curr->children[ch - 'a'] = new TrieNode();
            }

            // Move the curr to point to that children
            curr = curr->children[ch - 'a'];
        }

        // once done, creating a word, fill the isword to true
        // to tell that the current word ends here
        curr->isWord = true;

        return;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
