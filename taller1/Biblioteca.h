#pragma once
#include "MaterialBibliografico.h"
#include "Usuario.h"
#include "Libro.h"
#include "Revista.h"
#include <iostream>

class Biblioteca{
    private:
    Usuario* listaUsuarios[100];
    MaterialBibliografico* listaMateriales[100];
    public:
    Biblioteca();
    void agregarUsuario(std::string nombre, std::string id);

    void agregarMaterialRevista(std::string nombre, std::string autor, std::string isbn,
    std::string numeroEdicion, std::string mesPublicacion);

    void agregarMaterialLibro(std::string nombre, std::string autor, std::string isbn,
     std::string fechaPublicacion, std::string resumen);

    void eliminarUsuario(std::string , std::string id);

    void eliminarMaterial();

    std::string buscarMaterial();

    std::string buscarUsuario(std::string , std::string id);
    
    ~Biblioteca();
};
