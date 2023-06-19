#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <iostream>

class Mensagem
{
private:
    std::string dataHora;
    int enviadaPor;
    std::string conteudo;
public:
    Mensagem();
    ~Mensagem();
};

#endif