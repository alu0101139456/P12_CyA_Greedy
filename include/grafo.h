/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  * Curso: 2º
  * Editor: Visual Studio Code
  * Estilo Google C++ Style Guide
  *
  * @file grafo.h
  * @version 1.0
  * @author Laura Cañizares Herrera
  * @date 13 de enero 2021
*/
#pragma once
#include "arista.h"
#include "nodo.h"
#include "fstream"
#include <iostream>
#include <limits.h>

class Grafo {
private:
  std::vector<Nodo> vNodos_;
  std::vector<Nodo> vSolution_;
  // std::vector<arista> vArista_;
  unsigned nCiudades_;
  unsigned dirigido_;
  float distancia_ = 0.0;

public:
  Grafo(std::string nameFile, bool dirigido);
  ~Grafo();

  void ReadInputFile(std::string nameFile, bool dirigido);
  void MakeGrafo();
  void PrintGrafo(); 

private:
  int SeleccionarArista(int nodo);
  bool IsInSolution(int nodo);
  void vueltaorigen();
  void print();
};