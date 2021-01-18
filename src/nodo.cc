/**
 * @file nodo.cpp
 * @author Ángel Julián Bolaño Campos (alu0101139456@ull.edu.es)
 * @brief Práctica 12: Algoritmos Voraces
 * @version 0.1
 * @date 02-01-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "nodo.h"

Nodo::Nodo(int id): 
  id_(id) {
}

Nodo::~Nodo() {}

//Setters
void Nodo::SetId(int id) {
  id_ = id;
}

void Nodo::Set_vArista(std::vector<Arista> vAristas) {
  vAristas_ = vAristas; 
}

//Getters
int Nodo::GetId() {
  return id_;
}
  
std::vector<Arista> Nodo::Get_vArista() {
  return vAristas_;
}

void Nodo::insertArista(Arista aux) {
  vAristas_.push_back(aux);
}
