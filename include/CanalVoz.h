#ifndef CANALVOZ_H
#define CANALVOZ_H

#include <iostream>
#include "Canal.h"
#include "Mensagem.h"

/**
 * @brief Essa é a classe CanalVoz que servirá para armazenar a última mensagem enviada em um servidor dentro de um canal específico
*/
class CanalVoz: public Canal
{
private:
    Mensagem ultimaMensagem;
public:

    /**
     * @brief Construtor e Destrutor da classe
    */
    CanalVoz();
    ~CanalVoz();
    
    /**
     * @brief Métodos get e set para o atributo ultimaMensagem
    */
    Mensagem getUltimaMensagem();
    void setUltimaMensagem(Mensagem ultimaMensagem);
};

#endif