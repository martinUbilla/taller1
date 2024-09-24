#include "MaterialBibliografico.h"
#include <iostream>

    MaterialBibliografico::MaterialBibliografico(std::string nombre,std::string autor,std::string isbn){
        this->nombre = nombre;
        this->isbn = isbn;
        this->autor = autor;
        this->idUsuario = "S/U";
        this->prestado = false;
    }
    void  MaterialBibliografico::setIdUsuario(std::string idUsuario){
        this->idUsuario = idUsuario;
    }
    std::string MaterialBibliografico::getIdUsuario(){
        return this->idUsuario;
    }
    void MaterialBibliografico::setPrestado(bool estado){
        this->prestado = estado;
    }
    std::string  MaterialBibliografico::getIsbn(){
        return this->isbn;
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
        // cout de las variables de la clase padre.
        std::string estado;
        if(getPrestado()==true){
        estado="Prestado";
    }else{
        estado="Disponible";
    }
        return  "--------------------------------------\nTitulo: " + nombre + "\nAutor: " + autor + "\nISBN: "+  isbn+"\nEstado: " + estado;
    }
    MaterialBibliografico::~MaterialBibliografico(){
    };



 