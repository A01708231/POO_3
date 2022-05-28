/*
 * Proyecto Transportes main
 * Diego González Aguado
 * A01708231
 * 27/05/2022
 */

#include <iostream>   // para imprimir.

#include "trabajador_p.h" // bibliotecas con objetos de mi proyecto.

#include "empresa_p.h"

using namespace std;

int main(int argc, char * argv[]) {

  double t = 0;
  string ruta;
  double kilometros;
  int horas;

  Empresa empresa;
  empresa.crea_ejemplos();
  empresa.muestra_rutas();

  cout << "test \n\n";
  empresa.muestra_trabajadores("asalariado");
  t = empresa.calc_paga_trabajadores();
  cout << "pago trabajadores " << t << endl;
  t = empresa.calc_sat();
  cout << "pago hacienda " << t << endl;
  empresa.agrega_trabajador("Johnny", 20032);
  empresa.muestra_trabajadores("asalariado");
  empresa.agrega_por_hora("Veronica", 170, 100000);
  empresa.muestra_trabajadores("por hora");
  empresa.agrega_practicante("Benjamin", 40, 3000);
  empresa.muestra_trabajadores("practicante");
  cout << "test \n\n";
}