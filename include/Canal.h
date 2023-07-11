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
     * @brief Função para adicionar mensagens ao canal (Texto ou Voz)
    */
    virtual void adicionarMensagens(Mensagem mensagem);

    /**
     * @brief Função para listar mensagens ao canal (Texto ou Voz)
    */
    virtual void listarMensagens();

    virtual std::string retornaTipo();

    virtual int quantMensagens();

    virtual Mensagem retornaMensagens();
};

#endif