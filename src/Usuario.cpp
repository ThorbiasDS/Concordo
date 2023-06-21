#include "Usuario.h"

Usuario::Usuario()
{

}

Usuario::Usuario(std::string nome, std::string email, std::string senha)
{
    this->nome = nome;
    this->email = email;
    this->senha = senha;
    this->quantUsuarios++;
    this->id = quantUsuarios;
}

int Usuario::getId()
{
    return this->id;
}

void Usuario::setId(int id)
{
    this->id = id;
}

std::string Usuario::getNome()
{
    return this->nome;
}

void Usuario::setNome(std::string nome)
{
    this->nome = nome;
}

std::string Usuario::getEmail()
{
    return this->email;
}

void Usuario::setEmail(std::string email)
{
    this->email = email;
}

std::string Usuario::getSenha()
{
    return this->senha;
}

void Usuario::setSenha(std::string senha)
{
    this->senha = senha;
}

int Usuario::getQuantUsuarios()
{
    return this->quantUsuarios;
}

void Usuario::setQuantUsuarios(int quantUsuarios)
{
    this->quantUsuarios = quantUsuarios;
}