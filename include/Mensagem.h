#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <iostream>

/**
 * @brief Essa é a classe Mensagem que servirá para modelar as mensagens da aplicação
*/
class Mensagem
{
private:
    std::string dataHora;
    int enviadaPor;
    std::string conteudo;
public:

    /**
     * @brief Construtor e Destrutor da classe
    */
    Mensagem();
    Mensagem(std::string conteudo, std::string dataHora, int enviadaPor);
    ~Mensagem();

    /**
     * @brief Métodos get e set para o atributo dataHora
    */
    std::string getDataHora();
    void setDataHora(std::string dataHora);

    /**
     * @brief Métodos get e set para o atributo enviadaPor
    */
    int getEnviadaPor();
    void setEnviadaPor(int enviadaPor);
    
    /**
     * @brief Métodos get e set para o atributo conteudo
    */
    std::string getConteudo();
    void setConteudo(std::string conteudo);
};

#endif