#pragma once
#include <iostream>
#include "MaterialBibliografico.h"
const int MAX_MATERIALES = 5;
class Usuario{
    private:
    std::string nombre, id;
    MaterialBibliografico* materialesPrestados[MAX_MATERIALES] = {nullptr};
    public:
    //Constructor de la clase Usuario
    Usuario(std::string nombre, std::string id);
    //Getter del atributo nombre de la clase Usuario en el cual retorna un string 
    //con dicho atributo
    std::string  getNombre();
    //Getter del atributo id de la clase Usuario en el cual retorna un string
    //con dicho atributo
    std::string  getId();   
    //Presta el material bibliografico correspondiente en caso de ser posible
    bool prestarMaterial(MaterialBibliografico* material);
    //Devuelve el material bibliografico correspondiente en caso de ser posible
    bool devolverMaterial(MaterialBibliografico* material);
    //Retorna la lista de los materiales prestados
    std::string imprimirLista();
    //Elimina el material de la lista de materialesPrestados
    void eliminarMaterialLista();
    ~Usuario();
};