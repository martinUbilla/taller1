#pragma once
#include "MaterialBibliografico.h"
#include <iostream>
class Revista : public MaterialBibliografico{
    private:
    std::string nombre, autor, isbn,numeroEdicion, mesPublicacion;
    bool prestado;
    public:
    Revista(std::string nombre, std::string autor, std::string isbn, std::string numeroEdicion, std::string mesPublicacion);
    std::string getNombre();
    std::string getAutor();
    std::string getIsbn();
    std::string getNumeroEdicion();
    std::string getMesPublicacion();
    std::string mostrarInformacion() override;
    bool getPrestado();
    void setPrestado(bool prestado);
    ~Revista();
};