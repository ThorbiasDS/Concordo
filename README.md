# Concordo
## Mini clone do Discord utilizando apenas comandos de texto feito em C++

### Autor: Tobias Daniel Siqueira

### Descrição do projeto

Este projeto foi proposto na disciplina Liguagem de Programação 1, do curso de Bacharelado em Tecnologia da Informação do IMD/UFRN.
Ele tem como objetivo a criação de um mini clone do Discord utilizando apenas comandos de texto. O usuário deve digitar os comandos no terminal e o sistema emitirá uma resposta de acordo com o que foi pedido.
Esta aplicação não trabalha com recursos de rede nem de voz. A classe CanalVoz armazena apenas a última mensagem enviada.
A entrega do projeto foi dividida em três partes, com a primeira contendo apenas a implementação das funções referentes aos Usuários e Servidores.

### Comandos de Usuários e Servidores

Abaixo estão listados os comandos referentes às funções de Usuários e Servidores

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