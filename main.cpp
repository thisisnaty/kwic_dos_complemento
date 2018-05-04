#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "rotator.h"
using namespace std;

vector<string> input_vector(string query_message)
{
    string file_name;
    vector<string> result;
    cout << query_message << endl;
    cin >> file_name;
    try
    {
        result = Utility::file_to_string_vector(file_name);
    }
    catch (const char *error_message)
    {
        cerr << error_message << endl;
        input_vector(query_message);
    }
    return result;
}

vector<string> input_phrases()
{
    return input_vector("Ingrese el nombre del archivo con las frases de input con el formato 'nombre.txt':");
}

vector<string> input_stop_words()
{
    return input_vector("Ingrese el nombre del archivo que contiene las palabras que se desean omitir en el formato 'nombre.txt':");
}

char input_order()
{
    char order;
    try
    {
        cout << "Desea que el ordenamiento sea incremental('i') o decremental('d')?" << endl;
        cin >> order;
        if (order != 'i' && order != 'd')
        {
            throw "Ordenamiento inválido";
        }
    }
    catch (const char *error_message)
    {
        cerr << error_message << endl;
        input_order();
    }
    return order == 'i';
}

void menu()
{
    cout << "*** MENU *** " << endl;
    cout << "1. Cambiar ordenamiento" << endl;
    cout << "2. Cambiar archivo de frases" << endl;
    cout << "3. Cambiar archivo de palabras a omitir" << endl;
    cout << "4. Salir" << endl;
}

int main()
{
    //SE DECLARA UN VECTOR DE FRASES QUE GUARDA TODAS LAS FRASES DEL DOCUMENTO
    vector<string> phrases = input_phrases();
    //SE DECLARA UN VECTOR DE STOPWORDS QUE GUARDA TODAS LAS PALABRAS A BORRAR DE LAS FRASES
    vector<string> stop_words = input_stop_words();
    //INPUT DEL TIPO DE ORDENAMIENTO A REALIZAR
    bool ascending = input_order();
    //SE CREA UNA INSTANCIA DE LA CLASE ROTATOR
    int menu_option;
    Rotator r(phrases, stop_words, ascending);
    bool valid_option = true;
    while (true)
    {
        if (valid_option)
        {
            r.results();
            cout << "Los resultados se encuentran en el archivo 'results.txt'" << endl;
        }
        menu();
        cin >> menu_option;
        switch (menu_option)
        {
        case 1:
            ascending = input_order();
            r.setAscending(ascending);
            break;
        case 2:
            phrases = input_phrases();
            r.setPhrases(phrases);
            break;
        case 3:
            stop_words = input_stop_words();
            r.setStopWords(stop_words);
            break;
        case 4:
            return 0;
        default:
            cout << "Elija una opción válida" << endl;
            valid_option = false;
            break;
        }
    }

    return 0;
}
