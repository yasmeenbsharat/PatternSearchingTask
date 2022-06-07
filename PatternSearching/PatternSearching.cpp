#include"PatternSearching.h"

#include "MyException.h"

/**
 * @brief :Parameterized Constructor to create an empty trie node and points to it by m_root
 and for setting initial values to m_input
 * @param  string:input
*/
PatternSearching::PatternSearching() {

    m_root = new TrieNode();

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
            input += '$';
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
                CollectDollar(current->m_children, result);
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
    for (int i = 0; i < word.length(); i++) {
        char key = word[i];
        if (current->m_children.find(key) == current->m_children.end()) {
            if (key == '$') {
                current->m_children[key] = new TrieNode(index);
            }
            else {
                current->m_children[key] = new TrieNode();

            }
        }
        current = current->m_children[key];
    }
}
/**
 * @brief : Collect all the indexes where the pattern occur from '$' node using DFS
 * @param children
 * @param result :vector <int >to store all the indexes where the pattern occur

*/
void PatternSearching::CollectDollar(std::unordered_map < char, TrieNode* > children, std::vector < int >& result) {
    for (auto child : children) {
        if (child.first == '$') {
            result.push_back(child.second->m_startIndex);
        }
        else {
            CollectDollar(child.second->m_children, result);
        }
    }
}

void PatternSearching::DeleteSuffix(TrieNode* node) {
    for (auto child : node->m_children) {

        if (child.first == '$') {
            delete child.second;
        }
        else {
            DeleteSuffix(child.second);
            delete child.second;
        }

    }

}
//Free the dynamically allocated memory
/**
 * @brief : this function use to find and print all the occurrences of pattern in the text
 * @param string: pattern
 */
PatternSearching::~PatternSearching() {
    if (!(m_root->m_children.empty())) {
        for (auto child : m_root->m_children) {
            DeleteSuffix(child.second);
        }
    }
    delete m_root;
}