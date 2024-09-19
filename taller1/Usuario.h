#pragma once
#include <iostream>
#include "MaterialBibliografico.h"
class Usuario{
    private:
    std::string nombre, id;
    MaterialBibliografico* materialesPrestados[5];
    public:
    Usuario(std::string nombre, std::string id);
    void prestarMaterial(MaterialBibliografico* material);
    void devolverMaterial(MaterialBibliografico* material);
    void mostrarMaterialesPrestados();
    ~Usuario();
};