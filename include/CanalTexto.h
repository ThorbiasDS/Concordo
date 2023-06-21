#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <iostream>
#include <vector>
#include "Canal.h"
#include "Mensagem.h"

class CanalTexto: public Canal
{
private:
    std::vector <Mensagem> mensagens;
public:
    CanalTexto();
    ~CanalTexto();
    std::vector <Mensagem> getMensagens();
    void setMensagens(std::vector <Mensagem> mensagens);
};

#endif