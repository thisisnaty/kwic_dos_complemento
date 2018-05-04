#include <vector>
#include <iostream>
#include <fstream>
#include "rotator.h"
using namespace std;

int main() {
//SE DECLARA UN VECTOR DE FRASES QUE GUARDA TODAS LAS FRASES DEL DOCUMENTO
vector<string> phrases;
string phrase;
//SE DECLARA UN VECTOR DE STOPWORDS QUE GUARDA TODAS LAS PALABRAS A BORRAR DE LAS FRASES
vector<string> stopWords;
string stopWord;

//DECLARACION DE NOMBRES DE ARCHIVOS
  string archiFrases;
  string archiStopWords;
  char ordenamiento;

//INPUT DEL ARCHIVO QUE CONTIENE LAS FRASES A MANIPULAR
  cout<< "Ingrese el nombre del archivo con las frases de input con el formato 'nombre.txt':\n"<<endl;
  cin>> archiFrases;
  ifstream input_file;
  input_file.open (archiFrases); //INTENTA ABRIR EL ARCHIVO
  //SI NO ESTA EN EL DIRECTORIO, PIDE QUE INGRESE UN ARCHIVO VALIDO
  if(!input_file.is_open()){
      cout<<"Por favor ingrese un archivo valido. Revise si esta bien escrito\n";
      cin>> archiFrases;
      input_file.open (archiFrases);
  }
  else{
     while(getline (input_file, phrase)){
         phrases.push_back(phrase);
     }
    //SE CIERRA ARCHIVO
    input_file.close();
  }


//INPUT DEL ARCHIVO QUE CONTIENE LAS STOPWORDS A ELIMINAR
  cout<< "Ingrese el nombre del archivo que contiene las palabras que se desean omitir en el formato 'nombre.txt':\n"<<endl;
  cin>> archiStopWords;
  ifstream stopWords_file;
  stopWords_file.open (archiStopWords); //INTENTA ABRIR EL ARCHIVO
  //SI NO ESTA EN EL DIRECTORIO, PIDE QUE INGRESE UN ARCHIVO VALIDO
  if(!stopWords_file.is_open()){
      cout<<"Por favor ingrese un archivo valido. Revise si esta bien escrito\n";
      cin>> archiStopWords;
      stopWords_file.open (archiStopWords);
  }
  else{
      while(getline (stopWords_file, phrase)){
          stopWords.push_back(stopWord);
      }
    //SE CIERRA ARCHIVO
    stopWords_file.close();
  }

//INPUT DEL TIPO DE ORDENAMIENTO A REALIZAR
  cout<< "Desea que el ordenamiento sea incremental('i') o decremental('d')?\n";
  cin>> ordenamiento;
//VALIDACION DE QUE LA INFORMACION SEA CORRECTA PARA REALIZAR LAS OPERACIONES
  while(ordenamiento != 'i' && ordenamiento != 'd') {
      cout<<"Por favor ingrese el tipo de ordenamiento con el formato 'i'/'d'.\n";
      cin>> ordenamiento;
  }
//SE CREA UNA INSTANCIA DE LA CLASE ROTATOR
Rotator r(phrases,stopWords,ordenamiento);
r.results();

    return 0;
}
