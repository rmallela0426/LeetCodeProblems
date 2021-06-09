
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 208: Implement Trie (Prefix Tree)
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently
 * store and retrieve keys in a dataset of strings. There are various applications of this
 * data structure, such as autocomplete and spellchecker.
 *
 * Implement the Trie class:
 *  . Trie() Initializes the trie object.
 *  . void insert(String word) Inserts the string word into the trie.
 *  . boolean search(String word) Returns true if the string word is in the trie (i.e., was
 *                                inserted before), and false otherwise.
 *  . boolean startsWith(String prefix) Returns true if there is a previously inserted string
 *                                      word that has the prefix prefix, and false otherwise.
 *
 * Example 1:
 * Input
 *    ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 *    [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 *    [null, null, true, false, true, null, true]
 * Explanation
 *    Trie trie = new Trie();
 *    trie.insert("apple");
 *    trie.search("apple");   // return True
 *    trie.search("app");     // return False
 *    trie.startsWith("app"); // return True
 *    trie.insert("app");
 *    trie.search("app");     // return True
 *
 * Constraints:
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 104 calls in total will be made to insert, search, and startsWith.n
*/
class Trie {
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

public:
    /** Initialize your data structure here. */
    Trie() {
        // Allocate the root
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        // Assign the root to curr
        curr = root;

        // Traverse each char in word and create a trie
        for (char& ch : word) {
            // Check if there is already a children with this char or not
            if (!curr->children[ch - 'a']) {
                // No child with current char, create one
                curr->children[ch - 'a'] = new TrieNode();
            }

            // Move the curr to point to child node
            curr = curr->children[ch - 'a'];
        }

        // End of the word, define it that will help to know that a word is
        // ended at this curr position while traversing
        curr->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        // Assign the root to curr
        curr = root;

        // Traverse each char in the prefix and retrieve the children
        for (char& ch : word) {
            // Check if there childrens or words for the current char
            // If not return
            if (!curr->children[ch - 'a']) {
                return false;
            }

            // Adjust the curr to point the children
            curr = curr->children[ch - 'a'];
        }

        return curr->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        // Assign the root to curr
        curr = root;

        // Traverse each char in the prefix and retrieve the children
        for (char& ch : prefix) {
            // Check if there childrens or words for the current char
            // If not return
            if (!curr->children[ch - 'a']) {
                return false;
            }

            // Adjust the curr to point the children
            curr = curr->children[ch - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */