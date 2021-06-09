
/*
 *  Author: Raghavendra Mallela
*/
/*
 * LeetCode 1268: Search Suggestions System
 *
 * Given an array of strings products and a string searchWord. We want to design
 * a system that suggests at most three product names from products after each
 * character of searchWord is typed. Suggested products should have common prefix
 * with the searchWord. If there are more than three products with a common prefix
 * return the three lexicographically minimums products.
 *
 * Return list of lists of the suggested products after each character of searchWord
 * is typed. 
 *
 * Example 1:
 * Input: products = ["mobile","mouse","moneypot","monitor","mousepad"],
 *        searchWord = "mouse"
 * Output: [
 * ["mobile","moneypot","monitor"],
 * ["mobile","moneypot","monitor"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"],
 * ["mouse","mousepad"]
 * ]
 * Explanation: products sorted lexicographically = 
 *     ["mobile","moneypot","monitor","mouse","mousepad"]
 * After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
 * After typing mou, mous and mouse the system suggests ["mouse","mousepad"]
 *
 * Example 2:
 * Input: products = ["havana"], searchWord = "havana"
 * Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
 *
 * Example 3:
 * Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
 * Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]
 *
 * Example 4:
 * Input: products = ["havana"], searchWord = "tatiana"
 * Output: [[],[],[],[],[],[],[]]
 *
 * Constraints:
 * 1 <= products.length <= 1000
 * There are no repeated elements in products.
 * 1 <= Σ products[i].length <= 2 * 10^4
 * All characters of products[i] are lower-case English letters.
 * 1 <= searchWord.length <= 1000
 * All characters of searchWord are lower-case English letters. 
*/
/* Approach is to sort the input list and restrict the possibilities linearly4
 * using 2 pointers approach
*/
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    // sort the input vector in ascending lexicographical order
    sort(products.begin(), products.end());

    // variable to store the result which is of size searchword length
    vector<vector<string>> res(searchWord.length());

    // Two pointers that can help to identify to search the products linearly
    int left = 0;
    int right = products.size() - 1;

    // Traverse each char in a searchword
    for (int i = 0; i < searchWord.length(); i++) {
        // skip the products that doesn't start with current chars
        // and whose products doesn't have enough length of current
        // index
        while (left <= right &&
            (products[left].length() <= i || products[left][i] != searchWord[i])) {
            // current product at left index is not a suitable product
            left++;
        }

        while (left <= right &&
            (products[right].length() <= i || products[right][i] != searchWord[i])) {
            // current product at right index is not suitable
            right--;
        }

        // Now that there are suitable products between left and right, extract
        // first three products and push it to result
        for (int k = left; k <= right && k < left + 3; k++) {
            res[i].push_back(products[k]);
        }
    }

    return res;
}

/* Approach is to create a trie data structure with the input products
 * Once Trie is created, traverse each character in search word and
 * traverse the TRIE using dfs + backtracking and return the 3 words
 * that are matching and push it to result
*/
class Trie {
private:
    // Definition of a Trie Node
    struct TrieNode {
        // tells Whether the word ends here or not
        bool isWord = false;
        // Holds the pointers of their children as there are only
        // only 26 lower case letters, the size of the vector is 26            
        vector<TrieNode*> children{ vector<TrieNode*>(26, NULL) };
    };

    TrieNode* root;
    TrieNode* curr;

    void dfs(TrieNode* curr, string& word, vector<string>& result) {
        // Only 3 words are needed, so return if vector has 3
        if (result.size() == 3) {
            // 3 suggested words are already traversed
            return;
        }

        // Check if we have a complete word
        if (curr->isWord) {
            // Got a word, push it to result
            result.push_back(word);
        }

        // perform the dfs for all possible children
        for (char ch = 'a'; ch <= 'z'; ch++) {
            // check whether current child is NULL or not
            if (curr->children[ch - 'a']) {
                // Add the curr char to the word
                word += ch;
                // perform dfs until we found a word
                dfs(curr->children[ch - 'a'], word, result);
                // Remove the last char that is added to the word
                // to get the next word
                word.pop_back();
            }
        }

        return;
    }

public:
    Trie() {
        // Construct the root node
        root = new TrieNode();
    }

    // Function for inserting the words into the Trie
    void insert(string& st) {
        // Make the curr as root
        curr = root;

        // traverse each char in input string
        for (char& ch : st) {
            // Check if there is already child with the curr char or not
            if (!curr->children[ch - 'a']) {
                // Child for the current char is not present, creating one
                curr->children[ch - 'a'] = new TrieNode();
            }

            // Assign the current child to curr
            curr = curr->children[ch - 'a'];
        }

        // Now Curr points to the end character of the string
        // Mark the isWord to true so that while traversing we get to know
        // that a word is ended here
        curr->isWord = true;
    }

    // Function to retrieve the suggested strings that matches the prefix
    void retrieveSuggestedWords(string& prefix, vector<string>& result) {
        // Assign the root to curr
        curr = root;

        // Traverse each char in the prefix and retrieve the children
        for (char& ch : prefix) {
            // Check if there childrens or words for the current char
            // If not return
            if (!curr->children[ch - 'a']) {
                return;
            }

            // Adjust the curr to point the children
            curr = curr->children[ch - 'a'];
        }

        // Now that curr points to the node that matches the prefix and holds
        // all words matching the prefix, perform dfs and backtracking to
        // retreive all words
        dfs(curr, prefix /*temp for backtracking*/, result);

        return;
    }


};


vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    // variable to store the result which is of size searchword length
    vector<vector<string>> res;

    // Create an object for Trie class
    Trie* trie = new Trie();

    // Add the products to trie data structure
    for (string& product : products) {
        trie->insert(product);
    }

    // vector that stores suggested words for each character
    vector<string> words;

    string prefix = "";

    // Traverse each character from search word and find suggested words
    for (char& ch : searchWord) {
        // Clear the temporary words array to get new list of words
        words.clear();

        // Add the current char to prefix string
        prefix += ch;

        // search Trie to find all suggested words
        trie->retrieveSuggestedWords(prefix, words);
        // Push all suggested words to the result
        res.push_back(words);
    }

    // Delete Trie
    delete trie;

    return res;
}
