/**
 * @file arista.cpp
 * @author Ángel Julián Bolaño Campos (alu0101139456@ull.edu.es)
 * @brief Práctica 12: Algoritmos Voraces
 * @version 0.1
 * @date 02-01-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "arista.h"

Arista::Arista(int nodoDest, float dist) {
  dist_ = dist;
  nodoDestino_ = nodoDest;
}

Arista::~Arista() {}

//Setters
  void Arista::SetDistancia(float dist) {
    dist_ = dist;
  }

  void Arista::SetDestino(int nodoDest) {
    nodoDestino_ = nodoDest;
  }

//Getters
  float Arista::GetDist() {
    return dist_;
  }

  int Arista::GetDestino() {
    return nodoDestino_;
  }
