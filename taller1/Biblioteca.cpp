#include "Biblioteca.h"
#include <iostream>

 Biblioteca::Biblioteca(){};
    void Biblioteca::agregarUsuario(std::string nombre, std::string id){
      bool existe = verificarId(id);
      if(existe == false){
         std::cout<<"El usuario con el id " + id + " ya existe"<<std::endl;
         return;
      }
      Usuario* usuario = new Usuario(nombre,id);
      for (int i = 0; i < MAX_USUARIOS; i++){  
         if(this -> listaUsuarios[i] == nullptr){
            this -> listaUsuarios[i] = usuario;
            return;
         }
      }
      delete usuario;
      std::cout << "No hay espacio disponible para agregar un nuevo usuario" << std::endl;
    };
   bool Biblioteca::verificarId(std::string id){
      for(int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaUsuarios[i] != nullptr && this->listaUsuarios[i]->getId() == id){
               return false;
         }
      }
      return true;
   };
   bool Biblioteca::verificarIsbn(std::string isbn){  
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this -> listaMateriales[i] != nullptr){
            if(this -> listaMateriales[i]->getIsbn() ==  isbn){
               return false;
            }
         }
      }
      return true;
   };
    void Biblioteca::agregarMaterialRevista(std::string nombre, std::string autor, std::string isbn,
    std::string numeroEdicion, std::string mesPublicacion){
      bool verificacion = verificarIsbn(isbn);
      if(verificacion == false){
         std::cout << "El material con el isbn " << isbn << " ya existe en la Biblioteca"<<std::endl;
         return;
      }
      Revista* revista = new Revista(nombre, autor, isbn, numeroEdicion, mesPublicacion);

      for (int i = 0; i < MAX_USUARIOS; i++){  
         if(this -> listaMateriales[i] == nullptr){
            this -> listaMateriales[i] = revista;
            return;
         }
      }
      delete revista;
      std::cout<<"La lista está llena!"<<std::endl;  
      
    };

    void  Biblioteca::agregarMaterialLibro(std::string nombre, std::string autor, std::string isbn,
     std::string fechaPublicacion, std::string resumen){
      bool verificacion = verificarIsbn(isbn);
      if(verificacion == false){
         std::cout << "El material con el isbn " << isbn << " ya existe en la Biblioteca"<<std::endl;
         return;
      }
      Libro* libro = new Libro(nombre, autor, isbn, fechaPublicacion, resumen);
      for (int i = 0; i < MAX_USUARIOS; i++)
      {  if(this -> listaMateriales[i] == nullptr){
         this -> listaMateriales[i] = libro;
         return;
         }
      }
      delete libro;
      std::cout<<"La lista esta llena!"<<std::endl;
     };

    void  Biblioteca::eliminarUsuario(std::string id){
      bool existe = verificarId(id);
      if(existe == false){
         return;
      } 
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaUsuarios[i] != nullptr &&  this->listaUsuarios[i]->getId() == id){
            this->listaUsuarios[i]->eliminarMaterialLista();
            delete this->listaUsuarios[i];
            this->listaUsuarios[i] = nullptr;
         }
      }
    };

    void Biblioteca::eliminarMaterial(std::string isbn){
      MaterialBibliografico* materialActual = material(isbn);
      if(materialActual != nullptr && materialActual->getPrestado()!=false){
         Usuario* usuarioActual = usuario(materialActual->getIdUsuario());
         delete materialActual;
      }
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i]!=nullptr && this->listaMateriales[i]->getIsbn()==isbn){
            std::cout<<"Se ha eliminado el material " + this->listaMateriales[i]->getNombre()<<std::endl;
            delete this->listaMateriales[i];
            this->listaMateriales[i] = nullptr;
            return;
         }
      }
      std::cout<<"No se ha encontrado el material!"<<std::endl;
    };

    std::string  Biblioteca::buscarMaterialTitulo(std::string nombre){
         std::string texto = "";
       for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i]!=nullptr && this->listaMateriales[i]->getNombre()==nombre){
            texto +=  this->listaMateriales[i]->mostrarInformacion();
         }
      }
      if(texto == ""){
         return "No se ha encontrado el material!";
         }
      else{
         return texto;
      }
    };
    std::string Biblioteca::buscarMaterialAutor(std::string autor){
      std::string texto = "";
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i]!=nullptr && this->listaMateriales[i]->getAutor()==autor){
            texto +=  this->listaMateriales[i]->mostrarInformacion();
         }
      }
      if(texto == ""){
         return "No se ha encontrado el material!";
         }
      else{
         return texto;
      }
    }

   MaterialBibliografico* Biblioteca::material(std::string isbn){
       for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i]!=nullptr && this->listaMateriales[i]->getIsbn()==isbn){
            return listaMateriales[i];
         }
      }
      return nullptr;
   }
   Usuario* Biblioteca::usuario(std::string id){
       for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaUsuarios[i]!=nullptr && this->listaUsuarios[i]->getId()==id){
            return listaUsuarios[i];
         }
      }
      return nullptr;
   }

    std::string Biblioteca::buscarUsuario( std::string id){
      std::string texto;
      bool existe = verificarId(id);
      if(existe == true){
         return "El usuario con el id " + id + " no existe";
      }
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaUsuarios[i] != nullptr && this->listaUsuarios[i]->getId()==id){
           texto += this->listaUsuarios[i]->getNombre()+ "\n";
            texto += this->listaUsuarios[i]->imprimirLista();
         }
      }
      return texto;


    };
    std::string Biblioteca::mostrarInformacionMateriales(){
      std::string texto = "";
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i]!=nullptr){
            texto += listaMateriales[i]->mostrarInformacion();
         }
      }
      if(texto == ""){
         return "No hay materiales!";
         }
      else{
         return texto;
      }

    }
    std::string Biblioteca::mostrarMaterialesDisponibles(){
      std::string texto = "";
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i] != nullptr && this->listaMateriales[i]->getPrestado() == false){
            texto += listaMateriales[i]->getNombre()+ " / " + listaMateriales[i]->getIsbn()+ "\n";
         }
      }
      if(texto == ""){
         return texto;
      }
      return texto;
    }
    std::string Biblioteca::prestarMaterial(std::string id , std::string isbn){
      std::string texto = "";
         for (int i = 0; i < MAX_USUARIOS; i++){
            if(this->listaUsuarios[i] != nullptr && this->listaUsuarios[i]->getId() == id){
               for(int j = 0; j < MAX_USUARIOS; j++){
                  if(this->listaMateriales[j] != nullptr && this->listaMateriales[j]->getIsbn() == isbn){
                     if(this->listaMateriales[j]->getPrestado() == false){
                        this->listaMateriales[j]->setPrestado(true);
                        texto = this->listaUsuarios[i]->prestarMaterial(this->listaMateriales[j]);
                        return texto;
                     }

                  }
               }
            }
         }
        /* MaterialBibliografico* materialActual = material(isbn);
         if(materialActual->getPrestado()==true){
            texto = "El material con el isbn " + isbn + " ya está prestado"; 
            return texto;
         }
         Usuario* usuarioActual = usuario(id);
         texto = usuarioActual->prestarMaterial(materialActual);
         return texto;
         */
    }
    Biblioteca::~Biblioteca(){};