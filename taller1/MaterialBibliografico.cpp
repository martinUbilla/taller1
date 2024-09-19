#include "materialBibliografico.h"
#include <iostream>

    MaterialBibliografico::MaterialBibliografico(std::string nombre,std::string autor,std::string isbn){
        this->nombre = nombre;
        this->isbn = isbn;
        this->autor = autor;
        this->prestado = false;
    }
    void MaterialBibliografico::setPrestado(bool prestado){
        this->prestado = prestado;
    }
    bool MaterialBibliografico::getPrestado(){
        return this->prestado;
    }
    std::string MaterialBibliografico::getNombre(){
        return this->nombre;
    }
    std::string MaterialBibliografico::getAutor(){
        return this->autor;
    }
    std::string MaterialBibliografico::mostrarInformacion(){
    }
    MaterialBibliografico::~MaterialBibliografico(){
        std::cout<<"se ha eliminado el objeto MaterialBibligrafico"<<std::endl;
    }
;


 