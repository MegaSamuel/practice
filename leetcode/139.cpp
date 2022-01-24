#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

#define knLetterCount 26

struct TrieNode
{
    TrieNode *node[knLetterCount]; 
    bool terminal_node;
};

public:
    Solution()
    {
        m_root = create_node();
    }

    void insert_word(const string& word)
    {
        int ind;
        TrieNode *current = m_root;
 
        // проходим по всем буквам слова
        for(int i = 0; i < static_cast<int>(word.length()); i++)
        {
            // определяем индекс буквы в массиве
            // 97 - это код буквы 'a'
            ind = static_cast<int>(word[i]) - 97;

            // если узла с индексом ind нет - создаем
            if(nullptr == current->node[ind])
                current->node[ind] = create_node();

            current = current->node[ind];
        }
 
        // помечаем узел как терминальный
        current->terminal_node = true;
    }

    bool wordBreak(string s, vector<string>& wordDict) 
    {
        for(const auto& word : wordDict)
        {
            insert_word(word);
        }

        vector<bool> dp(s.length()+1);
        dp[0] = true; 

        // проходим по всем буквам
        for(int i = 0; i < static_cast<int>(s.length()); i++)
        {
            if(dp[i])
            {
                int ind;
                TrieNode *current = m_root;

                for(int j = i; j < static_cast<int>(s.length()); j++)
                {
                    // определяем индекс буквы в массиве
                    ind = static_cast<int>(s[j]) - 97;

                    // если узла с индексом ind нет - значит слова нет в боре
                    if(nullptr == current->node[ind])
                        break;

                    current = current->node[ind];

                    if(current->terminal_node)
                        dp[j+1] = true; 
                }
            }
        }

        return dp[s.length()];
    }

private:
    TrieNode *m_root;

    TrieNode *create_node()
    {
        // создаем узел
        TrieNode *current =  new TrieNode;

        // все дети по умолчанию nullptr
        for(int i = 0; i < knLetterCount; i++)
            current->node[i] = nullptr;
 
        // узел по умолчанию не терминальный
        current->terminal_node = false;

        return current;
    }
};

int main()
{
    Solution sol;
    string str = "leetcode";
    vector<string> words;
    words.push_back("leet");
    words.push_back("code");

    cout << sol.wordBreak(str, words);
}
