#pragma once
#include "MaterialBibliografico.h"
#include <iostream>
class Revista : public MaterialBibliografico{
    private:
    std::string nombre, autor, isbn,numeroEdicion, mesPublicacion,idUsuario;
    bool prestado;
    public:
    Revista(std::string nombre, std::string autor, std::string isbn, std::string numeroEdicion, std::string mesPublicacion);
    std::string getNombre();
    std::string getAutor();
    std::string getIsbn();
    std::string getNumeroEdicion();
    std::string getMesPublicacion();
    void setIdUsuario(std::string id);
    std::string getIdUsuario();
    std::string mostrarInformacion() override;

    ~Revista();
};