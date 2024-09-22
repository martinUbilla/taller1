#include "main.h"
#include "Biblioteca.h"
#include <iostream>
#include <limits>
#include <cctype>
#include <fstream>
using namespace std;
int main(){
    Biblioteca* sistemaBiblioteca = new Biblioteca();
    menu(sistemaBiblioteca);
    delete sistemaBiblioteca;
    return 0;
}

void menu(Biblioteca*  sistemaBiblioteca){
   int opcion;
do
{
    //falta control de error para la opcion!!!!!!1
    cout << "--------------------------------------" << endl;
    cout << "              Biblioteca" << endl;
    //x
    cout << " 1. Agregar material a la biblioteca" << endl;
    //x arreglar prints!!!1
    cout << " 2. Buscar material en la biblioteca" << endl;
    //x
    cout << " 3. Mostrar informacion materiales" << endl;
    //x
    cout << " 4. Agregar Usuario" << endl;
    //x
    cout << " 5. Eliminar Usuario" << endl;
    //x
    cout << " 6. Buscar Usuario" << endl;
    //x
    cout << " 7. Prestar material" << endl;
    //?
    cout << " 8. Devolver material" << endl;
    //x
    cout << " 9. Salir" << endl;

    cout << " Ingrese opcion" << endl;
    cout << ">> ";
    while (!(cin >> opcion)) { // Verifica si la entrada es válida
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la línea
            cout << "Entrada no válida. Por favor ingrese un número entre 1 y 9." << endl;
            cout << ">> ";
        }
    cin.ignore();
    switch (opcion)
    {
        case 1:{
            string nombre, autor,isbn,opcionTipo;
            cout<<"¿Revista o Libro? (R/L)"<<endl;
            getline(cin,opcionTipo);
            while(opcionTipo.size() != 1 || (toupper(opcionTipo[0])) !='R' && (toupper(opcionTipo[0]))!='L'){
                cout<<"Ingrese opción correcta (R/L)"<<endl;
                getline(cin,opcionTipo);
            }
            char tipo;
            tipo = toupper(opcionTipo[0]);
            if(tipo=='R'){
                string numeroEdicion,mesPublicacion;
                cout<<"Ingrese titulo:"<<endl;
                getline(cin,nombre);
                cout<<"Ingrese autor:"<<endl;
                getline(cin,autor);
                cout<<"Ingrese Isbn:"<<endl;
                getline(cin,isbn);
                cout<<"Ingrese numero de edicion:"<<endl;
                getline(cin,numeroEdicion);
                cout<<"Ingrese mes de publicacion:"<<endl;
                getline(cin,mesPublicacion);
                sistemaBiblioteca->agregarMaterialRevista(nombre,autor,isbn,numeroEdicion,mesPublicacion);
            }
            else if (tipo=='L'){
                string fechaPublicacion, resumen;
                cout<<"Ingrese titulo:"<<endl;
                getline(cin,nombre);                                  
                cout<<"Ingrese autor:"<<endl;
                getline(cin,autor);
                cout<<"Ingrese Isbn:"<<endl;
                getline(cin,isbn);
                cout<<"Ingrese Fecha de publicación:"<<endl;
                getline(cin,fechaPublicacion);
                cout<<"Ingrese resumen:"<<endl;
                getline(cin,resumen);
                sistemaBiblioteca->agregarMaterialLibro(nombre,autor,isbn,fechaPublicacion,resumen);
            }
            
            break;
        }


        case 2:{
        string texto,opcionBusqueda;
         bool listaMateriales = sistemaBiblioteca->listaMaterial();
            if(listaMateriales==false){
                cout<<"**********************************"<<endl;
                cout<<"* No hay materiales disponibles! *"<<endl;
                cout<<"**********************************"<<endl;
                break;
            }
        cout<<"Ingrese busqueda por autor o titulo del material (A/T)"<<endl;
        getline(cin,opcionBusqueda);
        while(opcionBusqueda.size() != 1 || (toupper(opcionBusqueda[0])) !='A' && (toupper(opcionBusqueda[0]))!='T'){
                
                cout<<"Ingrese opción correcta (A/T)"<<endl;
                getline(cin,opcionBusqueda);
            }
        char opcion = toupper(opcionBusqueda[0]);
         if(opcion=='T'){
            
            string titulo;
            cout<<"Ingrese titulo del material a buscar"<<endl;
            getline(cin,titulo);
            texto = sistemaBiblioteca->buscarMaterialTitulo(titulo);
            cout<<texto<<endl;
         }else if(opcion =='A'){
            
            string autor;
            cout<<"Ingrese autor del material a buscar"<<endl;
            getline(cin,autor);
            texto = sistemaBiblioteca->buscarMaterialAutor(autor);
            cout<<texto<<endl;

        }
            break;
        }
        case 3:{
            string texto;
            texto = sistemaBiblioteca->mostrarInformacionMateriales();
            cout<<texto<<endl;
            break;
        }

        case 4:{   
            string nombre,id;
            cout<<"Ingrese nombre del usuario:"<<endl;
            getline(cin,nombre);
            cout<<"Ingrese id del usuario:"<<endl;
            getline(cin,id);
            sistemaBiblioteca->agregarUsuario(nombre,id);
            break;
        }

        case 5:{
            string id;
            bool listaUsuario = sistemaBiblioteca->listaUsuario();
            if(listaUsuario==false){
                cout<<"**********************************"<<endl;
                cout<<"*  No hay usuarios registrados!  *"<<endl;
                cout<<"**********************************"<<endl;
                break;
            }
            cout<<"Ingrese id del usuario a eliminar:"<<endl;
            getline(cin,id);
            sistemaBiblioteca->eliminarUsuario(id);
            break;
        }
        case 6:{
             string id;
            bool listaUsuario = sistemaBiblioteca->listaUsuario();
            if(listaUsuario==false){
                cout<<"**********************************"<<endl;
                cout<<"*  No hay usuarios registrados!  *"<<endl;
                cout<<"**********************************"<<endl;
                break;
            }
            cout<<"Ingrese id del usuario a buscar:"<<endl;
            getline(cin,id);
            cout<<sistemaBiblioteca->buscarUsuario(id)<<endl;
            break;
        }

        case 7:{
            string id,isbn, texto;
            texto = sistemaBiblioteca->mostrarMaterialesDisponibles();
            if(texto == ""){
                cout<<"**********************************"<<endl;
                cout<<"* No hay materiales disponibles! *"<<endl;
                cout<<"**********************************"<<endl;
                break;
            }
            cout<<"--------------------------------------\n Materiales bibliograficos disponibles: "<<endl;
            cout<<texto;
            bool listaUsuario = sistemaBiblioteca->listaUsuario();
            if(listaUsuario==false){
                cout<<"**********************************"<<endl;
                cout<<"*  No hay usuarios registrados!  *"<<endl;
                cout<<"**********************************"<<endl;
                break;
            }
            cout<<"Ingrese id del usuario:"<<endl;
            getline(cin,id);
            while(sistemaBiblioteca->verificarId(id)){
                cout<<"El id ingresado no existe, por favor ingrese otro id:"<<endl;
                getline(cin,id);
            }
            cout<<"Ingrese isbn del material a prestar:"<<endl;
            getline(cin,isbn);
             while(sistemaBiblioteca->verificarIsbn(isbn)){
                cout<<"El isbn ingresado no existe, por favor ingrese otro isbn:"<<endl;
                getline(cin,isbn);
            }
            string prestamo = sistemaBiblioteca->prestarMaterial(id,isbn);
            cout<<prestamo<<endl;
            break;
        }
       

        case 8:{
            string id,isbn, texto, devolucion;

            devolucion = sistemaBiblioteca->mostrarMaterialesDisponibles();
            if(devolucion != ""){
                cout<<"**********************************"<<endl;
                cout<<"* No hay materiales disponibles! *"<<endl;
                cout<<"**********************************"<<endl;
                break;
            }
            bool listaUsuario = sistemaBiblioteca->listaUsuario();
            if(listaUsuario==false){
                cout<<"**********************************"<<endl;
                cout<<"*  No hay usuarios registrados!  *"<<endl;
                cout<<"**********************************"<<endl;
                break;
            }
            cout<<"Ingrese id del usuario:"<<endl;
            getline(cin,id);
            while(sistemaBiblioteca->verificarId(id)){
                cout<<"El id ingresado no existe, por favor ingrese otro id:"<<endl;
                getline(cin,id);
            }
            bool listaMateriales = sistemaBiblioteca->listaMaterial();
            if(listaMateriales==false){
                cout<<"**********************************"<<endl;
                cout<<"* No hay materiales disponibles! *"<<endl;
                cout<<"**********************************"<<endl;
                break;
            }

            cout<<"Ingrese isbn del material a devolver:"<<endl;
            getline(cin,isbn);
             while(sistemaBiblioteca->verificarIsbn(isbn)){
                cout<<"El isbn ingresado no existe, por favor ingrese otro isbn:"<<endl;
                getline(cin,isbn);
            }
            string devolver = sistemaBiblioteca->devolverMaterial(id,isbn);
            cout<<devolver<<endl;
            break;
        }
        
        case 9:
            cout<<"Adios"<<endl;
            break;
        default:
            cout << " Opcion invalida" << endl;
            break;
        
    }
} while (opcion != 9);


}
