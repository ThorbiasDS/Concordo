#include <iostream>
#include <string>
#include "Sistema.h"
#include "Usuario.h"

Sistema::Sistema()
{
    this->comando = "";
}

Sistema::~Sistema()
{

}

std::vector <Usuario> Sistema::getUsuarios()
{
    return this->usuarios;
}

void Sistema::setUsuarios(std::vector <Usuario> usuarios)
{
    this->usuarios = usuarios;
}

std::vector <Servidor> Sistema::getServidores()
{
    return this->servidores;
}

void Sistema::setServidores(std::vector <Servidor> servidores)
{
    this->servidores = servidores;
}

Usuario Sistema::getUsuarioLogado()
{
    return this->usuarioLogado;
}

void Sistema::setUsuarioLogado(Usuario usuarioLogado)
{
    this->usuarioLogado = usuarioLogado;
}

Servidor Sistema::getServidorVisualizando()
{
    return this->servidorVisualizando;
}

void Sistema::setServidorVisualizando(Servidor servidorVisualizando)
{
    this->servidorVisualizando = servidorVisualizando;
}

Canal Sistema::getCanalVisualizando()
{
    return this->canalVisualizando;
}

void Sistema::setCanalVisualizando(Canal canalVisualizando)
{
    this->canalVisualizando = canalVisualizando;
}

int Sistema::getEstado()
{
    return this->estado;
}

void Sistema::setEstado(int estado)
{
    this->estado = estado;
}

std::string Sistema::getComando()
{
    return this->comando;
}

void Sistema::setComando(std::string comando)
{
    this->comando = comando;
}

std::vector<std::string> split(const std::string &linha, char sep)
{
    std::vector<std::string> tokens;
    std::size_t start = 0, end = 0;

    while ((end = linha.find(sep, start)) != std::string::npos)
    {
        tokens.push_back(linha.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(linha.substr(start));
    return tokens;
}

void Sistema::escolher()
{
    std::vector<std::string> linha;
    while (comando != "quit")
    {
        getline(std::cin, comando);
        linha = split(comando, ' ');

        if (linha[0] == "create-user")
        {
            std::string email, senha, nome;
            email = linha[1];
            senha = linha[2];
            for (auto it = (linha.begin() + 3); it < linha.end(); it++)
            {
                nome = nome + *it + " ";
            }
            bool existe = false;

            for (auto it = usuarios.begin(); it < usuarios.end(); it++)
            {
                if (it->getEmail() == nome)
                {
                    std::cout << "Usuário já existe" << std::endl;
                    existe = true;
                }
            }

            if (existe == false)
            {
                Usuario usuario(nome, email, senha);
                usuarios.push_back(usuario);
                std::cout << "Usuario criado" << std::endl;
            }
        }
        else if (linha[0] == "login")
        {
        }
        else if (linha[0] == "disconnect")
        {
        }
        else if (linha[0] == "create-server")
        {
        }
        else if (linha[0] == "set-server-desc")
        {
        }
        else if (linha[0] == "set-server-invite-code")
        {
        }
        else if (linha[0] == "list-servers")
        {
        }
        else if (linha[0] == "remove-server")
        {
        }
        else if (linha[0] == "enter-server")
        {
        }
        else if (linha[0] == "leave-server")
        {
        }
        else if (linha[0] == "list-participants")
        {
        }
    }
}