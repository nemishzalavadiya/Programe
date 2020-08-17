/*
Add and Search Word - Data structure design

Solution
You should design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) adds word to the data structure, it can be matched later.
bool search(word) returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 500
word in addWord consists lower-case English letters.
word in search consist of  '.' or lower-case English letters.
At most 50000 calls will be made to addWord and search .
   Hide Hint #1  
You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct trie
    {
        int end;
        trie *child[26];
    };

    trie *getNode(char c)
    {
        trie *temp = new trie;
        temp->end = 0;
        for (int i = 0; i < 26; i++)
        {
            temp->child[i] = NULL;
        }
        return temp;
    }
    trie *head = NULL;
    /** Initialize your data structure here. */
    WordDictionary()
    {
        head = getNode('/');
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        trie *temp = head;
        for (auto c : word)
        {
            if (temp->child[c - 'a'] == nullptr)
            {
                temp->child[c - 'a'] = getNode(c);
            }
            temp = temp->child[c - 'a'];
        }
        temp->end = 1;
    }

    bool se(string word, trie *temp)
    {
        for (int i = 0; i < word.size(); i++)
        {
            //cout<<"running for word : "<<word[i]<<endl;
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    if (temp->child[j] != nullptr)
                    {
                        //cout<<"in all child running for word : "<<char(i+'a')<<endl;
                        if (se(word.substr(i + 1), temp->child[j]))
                        {
                            return true;
                        }
                    }
                }
                return false;
            }
            if (temp->child[word[i] - 'a'] == nullptr)
                return false;
            temp = temp->child[word[i] - 'a'];
        }
        if (temp->end == 1)
            return true;
        return false;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        //cout<<"result of : "<<word<<endl;
        return se(word, head);
    }
};
int main(int argc, char *argv[])
{
    WordDictionary *obj = new WordDictionary();
    bj->addWord(word);
    bool param_2 = obj->search(word);
    return 0;
}