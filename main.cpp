#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Each node in the Trie
class TrieNode {
public:
    // Each node has up to 26 children (for each letter)
    TrieNode* children[26];

    // Marks if this node completes a word
    bool isEndOfWord;

    // Constructor
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// The Trie class
class Trie {
private:
    TrieNode* root;

    void findAllWords(TrieNode* node, string currentWord, vector<string>& results) {
        if (!node) return;

        
        if (node->isEndOfWord) {
            results.push_back(currentWord);
        }

        
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                char nextChar = 'a' + i;
                findAllWords(node->children[i], currentWord + nextChar, results);
            }
        }
    }

public:
    Trie() {
        // TODO: Implement this function
    }

    void insert(string word) {
        // TODO: Implement this function
    }

    bool search(string word) {
        TrieNode* current = root;
        if (word == "") return false;
        for (char c : word) {
            int index = c - 'a';
            if (index < 0 || index >= 26 || current->children[index] == nullptr)
                return false;
            current = current->children[index];
        }
        return current->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;
        if (prefix == "") return true;
        for (char c : prefix) {
            int index = c - 'a';
            if (index < 0 || index >= 26 || current->children[index] == nullptr)
                return false;
            current = current->children[index];
        }
        return true;
    }

    vector<string> autocomplete(string prefix) {
        vector<string> suggestions;
        // TODO: Implement this function
        return suggestions;
    }
};

int main() {
    cout << "=== TRIE DATA STRUCTURE IMPLEMENTATION ===" << endl;
    cout << "Testing all Trie functionalities..." << endl;

    Trie trie;

    cout << "\n1. Testing basic insertion and search:" << endl;
    cout << "======================================" << endl;

    vector<string> words = {"apple", "banana", "orange", "grape", "kiwi"};
    for (const string& word : words) {
        trie.insert(word);
        cout << "Inserted: " << word << endl;
    }

    for (const string& word : words) {
        bool found = trie.search(word);
        cout << "Search '" << word << "': " << (found ? "FOUND" : "NOT FOUND") << endl;
    }

    vector<string> nonExisting = {"app", "ban", "ora", "graph", "kiwis"};
    for (const string& word : nonExisting) {
        bool found = trie.search(word);
        cout << "Search '" << word << "': " << (found ? "FOUND" : "NOT FOUND") << " (expected: NOT FOUND)" << endl;
    }

    cout << "\n2. Testing prefix checking:" << endl;
    cout << "==========================" << endl;

    vector<string> prefixes = {"app", "ban", "ora", "grap", "k"};
    for (const string& prefix : prefixes) {
        bool hasPrefix = trie.startsWith(prefix);
        cout << "Prefix '" << prefix << "': " << (hasPrefix ? "EXISTS" : "DOESN'T EXIST") << endl;
    }

    vector<string> nonPrefixes = {"x", "yield", "zed", "micro", "nano"};
    for (const string& prefix : nonPrefixes) {
        bool hasPrefix = trie.startsWith(prefix);
        cout << "Prefix '" << prefix << "': " << (hasPrefix ? "EXISTS" : "DOESN'T EXIST") << " (expected: DOESN'T EXIST)" << endl;
    }

    cout << "\n3. Testing autocomplete functionality:" << endl;
    cout << "======================================" << endl;

    vector<string> testPrefixes = {"a", "b", "o", "g", "k", "ap", "ban", "ora", "gr", "ki"};
    for (const string& prefix : testPrefixes) {
        vector<string> suggestions = trie.autocomplete(prefix);
        cout << "Autocomplete for '" << prefix << "': ";
        if (suggestions.empty()) {
            cout << "No suggestions found";
        } else {
            for (size_t i = 0; i < suggestions.size(); i++) {
                if (i > 0) cout << ", ";
                cout << suggestions[i];
            }
        }
        cout << endl;
    }

    cout << "\n4. Testing edge cases:" << endl;
    cout << "======================" << endl;

    bool emptySearch = trie.search("");
    cout << "Search empty string: " << (emptySearch ? "FOUND" : "NOT FOUND") << " (expected: NOT FOUND)" << endl;

    bool emptyPrefix = trie.startsWith("");
    cout << "Starts with empty prefix: " << (emptyPrefix ? "EXISTS" : "DOESN'T EXIST") << " (expected: EXISTS)" << endl;

    vector<string> emptySuggestions = trie.autocomplete("");
    cout << "Autocomplete for empty string: ";
    if (emptySuggestions.empty()) {
        cout << "No suggestions found";
    } else {
        for (size_t i = 0; i < emptySuggestions.size(); i++) {
            if (i > 0) cout << ", ";
            cout << emptySuggestions[i];
        }
    }
    cout << " (expected: all words)" << endl;

    cout << "\n5. Testing with additional words:" << endl;
    cout << "================================" << endl;

    vector<string> additionalWords = {"application", "appetizer", "banister", "bandana", "oracle", "grapefruit"};
    for (const string& word : additionalWords) {
        trie.insert(word);
        cout << "Inserted: " << word << endl;
    }

    for (const string& word : additionalWords) {
        bool found = trie.search(word);
        cout << "Search '" << word << "': " << (found ? "FOUND" : "NOT FOUND") << endl;
    }

    vector<string> newPrefixes = {"app", "ban", "ora", "gra"};
    for (const string& prefix : newPrefixes) {
        vector<string> suggestions = trie.autocomplete(prefix);
        cout << "Autocomplete for '" << prefix << "': ";
        if (suggestions.empty()) {
            cout << "No suggestions found";
        } else {
            for (size_t i = 0; i < suggestions.size(); i++) {
                if (i > 0) cout << ", ";
                cout << suggestions[i];
            }
        }
        cout << endl;
    }

    cout << "\n6. Testing case sensitivity:" << endl;
    cout << "============================" << endl;

    trie.insert("Hello");
    trie.insert("WORLD");

    vector<string> caseWords = {"hello", "Hello", "WORLD", "world"};
    for (const string& word : caseWords) {
        bool found = trie.search(word);
        cout << "Search '" << word << "': " << (found ? "FOUND" : "NOT FOUND") << endl;
    }

    cout << "\n=== ALL TESTS COMPLETED ===" << endl;

    return 0;
}
