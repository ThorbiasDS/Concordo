# Concordo
## Mini clone do Discord utilizando apenas comandos de texto feito em C++

### Autor: Tobias Daniel Siqueira | Turma: DIM0120 - LINGUAGEM DE PROGRAMAÇÃO I - T02 (2023.1)

#### Descrição do projeto

Este projeto foi proposto na disciplina Linguagem de Programação 1, do curso de Bacharelado em Tecnologia da Informação do IMD/UFRN.

Ele tem como objetivo a criação de um mini clone do Discord utilizando apenas comandos de texto. O usuário deve digitar os comandos no terminal e o sistema emitirá uma resposta de acordo com o que foi pedido.

Esta aplicação não trabalha com recursos de rede nem de voz. A classe CanalVoz armazena apenas a última mensagem enviada.
A entrega do projeto foi dividida em três partes, com a primeira contendo apenas a implementação das funções referentes aos Usuários e Servidores, a segunda com as funções referentes aos Canais e a terceira com a persistência dos dados no disco do computador.

#### Comandos de Usuários e Servidores

Abaixo estão listados os comandos referentes à primeira parte do projeto, ou seja as funções de Usuários e Servidores.

- quit
- create-user *email* *senha_sem_espacos* *nome com espaços*
- login *email* *senha*
- disconnect
- create-server *nome*
- set-server-desc *nome* "*descricao*"
- set-server-invite-code *nome* *codigo*
- list-servers
- remove-server *nome*
- enter-server *nome*
- leave-server
- list-participants

#### Comandos de Canais

Já neste tópico, estão listados os comandos referentes à segunda parte do projeto, ou seja as funções de Canais.

- list-channels
- create-channel *nome* *tipo*
- enter-channel *nome*
- leave-channel
- send-message *mensagem a ser enviada*
- list-messages

#### Como compilar e rodar o programa

Para compilar o programa é necessário estar com CMake instalado em seu computador. Após instalado você deve entrar na pasta do projeto em rodar o comando *cmake .* para que a ferramenta crie os arquivos necessários para a compilação. Depois disso, utilize o comando *make* para que o arquivo executável seja gerado.

Feito isso, execute o arquivo *./program* para que o programa inicie. Por fim, basta usar o teclado para digitar os comandos ou o arquivo scripts.txt que já contêm comandos, fazendo *./program < scripsts.txt* para que eles sejam passados ao programa.

#### Exemplos de entrada e saída 

    Entrada: create-user thor@marvel.ufrn.br Thor777 Thor Odinson
    Saída: "Usuário criado"

    Entrada: create-server vingadores
    Saída: "Servidor criado"

    Entrada: set-server-invite-code vingadores 111
    Saída: "Código de convite do servidor 'vingadores' modificado"

    Entrada: remove-server vingadores
    Saída: "Servidor 'vingadores' removido"

    Entrada: enter-channel escarlate
    Saída: "Entrou no canal 'escarlate'"

    Entrada: leave-channel
    Saída: "Saindo do canal 'escarlate'"

#### Limitações e dificuldades

Esta versão do Concordo está com alguns vazamentos, o arquivo de scripts não está muito completo e a persistência de dados no disco não foi terminada.
