#include "TrieNode.h"

#include <string>

#include <iostream>

#include <vector>

/**
 * @brief
 */
class PatternSearching {
public:
    PatternSearching();
    void Search(const std::string text,
        const std::string pattern);
    void BulidSuffixTree(std::string text);
    void Insert(std::string word, int index);
    void CollectDollar(std::unordered_map < char, TrieNode* > children, std::vector < int >& result);
    void DeleteSuffix(TrieNode* node);
    ~PatternSearching();

private:
    TrieNode* m_root;

};
