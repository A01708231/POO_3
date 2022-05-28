/*
 *
 * Diego González Aguado
 * A01708231
 * 27/05/2022
 */

#ifndef EMPRESA_P_H_
#define EMPRESA_P_H_

#include <string>

#include <iostream>

#include <sstream>

#include "trabajador_p.h" //biblioteca con mis objetos a usar

using namespace std;

const int MAX = 1000; //constante de tamaño de arreglos

class Empresa {

  //Declaro las variables privadas de instancia
  private:

    Empleado * emp[MAX]; //se define como apuntador para usar polimorfismo
  int nomina;

  //Declaro constructor por default y metodos públicos.
  public:

    Empresa(): nomina(0) {}; //constructor por defualt

  void crea_ejemplos();
  void muestra_trabajadores();
  void muestra_trabajadores(string tipo);
  double calc_paga_trabajadores();
  double calc_paga_trabajadores(string tipo);
  double calc_sat();
  double calc_pago_total();
  void agrega_trabajador(string nombre, double salario);
  void agrega_por_hora(string nombre, int horas, double salario);
  void agrega_practicante(string nombre, int horas, double salario);

};

/**
 * crea_ejemplos genera objetos en Empleados[]
 *
 * genera objetos de tipo Asalariado PorHora y Practicante y los
 * guarda en la varibale de instancia en emp[] (arreglo de empleados)
 * para poder hacer pruebas. No usar esta función si se va a usar el programa
 * en producción, ya que los datos son falsos.
 *
 * @param
 * @return
 */
void Empresa::crea_ejemplos() {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  emp[nomina] = new Trabajador(nomina, "Fernando", 2000);
  nomina++;
  emp[nomina] = new Trabajador(nomina, "Alejandro", 1800);
  nomina++;
  emp[nomina] = new Trabajador(nomina, "Ivett", 1200);
  nomina++;
  emp[nomina] = new Trabajador(nomina, "Claudia", 24, 400);
  nomina++;
  emp[nomina] = new Trabajador(nomina, "Felipe", 20, 650);
  nomina++;
  emp[nomina] = new Trabajador(nomina, "María", 10, 200);
  nomina++;
  emp[nomina] = new Trabajador(nomina, "Ramon", 15, 200);
  nomina++;
  emp[nomina] = new Trabajador(nomina, "Luisa", 20, 150);
  nomina++;
}

/**
 * muestra_empleados imprime empleados
 *
 * utiliza el arreglo emp[] y el número de nómina, para recorre todo el
 * arreglo imprimiendo cada uno de los objetos con su método to_string().
 *
 * @param
 * @return
 */
void Empresa::muestra_trabajadores() {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < nomina; i++)
    cout << emp[i] -> to_string();
}

/**
 * muestra_trabajadores imprime trabajadores que coinciden con tipo
 *
 * utiliza el arreglo emp[] y el número de nómina, para recorre todo el
 * arreglo imprimiendo cada uno de los objetos  que coinciden con el
 * string tipo ("asalariado, por hora o practicante").
 *
 * @param string tipo debe ser: 'asalariado', 'por hora' o 'practicante'
 * @return
 */
void Empresa::muestra_Trabajadores(string tipo) {

  //Ciclo que recorre el arreglo e imprime cada objeto.
  for (int i = 0; i < nomina; i++) {
    if (emp[i] -> get_tipo() == tipo)
      cout << emp[i] -> to_string();
  }
}

/**
 * calc_paga_trabajadores suma la paga total de todos los trabajadores
 *
 * utiliza el arreglo emp[] y el número de nómina, para recorre todo el
 * arreglo acumulando el pago mensual de todos los emleados.
 *
 * @param
 * @return double con la suma de todos los pagos a trabajadores
 */
double Empresa::calc_paga_trabajadores() {

  double total = 0;
  for (int i = 0; i < nomina; i++)
    total = total + emp[i] -> pago_mensual();
  return total;
}

/**
 * calc_paga_trabajadores suma la paga total de todos los trabajadores de un tipo
 *
 * utiliza el arreglo emp[] y el número de nómina, para recorre todo el
 * arreglo acumulando el pago mensual de todos los trabajadores, cuyo string
 * get_tipo() coincida con el tipo recibido como parámentro.
 *
 * @param string tipo debe ser: 'asalariado', 'por hora' o 'practicante'
 * @return double con la suma de todos los pagos a trabajadores
 */
double Empresa::calc_paga_trabajadores(string tipo) {

  int total = 0;
  for (int i = 0; i < nomina; i++) {
    if (emp[i] -> get_tipo() == tipo)
      total = total + emp[i] -> pago_mensual();
  }
  return total;
}

/**
 * calc_paga_trabajadores suma la paga total de todos los trabajadores fiscales
 *
 * utiliza el arreglo emp[] y el número de nómina, para recorre todo el
 * arreglo acumulando el pago mensual de todos los trabajadores fiscales:
 * que son de tipo Asalariado y PorHora.
 *
 * @param
 * @return double con la suma de todos los pagos a trabajadores
 */
double Empresa::calc_paga_hacienda() {

  return calc_paga_trabajadores("asalariado") + calc_paga_trabajadores("por hora");
}

/**
 * calc_pago_total suma la paga total de todos los trabajadores
 *
 * verifica que haya trabajadores antes devolver la suma de sus salarios, incluye
 * practicantes como trabajadores
 *
 * @param
 * @return double con la suma de todos los pagos a trabajadores
 */
double Empresa::calc_pago_total() {

  if (nomina > 0)
    return calc_paga_trabajadores();
  else
    return 0.0;
}

/**
 * agrega_asalariado crea un objeto Asalariado y lo agrega a
 * arreglo de empleados
 *
 * crea un objeto Asalariado y lo agrega a arreglo de empleados usando como
 * indice el número de nómina, el cuál después incrementa en 1.
 *
 * @param string nombre del empleado y  double salario.
 * @return
 */
void Empresa::agrega_asalariado(string nombre, double salario) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  emp[nomina] = new Asalariado(nomina, nombre, salario);
  nomina++;
}

/**
 * agrega_por_hora crea un objeto PorHora y lo agrega a
 * arreglo de empleados
 *
 * crea un objeto PorHora y lo agrega a arreglo de empleados usando como
 * indice el número de nómina, el cuál después incrementa en 1.
 *
 * @param string nombre del empleado, int horas y double salario.
 * @return
 */
void Empresa::agrega_por_hora(string nombre, int horas, double salario) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  emp[nomina] = new PorHora(nomina, nombre, horas, salario);
  nomina++;
}

/**
 * agrega_practicante crea un objeto Practicante y lo agrega a
 * arreglo de empleados
 *
 * crea un objeto Practicante y lo agrega a arreglo de empleados usando como
 * indice el número de nómina, el cuál después incrementa en 1.
 *
 * @param string nombre del empleado, int horas y double salario.
 * @return
 */
void Empresa::agrega_practicante(string nombre, int horas, double salario) {

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  emp[nomina] = new Practicante(nomina, nombre, horas, salario);
  nomina++;
}

#endif // EMPRESA_P_H_