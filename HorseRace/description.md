O presente trabalho tem como finalidade a exposição dos conceitos vistos em sala de aula na disciplina de Sistemas Operacionais aplicados na elaboração de um Jogo – objeto de nossa proposta de trabalho. Neste segundo projeto da disciplina, conforme solicitado aos alunos, a proposta de trabalho deve envolver principalmente a manipulação de processos com o comando Fork, neste caso fazendo uso da BeagleBone Black. Descreveremos então nossa proposta, os requisitos, funcionalidades, e de que maneira serão usados os conhecimentos sobre Processos e Forks.

Como dito anteriormente, decidimos seguir o caminho dos Jogos. A nossa proposta de trabalho será de um jogo de apostas de corrida de cavalos. Como requisitos necessários para sua aplicação faremos uso de:

- BeagleBone Black
- Botão
- Led Comum
- Led Vermelho
- Resistores
- Potenciômetro

Antes de iniciar a corrida é preciso definir a quantidade de cavalos, para isso será utilizado o potenciômetro. A partir da regulagem do potenciômetro é definida a quantidade de corredores (no intervalo entre 2 e 4). O usuário saberá o número de corredores através do led rgb, que ficará azul para apenas 2 corredores, verde para 3 e vermelho para 4. Após selecionada a quantidade, deve ser pressionado o botão para dar início ao programa, o led vermelho acenderá, indicando que a corrida está em andamento. A corrida termina quando o primeiro corredor percorrer todo o trajeto, apagando assim o led vermelho e acendendo o RGB com a cor que representa o vencedor (1 - azul, 2 - verde, 3 - vermelho, 4 - branco).

Ao pressionar o botão, a aplicação reconhecerá a quantidade de competidores setados no potenciômetro e criará um processo para cada (2 a 4) utilizando o comando Fork. Cada processo é uma representação de um competidor. A execução de cada processo se dá gerando um número aleatório (sempre positivo a fim de se evitar corridas infinitas), que representa o seu deslocamento naquele intervalo de tempo (500ms), o qual é adicionado ao deslocamento total do competidor. O primeiro a percorrer todo o trajeto é o vencedor, acendendo o seu led correspondente.
