#include "pch.h"

#include "TrieNode.h"

/**
 * @brief  Default constructor use  for setting initial values for member variable
 * @param index  :the initial value for the m_startIndex  by default is -1
 * @param key
 */
TrieNode::TrieNode(char key, int index) {

    for (int i = 0; i < MAX_CHAR; i++)
        m_children[i] = NULL;
    m_key = key;
    m_startIndex = index;

}