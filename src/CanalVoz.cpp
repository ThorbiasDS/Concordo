#include "CanalVoz.h"

CanalVoz::CanalVoz()
{

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