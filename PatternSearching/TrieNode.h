#include <iostream>

#include <unordered_map>

/**
 * @brief :every trie node has two main components an unordered map  to child node where the key is a character
 and the value is a pointer to another node  and the second one is an integer it stores the index
 of the suffix
*/

class TrieNode {

public:
    TrieNode(int index = -1);
    friend class PatternSearching;
private:
    std::unordered_map < char, TrieNode* > m_children;
    int m_startIndex;

};
