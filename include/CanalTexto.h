#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <iostream>
#include <vector>
#include "Canal.h"
#include "Mensagem.h"

/**
 * @brief Essa é a classe CanalTexto que armazenará as mensagens enviadas em um servidor dentro de um canal específico
*/
class CanalTexto: public Canal
{
private:
    std::vector <Mensagem> mensagens;
public:

    /**
     * @brief Construtor e Destrutor da classe
    */
    CanalTexto();
    CanalTexto(std::string nome);
    ~CanalTexto();
    
    /**
     * @brief Métodos get e set para o atributo mensagens
    */
    std::vector <Mensagem> getMensagens();
    void setMensagens(std::vector <Mensagem> mensagens);

    /**
     * @brief Método herdado para adicionar mensagens
     * @param mensagem recebe uma mensagem para ser adicionada na lista de mensagens
    */
    void adicionarMensagens(Mensagem mensagem) override;

    /**
     * @brief Função para listar mensagens ao canal
    */
    void listarMensagens() override;

    std::string retornaTipo() override;

    int quantMensagens() override;

    Mensagem retornaMensagens() override;
};

#endif