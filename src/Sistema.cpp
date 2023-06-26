#include <iostream>
#include <string>
#include "Sistema.h"
#include "Usuario.h"

Sistema::Sistema()
{
    this->comando = "";
    this->estado = 0;
    this->geradorID = 0;
    this->geradorQuantidade = 0;
    this->usuarioLogado.setNome("");
    this->usuarioLogado.setEmail("");
    this->usuarioLogado.setSenha("");
    this->usuarioLogado.setId(0);
    this->usuarioLogado.setQuantUsuarios(0);
    this->servidorVisualizando.setNome("");
}

Sistema::~Sistema()
{
}

std::vector<Usuario> Sistema::getUsuarios()
{
    return this->usuarios;
}

void Sistema::setUsuarios(std::vector<Usuario> usuarios)
{
    this->usuarios = usuarios;
}

std::vector<Servidor> Sistema::getServidores()
{
    return this->servidores;
}

void Sistema::setServidores(std::vector<Servidor> servidores)
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

int Sistema::getGeradorID()
{
    return this->geradorID;
}

void Sistema::setGeradorID(int geradorID)
{
    this->geradorID = geradorID;
}

int Sistema::getGeradorQuantidade()
{
    return this->geradorQuantidade;
}

void Sistema::setGeradorQuantidade(int geradorQuantidade)
{
    this->geradorQuantidade = geradorQuantidade;
}

std::vector<int> Sistema::getParticipantesID()
{
    return this->participantesID;
}

void Sistema::setParticipantesID(std::vector<int> participantes)
{
    this->participantesID = participantesID;
}

std::vector<std::string> Sistema::split(const std::string &linha, char sep)
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
    bool ativo = true;
    std::vector<std::string> linha;

    while (ativo == true)
    {
        getline(std::cin, this->comando);
        linha = split(this->comando, ' ');

        if (linha[0] == "quit")
        {
            std::cout << "\"Saindo do Concordo\"" << std::endl;
            ativo = false;
        }
        else if (linha[0] == "create-user")
        {
            if (this->estado != 0)
            {
                std::cout << "\"Não é possível criar um usuário nesse estado\"" << std::endl;
            }
            else
            {
                std::string email = linha[1];
                std::string senha = linha[2];
                std::string nome = "";
                bool existe = false;

                for (auto it = (linha.begin() + 3); it < linha.end(); it++)
                {
                    nome = nome + *it + " ";
                }

                for (auto it = usuarios.begin(); it < usuarios.end(); it++)
                {
                    if (it->getEmail() == email)
                    {
                        std::cout << "\"Usuário já existe\"" << std::endl;
                        existe = true;
                    }
                }

                if (existe == false)
                {
                    Usuario usuario(nome, email, senha);
                    usuarios.push_back(usuario);
                    std::cout << "\"Usuario criado\"" << std::endl;

                    this->geradorID++;
                    this->geradorQuantidade++;

                    usuario.setQuantUsuarios(this->geradorQuantidade);
                    usuario.setId(this->geradorID);
                }
            }
        }
        else if (linha[0] == "login")
        {
            if (this->estado != 0)
            {
                std::cout << "\"Não é possível fazer login nesse estado\"" << std::endl;
            }
            else
            {
                std::string email = linha[1];
                std::string senha = linha[2];
                bool existe = false;

                for (auto it = usuarios.begin(); it < usuarios.end(); it++)
                {
                    if (it->getEmail() == email && it->getSenha() == senha)
                    {
                        this->usuarioLogado = *it;
                        std::cout << "\"Logado como " << it->getEmail() << "\"" << std::endl;
                        existe = true;
                        this->estado = 1;
                    }
                }

                if (existe == false)
                {
                    std::cout << "\"Senha ou usuários inválidos!\"" << std::endl;
                }
            }
        }
        else if (linha[0] == "disconnect")
        {
            if (this->estado != 1)
            {
                std::cout << "\"Não é possível desconectar do servidor nesse estado\"" << std::endl;
            }
            else
            {
                if (this->usuarioLogado.getNome() == "" && this->usuarioLogado.getEmail() == "" && this->usuarioLogado.getSenha() == "")
                {
                    std::cout << "\"Não está conectado\"" << std::endl;
                }
                else
                {
                    std::cout << "\"Desconectando usuário " << this->usuarioLogado.getEmail() << "\"" << std::endl;
                    this->usuarioLogado.setNome("");
                    this->usuarioLogado.setEmail("");
                    this->usuarioLogado.setSenha("");
                    this->estado = 0;
                }
            }
        }
        else if (linha[0] == "create-server")
        {
            if (this->estado != 1)
            {
                std::cout << "\"Não é possível criar um servidor nesse estado\"" << std::endl;
            }
            else
            {
                if (this->usuarioLogado.getEmail() == "" && this->usuarioLogado.getNome() == "" && this->usuarioLogado.getSenha() == "")
                {
                    std::cout << "\"Sem usuário logado\"" << std::endl;
                }
                else
                {
                    std::string nome = linha[1];
                    bool existe = false;

                    for (auto it = servidores.begin(); it < servidores.end(); it++)
                    {
                        if (it->getNome() == nome)
                        {
                            std::cout << "\"Servidor com esse nome já existe\"" << std::endl;
                            existe = true;
                        }
                    }

                    if (existe == false)
                    {
                        Servidor servidor(nome);
                        servidores.push_back(servidor);
                        servidor.setUsuarioDonoId(this->usuarioLogado.getId());
                        std::cout << "\"Servidor criado\"" << std::endl;
                    }
                }
            }
        }
        else if (linha[0] == "set-server-desc")
        {
            if (this->estado != 1)
            {
                std::cout << "\"Não é possível mudar a descrição de um servidor nesse estado\"" << std::endl;
            }
            else
            {
                if (this->usuarioLogado.getEmail() == "" && this->usuarioLogado.getNome() == "" && this->usuarioLogado.getSenha() == "")
                {
                    std::cout << "\"Sem usuário logado\"" << std::endl;
                }
                else
                {
                    std::string nome = linha[1];
                    std::string descricao = "";
                    bool existe = false;

                    for (auto it = servidores.begin(); it < servidores.end(); it++)
                    {
                        if (nome == it->getNome())
                        {
                            existe = true;

                            for (auto it = (linha.begin() + 2); it < linha.end(); it++)
                            {
                                descricao = descricao + *it + " ";
                            }

                            if (it->getUsuarioDonoId() == this->usuarioLogado.getId())
                            {
                                it->setDescricao(descricao);
                                std::cout << "\"Descrição do servidor '" << nome << "' modificada!\"" << std::endl;
                            }
                            else
                            {
                                std::cout << "\"Você não pode alterar a descricao de um servidor que não foi criado por você\"" << std::endl;
                            }
                        }
                    }

                    if (existe == false)
                    {
                        std::cout << "\"Servidor '" << nome << "' não existe\"" << std::endl;
                    }
                }
            }
        }
        else if (linha[0] == "set-server-invite-code")
        {
            if (this->estado != 1)
            {
                std::cout << "\"Não é possível setar o código de convite de um servidor nesse estado\"" << std::endl;
            }
            else
            {
                if (this->usuarioLogado.getEmail() == "" && this->usuarioLogado.getNome() == "" && this->usuarioLogado.getSenha() == "")
                {
                    std::cout << "\"Sem usuário logado\"" << std::endl;
                }
                else
                {
                    std::string nome = linha[1];
                    std::string codigo;
                    bool existe = false;

                    if(linha.size() == 3)
                    {
                        codigo = linha[2];
                    }
                    else
                    {
                        codigo = "";
                    }

                    for (auto it = servidores.begin(); it < servidores.end(); it++)
                    {
                        if (nome == it->getNome())
                        {
                            existe = true;

                            if (codigo == "")
                            {
                                it->setCodigoConvite(codigo);
                                std::cout << "\"Código de convite do servidor '" << nome << "' removido!\"" << std::endl;
                            }
                            else
                            {
                                it->setCodigoConvite(codigo);
                                std::cout << "\"Código de convite do servidor '" << nome << "' modificado!\"" << std::endl;
                            }
                        }
                    }

                    if (existe == false)
                    {
                        std::cout << "\"Servidor '" << nome << "'não existe\"" << std::endl;
                    }
                }
            }
        }
        else if (linha[0] == "list-servers")
        {
            if (this->estado != 1)
            {
                std::cout << "\"Não é possível listar os servidores nesse estado\"" << std::endl;
            }
            else
            {
                if (this->usuarioLogado.getEmail() == "" && this->usuarioLogado.getNome() == "" && this->usuarioLogado.getSenha() == "")
                {
                    std::cout << "\"Sem usuário logado\"" << std::endl;
                }
                else
                {
                    for (auto it = servidores.begin(); it < servidores.end(); it++)
                    {
                        std::cout << it->getNome() << std::endl;
                    }
                }
            }
        }
        else if (linha[0] == "remove-server")
        {
            if (this->estado != 1)
            {
                std::cout << "\"Não é possível remover um servidor nesse estado\"" << std::endl;
            }
            else
            {
                if (this->usuarioLogado.getEmail() == "" && this->usuarioLogado.getNome() == "" && this->usuarioLogado.getSenha() == "")
                {
                    std::cout << "\"Sem usuário logado\"" << std::endl;
                }
                else
                {
                    std::string nome = linha[1];
                    bool existe = false;

                    for (auto it = servidores.begin(); it < servidores.end(); it++)
                    {
                        if (nome == it->getNome())
                        {
                            existe = true;
                        }
                    }

                    if (existe == false)
                    {
                        std::cout << "\"Sevidor '" << nome << "' não encontrado\"" << std::endl;
                    }
                    else if (existe == true)
                    {
                        for (auto it = servidores.begin(); it < servidores.end(); it++)
                        {
                            if (nome == it->getNome())
                            {
                                if (it->getUsuarioDonoId() == this->usuarioLogado.getId())
                                {
                                    servidores.erase(it);
                                    std::cout << "\"Servidor '" << nome << "' removido\"" << std::endl;
                                }
                                else
                                {
                                    std::cout << "\"Você não é o dono do servidor '" << nome << "'\"" << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (linha[0] == "enter-server")
        {
            if (this->estado != 1)
            {
                std::cout << "\"Não é possível entrar um servidor nesse estado\"" << std::endl;
            }
            else
            {
                if (this->usuarioLogado.getEmail() == "" && this->usuarioLogado.getNome() == "" && this->usuarioLogado.getSenha() == "")
                {
                    std::cout << "\"Sem usuário logado\"" << std::endl;
                }
                else
                {
                    std::string nome = linha[1];
                    std::string codigo;
                    bool existe = false;

                    if(linha.size() == 3)
                    {
                        codigo = linha[2];
                    }
                    else
                    {
                        codigo = "";
                    }

                    for (auto it = servidores.begin(); it < servidores.end(); it++)
                    {
                        if (nome == it->getNome())
                        {
                            existe = true;

                            if (it->getCodigoConvite() == "")
                            {
                                this->participantesID.push_back(this->usuarioLogado.getId());
                                it->setParticipantesIDs(this->participantesID);
                                this->servidorVisualizando = *it;
                                this->estado = 2;
                                std::cout << "\"Entrou no servidor com sucesso\"" << std::endl;
                            }
                            else
                            {
                                if (this->usuarioLogado.getId() == it->getUsuarioDonoId())
                                {
                                    this->participantesID.push_back(this->usuarioLogado.getId());
                                    it->setParticipantesIDs(this->participantesID);
                                    this->servidorVisualizando = *it;
                                    this->estado = 2;
                                    std::cout << "\"Entrou no servidor com sucesso\"" << std::endl;
                                }
                                else if (codigo == it->getCodigoConvite())
                                {
                                    this->participantesID.push_back(this->usuarioLogado.getId());
                                    it->setParticipantesIDs(this->participantesID);
                                    this->servidorVisualizando = *it;
                                    this->estado = 2;
                                    std::cout << "\"Entrou no servidor com sucesso\"" << std::endl;
                                }
                                else
                                {
                                    std::cout << "\"Servidor requer código de convite\"" << std::endl;
                                }
                            }
                        }
                    }

                    if (existe == false)
                    {
                        std::cout << "\"Sevidor '" << nome << "' não encontrado\"" << std::endl;
                    }
                }
            }
        }
        else if (linha[0] == "leave-server")
        {
            if (this->estado != 2)
            {
                std::cout << "\"Não é possível sair de um servidor nesse estado\"" << std::endl;
            }
            else
            {
                if (this->usuarioLogado.getEmail() == "" && this->usuarioLogado.getNome() == "" && this->usuarioLogado.getSenha() == "")
                {
                    std::cout << "\"Sem usuário logado\"" << std::endl;
                }
                else
                {
                    if(this->servidorVisualizando.getNome() == "")
                    {
                        std::cout << "\"Você não está visualizando nenhum servidor\"" << std::endl;
                    }
                    else
                    {
                        std::cout << "\"Saindo do servidor '" << this->servidorVisualizando.getNome() << "'\"" << std::endl; 
                        this->servidorVisualizando.setNome("");
                        this->servidorVisualizando.setUsuarioDonoId(0);
                        this->servidorVisualizando.setDescricao("");
                        this->servidorVisualizando.setCodigoConvite(0);
                    }
                }
            }
        }
        else if (linha[0] == "list-participants")
        {
            if (this->estado != 2)
            {
                std::cout << "\"Não é possível sair de um servidor nesse estado\"" << std::endl;
            }
            else
            {
                if (this->usuarioLogado.getEmail() == "" && this->usuarioLogado.getNome() == "" && this->usuarioLogado.getSenha() == "")
                {
                    std::cout << "\"Sem usuário logado\"" << std::endl;
                }
                else
                {
                    for (auto it = this->servidorVisualizando.getParticipantesIDs().begin(); it < this->servidorVisualizando.getParticipantesIDs().end(); it++)
                    {
                        for (auto count = this->usuarios.begin(); count < this->usuarios.end(); count++)
                        {
                            
                        }
                    }
                }
            }
        }
    }
}