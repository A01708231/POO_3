/*
 * Proyecto Transportes main
 * Diego González Aguado
 * A01708231
 * 27/05/2022
 */

#ifndef TRABAJADOR_P_H_
#define EMPRESA_P_H_

#include <string>

#include <sstream>

using namespace std;

//Declaracion de clase Trabajadoro que es abstracta
class Trabajador {

  //Declaro variables de instancia
  protected:
    int id;
  string nombre;
  string tipo;

  //Declaro los métodos que va a tener el objeto
  public:
    Trabajador(): id(0), nombre(""), tipo("") {}; //constructor por defualt
  Trabajador(int id_num, string nom, string tip):
    id(id_num), nombre(nom), tipo(tip) {};

  int get_id() {
    return id;
  }
  string get_nombre() {
    return nombre;
  }
  string get_tipo() {
    return tipo;
  }
  virtual double pago_mensual() = 0; //método abstracto será sobreescrito
  virtual string to_string() = 0;
};

//Declaro objeto Salario que hereda de Trabajador
class Salario: public Empleado {

  //Variables de instancia del objeto
  private: double salario_mensual;

  //Metodos del objeto
  public:

    Salario(): Empleado(0, "", "Salario") {};
  ASalario(int id, string nombre, double salar): Empleado(id, nombre, "Salario"),
  salario_mensual(salar) {};

  int get_id() {
    return id;
  }
  string get_nombre() {
    return nombre;
  }
  double pago_mensual() {
    return salario_mensual;
  }
  string to_string();
};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Salario::to_string() {

  stringstream aux;
  aux << "Id es " << id << " puesto " << tipo << "su nombre es " << nombre <<
    " su salario es " << salario_mensual << "\n";
  return aux.str();
}

//Declaro objeto PorHora que hereda de Trabajador
class PorHora: public Trabajador {

  //Declaro las variables de instancia privadas
  private:

    double horas_t,
  pago_por_h;

  //Declaro metodos públicos
  public:

    PorHora(): Trabajador(0, "", "por hora") {};
  PorHora(int id, string nombre, double horas, double pago): Trabajador(id, nombre, "por hora"),
  horas_t(horas),
  pago_por_h(pago) {};

  double pago_mensual() {
    return horas_t * pago_por_h;
  }
  string to_string();

};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string PorHora::to_string() {

  stringstream aux;
  aux << "Id es " << id << " puesto " << tipo << " su nombre es " << nombre <<
    " su pago mensual es " << pago_mensual() << "\n";
  return aux.str();
}

//Declaro el objet Practicante que hereda de Trabajador
class Practicante: public Trabajadoro {

  //Variables de instancia privadas del objeto
  private:

    double horas_t,
  pago_p;

  //Metodos públicos del objeto
  public:

    Practicante(): Trabajador(0, "", "practicante") {};

  Practicante(int id, string nombre, double horas, double pago): Trabajador(id, nombre, "practicante"),
  horas_t(horas),
  pago_p(pago) {};

  double pago_mensual() {
    return horas_t * pago_p;
  }
  string to_string();
};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Practicante::to_string() {

  stringstream aux;
  aux << "Id es " << id << " puesto " << tipo << " su nombre es " << nombre <<
    " su por practicas es " << pago_mensual() << "\n";
  return aux.str();
}

#endif // EMPLEADO_H_