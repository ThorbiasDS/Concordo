#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Usuario.h"
#include "Servidor.h"
#include "Canal.h"

/**
 * @brief Essa é a classe Sistema que ficará responsável por fazer toda a interação do ser humano com a aplicação
*/
class Sistema
{
private:
    std::vector<Usuario> usuarios;
    std::vector<Servidor> servidores;
    Usuario usuarioLogado;
    Servidor servidorVisualizando;
    Canal canalVisualizando;
    int estado;
    std::string comando;
    std::vector<int> participantesID;

    void salvarUsuarios();
    void salvarServidores();
    void carregarUsuarios();
    void carregarServidores();

public:
    /**
     * @brief Construtor e Destrutor da classe
     */
    Sistema();
    ~Sistema();

    /**
     * @brief Métodos get e set para o atributo usuario
     */
    std::vector<Usuario> getUsuarios();
    void setUsuarios(std::vector<Usuario> usuarios);

    /**
     * @brief Métodos get e set para o atributo servidores
     */
    std::vector<Servidor> getServidores();
    void setServidores(std::vector<Servidor> servidores);

    /**
     * @brief Métodos get e set para o atributo usuario
     */
    Usuario getUsuarioLogado();
    void setUsuarioLogado(Usuario usuario);

    /**
     * @brief Métodos get e set para o atributo servidorVisualizando
     */
    Servidor getServidorVisualizando();
    void setServidorVisualizando(Servidor servidorVisualizando);

    /**
     * @brief Métodos get e set para o atributo canalVisualizando
     */
    Canal getCanalVisualizando();
    void setCanalVisualizando(Canal canalVisualizando);

    /**
     * @brief Métodos get e set para o atributo estado
     */
    int getEstado();
    void setEstado(int estado);

    /**
     * @brief Métodos get e set para o atributo comando
     */
    std::string getComando();
    void setComando(std::string comando);

    /**
     * @brief Métodos get e set para o atributo participantesID
     */
    std::vector<int> getParticipantesID();
    void setParticipantesID(std::vector<int> participantesID);

    /**
     * @brief Método split. Ele serve para quebrar uma string em várias partes com base em um caractere delimitador
     * @param linha string original que deverá ser quebrada
     * @return retorna uma lista de strings contendo todas que foram geradas após a original ter sido quebrada
     */
    std::vector<std::string> split(const std::string &linha, char sep);

    /**
     * @brief Método escolher. 
     * Esse é o método principal do programa, ele é chamada uma única vez na classe main e serve para que o usuário digite qual comando deseja executar no sistema. 
     * A partir do comando digitado o sistema fará as operações necessárias.
     */
    void escolher();

    /**
     * @brief Método salvar.
     * Ele serve para executar os métodos privados salvarUsuarios() e salvarServidores().
     * Com isso as informações dos usuários e servidores serão salvos em disco.
    */
    void salvar();

    /**
     * @brief Método carregar.
     * Ele serve para carregar os dados salvos nos arquivos usuarios.txt e servidores.txt,
     * para que antes de qualquer comando ser executado, seja possível ter a garantia que todas as informações estão atualizadas.
    */
    void carregar();
};

#endif