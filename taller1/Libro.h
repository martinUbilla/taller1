#pragma once
#include "MaterialBibliografico.h"
#include <iostream>
class Libro  : public MaterialBibliografico {
    private:
    std::string nombre, isbn, autor,fechaPublicacion,resumen,idUsuario ;
    bool prestado;
    public:
    Libro(std::string nombre, std::string autor, std::string isbn, std::string fechaPublicacion, std::string resumen);
    std::string getAutor();
    std::string getIsbn();
    std::string getNombre();
    std::string getFechaPublicacion();
    std::string getResumen();
    void setPrestado(bool estado);
    bool getPrestado();
    void setIdUsuario(std::string id);
    std::string getIdUsuario();
    std::string mostrarInformacion() override;
    ~Libro();


};