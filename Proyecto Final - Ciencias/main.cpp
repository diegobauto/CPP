#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <typeinfo>
#include <sstream>

#include "estructura.h"
#include "Lista.h"
#include "Intensidad.h"
#include "Programa.h"
#include "Creditos.h"
#include "Semestre.h"

using namespace std;

//Listas generales
Lista<Asignatura> asignaturas;
Lista<Profesor> profesores;
Lista<Estudiante> estudiantes;
Lista<Grupo> grupos;

//Listas de cabeceras
Programa<Asignatura> progAsig;
Intensidad<Asignatura> intAsig;
Creditos<Asignatura> creAsig;
Semestre<Asignatura> semAsig;

string to_string(int k){
	stringstream ss;
	ss<<k;
	string s;
	ss>>s;
	return s;
}

//Funcion para registrar grupo 
void regisGrupo(Asignatura asig_par){
  cout<<endl<<"-------- REGISTRANDO GRUPO --------"<<endl;
  Grupo gruInfo;
  cout<<"Digite el id del Grupo: ";
  cin>>gruInfo.codigo;

  //Hacer una busqueda del profesor
  int p = 0;
  string nombre;
  cout<<"Digite el nombre del profesor: ";
  cin>>nombre;
  while(p<profesores.tamLista()){
    Profesor profe = profesores.obtener(p);
    for(int x=0; x<profe.proDict.tamLista(); x++){
      if(profe.nombre == nombre && profe.proDict.obtener(x) == asig_par.programa){
        gruInfo.nom_profesor = nombre;
        if(profe.asigDict.obtener(0)=="0"){
          profe.asigDict.editar(asig_par.nombre,0);
        }else{
          profe.asigDict.insertar(asig_par.nombre); 
        }
        p=9999;
      }else if(p == profesores.tamLista()-1){
        cout<<"No se encontro el profesor o no pertenece al programa indicado.\nDigite nuevamente otro profesor: ";
        cin>>nombre;
        p = -1;
      }
    }
    p++;
  }
  
  cout<<"Digite el maximo de estudiantes: ";
  cin>>gruInfo.max_estud;
  cout<<"Digite el aforo del grupo: ";
  cin>>gruInfo.aforo; 
  
  int nDicta;
  cout<<"Digite la cantidad de veces que se dicta: ";
  cin>>nDicta;
  for(int i=0; i<nDicta; i++){
    Horario horario;
    cout<<endl<<"---- Dia #"<<(i+1)<<" ---"<<endl;
    cout<<"Digite el dia: ";
    cin>>horario.dia;
    cout<<"Digite la hora de inicio: ";
    cin>>horario.hora_inicio;
    cout<<"Digite la hora final: ";
    cin>>horario.hora_final;
    cout<<"Digite el salon: ";
    cin>>horario.salon;
    (gruInfo.horarios).insertar(horario);
  }
  gruInfo.estInscritos.insertar("0");
  asig_par.grupos.insertar(gruInfo); 
  grupos.insertar(gruInfo);
  cout<<endl;
}

//Funcion para registrar un grupo
Grupo registrarGrupo(Asignatura asig_par){
  cout<<endl<<"-------- REGISTRANDO GRUPO --------"<<endl;
  Grupo gruInfo;
  cout<<"Digite el id del Grupo: ";
  cin>>gruInfo.codigo;

  //Hacer una busqueda del profesor
  int p = 0;
  string nombre;
  cout<<"Digite el nombre del profesor: ";
  cin>>nombre;
  while(p<profesores.tamLista()){
    Profesor profe = profesores.obtener(p);
    for(int x=0; x<profe.proDict.tamLista(); x++){
      if(profe.nombre == nombre && profe.proDict.obtener(x) == asig_par.programa){
        gruInfo.nom_profesor = nombre;
        if(profe.asigDict.obtener(0)=="0"){
          profe.asigDict.editar(asig_par.nombre,0);
        }else{
          profe.asigDict.insertar(asig_par.nombre); 
        }
        p=9999;
      }else if(p == profesores.tamLista()-1){
        cout<<"No se encontro el profesor o no pertenece al programa indicado.\nDigite nuevamente otro profesor: ";
        cin>>nombre;
        p = -1;
      }
    }
    p++;
  }
  
  cout<<"Digite el maximo de estudiantes: ";
  cin>>gruInfo.max_estud;
  cout<<"Digite el aforo del grupo: ";
  cin>>gruInfo.aforo; 
  
  int nDicta;
  cout<<"Digite la cantidad de veces que se dicta: ";
  cin>>nDicta;
  for(int i=0; i<nDicta; i++){
    Horario horario;
    cout<<endl<<"---- Dia #"<<(i+1)<<" ---"<<endl;
    cout<<"Digite el dia: ";
    cin>>horario.dia;
    cout<<"Digite la hora de inicio: ";
    cin>>horario.hora_inicio;
    cout<<"Digite la hora final: ";
    cin>>horario.hora_final;
    cout<<"Digite el salon: ";
    cin>>horario.salon;
    (gruInfo.horarios).insertar(horario);
  }
  gruInfo.estInscritos.insertar("0");
  grupos.insertar(gruInfo);
  cout<<endl;
  return gruInfo;
}

//Funcion para registrar una asignatura
bool registrarAsignatura(){
  Asignatura asigInfo;
  cout<<endl<<"-------- REGISTRANDO ASIGNATURA --------"<<endl;
  cout<<"Digite el programa de la Asignatura: ";
  cin>>asigInfo.programa;
  cout<<"Digite el codigo de la Asignatura: ";
  cin>>asigInfo.codigo;
  cout<<"Digite el nombre de la Asignatura: ";
  cin>>asigInfo.nombre;
  cout<<"Digite el numero de creditos de la Asignatura: ";
  cin>>asigInfo.creditos;
  cout<<"Digite la intensidad de la Asignatura: ";
  cin>>asigInfo.intensidad;
  cout<<"Se dicta en el proximo semestre la Asignatura? (0. No/1. Si): ";
  cin>>asigInfo.dicta_prox;
  cout<<"Digite el tipo de la Asignatura (Pregrado/Postgrado): ";
  cin>>asigInfo.tipo;
  cout<<"Digite el semestre de la Asignatura: ";
  cin>>asigInfo.semestre;
  
  int numG;
  cout<<"Cuantos grupos desea agregar a la asignatura?: ";
  cin>>numG;
  if(numG == 0){
    cout<<"Debe digitar al menos un grupo"<<endl;
    numG = 1;
  }
  for(int i=0; i<numG; i++){
	  asigInfo.grupos.insertar(registrarGrupo(asigInfo));
  }
  
  asignaturas.insertar(asigInfo);
  progAsig.insertar(asigInfo);
  intAsig.insertar(asigInfo);
  creAsig.insertar(asigInfo);
  semAsig.insertar(asigInfo);
  cout<<endl;
  return true;
}

//Funcion para registrar un profesor
bool registrarProfesor(){
  cout<<endl<<"-------- REGISTRANDO PROFESOR --------"<<endl;
  Profesor proInfo;
  cout<<"Digite el nombre del Profesor: ";
  cin>>proInfo.nombre;
  cout<<"Digite el codigo del Profesor: ";
  cin>>proInfo.codigo;
  cout<<"Digite el e-mail del Profesor: ";
  cin>>proInfo.email;
  
  int nVacuna;
  cout<<endl<<"Digite el numero de vacunas aplicadas: ";
  cin>>nVacuna;
  
  for(int i=0; i<nVacuna; i++){
    Vacuna vc;
    cout<<endl<<"---- Vacuna #"<<(i+1)<<" ---"<<endl;
    cout<<"Pfizer, Moderna, Johnson, AstraZeneca o Sinovac\nDigite la vacuna aplicada: ";
    cin>>vc.tipo;
    cout<<"Digite la fecha: "<<endl;
    cout<<"\tDia: ";
    cin>>vc.dia;
    cout<<"\tMes: ";
    cin>>vc.mes;
    cout<<"\tAnio: ";
    cin>>vc.anio;
    (proInfo.vacunas).insertar(vc);
  }
  
  int nProgramas;
  cout<<endl<<"Digite el numero de programas en los que dicta: ";
  cin>>nProgramas;
  for(int i=0; i<nProgramas; i++){
    string programa;
    cout<<"Programa #"<<(i+1)<<": ";
    cin>>programa;
    proInfo.proDict.insertar(programa);
  }
  proInfo.asigDict.insertar("0");
  
  profesores.insertar(proInfo);
  cout<<endl;
  return true;
}

//Funcion para registrar un estudiante
bool registrarEstudiante(){
  Estudiante estuInfo;
  cout<<endl<<"-------- REGISTRANDO ESTUDIANTE --------"<<endl;
  cout<<"Digite el codigo del Estudiante: ";
  cin>>estuInfo.codigo;
  cout<<"Digite el nombre del Estudiante: ";
  cin>>estuInfo.nombre;
  cout<<"Digite la edad del Estudiante: ";
  cin>>estuInfo.edad;
  cout<<"Digite el e-mail del Estudiante: ";
  cin>>estuInfo.email;
  cout<<"Digite el programa al cual pertenece del Estudiante: ";
  cin>>estuInfo.programa;
  cout<<"Digite el tipo del Estudiante (Pregrado/Postgrado): ";
  cin>>estuInfo.tipo;
  cout<<"Digite el semestre del Estudiante: ";
  cin>>estuInfo.semestre;
  
  int nVacuna;
  cout<<"Digite el numero de vacunas aplicadas: ";
  cin>>nVacuna;
  
  for(int i=0; i<nVacuna; i++){
    Vacuna vc;
    cout<<endl<<"---- Vacuna #"<<(i+1)<<" ---"<<endl;
    cout<<"Pfizer, Moderna, Johnson, AstraZeneca o Sinovac\nDigite la vacuna aplicada: ";
    cin>>vc.tipo;
    cout<<"Digite la fecha: "<<endl;
    cout<<"\tDia (DD): ";
    cin>>vc.dia;
    cout<<"\tMes (MM): ";
    cin>>vc.mes;
    cout<<"\tAnio (AAAA): ";
    cin>>vc.anio;
    (estuInfo.vacunas).insertar(vc);
  }
  estuInfo.grIns.insertar("0");
   
  estudiantes.insertar(estuInfo);
  cout<<endl;
  return true;
}

//******************** ARCHIVOS ********************
//Funcion para escribir una asignatura en archivo plano
void escribirAsig(){
  ofstream archivo;
  archivo.open("archivos//asignatura.txt", ios::out);
  if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
  }else{
    for(int i=0; i<asignaturas.tamLista(); i++){
      Asignatura asignatura_info = asignaturas.obtener(i);
      archivo<<asignatura_info.programa+"/"+
        to_string(asignatura_info.codigo)+"/"+
        asignatura_info.nombre+"/"+
        to_string(asignatura_info.creditos)+"/"+
        to_string(asignatura_info.intensidad)+"/"+
        to_string(asignatura_info.dicta_prox)+"/"+
        asignatura_info.tipo+"/"+
        to_string(asignatura_info.semestre)+"/";
      for(int j=0; j<asignatura_info.grupos.tamLista(); j++){
        Grupo gr = asignatura_info.grupos.obtener(j);
        if(j>0){
          archivo<<"-"+to_string(gr.codigo);
        }else{
          archivo<<to_string(gr.codigo);
        }
      }
      archivo<<"\n";
    }
  }
  archivo.close();
}

//Funcion para escribir un estudiante en archivo plano
void escribirEstud(){
  ofstream archivo;
  archivo.open("archivos//estudiantes.txt", ios::out);
  if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
  }else{
    for(int i=0; i<estudiantes.tamLista(); i++){
      Estudiante estud_info = estudiantes.obtener(i);
      archivo<<estud_info.codigo+"/"+
        estud_info.nombre+"/"+
        to_string(estud_info.edad)+"/"+
        estud_info.email+"/"+
        estud_info.programa+"/"+
        estud_info.tipo+"/"+
        to_string(estud_info.semestre)+"/";
      for(int j=0; j<estud_info.vacunas.tamLista(); j++){
        Vacuna vcna = estud_info.vacunas.obtener(j);
        if(j>0){
          archivo<<","+to_string(vcna.dia)+"-"+to_string(vcna.mes)+"-"+to_string(vcna.anio)+"-"+vcna.tipo;
        }else{
          archivo<<to_string(vcna.dia)+"-"+to_string(vcna.mes)+"-"+to_string(vcna.anio)+"-"+vcna.tipo;
        }
      }
      archivo<<"/";
      for(int k=0; k<estud_info.grIns.tamLista(); k++){
        string grp = estud_info.grIns.obtener(k);
        if(k>0){
          archivo<<"-"+grp;
        }else{
          archivo<<grp;
        }
      }
      archivo<<"\n";
    }
  }
  archivo.close();
}

//Funcion para escribir un profesor en archivo plano
void escribirProf(){
  ofstream archivo;
  archivo.open("archivos//profesores.txt", ios::out);
  if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
  }else{
    for(int i=0; i<profesores.tamLista(); i++){
      Profesor prof_info = profesores.obtener(i);
      archivo<<to_string(prof_info.codigo)+"/"+
        prof_info.nombre+"/"+
        prof_info.email+"/";
      for(int j=0; j<prof_info.vacunas.tamLista(); j++){
        Vacuna vcna = prof_info.vacunas.obtener(j);
        if(j>0){
          archivo<<","+to_string(vcna.dia)+"-"+to_string(vcna.mes)+"-"+to_string(vcna.anio)+"-"+vcna.tipo;
        }else{
          archivo<<to_string(vcna.dia)+"-"+to_string(vcna.mes)+"-"+to_string(vcna.anio)+"-"+vcna.tipo;
        }
      }
      archivo<<"/";
      for(int k=0; k<prof_info.proDict.tamLista(); k++){
        string prog = prof_info.proDict.obtener(k);
        if(k>0){
          archivo<<"-"+prog;
        }else{
          archivo<<prog;
        }
      }
      archivo<<"/";
      for(int h=0; h<prof_info.asigDict.tamLista(); h++){
        string asig = prof_info.asigDict.obtener(h);
        if(h>0){
          archivo<<"-"+asig;
        }else{
          archivo<<asig;
        }
      }
      archivo<<"\n";
    }
  }
  archivo.close();
}

//Funcion para escribir un grupo en archivo plano
void escribirGrupo(){
  ofstream archivo;
  archivo.open("archivos//grupos.txt", ios::out);
  if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
  }else{
    for(int i=0; i<grupos.tamLista(); i++){
      Grupo grup_info = grupos.obtener(i);
      archivo<<to_string(grup_info.codigo)+"/"+
        grup_info.nom_profesor+"/"+
        to_string(grup_info.max_estud)+"/"+
        to_string(grup_info.aforo)+"/";
      for(int j=0; j<grup_info.horarios.tamLista(); j++){
        Horario date = grup_info.horarios.obtener(j);
        if(j>0){
          archivo<<","+date.dia+"-"+to_string(date.hora_inicio)+"-"+to_string(date.hora_final)+"-"+date.salon;
        }else{
          archivo<<date.dia+"-"+to_string(date.hora_inicio)+"-"+to_string(date.hora_final)+"-"+date.salon;
        }
      }
      archivo<<"/";
      for(int k=0; k<grup_info.estInscritos.tamLista(); k++){
        string est = grup_info.estInscritos.obtener(k);
        if(k>0){
          archivo<<"-"+est;
        }else{
          archivo<<est;
        }
      }
      archivo<<"\n";
    }
  }
  archivo.close();
}

//Funcion para leer un profesor del archivo plano
void lecturaProf(){
  ifstream archivo;
  string texto, *data, *aux1, *aux2, *aux3, *aux4;  
  int contPosition;
  
  archivo.open("archivos//profesores.txt", ios::in);
  if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
  }else{
    while(getline(archivo, texto)){
      contPosition = 0;
      data = new string [6];
      for(int i=0; i<texto.length(); i++){
        if(texto[i] == '/'){
          contPosition++;
        }else{
          data[contPosition] += texto[i];
        }
      }

      Profesor cr_prof;
      cr_prof.codigo = atoi(data[0].c_str());
      cr_prof.nombre = data[1];
      cr_prof.email = data[2];

      int cont = 0;
      for(int j=0; j<data[3].length(); j++){
        if(data[3][j] == ','){
          cont++;
        }
      }

      contPosition = 0;
      aux1 = new string [cont+1];
      for(int k=0; k<data[3].length(); k++){
        if(data[3][k] == ','){
          contPosition++;
        }else{
          aux1[contPosition] += data[3][k];
        }
      }      
      
      for(int p=0; p<cont+1; p++){
        contPosition = 0;
        aux2 = new string [4];
        for(int t=0; t<aux1[p].length(); t++){
          if(aux1[p][t] == '-'){
            contPosition++;
          }else{
            aux2[contPosition] += aux1[p][t];
          } 
        }
        
        Vacuna vcuna;
        vcuna.dia = atoi(aux2[0].c_str());
        vcuna.mes = atoi(aux2[1].c_str());
        vcuna.anio = atoi(aux2[2].c_str());
        vcuna.tipo = aux2[3];
        cr_prof.vacunas.insertar(vcuna);
      }

      //Programas
      cont = 0;
      for(int j=0; j<data[4].length(); j++){
        if(data[4][j] == '-'){
          cont++;
        }
      }
      
      contPosition = 0;
      aux3 = new string [cont+1];
      for(int k=0; k<data[4].length(); k++){
        if(data[4][k] == '-'){
          contPosition++;
        }else{
          aux3[contPosition] += data[4][k];
        }
      }

      for(int x=0; x<cont+1; x++){
        cr_prof.proDict.insertar(aux3[x]);
      }

      //Asignaturas
      cont = 0;
      for(int j=0; j<data[5].length(); j++){
        if(data[5][j] == '-'){
          cont++;
        }
      }
      
      contPosition = 0;
      aux4 = new string [cont+1];
      for(int k=0; k<data[5].length(); k++){
        if(data[5][k] == '-'){
          contPosition++;
        }else{
          aux4[contPosition] += data[5][k];
        }
      }

      for(int f=0; f<cont+1; f++){
        cr_prof.asigDict.insertar(aux4[f]);
      }
      
      profesores.insertar(cr_prof);
    } 
  }
  archivo.close();
}

//Funcion para leer un estudiante del archivo plano
void lecturaEstud(){
  ifstream archivo;
  string texto, *data, *aux1, *aux2, *aux3;  
  int contPosition;
  
  archivo.open("archivos//estudiantes.txt", ios::in);
  if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
  }else{
    while(getline(archivo, texto)){
      contPosition = 0;
      data = new string [9];
      for(int i=0; i<texto.length(); i++){
        if(texto[i] == '/'){
          contPosition++;
        }else{
          data[contPosition] += texto[i];
        }
      }

      Estudiante cr_est;
      cr_est.codigo = data[0];
      cr_est.nombre = data[1];
      cr_est.edad = atoi(data[2].c_str());
      cr_est.email = data[3];
      cr_est.programa = data[4];
      cr_est.tipo = data[5];
      cr_est.semestre = atoi(data[6].c_str());

      int cont = 0;
      for(int j=0; j<data[7].length(); j++){
        if(data[7][j] == ','){
          cont++;
        }
      }

      contPosition = 0;
      aux1 = new string [cont+1];
      for(int k=0; k<data[7].length(); k++){
        if(data[7][k] == ','){
          contPosition++;
        }else{
          aux1[contPosition] += data[7][k];
        }
      }      
      
      for(int p=0; p<cont+1; p++){
        contPosition = 0;
        aux2 = new string [4];
        for(int t=0; t<aux1[p].length(); t++){
          if(aux1[p][t] == '-'){
            contPosition++;
          }else{
            aux2[contPosition] += aux1[p][t];
          } 
        }
        
        Vacuna vcuna;
        vcuna.dia = atoi(aux2[0].c_str());
        vcuna.mes = atoi(aux2[1].c_str());
        vcuna.anio = atoi(aux2[2].c_str());
        vcuna.tipo = aux2[3];
        cr_est.vacunas.insertar(vcuna);
      }
      //grupos inscritos
      cont = 0;
      for(int j=0; j<data[8].length(); j++){
        if(data[8][j] == '-'){
          cont++;
        }
      }
      
      contPosition = 0;
      aux3 = new string [cont+1];
      for(int k=0; k<data[8].length(); k++){
        if(data[8][k] == '-'){
          contPosition++;
        }else{
          aux3[contPosition] += data[8][k];
        }
      }

      for(int f=0; f<cont+1; f++){
        cr_est.grIns.insertar(aux3[f]);
      }
      
      estudiantes.insertar(cr_est);
    } 
  }
  archivo.close();
}

//Funcion para leer un grupo del archivo plano
void lecturaGrupo(){
  ifstream archivo;
  string texto, *data, *aux1, *aux2, *aux3;  
  int contPosition;
  
  archivo.open("archivos//grupos.txt", ios::in);
  if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
  }else{
    while(getline(archivo, texto)){
      
      contPosition = 0;
      data = new string [6];
      for(int i=0; i<texto.length(); i++){
        if(texto[i] == '/'){
          contPosition++;
        }else{
          data[contPosition] += texto[i];
        }
      }

      Grupo cr_grup;
      cr_grup.codigo = atoi(data[0].c_str());
      cr_grup.nom_profesor = data[1];
      cr_grup.max_estud = atoi(data[2].c_str());
      cr_grup.aforo = atoi(data[3].c_str());

      int cont = 0;
      for(int j=0; j<data[4].length(); j++){
        if(data[4][j] == ','){
          cont++;
        }
      }

      contPosition = 0;
      aux1 = new string [cont+1];
      for(int k=0; k<data[4].length(); k++){
        if(data[4][k] == ','){
          contPosition++;
        }else{
          aux1[contPosition] += data[4][k];
        }
      }      
      
      for(int p=0; p<cont+1; p++){
        contPosition = 0;
        aux2 = new string [4];
        for(int t=0; t<aux1[p].length(); t++){
          if(aux1[p][t] == '-'){
            contPosition++;
          }else{
            aux2[contPosition] += aux1[p][t];
          } 
        }
        
        Horario horio;
        horio.dia = aux2[0];
        horio.hora_inicio = atoi(aux2[1].c_str());
        horio.hora_final = atoi(aux2[2].c_str());
        horio.salon = aux2[3];
        cr_grup.horarios.insertar(horio); 
      }
      //EstInscritos
      cont = 0;
      for(int j=0; j<data[5].length(); j++){
        if(data[5][j] == '-'){
          cont++;
        }
      }
      
      contPosition = 0;
      aux3 = new string [cont+1];
      for(int k=0; k<data[5].length(); k++){
        if(data[5][k] == '-'){
          contPosition++;
        }else{
          aux3[contPosition] += data[5][k];
        }
      }

      for(int f=0; f<cont+1; f++){
        cr_grup.estInscritos.insertar(aux3[f]);
      }
      
      grupos.insertar(cr_grup);
    } 
  }
  archivo.close();
}

//Funcion para leer una asignatura del archivo plano
void lecturaAsig(){
  ifstream archivo;
  string texto, *data, *aux1;  
  int contPosition;
  
  archivo.open("archivos//asignatura.txt", ios::in);
  if(archivo.fail()){
    cout<<"No se pudo abrir el archivo";
  }else{
    while(getline(archivo, texto)){
      contPosition = 0;
      data = new string [9];
      for(int i=0; i<texto.length(); i++){
        if(texto[i] == '/'){
          contPosition++;
        }else{
          data[contPosition] += texto[i];
        }
      }

      Asignatura cr_asig;
      cr_asig.programa = data[0];
      cr_asig.codigo = atoi(data[1].c_str());
      cr_asig.nombre = data[2];
      cr_asig.creditos = atoi(data[3].c_str());
      cr_asig.intensidad = atoi(data[4].c_str());
      cr_asig.dicta_prox = atoi(data[5].c_str());
      cr_asig.tipo = data[6];
      cr_asig.semestre = atoi(data[7].c_str()); 

      int cont = 0;
      for(int j=0; j<data[8].length(); j++){
        if(data[8][j] == '-'){
          cont++;
        }
      }

      contPosition = 0;
      aux1 = new string [cont+1];
      for(int k=0; k<data[8].length(); k++){
        if(data[8][k] == '-'){
          contPosition++;
        }else{
          aux1[contPosition] += data[8][k];
        }
      }
      
      //Asignar grupos a la asignatura
      for(int t=0; t<cont+1; t++){
        for(int p=0;p<grupos.tamLista();p++){
          if(atoi(aux1[t].c_str()) == grupos.obtener(p).codigo){
            cr_asig.grupos.insertar(grupos.obtener(p));
          } 
        }
      }
      
      asignaturas.insertar(cr_asig);
      progAsig.insertar(cr_asig);
      intAsig.insertar(cr_asig);
      creAsig.insertar(cr_asig);
      semAsig.insertar(cr_asig);
    } 
  }
  archivo.close();
}

//******************** CONSULTAS ********************
void consulta1(){
  cout<<endl<<"----------- CONSULTA 1 ------------"<<endl;
  string programa;
  cout<<"Digite el programa: ";
  cin>>programa;
  int tam = progAsig.tam(programa);
  cout<<"Numero total de asignaturas: "<<tam<<endl;

  for(int i=1; i<11; i++){
    cout<<"Semestre #"<<i<<": "<<endl;
    for(int k=1; k<5; k++){
      cout<<"\tCreditos #"<<k<<": "<<endl;
      for(int j=0; j<creAsig.tam(k); j++){
        Asignatura cAsig = creAsig.obtener(k,j);
        if(cAsig.programa == programa && cAsig.semestre == i){
          cout<<"\t\t"<<cAsig.nombre<<" - "<<cAsig.tipo<<endl;
        }
      }
    }
  }
}

void consulta2(){
  cout<<endl<<"----------- CONSULTA 2 ------------"<<endl;
  string programa;
  cout<<"Digite el programa: ";
  cin>>programa;
  int tam = progAsig.tam(programa);
  for(int i=0; i<tam; i++){
    if(progAsig.obtener(programa,i).dicta_prox){
      cout<<"* "<<progAsig.obtener(programa,i).nombre;
      cout<<" - Cod.: "<<progAsig.obtener(programa,i).codigo<<endl;
      for(int j=0; j<progAsig.obtener(programa,i).grupos.tamLista(); j++){
    	  Grupo gr = progAsig.obtener(programa,i).grupos.obtener(j);
    	  cout<<"\t"<<"Grupo: "<<gr.codigo<<" - Cupos: "<<gr.max_estud<<endl;
        for(int k=0; k<gr.horarios.tamLista(); k++){
      		Horario hr = gr.horarios.obtener(k);
      		cout<<"\t\t"<<". Dia: "<<hr.dia<<" / Hora: "<<hr.hora_inicio<<" - "<<hr.hora_final<<" / Salon: "<<hr.salon<<endl;
		    }
      }
    }
  }
}

void consulta3(){
  cout<<endl<<"----------- CONSULTA 3 ------------"<<endl;
  string asig_nom;
  int grup_id;
  
  cout<<"Digite el nombre la asignatura: ";
  cin>>asig_nom; 
  cout<<"Digite el id del grupo: ";
  cin>>grup_id;

  for(int i=0; i<asignaturas.tamLista(); i++){
    Asignatura asig = asignaturas.obtener(i);
    if(asig.nombre == asig_nom){
      for(int j=0; j<asig.grupos.tamLista(); j++){
        Grupo grup = asig.grupos.obtener(j);
        int cont = 0;
        for(int u=0; u<grup.estInscritos.tamLista(); u++){
          if(grup.estInscritos.obtener(u) == "0"){
            cont++;    
          }
        }
        if(grup.codigo == grup_id){ 
          cout<<"Grupo: "<<grup.codigo<<" - No. Estudiantes: "<<grup.estInscritos.tamLista()-cont<<endl;
          for(int k=0; k<grup.estInscritos.tamLista(); k++){
            string cod = grup.estInscritos.obtener(k);
            for(int e=0; e<estudiantes.tamLista(); e++){
              if(estudiantes.obtener(e).codigo == cod){
                cout<<"\t"<<estudiantes.obtener(e).nombre<<" - "<<estudiantes.obtener(e).codigo<<endl;
                cout<<"\t\t"<<"No. Vacunas: "<<estudiantes.obtener(e).vacunas.tamLista()<<endl;
              }
            }
          }
        }
      }
    }
  }
}

void consulta4(){
  cout<<endl<<"----------- CONSULTA 4 ------------"<<endl;

  string codigo;
  cout<<"Digite el codigo del estudiante: ";
  cin>>codigo;

  for(int i=0; i<estudiantes.tamLista(); i++){
    Estudiante est = estudiantes.obtener(i);
    if(est.codigo == codigo){
      cout<<est.codigo<<" - "<<est.nombre<<endl;
      cout<<"Listado de Asignaturas: "<<endl;
      for(int j=0; j<est.grIns.tamLista(); j++){
        string gr = est.grIns.obtener(j);
        for(int k=0; k<asignaturas.tamLista(); k++){
          Asignatura asg = asignaturas.obtener(k);
          for(int h=0; h<asg.grupos.tamLista(); h++){
            Grupo gpo = asg.grupos.obtener(h);
            if(to_string(gpo.codigo) == gr){
              cout<<"\t"<<asg.nombre<<endl;
            }
          }
        }
      }
      cout<<"Vacunas:"<<endl;
      for(int v=0; v<est.vacunas.tamLista(); v++){
        Vacuna vcna = est.vacunas.obtener(v);
        cout<<"\t"<<vcna.tipo<<" - "<<vcna.dia<<"/"<<vcna.mes<<"/"<<vcna.anio<<endl;
      }
    }
  }
}

void consulta5(){
  cout<<endl<<"----------- CONSULTA 5 ------------"<<endl;
  string vacuna;
  
  cout<<"Digite la vacuna\n(Pfizer, Moderna, Johnson, AstraZeneca, Sinovac): ";
  cin>>vacuna;

  int contador = 0;
  for(int i=0; i<estudiantes.tamLista(); i++){
    Estudiante est = estudiantes.obtener(i);
    for(int y=0; y<est.vacunas.tamLista(); y++){
      if(est.vacunas.obtener(y).tipo == vacuna){
        contador++;
        break;
      }
    }
  }  
  cout<<"Numero de estudiantes vacunados: "<<contador<<endl;

  
  for(int j=0; j<5; j++){
    cout<<PROGRAMA[j]<<": "<<endl;
    for(int x=0; x<2; x++){
      cout<<"\t"<<TIPO[x]<<": "<<endl;
      for(int k=1; k<11; k++){
        cout<<"\t\t"<<SEMESTRE[k-1]<<": "<<endl;
        for(int i=0; i<estudiantes.tamLista(); i++){
          Estudiante est = estudiantes.obtener(i);
          int cont1 = 0;
          for(int y=0; y<est.vacunas.tamLista(); y++){
            if(est.vacunas.obtener(y).tipo == vacuna){
              cont1++;
            }
          }
          if(est.programa == PROGRAMA[j] && est.semestre == k && est.tipo == TIPO[x] && cont1>0){
            Vacuna date = est.vacunas.obtener(est.vacunas.tamLista()-1);
            cout<<"\t\t\t"<<est.nombre<<" - Fecha de la ultima vacuna: ";
            cout<<date.dia<<"/"<<date.mes<<"/"<<date.anio<<endl;
          }
        }
      }
    }
  }
}

void consulta6(){
  string programa;
  cout<<endl<<"----------- CONSULTA 6 ------------"<<endl;
  cout<<"Digite el programa: ";
  cin>>programa;

  for(int i=0; i<profesores.tamLista(); i++){
    Profesor prof = profesores.obtener(i);
    for(int j=0; j<prof.proDict.tamLista();j++){
      if(prof.proDict.obtener(j) == programa){
        cout<<prof.nombre<<": "<<endl;
        cout<<"\tAsignaturas: "<<endl;
        for(int k=0; k<prof.asigDict.tamLista(); k++){
          for(int x=0; x<progAsig.tam(programa); x++){
            if(prof.asigDict.obtener(k) == progAsig.obtener(programa,x).nombre){
              cout<<"\t\t"<<prof.asigDict.obtener(k)<<endl;
            }
          }
        }
        cout<<"\tVacunas: "<<endl;
        for(int x=0; x<prof.vacunas.tamLista(); x++){
          Vacuna vna = prof.vacunas.obtener(x);
          cout<<"\t\t"<<vna.tipo<<" - "<<vna.dia<<"/"<<vna.mes<<"/"<<vna.anio<<endl;
        }
      }
    }
  }
}

int esBis(int anio){
  if(anio % 400 == 0 || ( anio % 4 == 0 && anio % 100 != 0 )) return 1;
  else return 0;
}

int dMes(int mes, int anio) {
  switch(mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
      break;
    case 2:
      if (esBis(anio))
        return 29;
      else
        return 28;
  }
  return 0;
}
 
int calcularDias(int dia1,int mes1,int anio1, int dia2,int mes2,int anio2) {
  int acum = 0;
  while ( 1 ) {
    if ( anio1 == anio2 && mes1 == mes2 )
      break;
    acum = acum+(dMes(mes1,anio1)-dia1);
    if ( mes1 == 12 ) {
      mes1 = 1;
      anio1++;
    } else
      mes1++;
    dia1 = 0;
  }
  acum = acum+(dia2-dia1);
  return acum;
}

void consulta7(){
  cout<<endl<<"----------- CONSULTA 7 ------------"<<endl;
  for(int j=0; j<5; j++){
    cout<<PROGRAMA[j]<<": "<<endl;
    cout<<"\tEstudiantes: "<<endl;
    for(int i=0; i<estudiantes.tamLista(); i++){
      Estudiante est = estudiantes.obtener(i);
      if(est.vacunas.tamLista() == 2 && est.programa == PROGRAMA[j]){
        Vacuna sgdosis = est.vacunas.obtener(est.vacunas.tamLista()-1);
        if(calcularDias(sgdosis.dia,sgdosis.mes,sgdosis.anio,28,3,2022) >= 182){
          cout<<"\t\t"<<est.nombre<<" - Cod.: "<<est.codigo<<endl;
        }
      }
    }

    cout<<"\tProfesores: "<<endl;
    for(int i=0; i<profesores.tamLista(); i++){
      Profesor prof = profesores.obtener(i);
      for(int x=0; x<prof.proDict.tamLista(); x++){
        if(prof.vacunas.tamLista() == 2 && prof.proDict.obtener(x) == PROGRAMA[j]){
          Vacuna sgdosis = prof.vacunas.obtener(prof.vacunas.tamLista()-1);
          if(calcularDias(sgdosis.dia,sgdosis.mes,sgdosis.anio,28,3,2022) >= 182){
            cout<<"\t\t"<<prof.nombre<<" - Cod.: "<<prof.codigo<<endl;
          }
        }
      }
    }
  }
}

void consulta8(){
  cout<<endl<<"----------- CONSULTA 8 ------------"<<endl;
  string dia; 
  int hora;
  cout<<"Digite el dia: ";
  cin>>dia;
  cout<<"Digite la hora: ";
  cin>>hora;
  cout<<endl<<"Los salones ocupados son: "<<endl;
  for(int i=0; i<asignaturas.tamLista(); i++){
    Asignatura asig = asignaturas.obtener(i);
    for(int j=0; j<asig.grupos.tamLista(); j++){
      Grupo grp = asig.grupos.obtener(j);
      for(int k=0; k<grp.horarios.tamLista(); k++){
        Horario hrio = grp.horarios.obtener(k);
        if(hrio.dia == dia && hora>=hrio.hora_inicio && hora<=hrio.hora_final){
          cout<<"Salon: "<<hrio.salon<<endl;
          cout<<"\t"<<asig.nombre<<" - "<<asig.programa<<endl;
          cout<<"\tProfesor: "<<grp.nom_profesor<<endl;
          cout<<"\tMax: "<<grp.max_estud<<endl;
          int cont = 0;
          for(int u=0; u<grp.estInscritos.tamLista(); u++){
            if(grp.estInscritos.obtener(u) == "0"){
              cont++;    
            }
          }
          cout<<"\tNo. inscritos: "<<grp.estInscritos.tamLista()-cont<<endl;
        }
      }
    }
  }
}

void consulta9(){
  cout<<endl<<"----------- CONSULTA 9 ------------"<<endl;
  string vac;
  cout<<"Pfizer, Moderna, Johnson, AstraZeneca o Sinovac\nDigite la vacuna a consultar: ";
  cin>>vac;
  
  cout<<"--------ESTUDIANTES--------"<<endl;
  for(int i=0; i<estudiantes.tamLista(); i++){
    Estudiante est = estudiantes.obtener(i);
    int con = 0;
    for(int j=0; j<est.vacunas.tamLista(); j++){
      Vacuna vc_est = est.vacunas.obtener(j);
      if(vc_est.tipo == vac){
        con++;
        if(con==1){
          cout<<"\t"<<est.nombre<<":"<<endl;
        }
        cout<<"\t\tDosis #"<<j+1<<": "<<vc_est.dia<<"/"<<vc_est.mes<<"/"<<vc_est.anio<<endl;
      }
    }
  }
  cout<<endl<<"--------PROFESORES--------"<<endl;
  for(int i=0; i<profesores.tamLista(); i++){
    Profesor pro = profesores.obtener(i);
    int con = 0;
    for(int j=0; j<pro.vacunas.tamLista(); j++){
      Vacuna vc_est = pro.vacunas.obtener(j); 
      if(vc_est.tipo == vac){
        con++;
        if(con==1){
          cout<<"\t"<<pro.nombre<<":"<<endl;
        }
        cout<<"\t\tDosis #"<<j+1<<": "<<vc_est.dia<<"/"<<vc_est.mes<<"/"<<vc_est.anio<<endl;
      }
    }
  }
}

//Funcion para adicionar un grupo a un estudinate
void InsEstud(){
  string cod;
  Estudiante elegido;
  bool re = true;
  while(re){
    cout<<"Digite su codigo estudiantil: ";
    cin>>cod;
    for(int i=0;i<estudiantes.tamLista();i++){
      elegido = estudiantes.obtener(i);
      if(elegido.codigo == cod){
        re = false;
        break;
      }
    }
  }
  int con=0;
  cout<<endl<<"Asignaturas que puede agregar: "<<endl;
  for(int j=0;j<progAsig.tam(elegido.programa);j++){
    Asignatura asig = progAsig.obtener(elegido.programa,j);
    if(asig.semestre == elegido.semestre){
      for(int h=0;h<asig.grupos.tamLista(); h++){
        if(!elegido.grIns.encontrar(to_string(asig.grupos.obtener(h).codigo))){
          cout<<asig.nombre<<" - Grupo: "<<asig.grupos.obtener(h).codigo<<endl;
          con++;
        }
      }
    }
  }
  if(con>0){
    string aux;
    cout<<"Que grupo quiere inscribir: ";
    cin>>aux;
    if(elegido.grIns.obtener(0)=="0"){
      elegido.grIns.editar(aux,0);
    }else{
      elegido.grIns.insertar(aux); 
    }
    for(int k=0;k<progAsig.tam(elegido.programa);k++){
      Asignatura asig = progAsig.obtener(elegido.programa,k);
      for(int l=0; l<asig.grupos.tamLista(); l++){
        if(to_string(asig.grupos.obtener(l).codigo) == aux){
          if(asig.grupos.obtener(l).estInscritos.obtener(0) == "0"){
            asig.grupos.obtener(l).estInscritos.editar(elegido.codigo,0); 
          }else{
            asig.grupos.obtener(l).estInscritos.insertar(elegido.codigo); 
          }
        }
      }
    } 
  }else{
    cout<<"No puede inscribir ninguna asignatura";
  }
}

//Funcion para modificar un grupo a un estudinate
void modEstud(){
  string cod;
  Estudiante elegido;
  bool re = true;
  while(re){
    cout<<"Digite su codigo estudiantil: ";
    cin>>cod;
    for(int i=0;i<estudiantes.tamLista();i++){
      elegido = estudiantes.obtener(i);
      if(elegido.codigo == cod){
        re = false;
        break;
      }
    }
  }
  
  int con=0;
  cout<<endl<<"Asignaturas que puede cambiar: "<<endl;
  for(int j=0;j<progAsig.tam(elegido.programa);j++){
    Asignatura asig = progAsig.obtener(elegido.programa,j);
    if(asig.semestre == elegido.semestre){
      for(int h=0;h<asig.grupos.tamLista(); h++){
        if(elegido.grIns.encontrar(to_string(asig.grupos.obtener(h).codigo)) && asig.grupos.tamLista()>1){
          cout<<asig.nombre<<" - Grupo Actual: "<<asig.grupos.obtener(h).codigo<<endl;
          con++;
        }
      }
    }
  }
  
  if(con>0){
    int cod1;
    cout<<"Digite el grupo que desea cambiar?: ";
    cin>>cod1;
    
    cout<<"Disponibles: "<<endl;
    for(int j=0; j<progAsig.tam(elegido.programa); j++){
      Asignatura asig = progAsig.obtener(elegido.programa,j);
      for(int g=0; g<asig.grupos.tamLista(); g++){
        if(asig.grupos.obtener(g).codigo == cod1){
          for(int s=0; s<asig.grupos.tamLista(); s++){
            if(asig.grupos.obtener(s).codigo != cod1){
              cout<<asig.grupos.obtener(s).codigo<<endl;
            }
          }
        }
      }
    }
    string aux;
    cout<<endl<<"Por cual desea cambiarlo?: "<<endl;
    cin>>aux;
    elegido.grIns.editar(aux,elegido.grIns.obtenerPosicion(aux));

    //Cambiar estud en grupo.txt
    for(int p=0;p<grupos.tamLista();p++){
      Grupo gr = grupos.obtener(p);
      if(gr.codigo == cod1){
        gr.estInscritos.editar("0",gr.estInscritos.obtenerPosicion(elegido.codigo));
      }
      int cont = 0;
      if(atoi(aux.c_str()) == gr.codigo){
        for(int f=0; f<gr.estInscritos.tamLista();f++){
          if(gr.estInscritos.obtener(f) == "0"){
            gr.estInscritos.editar(elegido.codigo,gr.estInscritos.obtenerPosicion("0"));
            cont++;
          }
        }
        if(con == 0){
          gr.estInscritos.insertar(elegido.codigo);
        }
      }
    }
  }else{
    cout<<"No tiene grupos para cambiar";
  }
}

void menuMaterias(){
  int op=0;
  cout<<endl<<"************ MATERIAS ************"<<endl;
  cout<<" 1. Adicionar grupo"<<endl;
  cout<<" 2. Cambiar grupo"<<endl;
  cout<<" Opcion: ";
  cin>>op;
  cout<<"***********************************"<<endl;
  switch (op) {
    case 1:
      InsEstud();
      break;
    case 2:
      modEstud();
      break;
    default:
      cout<<endl<<"Opcion invalida"<<endl;
      break;
  }
}

void menuConsultas(){
  int op=0;
  cout<<endl<<"************ CONSULTAS ************"<<endl;
  cout<<"Digite el numero de la consulta que desea hacer: ";
  cin>>op;
  cout<<"***********************************"<<endl;
  switch (op) {
    case 1:
      consulta1();
      break;
    case 2:
      consulta2();
      break;
    case 3:
      consulta3();
      break;
    case 4:
      consulta4();
      break;
    case 5:
      consulta5();
      break;
    case 6:
      consulta6();
      break;
    case 7:
      consulta7();
      break;
    case 8:
      consulta8();
      break;
    case 9:
      consulta9();
      break;
    default:
      cout<<endl<<"Opcion invalida"<<endl;
      break;
  }
}

void menuRegistrar(){
  int op=0;
  cout<<endl<<"********** REGISTRO ***********"<<endl;
  cout<<" 1. Profesor"<<endl;
  cout<<" 2. Estudiante"<<endl;
  cout<<" 3. Asignatura"<<endl;
  cout<<" 4. Grupo"<<endl;
  cout<<" Opcion: ";
  cin>>op;
  cout <<"*****************************"<<endl;
  switch (op) {
    case 1:
      registrarProfesor();
      break;
    case 2:
      registrarEstudiante();
      break;
    case 3:
      registrarAsignatura();
      break;
    case 4:
      int cod_asig;
      cout<<"A que asignatura quiere agregar el grupo (codigo): ";
      cin>>cod_asig;
      for(int i=0; i<asignaturas.tamLista(); i++){
        if(asignaturas.obtener(i).codigo == cod_asig){
          regisGrupo(asignaturas.obtener(i));
          break;
        }
      }
      break;
    default:
      cout<<endl<<"Opcion invalida"<<endl;
      break;
  }
}

//********************** MAIN **********************
int main() {
  lecturaEstud();
  lecturaProf();
  lecturaGrupo();
  lecturaAsig();

  int op;
  do {
    do {
      cout<<endl<<"************ MENU ************"<<endl;
      cout<<" 1. Registros"<<endl;
      cout<<" 2. Consultas"<<endl;
      cout<<" 3. Materias"<<endl;
      cout<<" 0. Salir"<<endl;
      cout<<" Opcion: ";
      cin>>op;
      cout<<"******************************"<<endl;
    } while (op<0 && op>3);
    switch (op) {
      case 1:
        menuRegistrar();
        break;
      case 2:
        menuConsultas();
        break;
      case 3:
        menuMaterias();
        break;
      case 0:
        escribirEstud();
        escribirProf();
        escribirGrupo();
        escribirAsig();
        break;
      default:
        cout<<endl<<"Opcion invalida"<<endl;
    }
  } while (op!=0);
  return 0;
}
