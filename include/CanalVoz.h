#ifndef CANALVOZ_H
#define CANALVOZ_H

#include <iostream>
#include "Canal.h"
#include "Mensagem.h"

class CanalVoz: public Canal
{
private:
    Mensagem ultimaMensagem;
public:
    CanalVoz();
    ~CanalVoz();
};

#endif