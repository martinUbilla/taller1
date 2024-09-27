#pragma once
#include "MaterialBibliografico.h"
#include <iostream>
class Revista : public MaterialBibliografico{
    private:
    std::string nombre, autor, isbn,numeroEdicion, mesPublicacion,idUsuario;
    bool prestado;
    public:
    //Constructor de la clase Revista. Recibe como parámetros string nombre, autor, isbn
    //numeroEdicion, mesPublicacion
    Revista(std::string nombre, std::string autor, std::string isbn, std::string numeroEdicion, std::string mesPublicacion);
    //Getter del atributo nombre. No ingresan parámetros y retorna un string con el nombre de la revista
    std::string getNombre();
    //Getter del atributo autor. No ingresan parámetros y retorna un string con el autor de la revista
    std::string getAutor();
    //Getter del atributo isbn. No ingresan parámetros y retorna un string con el isbn de la revista
    std::string getIsbn();
    //Getter del atributo numeroEdicion. No ingresan parámetros 
    std::string getNumeroEdicion();
    //Getter del atributo mesPublicacion. No ingresan parámetros y retorna un string
    std::string getMesPublicacion();
    //Setter del atributo idUsuario. Ingresa como parámetro un string el cual cambia el atributo idUsuario y no retorna nada
    void setIdUsuario(std::string id);
    //Getter del atributo idUsuario. No ingresan parámetros y retorna un string con el idUsuario
    std::string getIdUsuario();
    //Método virtual en el que se muestra la informacion de los atributos de la clase revista
    //como la fecha de publicacion y el resumen
    std::string mostrarInformacion() override;
    //Destructor de la clase revista
    ~Revista();
};