#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include "utility.h"
using namespace std;

class Rotator
{
  private:
    vector<string> phrases;
    vector<string> stop_words;
    bool ascending;

    //PASO 1: LIMPIAR FRASES
    void limpiar()
    {
        vector<char> puntuacion = {'.', ',', '"', '?', '!'};
        for (int i = 0; i < phrases.size(); i++)
        {
            for (int j = 0; j < puntuacion.size(); j++)
            {
                while (phrases[i].find(puntuacion[j]) != -1)
                {
                    phrases[i].erase(phrases[i].find(puntuacion[j]), 1);
                }
            }
        }
    }

    //PASO 2: QUITAR STOP WORDS Y DESPUES HACER LOWER CASE
    void delete_stop_words()
    {
        for (int i = 0; i < phrases.size(); i++)
        {
            string old_phrase = phrases[i];
            transform(old_phrase.begin(), old_phrase.end(), old_phrase.begin(), ::tolower);
            vector<string> words = Utility::get_words(old_phrase);
            for (int j = 0; j < stop_words.size(); j++)
            {
                string stop = stop_words[j];
                transform(stop.begin(), stop.end(), stop.begin(), ::tolower);
                vector<string>::iterator result = find(words.begin(), words.end(), stop);
                if (result != words.end())
                {
                    words.erase(result);
                }
            }
            phrases[i] = Utility::get_sentence(words);
        }
    }

    //PASO 3: ROTAR (TODAS LAS PERMUTACIONES)
    vector<string> rotate()
    {
        vector<string> rotations, words;
        string old_phrase, new_phrase, word;
        for (int i = 0; i < phrases.size(); i++)
        {
            old_phrase = phrases[i];
            words = Utility::get_words(old_phrase);

            //REALIZA UNA ROTACION POR PALABRA
            for (int j = 0; j < words.size(); j++)
            {
                word = words.back();
                words.insert(words.begin(), word);
                words.pop_back();
                //METE CADA PERMUTACION DE LA FRASE EN UN NUEVO VECTOR
                new_phrase = Utility::get_sentence(words);
                rotations.push_back(new_phrase);
            }
        }
        return rotations;
    }

  public:
    Rotator(vector<string> frases, vector<string> delete_words, bool asc)
    {
        phrases = frases;
        stop_words = delete_words;
        ascending = asc;
    }

    void setAscending(bool asc)
    {
        ascending = asc;
    }

    void setPhrases(vector<string> frases)
    {
        phrases = frases;
    }

    void setStopWords(vector<string> delete_words)
    {
        stop_words = delete_words;
    }

    //PASO 5: ESCRIBIR RESULTADOS EN UN ARCHIVO
    void results()
    {
        limpiar();
        delete_stop_words();
        vector<string> rotations = rotate();
        if (ascending)
        {
            sort(rotations.begin(), rotations.end());
        }
        else
        {
            sort(rotations.begin(), rotations.end(), greater<string>());
        }
        //SE DECLARA EL ARCHIVO DONDE SE ESCRIBIRAN LOS RESULTADOS
        ofstream output_file("results.txt");
        //WRITING ON FILES AS TEST
        std::ostream_iterator<std::string> output_iterator(output_file, "\n");
        std::copy(rotations.begin(), rotations.end(), output_iterator);
        //SE CIERRA ARCHIVO
        output_file.close();
    }
};
