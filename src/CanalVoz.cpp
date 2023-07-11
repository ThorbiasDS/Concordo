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

void CanalVoz::adicionarMensagens(Mensagem mensagem)
{
    this->ultimaMensagem = mensagem;
}

void CanalVoz::listarMensagens()
{
    std::cout << this->ultimaMensagem.getConteudo() << std::endl;
}

std::string CanalVoz::retornaTipo()
{
    return "voz";
}

int CanalVoz::quantMensagens()
{
    return 1;
}

Mensagem CanalVoz::retornaMensagens()
{
    return this->ultimaMensagem;
}