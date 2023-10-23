#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

// TrieNode class for the Trie data structure
class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26];
    
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

// Trie class for word storage and search
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }
    
    // Search for a word in the Trie
    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node != nullptr && node->isEndOfWord;
    }
    
    // Get starting indices of suffixes in the Trie
    vector<int> getSuffixesStartIndices(const string& word) {
        vector<int> indices;
        TrieNode* node = root;
        for (int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            if (!node->children[index]) {
                break;
            }
            node = node->children[index];
            if (node->isEndOfWord) {
                indices.push_back(i + 1);
            }
        }
        return indices;
    }

private:
    TrieNode* root;
};

int main() {
   ios_base::sync_with_stdio(0);
     cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input_02.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // Initialize the Trie and data structures
    Trie trie;
    queue<pair<string, string>> wordQueue;
    unordered_set<string> compoundWords;
    auto start = std::chrono::high_resolution_clock::now();
    
    string word;

    // Read words from input
    while (cin >> word) {
        // Find suffixes and add them to the queue
        vector<int> sufIndices = trie.getSuffixesStartIndices(word);
        
        for (int i : sufIndices) {
            if (i >= word.length()) {
                break;
            }
            wordQueue.push({word, word.substr(i)});
        }
        
        // Insert the word into the Trie
        trie.insert(word);
    }

    pair<string, string> p;
    int maxLength = 0;
    string longest = "";
    string secLongest = "";

    // Process the words to find the longest and second longest compound words
    while (!wordQueue.empty()) {
        p = wordQueue.front();
        wordQueue.pop();
        string remainingSuffix = p.second;
        vector<int> sufIndices = trie.getSuffixesStartIndices(remainingSuffix);
        
        if (sufIndices.empty()) {
            continue;
        }

        for (int i : sufIndices) {
            if (i > remainingSuffix.length()) {
                break;
            }

            if (i == remainingSuffix.length()) {
                if (p.first.length() > maxLength) {
                    secLongest = longest;
                    maxLength = p.first.length();
                    longest = p.first;
                }
                compoundWords.insert(p.first);
            } else {
                wordQueue.push({p.first, remainingSuffix.substr(i)});
            }
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto time_taken = std::chrono::duration_cast<milliseconds>(stop - start);
    
    // Print the results and time taken
    cout << "Longest Compound Word: " << longest << endl;
    cout << "Second Longest Compound Word: " << secLongest << endl;
    cout << "Time taken to process the input file: "<< time_taken.count()<< " milliseconds" << endl;

    return 0;
}
