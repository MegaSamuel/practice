#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int CalculateSimilarity(vector<string> first, vector<string> second) {
    // выведите размер пересечения множеств слов
    set<string> uni1;
    set<string> uni2;
    set<string> res;
    
    for( string it : first )
    {
        uni1.insert( it );
    }

    for( string it : second )
    {
        uni2.insert( it );
    }

    for( string it : uni1 )
    {
        if( uni2.count( it ) )
        {
            res.insert( it );
        }
    }
    
    return res.size();
}

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == ' ') {
            words.push_back(word);
            word = "";
        } else {
            word += text[i];
        }
    }
    words.push_back(word);
    
    return words;
}

int main() {
    string query, description;

    getline(cin, query);
    getline(cin, description);

    cout << CalculateSimilarity(SplitIntoWords(query), SplitIntoWords(description)) << endl;

    return 0;
}
