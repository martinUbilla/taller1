#pragma once
#include <iostream>

class MaterialBibliografico{
    private:
    std::string nombre, isbn, autor, idUsuario;
    bool prestado;
    public:
    MaterialBibliografico(std::string nombre,std::string autor,std::string isbn);
    std::string getNombre();
    std::string getIsbn();
    std::string getAutor();
    bool getPrestado();
    void setPrestado(bool prestado) ;
    void setIdUsuario(std::string idUsuario);
    std::string getIdUsuario();
    virtual std::string mostrarInformacion();
    ~MaterialBibliografico();
};