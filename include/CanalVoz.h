#ifndef CANALVOZ_H
#define CANALVOZ_H

#include <iostream>
#include "Canal.h"
#include "Mensagem.h"

/**
 * @brief Essa é a classe CanalVoz que servirá para armazenar a última mensagem enviada em um servidor dentro de um canal específico
*/
class CanalVoz: public Canal
{
private:
    Mensagem ultimaMensagem;
public:

    /**
     * @brief Construtores e Destrutor da classe
    */
    CanalVoz();
    CanalVoz(std::string nome);
    ~CanalVoz();
    
    /**
     * @brief Métodos get e set para o atributo ultimaMensagem
    */
    Mensagem getUltimaMensagem();
    void setUltimaMensagem(Mensagem ultimaMensagem);

    /**
     * @brief Sobrescrita do método herdado para adicionar mensagens
     * @param mensagem recebe uma mensagem para ser colocada no atributo ultimaMensagem
    */
    void adicionarMensagens(Mensagem mensagem) override;

    /**
     * @brief Sobrescrita do método para listar mensagens ao canal
    */
    void listarMensagens() override;

    /**
     * @brief Sobrescrita do método herdado da classe Canal para retornar o tipo do canal em formato texto
    */
    std::string retornaTipo() override;

    /**
     * @brief Sobrescrita do método herdado da classe Canal para retornar a quantidade de mensagens em um canal
    */
    int quantMensagens() override;
};

#endif