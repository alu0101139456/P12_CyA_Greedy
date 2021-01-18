/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia
  * Curso: 2º
  * Editor: Visual Studio Code
  * Estilo Google C++ Style Guide
  *
  * @file arista.h
  * @version 1.0
  * @author Laura Cañizares Herrera
  * @date 13 de enero 2021
*/
#pragma once

class Arista {
private:
  float dist_; 
  int nodoDestino_;

public:
  Arista(int, float);
  ~Arista();

  //Setters
  void SetDestino(int);
  void SetDistancia(float);
  

  //Getters
  float GetDist();
  int GetDestino();

};