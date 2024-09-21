
#include "Libro.h"
#include <iostream>


    Libro::Libro(std::string nombre, std::string autor, std::string isbn, std::string fechaPublicacion, std::string resumen)
    : MaterialBibliografico(nombre,autor,isbn),
    nombre(nombre), isbn(isbn),autor(autor),
     fechaPublicacion(fechaPublicacion), resumen(resumen){
        this->idUsuario = "S/U";
        this->prestado = false;
     }
    void  Libro::setIdUsuario(std::string id){
        this->idUsuario = id;
    }
    std::string Libro::getIdUsuario(){
        return this->idUsuario;
    }

    std::string Libro::getAutor(){
        return this->autor;
    }
    std::string Libro::getIsbn(){
        return this->isbn;
    }
    std::string Libro::getNombre(){
        return this->nombre;
    }
    std::string Libro::getFechaPublicacion(){
        return this->fechaPublicacion;
    }
    std::string Libro::getResumen(){
        return this->resumen;
    }
    void Libro::setPrestado(bool prestado){
        this->prestado = prestado;
    }
    bool Libro::getPrestado(){
        return this->prestado;
    }
    std::string Libro::mostrarInformacion(){
        return  "Titulo: " + this->nombre + "\nAutor: " + this->autor+"\nIsbn: "+this->isbn + this->autor +"\nFechaPublicacion: "+this->fechaPublicacion
        +"\nResumen: "+this->resumen + "\n";
    }
    Libro::~Libro(){
    }