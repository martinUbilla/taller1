#include "Usuario.h"
#include <iostream>

Usuario::Usuario(std::string nombre, std::string id){
    this -> nombre = nombre;
    this -> id = id;

}
std::string Usuario::getId(){
    return this->id;
}
std::string Usuario::getNombre(){
    return this->nombre;
}
void Usuario::devolverMaterial(MaterialBibliografico* material){}
void Usuario::mostrarMaterialesPrestados(){
    for (int i = 0; i <MAX_MATERIALES; i++){
        if(materialesPrestados[i] != nullptr)
        std::cout << "Material " << i << ": " << materialesPrestados[i]->getNombre()<<std::endl;
    }
}
std::string Usuario::prestarMaterial(MaterialBibliografico* material){
    for (int i = 0; i < MAX_MATERIALES; i++){  
        if(materialesPrestados[i] == nullptr){
            materialesPrestados[i] = material;
            return "Material prestado con exito";

        } else if (materialesPrestados[i] == material){
            return "Este material ya fue prestado a este usuario" ;
            
        } 
    }
            return "No hay espacio disponible para prestar el material";
}
    void Usuario::eliminarMaterialLista(){
        for (int i = 0; i < MAX_MATERIALES; i++){
        if(this->materialesPrestados[i]!=nullptr ){
            this->materialesPrestados[i]->setPrestado(false);
            materialesPrestados[i] = nullptr;
        }
        }
    }
    std::string Usuario::imprimirLista(){
        std::string texto = "";
        for (int i = 0; i < MAX_MATERIALES; i++){
        if(this->materialesPrestados[i]!=nullptr ){
            texto +=  this->materialesPrestados[i]->getNombre() + "\n";
        }
        }
        if(texto==""){
            return texto = "No hay materiales prestados";
        }
         return texto = "Materiales prestados:\n" + texto;
        
    }
  Usuario::~Usuario(){
  }
;
