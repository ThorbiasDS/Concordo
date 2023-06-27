#ifndef CANAL_H
#define CANAL_H

#include <iostream>

/**
 * @brief Essa é a Canal que servirá como classe base para as classes CanalTexto e CanalVoz
*/
class Canal
{
private:
    std::string nome;
public:

    /**
     * @brief Construtor e Destrutor da classe
    */
    Canal();
    ~Canal();
    
    /**
     * @brief Métodos get e set da classe para o atributo nome
    */
    std::string getNome();
    void setNome(std::string nome);
};

#endif