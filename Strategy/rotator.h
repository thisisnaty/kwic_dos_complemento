#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


class Rotator{
private:
    vector<string> phrases;
    vector<string> stopWords;
    char ordenamiento;

public:
    Rotator(vector<string> frases, vector<string> deleteWords, char ordenar){
        phrases = frases;
        stopWords = deleteWords;
        ordenamiento = ordenar;
    }

    //PASO 1: LIMPIAR FRASES
    void limpiar(){
        char p[] = {'.', ',', '"', '?','!'};
        vector<char> puntuacion(p, p+5);
        for(int i=0; i<phrases.size(); i++){
            for(int j=0; j<puntuacion.size();j++){
                while(phrases[i].find(puntuacion[j]) != -1){
                    phrases[i].erase(phrases[i].find(puntuacion[j]),1);
                }
            }
        }
    }
    //PASO 2: QUITAR STOP WORDS Y DESPUES HACER LOWER CASE
    void deleteStopWords(){
        for(int i=0; i<phrases.size();i++){
            for(int j=0; j<stopWords.size();j++){
                //BUSCA POR LAS PALABRAS DE LA LISTA QUE DEBEN DE SER ELIMINADAS DE LAS FRASES
                while(phrases[i].find(stopWords[j]) != -1){
                    //ENCUENTRA LA POSICION INICIAL Y FINAL SI SE ENCUENTRAN EN EL VECTOR
                    int start = phrases[i].find(stopWords[j]);
                    int end = stopWords[j].length();
                    //BORRA LAS PALABRAS QUE ESTAN EN LA LISTA Y NO DEBERIAN ESTAR EN EL VECTOR
                    phrases[i].erase(start,end);
                }
                //CONVIERTE TODA LA FRASE A MINUSCULAS
                    transform(phrases[i].begin(), phrases[i].end(), phrases[i].begin(), ::tolower);
            }
        }
    }
    //PASO 3: ROTAR (TODAS LAS PERMUTACIONES)
    vector<string> rotate(){
        vector<string> rotations;
        int side;
    	for(int i=0; i<phrases.size(); i++){

            //REALIZA UNA CUENTA DE LA CANTIDAD DE PALABRAS EN LA FRASE
            string frase = phrases[i];
            vector<string> aux;
            string palabra = " ";

            int iter =0;
            int space = 0;
            while(frase.find(' ') != -1){
                palabra = frase.substr(space, frase.find(' '));
                aux.push_back(palabra);
                space = frase.find(' ');
                iter++;
            }
            palabra = frase.substr(space);
            aux.push_back(palabra);
            iter++;

            //REALIZA UNA ROTACION POR PALABRA DEPENDIENDO DEL ORDENAMIENTO
            for(int j=0; j<iter; j++){
                if(ordenamiento == 'd'){
                string str = aux[0];
                aux.push_back(str);
                aux.erase(aux.begin());
                //METE CADA PERMUTACION DE LA FRASE EN UN NUEVO VECTOR
                rotations.push_back(frase);
                }else{
                string str = aux.back();
                aux.insert(aux.begin(),str);
                aux.erase(aux.end());
                //METE CADA PERMUTACION DE LA FRASE EN UN NUEVO VECTOR
                rotations.push_back(frase);
                }
            }
        }
        return rotations;
    }
    //PASO 4: ORDENAR SEGUN ORDENAMIENTO INDICADO
    void order(vector<string> rotations){
        
    }
    //PASO 5: ESCRIBIR RESULTADOS EN UN ARCHIVO
    void results(){
        limpiar();
        deleteStopWords();
        vector<string> rotations = rotate();
        order(rotations);
        //SE DECLARA EL ARCHIVO DONDE SE ESCRIBIRAN LOS RESULTADOS
        ofstream output_file ("results.txt");
        //WRITING ON FILES AS TEST
        output_file << "my text here!\n";
        //SE CIERRA ARCHIVO
        output_file.close();
    }


};
