#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

using namespace std;

namespace Utility
{
vector<string> get_words(string str)
{
    vector<string> words;
    string word = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ' || str[i] == '\r')
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word += str[i];
        }
    }
    words.push_back(word);
    return words;
}

string get_sentence(vector<string> words)
{
    string word = words[0];
    string new_phrase = word;
    for (int i = 1; i < words.size(); i++)
    {
        word = words[i];
        new_phrase += " " + word;
    }
    return new_phrase;
}

void print(vector<string> strings)
{
    for (auto i : strings)
    {
        // process i
        cout << i << "\n"; // this will print all the contents of *strings*
    }
}

vector<string> file_to_string_vector(string file_name)
{
    ifstream input_file;
    input_file.open(file_name);

    vector<string> result;
    string line;

    if (!input_file.is_open())
    {
        throw "Nombre del archivo inválido";
    }
    while (getline(input_file, line))
    {
        result.push_back(line);
    }
    input_file.close();
    if (result.size() <= 0)
    {
        throw "El archivo no contiene frases";
    }
    return result;
}
}
