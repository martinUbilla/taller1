#pragma once
#include <iostream>
#include "MaterialBibliografico.h"
const int MAX_MATERIALES = 5;
class Usuario{
    private:
    std::string nombre, id;
    MaterialBibliografico* materialesPrestados[MAX_MATERIALES] = {nullptr};
    public:
    Usuario(std::string nombre, std::string id);
    std::string  getNombre();
    std::string  getId();
    bool prestarMaterial(MaterialBibliografico* material);
    bool devolverMaterial(MaterialBibliografico* material);
    std::string imprimirLista();
    void eliminarMaterialLista();
    void mostrarMaterialesPrestados();
    ~Usuario();
};