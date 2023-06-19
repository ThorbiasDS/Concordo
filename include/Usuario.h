#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

class Usuario
{
private:
    int id;
    std::string nome;
    std::string email;
    std::string senha;
public:
    Usuario();
    ~Usuario();
};

#endif