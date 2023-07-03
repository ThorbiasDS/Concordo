#include "Mensagem.h"

Mensagem::Mensagem()
{

}

Mensagem::Mensagem(std::string dataHora, int enviadaPor, std::string conteudo)
{
    this->dataHora = dataHora;
    this->enviadaPor = enviadaPor;
    this->conteudo = conteudo;
}

Mensagem::~Mensagem()
{

}

std::string Mensagem::getDataHora()
{
    return this->dataHora;
}

void Mensagem::setDataHora(std::string dataHora)
{
    this->dataHora = dataHora;
}

int Mensagem::getEnviadaPor()
{
    return this->enviadaPor;
}

void Mensagem::setEnviadaPor(int enviadaPor)
{

}

std::string Mensagem::getConteudo()
{
    return this->conteudo;
}

void Mensagem::setConteudo(std::string conteudo)
{
    this->conteudo = conteudo;
}