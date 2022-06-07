#include "TrieNode.h"

#include <string>

#include <iostream>

#include <vector>

/**
* @brief:@brief :this class is used to find all the occurrences of a pattern in the text.
 The first stage in this process is to construct the suffix tree of all suffixes and
 then Collect all the indexes where the pattern occurs and print them.
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
