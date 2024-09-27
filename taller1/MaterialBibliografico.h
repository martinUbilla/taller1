#pragma once
#include <iostream>

class MaterialBibliografico{
    private:
    std::string nombre, isbn, autor, idUsuario;
    bool prestado;
    public:
    //Constructor de la clase MaterialBibliografico
    MaterialBibliografico(std::string nombre,std::string autor,std::string isbn);
    //Getter del atributo nombre, no ingresan parametros y retorna un string con el nombre del material.
    std::string getNombre();
    //Getter del atributo isbn, no ingresan parametros y retorna un string con el isbn del material
    std::string getIsbn();
    //Getter del atributo autor, no ingresan parametros y retorna un string con el autor del material
    std::string getAutor();
    //Getter del atributo bool Prestado, no ingresan parámetros y retorna un bool.
    bool getPrestado();
    //Setter del atributo bool Prestado, ingresa un parámetro tipo bool el cual modifica el atributo Prestado,
    //no retorna nada
    void setPrestado(bool estado) ;
    //Setter del id del usuario, ingresa como parametro un string el cual modificará 
    // el atributo idUsuario y no retorna nada
    void setIdUsuario(std::string idUsuario);
     //Getter del id del usuario, no ingresan parametros y retorna el string del atributo idUsuario
    std::string getIdUsuario();
    //Método virtual que printeara por consola la informacion del material, por ejemplo
    //el nombre, autor, isbn, Prestado.
    virtual std::string mostrarInformacion();
    //Destructor de la clase
    ~MaterialBibliografico();
};