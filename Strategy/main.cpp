#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include "rotator.h"
using namespace std;

int main() {

//DECLARACION DE NOMBRES DE ARCHIVOS
  string archiFrases;
  string archiStopWords;
  char ordenamiento;

//SE DECLARA EL ARCHIVO DONDE SE ESCRIBIRAN LOS RESULTADOS
  ofstream output_file ("results.txt");

//INPUT DEL ARCHIVO QUE CONTIENE LAS FRASES A MANIPULAR
  cout<< "Ingrese el nombre del archivo con las frases de input con el formato 'nombre.txt':\n"<<endl;
  cin>> archiFrases;
  ifstream input_file;
  input_file.open (archiFrases); //INTENTA ABRIR EL ARCHIVO
  //SI NO ESTA EN EL DIRECTORIO, PIDE QUE INGRESE UN ARCHIVO VALIDO
  while(!input_file.is_open()){
      cout<<"Por favor ingrese un archivo valido. Revise si esta bien escrito\n";
      cin>> archiFrases;
      input_file.open (archiFrases);
  }

//INPUT DEL ARCHIVO QUE CONTIENE LAS STOPWORDS A ELIMINAR
  cout<< "Ingrese el nombre del archivo que contiene las palabras que se desean omitir en el formato 'nombre.txt':\n"<<endl;
  cin>> archiStopWords;
  ifstream stopWords_file;
  stopWords_file.open (archiStopWords); //INTENTA ABRIR EL ARCHIVO
  //SI NO ESTA EN EL DIRECTORIO, PIDE QUE INGRESE UN ARCHIVO VALIDO
  while(!stopWords_file.is_open()){
      cout<<"Por favor ingrese un archivo valido. Revise si esta bien escrito\n";
      cin>> archiStopWords;
      stopWords_file.open (archiStopWords);
  }

//INPUT DEL TIPO DE ORDENAMIENTO A REALIZAR
  cout<< "Desea que el ordenamiento sea incremental('i') o decremental('d')?\n";
  cin>> ordenamiento;
  
  while(ordenamiento != 'i' && ordenamiento != 'd') {
      cout<<"Por favor ingrese el tipo de ordenamiento con el formato 'i'/'d'.\n";
      cin>> ordenamiento;
      cout << ordenamiento << endl;
  }

//WRITING ON FILES AS TEST
  output_file << "my text here!\n";

//SE CIERRAN LOS ARCHIVOS
  input_file.close();
  stopWords_file.close();
  output_file.close();

    return 0;
}
