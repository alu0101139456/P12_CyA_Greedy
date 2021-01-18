/**
 * @file main.cpp
 * @author Ángel Julián Bolaño Campos (alu0101139456@ull.edu.es)
 * @brief Práctica 12: Algoritmos Voraces
 * @version 0.1
 * @date 02-01-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "grafo.h"

int main(int argc, char* argv[]){
  bool dirigido;
  std::cout << "¿Es un grafo dirigido? 1 [Sí] 0 [No] "  << std::endl;
  std::cin >> dirigido;
  if(argc == 2)
    Grafo aux(argv[1], dirigido);
  else 
    std::cout << "Ejecutar: ./main input.txt" << std::endl;
  
  return 0;
}
