#include "main.h"
#include "Biblioteca.h"
#include <iostream>
#include <limits>
#include <cctype>
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

    cout << " 7. Prestar material" << endl;

    cout << " 8. Devolver material" << endl;

    cout << " 9. Salir" << endl;

    cout << " Ingrese opcion" << endl;
    cin>> opcion;
    cin.ignore();
    switch (opcion)
    {
        case 1:{
            char tipo;
            string nombre, autor,isbn;
            cout<<"¿Revista o Libro? (R/L)"<<endl;
            cin>>tipo;
            tipo = toupper(tipo);
            while(tipo!='R' && tipo!='L'){
                cout<<"Ingrese opción correcta (R/L)"<<endl;
                cin>>tipo;
            }
            if(tipo=='R'){
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
            else if (tipo=='L'){
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
            
            break;
        }


        case 2:{
        char opcion;
        string texto;
        cout<<"Ingrese busqueda por autor o titulo del material (A/T)"<<endl;
        cin>>opcion;
        opcion = toupper(opcion);
        while(opcion!='A' && opcion!='T'){
                cout<<"Ingrese opción correcta (A/T)"<<endl;
                cin>>opcion;
            }
         if(opcion=='T'){
            string titulo;
            cout<<"Ingrese titulo del material a buscar"<<endl;
            cin>>titulo;
            texto = sistemaBiblioteca->buscarMaterialTitulo(titulo);
            cout<<texto<<endl;
         }else if(opcion =='A'){
            string autor;
            cout<<"Ingrese autor del material a buscar"<<endl;
            cin>>autor;
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
            cin>>nombre;
            cout<<"Ingrese id del usuario:"<<endl;
            cin>>id;
            sistemaBiblioteca->agregarUsuario(nombre,id);
            break;
        }

        case 5:{
            string id;
            cout<<"Ingrese id del usuario a eliminar:"<<endl;
            cin>>id;
            sistemaBiblioteca->eliminarUsuario(id);
            break;
        }
        case 6:{
             string id;
            cout<<"Ingrese id del usuario a buscar:"<<endl;
            cin>>id;
            cout<<sistemaBiblioteca->buscarUsuario(id)<<endl;
            break;
        }

        case 7:{
            string id,isbn, texto;
            texto = sistemaBiblioteca->mostrarMaterialesDisponibles();
            if(texto == ""){
                cout<<"No hay materiales disponibles!"<<endl;
                break;
            }
            cout<<texto;
            cout<<"Ingrese id del usuario:"<<endl;
            cin>>id;
            while(sistemaBiblioteca->verificarId(id)){
                cout<<"El id ingresado no existe, por favor ingrese otro id:"<<endl;
                cin>>id;
            }
            cout<<"Ingrese isbn del material a prestar:"<<endl;
            cin>>isbn;
             while(sistemaBiblioteca->verificarIsbn(isbn)){
                cout<<"El isbn ingresado no existe, por favor ingrese otro isbn:"<<endl;
                cin>>isbn;
            }
            string prestamo = sistemaBiblioteca->prestarMaterial(id,isbn);
            cout<<prestamo<<endl;
            break;
        }
       

        case 8:
        
          
            break;
        case 9:
        
          
            break;
        default:
            cout << " Opcion invalida" << endl;
            break;
        
    }
} while (opcion != 9);


}