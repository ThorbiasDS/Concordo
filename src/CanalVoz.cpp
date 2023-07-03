#include "CanalVoz.h"

CanalVoz::CanalVoz()
{

}

CanalVoz::CanalVoz(std::string nome)
{   
    this->nome = nome;
}

CanalVoz::~CanalVoz()
{

}

Mensagem CanalVoz::getUltimaMensagem()
{
    return this->ultimaMensagem;
}

void CanalVoz::setUltimaMensagem(Mensagem ultimaMensagem)
{
    this->ultimaMensagem = ultimaMensagem;
}