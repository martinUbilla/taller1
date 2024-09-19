#include "Revista.h"
#include <iostream>

Revista::Revista(std::string nombre, std::string autor, std::string isbn,
 std::string numeroEdicion, std::string mesPublicacion) : MaterialBibliografico (nombre,isbn,autor),
    nombre(nombre), isbn(isbn),autor(autor),
     numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion){}

std::string Revista::getNombre(){
    return this -> nombre;
}
std::string Revista::getAutor(){
    return this ->autor;
}
std::string Revista::getIsbn(){
    return this ->isbn;
}
std::string  Revista::getNumeroEdicion(){
    return this ->numeroEdicion;
}
std::string Revista::getMesPublicacion(){
    return this ->mesPublicacion;
}
std::string Revista::mostrarInformacion(){
    return  "Revista: " + nombre + "\nAutor: " + autor + "\nISBN: "+  isbn + "\nNumero de Edicion: "
     + numeroEdicion + "\nMes de Publicacion" +  mesPublicacion;

}
bool Revista::getPrestado(){
    return this ->prestado;
}
void Revista::setPrestado(bool prestado){
   this -> prestado = true;
}
Revista::~Revista(){}
;