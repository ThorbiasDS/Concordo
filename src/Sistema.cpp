#include <iostream>
#include <string>
#include <chrono>
#include <typeinfo>
#include <ctime>
#include <fstream>
#include "Sistema.h"
#include "Usuario.h"
#include "CanalTexto.h"
#include "CanalVoz.h"

Sistema::Sistema()
{
    this->comando = "";
    this->estado = 0;
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

void Sistema::salvarUsuarios()
{
    std::ofstream arquivo("usuarios.txt");

    if (arquivo.is_open())
    {
        arquivo << this->usuarios.size() << std::endl;
        for (int i = 0; i < this->usuarios.size(); i++)
        {
            arquivo << this->usuarios.at(i).getId() << std::endl;
            arquivo << this->usuarios.at(i).getNome() << std::endl;
            arquivo << this->usuarios.at(i).getEmail() << std::endl;
            arquivo << this->usuarios.at(i).getSenha() << std::endl;
        }

        arquivo.close();
    }
    else
    {
        std::cout << "\"Não foi possível abrir o arquivo 'usuários.txt'.\"" << std::endl;
    }
}

void Sistema::salvarServidores()
{
    std::ofstream arquivo("servidores.txt");

    if (arquivo.is_open())
    {
        arquivo << this->servidores.size() << std::endl;
        for (int i = 0; i < this->servidores.size(); i++)
        {
            arquivo << this->servidores.at(i).getUsuarioDonoId() << std::endl;
            arquivo << this->servidores.at(i).getNome() << std::endl;
            arquivo << this->servidores.at(i).getDescricao() << std::endl;
            arquivo << this->servidores.at(i).getCodigoConvite() << std::endl;
            arquivo << this->servidores.at(i).getParticipantesIDs().size() << std::endl;
            for (int j = 0; j < this->servidores.at(i).getParticipantesIDs().size(); j++)
            {
                arquivo << this->servidores.at(i).getParticipantesIDs().at(j) << std::endl;
            }
            arquivo << this->servidores.at(i).getCanais().size() << std::endl;
            for (int k = 0; k < this->servidores.at(i).getCanais().size(); k++)
            {
                arquivo << this->servidores.at(i).getCanais().at(k)->getNome() << std::endl;
                arquivo << this->servidores.at(i).getCanais().at(k)->retornaTipo() << std::endl;
                arquivo << this->servidores.at(i).getCanais().at(k)->quantMensagens() << std::endl;
            }
        }

        arquivo.close();
    }
    else
    {
        std::cout << "\"Não foi possível abrir o arquivo 'servidores.txt'.\"" << std::endl;
    }
}

void Sistema::salvar()
{
    salvarUsuarios();
    salvarServidores();
}

void Sistema::carregarUsuarios()
{
    
}

void Sistema::carregarServidores()
{
    
}

void Sistema::carregar()
{
    carregarUsuarios();
    carregarServidores();
}

void Sistema::escolher()
{
    bool ativo = true;
    std::vector<std::string> linha;
    int gerarID = 0;
    int gerarQuantidade = 0;

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
                    Usuario usuario(nome, email, senha, ++gerarID, ++gerarQuantidade);
                    usuarios.push_back(usuario);
                    std::cout << "\"Usuario criado\"" << std::endl;
                    salvar();
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
                    std::cout << "\"Senha ou usuário inválidos!\"" << std::endl;
                }
            }
        }
        else if (linha[0] == "disconnect")
        {
            if (this->estado != 1)
            {
                std::cout << "\"Não é possível fazer logoff nesse estado\"" << std::endl;
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
                    this->usuarioLogado.setId(0);
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
                    Servidor servidor(nome, this->usuarioLogado.getId());
                    this->servidores.push_back(servidor);
                    std::cout << "\"Servidor criado\"" << std::endl;
                    salvar();
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
                std::string nome = linha[1];
                std::string descricao = "";
                bool existe = false;

                for (auto it = (linha.begin() + 2); it < linha.end(); it++)
                {
                    descricao = descricao + *it + " ";
                }

                for (auto it = servidores.begin(); it < servidores.end(); it++)
                {
                    if (it->getNome() == nome)
                    {
                        existe = true;

                        if (it->getUsuarioDonoId() == this->usuarioLogado.getId())
                        {
                            it->setDescricao(descricao);
                            std::cout << "\"Descrição do servidor '" << nome << "' modificada!\"" << std::endl;
                            salvar();
                        }
                        else
                        {
                            std::cout << "\"Você não pode alterar a descrição de um servidor que não foi criado por você\"" << std::endl;
                        }
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
                std::string nome = linha[1];
                std::string codigo;
                bool existe = false;

                linha.size() == 3 ? codigo = linha[2] : codigo = "";

                for (auto it = servidores.begin(); it < servidores.end(); it++)
                {
                    if (it->getNome() == nome)
                    {
                        existe = true;

                        if (codigo == "")
                        {
                            it->setCodigoConvite(codigo);
                            std::cout << "\"Código de convite do servidor '" << nome << "' removido!\"" << std::endl;
                            salvar();
                        }
                        else
                        {
                            it->setCodigoConvite(codigo);
                            std::cout << "\"Código de convite do servidor '" << nome << "' modificado!\"" << std::endl;
                            salvar();
                        }
                    }
                }

                if (existe == false)
                {
                    std::cout << "\"Servidor '" << nome << "'não existe\"" << std::endl;
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
                for (auto it = servidores.begin(); it < servidores.end(); it++)
                {
                    std::cout << it->getNome() << std::endl;
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
                std::string nome = linha[1];
                bool existe = false;

                for (auto it = servidores.begin(); it < servidores.end(); it++)
                {
                    if (it->getNome() == nome)
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
                        if (it->getNome() == nome)
                        {
                            if (it->getUsuarioDonoId() == this->usuarioLogado.getId())
                            {
                                servidores.erase(it);
                                std::cout << "\"Servidor '" << nome << "' removido\"" << std::endl;
                                salvar();
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
        else if (linha[0] == "enter-server")
        {
            if (this->estado != 1)
            {
                std::cout << "\"Não é possível entrar em um servidor nesse estado\"" << std::endl;
            }
            else
            {
                std::string nome = linha[1];
                std::string codigo;
                bool existe = false;

                linha.size() == 3 ? codigo = linha[2] : codigo = "";

                for (auto it = servidores.begin(); it < servidores.end(); it++)
                {
                    if (it->getNome() == nome)
                    {
                        existe = true;

                        if (linha.size() == 2)
                        {
                            it->adicionarParticipanteID(this->usuarioLogado.getId());
                            this->servidorVisualizando = *it;
                            this->estado = 2;
                            std::cout << "\"Entrou no servidor com sucesso\"" << std::endl;
                            salvar();
                        }
                        else
                        {
                            if (it->getCodigoConvite() == codigo)
                            {
                                it->adicionarParticipanteID(this->usuarioLogado.getId());
                                this->servidorVisualizando = *it;
                                this->estado = 2;
                                std::cout << "\"Entrou no servidor com sucesso\"" << std::endl;
                                salvar();
                            }
                            else if (it->getCodigoConvite() != codigo)
                            {
                                if (this->usuarioLogado.getId() == it->getUsuarioDonoId())
                                {
                                    it->adicionarParticipanteID(this->usuarioLogado.getId());
                                    this->servidorVisualizando = *it;
                                    this->estado = 2;
                                    std::cout << "\"Entrou no servidor com sucesso\"" << std::endl;
                                    salvar();
                                }
                                else
                                {
                                    std::cout << "Servidor requer código de convite" << std::endl;
                                }
                            }
                        }
                    }
                }

                if (existe == false)
                {
                    std::cout << "\"Servidor não encontrado\"" << std::endl;
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
                if (this->servidorVisualizando.getNome() == "")
                {
                    std::cout << "\"Você não está visualizando nenhum servidor\"" << std::endl;
                }
                else
                {
                    std::cout << "\"Saindo do servidor '" << this->servidorVisualizando.getNome() << "'\"" << std::endl;
                    this->servidorVisualizando.setCodigoConvite("");
                    this->servidorVisualizando.setDescricao("");
                    this->servidorVisualizando.setNome("");
                    this->servidorVisualizando.setUsuarioDonoId(0);
                    this->estado = 1;
                    salvar();
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
                if (this->servidorVisualizando.getNome() != "")
                {
                    for (int i = 0; i < this->usuarios.size(); i++)
                    {
                        for (int j = 0; j < this->servidorVisualizando.getParticipantesIDs().size(); j++)
                        {
                            if (this->usuarios.at(i).getId() == this->servidorVisualizando.getParticipantesIDs().at(j))
                            {
                                std::cout << this->usuarios.at(i).getNome() << std::endl;
                            }
                        }
                    }
                }
                else
                {
                    std::cout << "Você não está visualizando nenhum servidor" << std::endl;
                }
            }
        }
        else if (linha[0] == "list-channels")
        {
            if (this->estado != 2)
            {
                std::cout << "\"Não é possível listar os canais nesse estado\"" << std::endl;
            }
            else
            {
                std::cout << "#canais de texto" << std::endl;
                auto canais = this->servidorVisualizando.getCanais();

                for (int i = 0; i < this->servidorVisualizando.getCanais().size(); i++)
                {
                    Canal *c = canais.at(i);
                    const std::type_info &tipo = typeid(*c);

                    if (tipo == typeid(CanalTexto))
                    {
                        std::cout << c->getNome() << std::endl;
                    }
                }

                std::cout << "#canais de voz" << std::endl;

                for (int i = 0; i < this->servidorVisualizando.getCanais().size(); i++)
                {
                    Canal *c = canais.at(i);
                    const std::type_info &tipo = typeid(*c);

                    if (tipo == typeid(CanalVoz))
                    {
                        std::cout << c->getNome() << std::endl;
                    }
                }
            }
        }
        else if (linha[0] == "create-channel")
        {
            if (this->estado != 2)
            {
                std::cout << "\"Não é possível criar um canal nesse estado\"" << std::endl;
            }
            else
            {
                if (this->usuarioLogado.getId() == this->servidorVisualizando.getUsuarioDonoId())
                {
                    std::string nome = linha[1];
                    std::string tipo = linha[2];

                    if (tipo == "texto")
                    {
                        Canal *texto = new CanalTexto(nome);
                        this->servidorVisualizando.adicionarCanal(texto);
                        std::cout << "\"Canal de texto '" << texto->getNome() << "' criado" << std::endl;
                        salvar();
                    }
                    else if (tipo == "voz")
                    {
                        Canal *voz = new CanalVoz(nome);
                        this->servidorVisualizando.adicionarCanal(voz);
                        std::cout << "\"Canal de voz '" << voz->getNome() << "' criado" << std::endl;
                        salvar();
                    }
                }
                else
                {
                    std::cout << "\"Você não pode criar um canal pois não é o dono do servidor\"" << std::endl;
                }
            }
        }
        else if (linha[0] == "enter-channel")
        {
            if (this->estado != 2)
            {
                std::cout << "\"Não é possível entrar em um canal nesse estado\"" << std::endl;
            }
            else
            {
                std::string nome = linha[1];
                auto canais = this->servidorVisualizando.getCanais();
                bool existe = false;

                for (int i = 0; i < this->servidorVisualizando.getCanais().size(); i++)
                {
                    Canal *c = canais.at(i);
                    if (nome == c->getNome())
                    {
                        this->canalVisualizando.setNome(c->getNome());
                        std::cout << "\"Entrou no canal '" << nome << "'\"" << std::endl;
                        existe = true;
                        salvar();
                    }
                }

                if (!existe)
                {
                    std::cout << "\"Canal '" << nome << "' não existe\"" << std::endl;
                }
            }
        }
        else if (linha[0] == "leave-channel")
        {
            std::cout << "\"Saindo do canal '" << this->canalVisualizando.getNome() << "'\"" << std::endl;
            this->canalVisualizando.setNome("");
            salvar();
        }
        else if (linha[0] == "send-message")
        {
            std::string conteudo = "";

            std::chrono::system_clock::time_point agora = std::chrono::system_clock::now();
            std::time_t horaAtual = std::chrono::system_clock::to_time_t(agora);
            std::string horaString = std::ctime(&horaAtual);

            for (auto it = (linha.begin() + 1); it < linha.end(); it++)
            {
                conteudo = conteudo + *it + " ";
            }

            Mensagem msg(conteudo, horaString, this->usuarioLogado.getId());
            this->canalVisualizando.adicionarMensagens(msg);
            salvar();
        }
        else if (linha[0] == "list-messages")
        {
            if (this->canalVisualizando.getNome() != "")
            {
                this->canalVisualizando.listarMensagens();
            }
            else
            {
                std::cout << "\"Você não está visualizando nenhum canal\"" << std::endl;
            }
        }
    }
}