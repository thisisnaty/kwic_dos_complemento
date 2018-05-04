#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include "Rotator.h"
using namespace std;

int main() {

  string archiFrases;
  string archiStopWords;

  cout<< "Ingrese el nombre del archivo con las frases de input con el formato 'nombre.txt':"<<endl;
  cin>> archiFrases;

  cout<< "Ingrese el nombre del archivo que contiene las palabras que se desean omitir en el formato 'nombre.txt':"<<endl;
  cin>> archiStopWords;

  ofstream output_file ("results.txt");
  ofstream input_file;
  ofstream stopWords_file;
  input_file.open (archiFrases);
  stopWords_file.open (archiStopWords);

  input_file << "Aqui van las frases.\n";
  stopWords_file << "Aqui van las condiciones.\n";
  output_file << "my text here!\n";
  input_file.close();
  stopWords_file.close();
  output_file.close();

    return 0;
}
