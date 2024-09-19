#include "main.h"
#include "Biblioteca.h"
#include "materialBibliografico.h"
#include "Libro.h"
#include <iostream>
using namespace std;
int main(){
    Biblioteca* sistemaBiblioteca = new Biblioteca();
    menu(sistemaBiblioteca);

    return 0;
}

void menu(Biblioteca*  sistemaBiblioteca){
    int opcion;
    do
    {
        cout << "--------------------------------------" << endl;
        cout << "              Biblioteca" << endl;
        cout << " 1. Agregar material a la biblioteca" << endl;
        cout << " 2. Eliminar material de la biblioteca" << endl;
        cout << " 3. Buscar material en la biblioteca" << endl;
        cout << " 4. Agregar Usuario" << endl;
        cout << " 5. Eliminar Usuario" << endl;
        cout << " 6. Buscar Usuario" << endl;
        cout << " 7. Prestar material" << endl;
        cout << " 8. Devolver material" << endl;
        cout << " 9. Salir" << endl;
        cout << " Ingrese opcion" << endl;
        cin >> opcion;
        switch (opcion){
        case 1:{
            string tipo;
            cout<<"¿Revista o Libro? (R/L)?"<<endl;
            cin>>tipo;
            while(tipo!="R" && tipo!="L"){
                cout<<"Ingrese opción correcta (R/L)"<<endl;
                cin>>tipo;
            }
            string nombre, autor,isbn;
            if(tipo=="R"){
                string numeroEdicion,mesPublicacion;
                cout<<"Ingrese nombre:"<<endl;
                cin>>nombre;
                cout<<"Ingrese autor:"<<endl;
                cin>>autor;
                cout<<"Ingrese Isbn:"<<endl;
                cin>>isbn;
                cout<<"Ingrese numero de edicion:"<<endl;
                cin>>numeroEdicion;
                cout<<"Ingrese mes de publicacion:"<<endl;
                cin>>mesPublicacion;
                sistemaBiblioteca->agregarMaterialRevista(nombre,autor,isbn,numeroEdicion,mesPublicacion);
            }
            else if (tipo=="L"){
                string fechaPublicacion, resumen;
                cout<<"Ingrese nombre:"<<endl;
                cin>>nombre;
                cout<<"Ingrese autor:"<<endl;
                cin>>autor;
                cout<<"Ingrese Isbn:"<<endl;
                cin>>isbn;
                cout<<"Ingrese Fecha de publicación:"<<endl;
                cin>>fechaPublicacion;
                cout<<"Ingrese resumen:"<<endl;
                cin>>resumen;
                sistemaBiblioteca->agregarMaterialLibro(nombre,autor,isbn,fechaPublicacion,resumen);
            }
        }
            break;

        case 2:{
            

        }
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            cout<<"Adios"<<endl;
            break;

        default:
            cout << " Opcion invalida" << endl;
            break;
        
    }
    } while (opcion != 9);
    


}