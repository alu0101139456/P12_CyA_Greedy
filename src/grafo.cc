/**
 * @file grafo.cpp
 * @author Ángel Julián Bolaño Campos (alu0101139456@ull.edu.es)
 * @brief Práctica 12: Algoritmos Voraces
 * @version 0.1
 * @date 02-01-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "grafo.h"



Grafo::Grafo(std::string nameFile, bool dirigido) {
  ReadInputFile(nameFile, dirigido);
  MakeGrafo();
  PrintGrafo();
  
}

Grafo::~Grafo() {}



void Grafo::ReadInputFile(std::string nameFile, bool dirigido) {
  std::ifstream fileInput;
  fileInput.open(nameFile);
  dirigido_ = dirigido;
  float dist;
  int nodo1, nodo2, nNodos;
  if( fileInput.is_open() ) {
    fileInput >> nCiudades_;
    for( unsigned i = 0 ; i < nCiudades_ ; i++ ) {
      fileInput >> nNodos; 
      vNodos_.push_back(Nodo(nNodos));
    }
    while( !fileInput.eof() ) {
      fileInput >> nodo1 >> nodo2 >> dist;
      for (size_t i = 0; i < nNodos; i++) {
        if(nodo1 == vNodos_[i].GetId()) {
          vNodos_[i].insertArista(Arista(nodo2, dist));
          if(!dirigido_) {
            for (size_t j = 0; j < nNodos; j++) {
              if(nodo2 == vNodos_[j].GetId()) {
                vNodos_[j].insertArista(Arista(nodo1, dist));
              }
            }
          }
        }
      }
    }
  }
  fileInput.close();
}

bool Grafo::IsInSolution(int nodo) {
  for( unsigned i = 0 ; i < vSolution_.size() ; i++ ) {
    if( vNodos_[nodo-1].GetId() == vSolution_[i].GetId() )
      return true;
  }
  return false; 
}



void Grafo::MakeGrafo() {
  float distTemp; 
  vSolution_.push_back(vNodos_[0]);
  int posible = 0;
  
  while(true) {
    float min = INT_MAX;
//MOD->auto nAristas = vSolution_[vSolution_.size()-1].GetNAristas();
    auto nodoActual = vSolution_[vSolution_.size()-1].GetId();
    for (size_t i = 0; i < vSolution_[vSolution_.size()-1].Get_vArista().size(); i++) {
      int position = vSolution_[vSolution_.size()-1].Get_vArista()[i].GetDestino();     
//MOD-->if(vSolution_[vSolution_.size()-1].Get_vArista()[i].GetDist() < min && !IsInSolution(position) && nodoActual+1 != position ){
      if(vSolution_[vSolution_.size()-1].Get_vArista()[i].GetDist() < min && !IsInSolution(position) ){
        posible = vSolution_[vSolution_.size()-1].Get_vArista()[i].GetDestino();
        min = vSolution_[vSolution_.size()-1].Get_vArista()[i].GetDist();      
      } 
    }
    if(min == INT_MAX) break;
    
    vSolution_.push_back(vNodos_[posible - 1]);
    distancia_ += min;
    
    if (vNodos_.size() == vSolution_.size()) break; 
  }
  
  if(!dirigido_) {
    for (size_t i = 0; i < vSolution_[vSolution_.size()-1].GetNAristas(); i++) {
      if(vSolution_[vSolution_.size()-1].Get_vArista()[i].GetDestino() == vSolution_[0].GetId() ) 
        distancia_ += vSolution_[vSolution_.size()-1].Get_vArista()[i].GetDist();
    }
    vSolution_.push_back(vNodos_[0]);
  }
}

void Grafo::PrintGrafo() {
  std::string temp;
  std::cout << "Número de ciudades: " << nCiudades_ << std::endl;
  dirigido_ ? temp = " " : temp = " no "; 
  std::cout << "Es un grafo" << temp << "dirigido. " << std::endl;   
  std::cout << "El camino será: " << std::endl;
  std::cout << "S = { ";
  for( unsigned i = 0 ; i < vSolution_.size(); i++ ) {
    std::cout << vSolution_[i].GetId() << " ";
  }
  std::cout << "}" << std::endl;
  std::cout << "La distancia recorrida es: " << distancia_ << " kms" << std::endl; 
  
}


void Grafo::print() {
  for (size_t i = 0; i < vNodos_.size(); i++) {
    std::cout << "Nodo: " << vNodos_[i].GetId() << std::endl;
    for (size_t j = 0; j < vNodos_[i].Get_vArista().size(); j++) {
      std::cout << "Destino: " << vNodos_[i].Get_vArista()[j].GetDestino() << " distancia: " << vNodos_[i].Get_vArista()[j].GetDist() << std::endl;

    }
    
  }
  
}
