#pragma once
#include "Usuario.h"
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include <iostream>

const int MAX_USUARIOS = 100;
class Biblioteca{
    private:
    Usuario* listaUsuarios[MAX_USUARIOS] = {nullptr};
    MaterialBibliografico* listaMateriales[MAX_USUARIOS] = {nullptr};
    MaterialBibliografico* material(std::string isbn);
    Usuario* usuario(std::string id);
    public:
    //Constructor de la clase, en el cual se leen los archivos de "Usuarios.txt" y "Materiales.txt" 
    //en el caso de tener informacion guardada de  usuarios y materiales se crean instancias  de estas clases.
    Biblioteca();
    //Recibe un parametro  de tipo string que representa el isbn del material que se quiere buscar y retorna un bool.
    //Si el material ya existe este retornara un bool false, de lo contrario retornara un bool true.
    bool verificarIsbn(std::string isbn);
    //Recibe un parametro de tipo string que representa el id del usuario que se quiere buscar y retorna un bool.
    //Si el usuario ya existe este retornara un bool false, de lo contrario retornara un bool true.
    bool verificarId(std::string id);
    //Recibe dos parametros, ambos de tipo string que representan el nombre e id del usuario.
    //Se crea la instancia de usuario y se agrega a la lista de usuarios si el id no existe y la lista  no esta llena.
    void agregarUsuario(std::string nombre, std::string id);
    //Recibe seis parametros de tipo string los cuales representan el nombre, autor, isbn, numeroEdicion,
    //mespublicacion e idUsuario de la revista.
    //No retorna  nada, se crea la instancia de revista y se agrega a la lista de materiales.
    void agregarMaterialRevista(std::string nombre, std::string autor, std::string isbn,
    std::string numeroEdicion, std::string mesPublicacion, std::string idUsuario);
    //Recibe seis parametros de tipo string los cuales  representan el nombre, autor, isbn, fechaPublicacion, 
    //resumen,  idUsuario del libro.
    //No retorna  nada, se crea la instancia de libro y se agrega a la lista de materiales.
    void agregarMaterialLibro(std::string nombre, std::string autor, std::string isbn,
     std::string fechaPublicacion, std::string resumen,std::string idUsuario);
    //Recibe un parametro de tipo string  que representa el id del usuario que se quiere eliminar.
    //No retorna nada, se elimina la instancia de usuario de la lista de usuarios.
    void eliminarUsuario(std::string id);
    //Recibe un parametro de tipo string que representa el nombre del material que se quiere buscar por su titulo.
    //Si se encuentra el/los material/es se retorna un string con la informacion del material o materiales, 
    //de lo contrario se retorna un string indicando que el material no se ha  encontrado.
    std::string buscarMaterialTitulo(std::string nombre);
    //Recibe un parametro de tipo strinf que representa al autor del material  que se quiere buscar por su autor.
    //Si se encuentra  el/los material/es se retorna un string con la informacion del material o materiales, 
    //de lo contrario  se retorna un string indicando que el material no se ha encontrado.
    std::string  buscarMaterialAutor(std::string autor);
    //Si se encuentran materiales en la lista de materiales  se retornara un string con la informacion de los materiales.
    //Si no se encuentran materiales se retornara un string indicando que no hay materiales.
    std::string mostrarInformacionMateriales();
    //Recibe un parametro  de tipo string que representa el id del usuario que se quiere buscar.
    //Si se encuentra el usuario se retornara un string con la informacion del usuario.
    std::string buscarUsuario( std::string id);
    //Recorre la lista de los materiales buscando aquellos que esten disponibles y
    //retorna  un string con la informacion de los materiales disponibles.
    std::string mostrarMaterialesDisponibles();
    //Recibe un parámetro string con el id  del usuario que se le va a prestar el material, y 
    //el isbn del material a prestar. Retorna un string con el aviso de si se prestó el material, 
    // o no se pudo prestar el material.

    std::string prestarMaterial(std::string id, std::string isbn);
    //Recibe un parámetro string con el id  del usuario que va a devolver el material, y 
    //el isbn del material a devolver. Retorna un string con el aviso de si se devolvió el material, 
    // o no se pudo devolver el material.
    std::string devolverMaterial(std::string  id, std::string isbn);
    //Verifica que la lista de usuarios este o no vacía, retorna un boolean
    bool listaUsuario();
    //Verifica que la lista de materiales este o no vacía, retorna un boolean
    bool listaMaterial();
    //Verifica si hay materiales para devolver, retorna un boolean
    bool materialesParaDevolver();
    //Destructor de la clase. En este método también se escribe en los archivos "Usuarios.txt" y "Materiales.txt"
    //la información de las respectivas clases.
    ~Biblioteca();
};
