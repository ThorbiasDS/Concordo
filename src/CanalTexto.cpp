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
    this->mensagens.push_back(mensagem);
}

void CanalTexto::listarMensagens()
{
    for (int i = 0; i < this->mensagens.size(); i++)
    {
        std::cout << this->mensagens.at(i).getConteudo() << std::endl;
    }
}