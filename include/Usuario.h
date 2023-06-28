#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>

/**
 * @brief Essa é a classe Usuario que servirá para modelar os usuários da aplicação
*/
class Usuario
{
private:
    int id;
    std::string nome;
    std::string email;
    std::string senha;
    int quantUsuarios;
public:

    /**
     * @brief Construtores e Destrutores da classe
    */
    Usuario();
    Usuario(std::string nome, std::string email, std::string senha, int id, int quantUsuarios);
    ~Usuario();

    /**
     * @brief Métodos get e set para o atributo id
    */
    int getId();
    void setId(int id);

    /**
     * @brief Métodos get e set para o atributo nome
    */
    std::string getNome();
    void setNome(std::string nome);

    /**
     * @brief Métodos get e set para o atributo email
    */
    std::string getEmail();
    void setEmail(std::string email);

    /**
     * @brief Métodos get e set para o atributo senha
    */
    std::string getSenha();
    void setSenha(std::string senha);
    
    /**
     * @brief Métodos get e set para o atributo quantUsuarios
    */
    int getQuantUsuarios();
    void setQuantUsuarios(int quantUsuarios);
};

#endif