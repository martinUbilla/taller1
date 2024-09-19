
#include "Libro.h"
#include <iostream>


    Libro::Libro(std::string nombre, std::string autor, std::string isbn, std::string fechaPublicacion, std::string resumen)
    : MaterialBibliografico(nombre,autor,isbn),
    nombre(nombre), isbn(isbn),autor(autor),
     fechaPublicacion(fechaPublicacion), resumen(resumen){}

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
    std::string Libro::mostrarInformacion(){
        return  "Nombre: " + this->nombre + "\nAutor: " + this->autor +"\nFechaPublicacion: "+this->fechaPublicacion
        +"\nResumen: "+this->resumen +"\nIsbn: "+this->isbn;
    }
    Libro::~Libro(){
        std::cout << " Se ha eliminado el objeto Libro" << std::endl;
    }