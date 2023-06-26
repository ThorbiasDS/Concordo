#include "Servidor.h"

Servidor::Servidor()
{

}

Servidor::Servidor(std::string nome)
{
    this->nome = nome;
    this->codigoConvite = " ";
}

Servidor::~Servidor()
{

}

int Servidor::getUsuarioDonoId()
{
    return this->usuarioDonoId;
}

void Servidor::setUsuarioDonoId(int usuarioDonoId)
{
    this->usuarioDonoId = usuarioDonoId;
}

std::string Servidor::getNome()
{
    return this->nome;
}

void Servidor::setNome(std::string nome)
{
    this->nome = nome;
}

std::string Servidor::getDescricao()
{
    return this->descricao;
}

void Servidor::setDescricao(std::string descricao)
{
    this->descricao = descricao;
}

std::string Servidor::getCodigoConvite()
{
    return this->codigoConvite;
}

void Servidor::setCodigoConvite(std::string codigoConvite)
{
    this->codigoConvite = codigoConvite;
}

std::vector <Canal *> Servidor::getCanais()
{   
    return this->canais;
}

void Servidor::setCanais(std::vector <Canal*> canais)
{
    this->canais = canais;
}

std::vector <int> Servidor::getParticipantesIDs()
{
    return this->participantesIDs;
}

void Servidor::setParticipantesIDs(std::vector <int> participantesIDs)
{
    this->participantesIDs = participantesIDs;
}