#ifndef CANAL_H
#define CANAL_H

#include <iostream>
#include "Mensagem.h"

/**
 * @brief Essa é a Canal que servirá como classe base para as classes CanalTexto e CanalVoz
*/
class Canal
{
protected:
    std::string nome;
public:

    /**
     * @brief Construtor e Destrutor da classe
    */
    Canal();
    ~Canal();
    
    /**
     * @brief Métodos get e set da classe para o atributo nome
    */
    std::string getNome();
    void setNome(std::string nome);

    /**
     * @brief Método para adicionar mensagens ao canal (Texto ou Voz)
    */
    virtual void adicionarMensagens(Mensagem mensagem);

    /**
     * @brief Método para listar mensagens ao canal (Texto ou Voz)
    */
    virtual void listarMensagens();

    /**
     * @brief Método para retornar o tipo do canal no formato String
    */
    virtual std::string retornaTipo();

    /**
     * @brief Método para retornar a quantidade de mensagens em um canal
    */
    virtual int quantMensagens();
};

#endif