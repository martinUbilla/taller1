#include "Biblioteca.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

 Biblioteca::Biblioteca(){
    std::ifstream txtUsuarios("Usuarios.txt");
    if (!txtUsuarios.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
      
    }
   //Usuario formato : id, nombre
    std::string linea;
    while (std::getline(txtUsuarios, linea)) {
         std::istringstream iss(linea);
      std::vector<std::string> partes;
    for (std::string parte; std::getline(iss, parte, ';'); ) {
        partes.push_back(parte);
    }
        std::string id, nombre;
        id = partes[0];
        nombre = partes[1];
        agregarUsuario(nombre,id);
}

    txtUsuarios.close();
   std::ifstream txtMateriales("Materiales.txt");
    if (!txtMateriales.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
      
    }
   //material formato : tipo(L), nombre, autor, isbn, fechaPublicacion, resumen, idUsuario
   //material formato : tipo(R), nombre, autor, isbn, numeroEdicion , mesPublicacion, idUsuario
    std::string lineaMateriales;
    while (std::getline(txtMateriales, lineaMateriales)) {
         std::istringstream iss(lineaMateriales);
      std::vector<std::string> partes;
    for (std::string parte; std::getline(iss, parte, ';'); ) {
        partes.push_back(parte);
    }
        std::string tipo, nombre, autor, isbn, idUsuario;
        tipo = partes[0];
        nombre = partes[1];
        autor = partes[2];
        isbn = partes[3];
        idUsuario = partes[6];
         if(tipo=="L"){
            std::string fechaPublicacion = partes[4];
            std::string resumen = partes[5];
            agregarMaterialLibro(nombre, autor, isbn, fechaPublicacion, resumen,idUsuario);
         }else if(tipo=="R"){
            std::string numeroEdicion = partes[4];
            std::string mesPublicacion = partes[5];
            agregarMaterialRevista(nombre, autor, isbn, numeroEdicion, mesPublicacion,idUsuario);
         }
}

    txtMateriales.close();
    
    
 };
    void Biblioteca::agregarUsuario(std::string nombre, std::string id){
      bool existe = verificarId(id);
      if(existe == false){
         std::cout<<">> El usuario con el id '" + id + "' ya existe <<"<<std::endl;
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
      std::cout << ">> No hay espacio disponible para agregar un nuevo usuario <<" << std::endl;
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
    std::string numeroEdicion, std::string mesPublicacion,std::string idUsuario){
      bool verificacion = verificarIsbn(isbn);
      if(verificacion == false){
         std::cout << ">> El material con el isbn '" << isbn << "' ya existe en la Biblioteca <<"<<std::endl;
         return;
      }
      Revista* revista = new Revista(nombre, autor, isbn, numeroEdicion, mesPublicacion);

      for (int i = 0; i < MAX_USUARIOS; i++){  
         if(this -> listaMateriales[i] == nullptr){
            this -> listaMateriales[i] = revista;
         if(idUsuario!="S/U"){
            prestarMaterial(idUsuario, isbn);
         }
            return;
         }
      }
      delete revista;
      std::cout<<">> La lista está llena! <<"<<std::endl;  
      
    };

    void  Biblioteca::agregarMaterialLibro(std::string nombre, std::string autor, std::string isbn,
     std::string fechaPublicacion, std::string resumen,std::string  idUsuario){

      bool verificacion = verificarIsbn(isbn);
      if(verificacion == false){
         std::cout << ">> El material con el isbn '" << isbn << "' ya existe en la Biblioteca <<"<<std::endl;
         return;
      }
      Libro* libro = new Libro(nombre, autor, isbn, fechaPublicacion, resumen);
      for (int i = 0; i < MAX_USUARIOS; i++)
      {  if(this -> listaMateriales[i] == nullptr){
         this -> listaMateriales[i] = libro;
         if(idUsuario!="S/U"){
            prestarMaterial(idUsuario, isbn);
         }
         return;
         }
      }
      delete libro;
      std::cout<<">> La lista esta llena! <<"<<std::endl;
     };

    void  Biblioteca::eliminarUsuario(std::string id){
      bool existe = verificarId(id);
      if(existe == true){
         std::cout<<" No se ha encontrado el usuario!";
         return;
      } 
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaUsuarios[i] != nullptr &&  this->listaUsuarios[i]->getId() == id){
            this->listaUsuarios[i]->eliminarMaterialLista();
            delete this->listaUsuarios[i];
            this->listaUsuarios[i] = nullptr;
            return;
         }
      }
    };

    std::string  Biblioteca::buscarMaterialTitulo(std::string nombre){
         std::string texto = "";
       for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i]!=nullptr && this->listaMateriales[i]->getNombre()==nombre){
            texto +=  this->listaMateriales[i]->mostrarInformacion();
         }
      }
      if(texto == ""){
         return ">> No se ha encontrado el material! <<";
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
         return ">> No se ha encontrado el material! <<";
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
      texto += "Nombre: ";
      if(existe == true){
         return ">> El usuario con el id '" + id + "' no existe <<";
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
         return "********************\n*No hay materiales!*\n********************";
         }
      else{
         return "Informacion de Materiales: \n"+texto;
      }

    }
    std::string Biblioteca::mostrarMaterialesDisponibles(){
      std::string texto = "";
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i] != nullptr && this->listaMateriales[i]->getPrestado() == false){
            texto += "-Nombre: " + listaMateriales[i]->getNombre()+ " / Isbn: " + listaMateriales[i]->getIsbn()+ "\n";
         }
      }
      if(texto == ""){
         return texto;
      }
      return texto;
    }
    std::string Biblioteca::prestarMaterial(std::string id , std::string isbn){
      std::string texto;
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaUsuarios[i] != nullptr &&  this->listaUsuarios[i]->getId()==id){
            for (int j = 0; j < MAX_USUARIOS; j++){  
               if(this->listaMateriales[j]!=nullptr && this->listaMateriales[j]->getIsbn()==isbn){
                    bool prestamo = listaUsuarios[i]->prestarMaterial(listaMateriales[j]);
                     if(prestamo == true){
                     texto += "Material prestado con exito\n";
                     listaMateriales[j]->setPrestado(true);
                     return texto;

                     }else{
                        texto += "No se pudo prestar el material\n";
                        return texto;
                     }
               
               }
            
            
            }
         }
      }
      return "No se ha podido realizar el prestamo!";
    }
    std::string  Biblioteca::devolverMaterial(std::string id , std::string isbn){
      std::string texto;
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaUsuarios[i] != nullptr &&  this->listaUsuarios[i]->getId()==id){
            for (int j = 0; j < MAX_USUARIOS; j++){  
               if(this->listaMateriales[j]!=nullptr && this->listaMateriales[j]->getIsbn()==isbn){
                    bool prestamo = listaUsuarios[i]->devolverMaterial(listaMateriales[j]);
                     if(prestamo == true){
                     texto += "Material devuelto con exito\n";
                     listaMateriales[j]->setPrestado(false);
                     return texto;

                     }else{
                        texto += "No se pudo devolver el material\n";
                        return texto;
                     }
               
               }
            
            
            }
         }
      }
      return "No se ha podido realizar la devolucion!";

    }

   bool Biblioteca::listaUsuario(){
      int cont = 0;
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaUsuarios[i]!=nullptr){
            cont += 1;
         }
      }
      if(cont>0){
         return true;
      }
      return false;
   }
    bool Biblioteca::listaMaterial(){
      int cont = 0;
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i]!=nullptr){
            cont += 1;
         }
      }
      if(cont>0){
         return true;
      }
      return false;
   }
   bool Biblioteca::materialesParaDevolver(){
      int cont = 0;
      for (int i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i] != nullptr && this->listaMateriales[i]->getPrestado()==true){
            cont += 1; 
         }
      }
      if(cont>0){
         return true;
      }
      return false;

   }
   //guardar en un texto la informacion
    Biblioteca::~Biblioteca(){
   //aqui va el guardar las cosas
   std::ofstream txtUsuarios("Usuarios.txt");
   if(txtUsuarios.is_open()){
      for  (int  i = 0; i < MAX_USUARIOS; i++){
         if(this->listaUsuarios[i] != nullptr){
            txtUsuarios<<this->listaUsuarios[i]->getId()+";"+this->listaUsuarios[i]->getNombre()<<std::endl;
         }
      }
      txtUsuarios.close();
   }else{
      std::cout<<">> No se pudo abrir el archivo <<"<<std::endl;
   }
   std::ofstream txtMateriales("Materiales.txt");
   if(txtMateriales.is_open()){
      for  (int  i = 0; i < MAX_USUARIOS; i++){
         if(this->listaMateriales[i] != nullptr){
         if((dynamic_cast<Libro*>(listaMateriales[i])) == this->listaMateriales[i]){
            txtMateriales<<"L;"+this->listaMateriales[i]->getNombre()+","+this->listaMateriales[i]->getAutor()
            +";"+this->listaMateriales[i]->getIsbn()+";"+(dynamic_cast<Libro*>(listaMateriales[i]))->getFechaPublicacion()+";"+
            (dynamic_cast<Libro*>(listaMateriales[i]))->getResumen()+","+listaMateriales[i]->getIdUsuario()<<std::endl;
         }else if((dynamic_cast<Revista*>(listaMateriales[i])) == this->listaMateriales[i]){
            txtMateriales<<"R;"+this->listaMateriales[i]->getNombre()+";"+this->listaMateriales[i]->getAutor()
            +";"+this->listaMateriales[i]->getIsbn()+";"+(dynamic_cast<Revista*>(listaMateriales[i]))->getNumeroEdicion()+";"+
            (dynamic_cast<Revista*>(listaMateriales[i]))->getMesPublicacion()+";"+listaMateriales[i]->getIdUsuario()<<std::endl;
         }
         }
      }
      txtMateriales.close();
   }else{
      std::cout<<">> No se pudo abrir el archivo <<"<<std::endl;
   }

   //liberacion de memoria
   for  (int  i = 0; i < MAX_USUARIOS; i++){
      if(this->listaMateriales[i] != nullptr){
         delete this->listaMateriales[i];
      }
      if(this->listaUsuarios[i] != nullptr){
         delete this->listaUsuarios[i];
       }
   }
    };