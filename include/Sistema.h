#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <vector>
#include "Usuario.h"
#include "Servidor.h"
#include "Canal.h"

class Sistema
{
private:
    std::vector <Usuario> usuarios;
    std::vector <Servidor> servidores;
    Usuario usuarioLogado;
    Servidor servidorVisualizando;
    Canal canalVisualizando;
    int estado;
    std::string comando;
    int geradorID;
    int geradorQuantidade;
    std::vector <int> participantesID;
public:
    Sistema();
    ~Sistema();

    std::vector <Usuario> getUsuarios();
    void setUsuarios(std::vector <Usuario> usuarios);

    std::vector <Servidor> getServidores();
    void setServidores(std::vector <Servidor> servidores);

    Usuario getUsuarioLogado();
    void setUsuarioLogado(Usuario usuario);

    Servidor getServidorVisualizando();
    void setServidorVisualizando(Servidor servidorVisualizando);

    Canal getCanalVisualizando();
    void setCanalVisualizando(Canal canalVisualizando);

    int getEstado();
    void setEstado(int estado);

    std::string getComando();
    void setComando(std::string comando);
    
    int getGeradorID();
    void setGeradorID(int geradorID);

    int getGeradorQuantidade();
    void setGeradorQuantidade(int geradorQuantidade);

    std::vector <int> getParticipantesID();
    void setParticipantesID(std::vector <int> participantesID);

    std::vector<std::string> split(const std::string &linha, char sep);
    void escolher();
};

#endif 