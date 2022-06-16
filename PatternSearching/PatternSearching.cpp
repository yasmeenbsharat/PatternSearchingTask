#include "pch.h"

#include"PatternSearching.h"

#include "MyException.h"

/**
 * @brief :Parameterized Constructor to create an empty trie node and points to it by m_root
 and for setting initial values to m_input
 * @param  string:input
*/
PatternSearching::PatternSearching() {

    m_root = new TrieNode('\0');

}

/**
 * @brief : this function use to find and print all the occurrences of pattern in the text
 * @param string: pattern
 */
void PatternSearching::Search(const std::string text,
    const std::string pattern) {
    try {
        if (text.empty())
            throw MyException("The input string must not be empty");
        if (pattern.empty())
            throw MyException("The pattern must not be empty");

        else if (text.length() > 1024)
            throw MyException("The input string limits is 1024 characters");

        else {
            std::string input = text;
            // input += '$';
            BulidSuffixTree(input);
            std::vector < int > result;
            bool r = true;
            TrieNode* current = m_root;

            for (int i = 0; i < pattern.length(); i++) {
                char key = pattern[i];
                current = current->m_children[key];
                if (current == NULL) {
                    r = false;
                    break;

                }

            }
            if (r) {
                CollectResult(current, result);
                std::cout << pattern << " is found at index ";
                for (size_t i = 0; i < result.size(); i++) {
                    std::cout << "," << result[i];
                }

            }
            else {
                std::cout << pattern << " is not found  ";

            }
        }

    }
    catch (const std::exception& exception) {
        std::cerr << exception.what() << "\n";
    }

}

/**
 * @brief :this function use to implement suffix tree for a string
 *
 * @param string: text
 */
void PatternSearching::BulidSuffixTree(std::string text) {

    for (int i = 0; i < text.length(); i++) {
        Insert(text.substr(i), i);

    }

}

/**
 * @brief :this function use to add a new suffix to the trie tree
 * @param word: The substring(suffix) to insert in the tree
 * @param index :The index of the first character in this substring
 */
void PatternSearching::Insert(std::string word, int index) {
    TrieNode* current = m_root;
    for (int i = 0; i <= word.length(); i++) {
        char key = word[i];
        if (current->m_children[key] == NULL) {
            if (key == '\0') {
                current->m_children[key] = new TrieNode('\0', index);
            }
            else {
                current->m_children[key] = new TrieNode(key);

            }
        }
        current = current->m_children[key];
    }
}
/**
 * @brief : Collect all the indexes where the pattern occur
 * @param current
 * @param result :vector <int >to store all the indexes where the pattern occur
 */
void PatternSearching::CollectResult(TrieNode* current, std::vector < int >& result) {

    for (int i = 0; i < MAX_CHAR; i++) {
        if (current->m_children[i] != NULL) {
            if (current->m_children[i]->m_key == '\0') {
                result.push_back(current->m_children[i]->m_startIndex);
            }
            else {
                CollectResult(current->m_children[i], result);
            }
        }
    }
}

/**
 * @brief :this function use to delete a suffix from the trie tree
 * @param node
 */

void PatternSearching::DeleteSuffix(TrieNode* node) {

    for (int i = 0; i < MAX_CHAR; i++) {
        if (node->m_children[i] != NULL) {
            if (node->m_children[i]->m_key == '\0') {
                delete node->m_children[i];
            }
            else {
                DeleteSuffix(node->m_children[i]);
                delete node->m_children[i];
            }
        }

    }
}

/**
 * @brief : Destructor to Free the dynamically allocated memory
 */

PatternSearching::~PatternSearching() {
    if (m_root != NULL) {
        for (int i = 0; i < MAX_CHAR; i++) {
            if (m_root->m_children[i] != NULL) {
                DeleteSuffix(m_root->m_children[i]);
            }
        }

    }
    delete m_root;
}