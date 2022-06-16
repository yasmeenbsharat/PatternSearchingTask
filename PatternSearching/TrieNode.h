#include <iostream>

#define MAX_CHAR 256
/**
 * @brief :every trie node has three main components an array of child pointers . The second one is an integer it stores the index
 of the suffix and the last one is a  character to store key.
*/

class TrieNode {

public:
    TrieNode(char key, int index = -1);
    friend class PatternSearching;
private:
    TrieNode* m_children[MAX_CHAR];
    char m_key;
    int m_startIndex;

};