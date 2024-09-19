#pragma once
#include <iostream>

class MaterialBibliografico{
    private:
    std::string nombre;
    std::string isbn;   
    std::string autor;
    bool prestado;
    public:
    MaterialBibliografico(std::string nombre,std::string autor,std::string isbn);
    std::string getNombre();
    std::string getIsbn();
    std::string getAutor();
    bool getPrestado();
    void setPrestado(bool);
    virtual std::string mostrarInformacion();
    ~MaterialBibliografico();
};