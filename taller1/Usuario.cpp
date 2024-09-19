#include "Usuario.h"
#include <iostream>

Usuario::Usuario(std::string nombre, std::string id){
    this -> nombre = nombre;
    this -> id = id;

}
void Usuario::devolverMaterial(MaterialBibliografico* material){}
void Usuario::mostrarMaterialesPrestados(){
    for (int i = 0; i <sizeof(materialesPrestados); i++){
        if(materialesPrestados[i] != nullptr)
        std::cout << "Material " << i << ": " << materialesPrestados[i]->getNombre()<<std::endl;
    }
}
void Usuario::prestarMaterial(MaterialBibliografico* material){
    for (int i = 0; i < sizeof(materialesPrestados); i++)
        {   if(materialesPrestados[i] == nullptr){
            materialesPrestados[i] = material;
            break;
        } else if (materialesPrestados[i] == material){
            std::cout  << "Este material ya fue prestado por este usuario" << std::endl;
            break;
        }
        else {
            std::cout << "No hay espacio disponible para prestar el material" << std::endl;
            break;
        }
    }
}
  Usuario::~Usuario(){

  }
;
