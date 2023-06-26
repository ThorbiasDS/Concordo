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
    int quantUsuarios;
public:
    Usuario();
    Usuario(std::string nome, std::string email, std::string senha);
    ~Usuario();

    int getId();
    void setId(int id);

    std::string getNome();
    void setNome(std::string nome);

    std::string getEmail();
    void setEmail(std::string email);

    std::string getSenha();
    void setSenha(std::string senha);
    
    int getQuantUsuarios();
    void setQuantUsuarios(int quantUsuarios);
};

#endif