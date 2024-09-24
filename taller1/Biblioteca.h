#pragma once
#include "Usuario.h"
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include <iostream>

const int MAX_USUARIOS = 100;
class Biblioteca{
    private:
    Usuario* listaUsuarios[MAX_USUARIOS] = {nullptr};
    MaterialBibliografico* listaMateriales[MAX_USUARIOS] = {nullptr};
    MaterialBibliografico* material(std::string isbn);
    Usuario* usuario(std::string id);
    public:
    Biblioteca();
    bool verificarIsbn(std::string isbn);
    bool verificarId(std::string id);
    void agregarUsuario(std::string nombre, std::string id);

    void agregarMaterialRevista(std::string nombre, std::string autor, std::string isbn,
    std::string numeroEdicion, std::string mesPublicacion, std::string idUsuario);

    void agregarMaterialLibro(std::string nombre, std::string autor, std::string isbn,
     std::string fechaPublicacion, std::string resumen,std::string idUsuario);

    void eliminarUsuario(std::string id);

    void eliminarMaterial(std::string isbn);

    std::string buscarMaterialTitulo(std::string nombre);
    std::string  buscarMaterialAutor(std::string autor);
    std::string mostrarInformacionMateriales();

    std::string buscarUsuario( std::string id);
    std::string mostrarMaterialesDisponibles();
    std::string prestarMaterial(std::string id, std::string isbn);
    std::string devolverMaterial(std::string  id, std::string isbn);
    bool listaUsuario();
    bool listaMaterial();
    bool materialesParaDevolver();
    ~Biblioteca();
};
