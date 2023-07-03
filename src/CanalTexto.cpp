#include <iostream>
#include "CanalTexto.h"

CanalTexto::CanalTexto()
{

}

CanalTexto::CanalTexto(std::string nome)
{
    this->nome = nome;
}

CanalTexto::~CanalTexto()
{

}

std::vector <Mensagem> CanalTexto::getMensagens()
{
    return this->mensagens;
}

void CanalTexto::setMensagens(std::vector <Mensagem> mensagens)
{
    this->mensagens = mensagens;
}

void CanalTexto::adicionarMensagens(Mensagem mensagem)
{
    this->getMensagens().push_back(mensagem);
}

void CanalTexto::listarMensagens()
{
    for (auto i = this->mensagens.begin(); i < this->mensagens.end(); i++)
    {
        std::cout << i->getConteudo() << std::endl;
    }
}