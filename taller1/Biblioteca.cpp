#include "Biblioteca.h"
#include <iostream>

 Biblioteca::Biblioteca(){};
    void Biblioteca::agregarUsuario(std::string nombre, std::string id){};

    void Biblioteca::agregarMaterialRevista(std::string nombre, std::string autor, std::string isbn,
    std::string numeroEdicion, std::string mesPublicacion){
      Revista* revista = new  Revista(nombre, autor, isbn, numeroEdicion, mesPublicacion);
      verificarIsbn(isbn);
      for (int i = 0; i < sizeof(this -> listaMateriales); i++)
      {  if(this -> listaMateriales[i] == nullptr){
         this -> listaMateriales[i] = revista;
         break;
         }
      }
      std::cout<<"La lista está llena!"<<std::endl;  
      

    };

    void  Biblioteca::agregarMaterialLibro(std::string nombre, std::string autor, std::string isbn,
     std::string fechaPublicacion, std::string resumen){
      Libro* libro = new Libro(nombre, autor, isbn, fechaPublicacion, resumen);
      for (int i = 0; i < sizeof(this -> listaMateriales); i++)
      {  if(this -> listaMateriales[i] == nullptr){
         this -> listaMateriales[i] = libro;
         break;
         }
      }
      std::cout<<"La lista esta llena!"<<std::endl;
     };

    void  Biblioteca::eliminarUsuario(std::string , std::string id){};

    void  Biblioteca::eliminarMaterial(){};

    std::string  Biblioteca::buscarMaterial(){};

    std::string  Biblioteca::buscarUsuario(std::string , std::string id){};
    
    Biblioteca::~Biblioteca(){};