#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include <vector>
#include <memory>
#include "Canal.h"

/**
 * @brief Essa é a classe Servidor que servirá para modelar os servidores da aplicação
*/
class Servidor
{
private:
    int usuarioDonoId;
    std::string nome;
    std::string descricao;
    std::string codigoConvite;
    std::vector <Canal*> canais;
    std::vector <int> participantesIDs;
public:

    /**
     * @brief Construtores e Destrutor da classe
    */
    Servidor();
    Servidor(std::string nome, int usuarioDonoId);
    ~Servidor();

    /**
     * @brief Métodos get e set para o atributo usuarioDonoId
    */
    int getUsuarioDonoId();
    void setUsuarioDonoId(int usuarioDonoId);

    /**
     * @brief Métodos get e set para o atributo nome
    */
    std::string getNome();
    void setNome(std::string nome);

    /**
     * @brief Métodos get e set para o atributo descricap
    */
    std::string getDescricao();
    void setDescricao(std::string descricao);

    /**
     * @brief Métodos get e set para o atributo codigoConvite
    */
    std::string getCodigoConvite();
    void setCodigoConvite(std::string codigoConvite);

    /**
     * @brief Métodos get e set para o atributo canais
    */
    std::vector <Canal*> getCanais();
    void setCanais(std::vector <Canal*> canais);
    
    /**
     * @brief Métodos get e set para o atributo participantesIDs
    */
    std::vector <int> getParticipantesIDs();
    void setParticipantesIDs(std::vector <int> participantesIDs);

    void adicionarCanal(Canal *canal);
};

#endif