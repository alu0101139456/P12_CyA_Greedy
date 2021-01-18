/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  * Curso: 2º
  * Editor: Visual Studio Code
  * Estilo Google C++ Style Guide
  *
  * @file nodo.h
  * @version 1.0
  * @author Laura Cañizares Herrera
  * @date 13 de enero 2021
*/
#pragma once
#include <vector>

#include "arista.h"

class Nodo {
private:
  int id_;
  std::vector<Arista> vAristas_; 

public:
  Nodo(int id);
  ~Nodo();

  //Setters
  void SetId(int id);
  void Set_vArista(std::vector<Arista> vAristas);

  //Getters
  int GetId();
  std::vector<Arista> Get_vArista();
  int GetNAristas() { return vAristas_.size(); }
  void insertArista(Arista aux);
};