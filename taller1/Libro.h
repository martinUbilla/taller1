#pragma once
#include "MaterialBibliografico.h"
#include <iostream>
class Libro  : public MaterialBibliografico {
    private:
    std::string nombre, isbn, autor,fechaPublicacion,resumen,idUsuario ;
    bool prestado;
    public:
    //Constructor de la clase Libro, ingresan atributos string, como nombre, autor, isbn, 
    //fechaPublicacion, resumen.
    Libro(std::string nombre, std::string autor, std::string isbn, std::string fechaPublicacion, std::string resumen);
    //Getter del atributo autor. No ingresan parámetros y retorna un string con el autor del libro
    std::string getAutor();
    //Getter del atributo isbn. No ingresan parámetros y retorna un string con el isbn del libro
    std::string getIsbn();
    //Getter del atributo nombre. No ingresan parámetros y retorna un string con el nombre del libro
    std::string getNombre();
    //Getter del atributo fechaPublicacion. No ingresan parámetros y retorna un string con la fecha de
    //publicacion del libro
    std::string getFechaPublicacion();
    //Geter del atributo resumen. No ingresan parámetros y retorna un string con un resumen del libro
    std::string getResumen();
    //Setter del atributo idUsuario. Ingresa como parámetro un string el cual cambia el atributo idUsuario y no retorna nada
    void setIdUsuario(std::string id);
    //Getter del atributo idUsuario. No ingresan parámetros y retorna un string con el idUsuario
    std::string getIdUsuario();
    //Método virtual en el que se muestra la informacion de los atributos de la clase libro
    //como la fecha de publicacion y el resumen
    std::string mostrarInformacion() override;
    //Destructor de la clase libro
    ~Libro();


};