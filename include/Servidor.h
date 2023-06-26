#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include <vector>
#include "Canal.h"

class Servidor
{
private:
    int usuarioDonoId;
    std::string nome;
    std::string descricao;
    std::string codigoConvite;
    std::vector <Canal *> canais;
    std::vector <int> participantesIDs;
public:
    Servidor();
    Servidor(std::string nome);
    ~Servidor();

    int getUsuarioDonoId();
    void setUsuarioDonoId(int usuarioDonoId);

    std::string getNome();
    void setNome(std::string nome);

    std::string getDescricao();
    void setDescricao(std::string descricao);

    std::string getCodigoConvite();
    void setCodigoConvite(std::string codigoConvite);

    std::vector <Canal *> getCanais();
    void setCanais(std::vector <Canal*> canais);
    
    std::vector <int> getParticipantesIDs();
    void setParticipantesIDs(std::vector <int> participantesIDs);
};

#endif