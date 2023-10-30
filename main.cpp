#include <iostream>
#include <cstring>

using namespace std;

#include "parcial1l.h"

class ArchivoDeporte5
{

private:
    int _DNI;
    char _nombre[30];
    char _apellido[30];
    Fecha _fechaDeInscripcion;

public:
    // void Cargar();
    bool grabarRegistro()
    {
        FILE *p;
        p = fopen("ArchivoDeporte5.dat", "ab");
        if (p == NULL){
            cout<<"ERROR AL CREAR EL P"<<endl;
            return false;
        }
        bool escribio = fwrite(this, sizeof(ArchivoDeporte5), 1, p);
        fclose(p);
        return escribio;
    }

    void setDNI(int dni) { _DNI = dni; }
    void setNombre(const char *nombre) { strcpy(_nombre, nombre); }
    void setApellido(const char *apellido) { strcpy(_apellido, apellido); }
    void setFechaInscripcion(Fecha fechaDeInscripcion) { _fechaDeInscripcion = fechaDeInscripcion; }

    // int _DNI;
    // char _nombre[30];
    // char _apellido[30];
    // Fecha _fechaDeInscripcion;

    int getDNI() { return _DNI; }
    const char *getNOMBRE() { return _nombre; }
    const char *getAPELLIDO() { return _apellido; }
    Fecha getFecha(){return _fechaDeInscripcion;}

    void Mostrar()
    {
        cout << "_DNI= " << getDNI() << endl;
        cout << "_nombre= " << getNOMBRE() << endl;
        cout << "_apellido= " << getAPELLIDO() << endl;
       _fechaDeInscripcion.Mostrar();
       cout<<endl;
    }
};

bool buscarJugadorCategoria5(int id);

void MostrarArchivoCompleto();
void VaciarArchivoDeporte5();

void CargarArchivosDeporte(int tam);
void CargarArchivosJugadores(int tam);

void MostrarArchivosDeporte();
void MostrarArchivosJugadores();

int main()
{

    //CargarArchivosJugadores(30);
    //CargarArchivosDeporte(30);
    MostrarArchivosJugadores();
    //MostrarArchivosDeporte();


    //////////////////////////////
    int tamReg;
    ArchivoJugadores AJ("jugadores.dat");
    tamReg = AJ.contarRegistros(); //<-----------------------
    Jugador J;
    ArchivoDeporte5 AD5;

    for (int i = 0; i < tamReg; i++)
    {
         J = AJ.leerRegistro(i);
         if (J.getEstado() == true)
         {
            
             if (J.getClaustro() == 2)
             {
                
                 if (buscarJugadorCategoria5(J.getIdDeporte())==true)
                 {
                     AD5.setNombre(J.getNombre());
                     AD5.setApellido(J.getApellido());
                     AD5.setDNI(J.getDNI());
                     AD5.setFechaInscripcion(J.getFechaInscirpcion());
                     if (AD5.grabarRegistro() == true)
                     {
                         cout << "Se Guardo Correctamente" << endl;
                     }
                     
                 }/// ///else{ if(AD5.grabarRegistro()){cout << "Se Guardo Correctamente,un arcchivo vacio " << endl;}}
             }
         }
    }

    MostrarArchivoCompleto();
    //////////////////////////////





    return 0;
}

bool buscarJugadorCategoria5(int id) //<------------
{
    int tamReg;
    ArchivoDeportes AD("deportes.dat");
    tamReg = AD.contarRegistros();
    Deporte D;

    for (int i = 0; i < tamReg; i++)
    {
        D = AD.leerRegistro(i);

    if((D.getIdCtegoria()==5) && (D.getEstado()==true) && (id == D.getIdDeporte())){

        //cout<<"SI id"<<id<<endl;
        //cout<<"SI getIdDeporte"<<D.getIdDeporte()<<endl;
            //cout<<"SI 2"<<endl;
            return true;
    }


    }
    return false;
}

void MostrarArchivoCompleto()
{
    

    ArchivoDeporte5 ClassM;
    FILE *p;

    p = fopen("ArchivoDeporte5.dat", "rb");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO1" << endl;
        system("pause");
    }

    while (fread(&ClassM, sizeof(ArchivoDeporte5), 1, p) == 1)
    {
        ClassM.Mostrar();
    }

    VaciarArchivoDeporte5();

    fclose(p);
    
}
void MostrarArchivosDeporte(){

ArchivoDeportes AD("deportes.dat");
int tam;
tam=AD.contarRegistros();
Deporte d;
for(int i=0;i<tam;i++)
{
    d=AD.leerRegistro(i);
    d.Mostrar();
}
}

void MostrarArchivosJugadores(){
ArchivoJugadores AJ("jugadores.dat");

int tam2;
tam2=AJ.contarRegistros();
Jugador j;

for(int i=0;i<tam2;i++)
{
    j=AJ.leerRegistro(i);
    j.Mostrar();
}
}

void CargarArchivosJugadores(int tam){


FILE *p;
Jugador ClassM;
p=fopen("jugadores.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}
for(int i=0; i<tam; i++){
ClassM.Cargar();
fwrite(&ClassM,sizeof (Jugador),1,p);
}
fclose(p);
}

void CargarArchivosDeporte(int tam){
FILE *p;
Deporte ClassM;
p=fopen("deportes.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}
for(int i=0; i<tam; i++){
ClassM.Cargar();
fwrite(&ClassM,sizeof (Deporte),1,p);
}
fclose(p);

}

void VaciarArchivoDeporte5(){
    ArchivoDeporte5 ClassM;
    FILE *p;

    p = fopen("ArchivoDeporte5.dat", "wb");
    if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
    }
    fclose(p);
}