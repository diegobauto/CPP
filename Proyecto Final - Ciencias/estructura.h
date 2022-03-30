#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <iostream>
#include "Interna.h"
using namespace std;

template <class T>
struct nodo{
  nodo<T> *sig, *sigProg, *sigInt, *sigCre, *sigSem;
  T info;
};

struct Vacuna{
  int dia;
  int mes;
  int anio;
	string tipo;
};

struct Horario{
	string dia;
	int hora_inicio;
	int hora_final;
	string salon;
};


struct Profesor{
	int codigo;
	string nombre;
	string email;
  Interna<Vacuna> vacunas;
  Interna<string> proDict;
  Interna<string> asigDict;
};

struct Estudiante{
	string codigo;
	string nombre;
	int edad;
	string email;
	string programa;
	string tipo;
	int semestre;
  Interna<Vacuna> vacunas;
  Interna<string> grIns;
};

struct Grupo{
	int codigo;
	string nom_profesor;
	int max_estud;
  int aforo; 
	Interna<Horario> horarios;
  Interna<string> estInscritos;
};

struct Asignatura{
	string programa;
  int codigo;
	string nombre;
	int creditos;
	int intensidad;
	bool dicta_prox;
	string tipo;
	int semestre;
  Interna<Grupo> grupos;
};

const string PROGRAMA[5] = {"Sistemas", "Electronica", "Industrial", "Electrica", "Catastral"}; 
const int SEMESTRE[10] = {1,2,3,4,5,6,7,8,9,10};
const string TIPO[10] = {"Pregrado", "Postgrado"};

#endif
