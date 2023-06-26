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

    std::string getDataHora();
    void setDataHora(std::string dataHora);

    int getEnviadaPor();
    void setEnviadaPor(int enviadaPor);
    
    std::string getConteudo();
    void setConteudo(std::string conteudo);
};

#endif