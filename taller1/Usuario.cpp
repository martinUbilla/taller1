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
bool Usuario::devolverMaterial(MaterialBibliografico* material){
     for (int i = 0; i < MAX_MATERIALES; i++){  
        if(materialesPrestados[i] == material && materialesPrestados[i]!=nullptr){
            material->setPrestado(false);
            material->setIdUsuario("S/U");
            materialesPrestados[i] = nullptr;
            return true;
        } 
    }
            return false;
}

bool Usuario::prestarMaterial(MaterialBibliografico* material){
    if(material->getPrestado()==true){
        return false;
    }
    for (int i = 0; i < MAX_MATERIALES; i++){
        if(this->materialesPrestados[i] == nullptr ){
            materialesPrestados[i] = material;
            material->setPrestado(true);    
            material->setIdUsuario(this->id);
            return true;
        }
    }
    return false;
}
    void Usuario::eliminarMaterialLista(){
        for (int i = 0; i < MAX_MATERIALES; i++){
        if(this->materialesPrestados[i] != nullptr ){
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
