#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
 
string ReadLine() {
    string s;
    getline(cin, s);
    return s;
}
 
int ReadLineWithNumber() {
    string s;
    getline(cin, s);
    // функция stoi переводит строку в число типа int
    int result = stoi(s);
    return result;
}
 
vector<string> SplitIntoWords(const string& text) {
    vector<string> words;
    string word;
    if( !text.empty() )
    {
        for (const char c : text) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word);
    }
    
    return words;
}
 
set<string> ParseStopWords(const string& text) {
    set<string> stop_words;
    for (const string& word : SplitIntoWords(text)) {
        stop_words.insert(word);
    }
    return stop_words;
}
 
vector<string> SplitIntoWordsNoStop(const string& text, const set<string>& stop_words) {
    vector<string> words;
    // проходим по всем словам из текста и проверяем, что их нет в списке стоп-слов
    for (const string& word : SplitIntoWords(text)) {
        if (stop_words.count(word) == 0) {
            words.push_back(word);
        }
    }
    // вернём результат без стоп-слов
    return words;
}

void AddDocument(map<string, set<int>>& word_to_documents,
                 const set<string>& stop_words,
                 int document_id,
                 const string& document) {
    // пройдём по всем словам (без стоп-слов) и добавим их в базу данных
    for (const string& word : SplitIntoWordsNoStop(document, stop_words)) {
        word_to_documents[word].insert(document_id);
    }
}
 
vector<int> FindDocuments(const map<string, set<int>>& word_to_documents,
                          const set<string>& stop_words,
                          const string& query) {
    // напишите тут код функции
    vector<int> vct;
    set<int> set_result;
    
    for( const string& word : SplitIntoWordsNoStop( query, stop_words ) )
    {
        if( word_to_documents.count(word) )
        {
            for( const int id : word_to_documents.at(word) )
            {
                set_result.insert(id);
            }
        }
    }
    
    for( const int id : set_result )
    {
        vct.push_back(id);
    }
    
    return vct;
}
 
int main() {
    cout << "Stop words : "s << endl;
    const string stop_words_joined = ReadLine();
    const set<string> stop_words = ParseStopWords(stop_words_joined);
    
    // Read documents
    map<string, set<int>> word_to_documents;
    cout << "Number of documents to add : "s << endl;
    const int document_count = ReadLineWithNumber();
    for (int document_id = 0; document_id < document_count; ++document_id) {
        cout << document_id << " : "s << endl;
        AddDocument(word_to_documents, stop_words, document_id, ReadLine());
    }
    
    cout << "Search request : "s << endl;
    const string query = ReadLine();
    cout << "Search results : "s;
    for (const int document_id : FindDocuments(word_to_documents, stop_words, query)) {
        cout << document_id << ' ';
    }
    cout << endl;
}
