---
layout: post
title: "Pais e Filhos"
description: "Project Description Here²"
date: 2016-10-04
tags: [thread, fork]
comments: true
share: true
---

<div class="full-width-video">
  <iframe width="1280" height="720" src="https://www.youtube.com/embed/gHNesvaibpY?rel=0" frameborder="0" allowfullscreen></iframe>
</div>

---


```cpp
...
father = getppid();

for (i = 1; i <= 40; i++) {
    sleep(1);

    // Nascem os filhos
    // Filho1
    if (i == 18 && idFilho1 == 0) {
        idFilho1 = fork();
        if (idFilho1 == 0) {
            son1 = getpid();
            idFilho2 = 1;
            idFilho3 = 1;
            printf("Nasce o Filho1\n");
        }
    }
...
```

O código acima verifica se o idFilho1 é zero, se verdadeiro é sinal que estamos no Filho 1, sendo assim pegamos o PID do filho 1 através do método `getpid()` e a atribuímos em uma variável, o `idFilho2 = 1` e o `idFilho3 = 1` é para garantir que o Filho não entre no condicionais dos filhos 2 e 3, pois inicialmente o PID é zero e nesse caso deixaria aberto para o filho 1 ter seu propio filho 2.

A ideia do código acima é replicada nos outros 2 filhos como pode-se ver no código abaixo:

```cpp
...
// Filho2
if (i == 20 && idFilho2 == 0) {
    idFilho2 = fork();
    if (idFilho2 == 0) {
        son2 = getpid();
        idFilho3 = 1;
        idFilho2 = 1;
        printf("Nasce o Filho2\n");
    }
}
// Filho3
if (i == 21 && idFilho3 == 0) {
    idFilho3 = fork();
    if (idFilho3 == 0) {
        son3 = getpid();
    }
}
...
```

---
```cpp
...
// Informa Pai
if (getppid() == father) {
    printf("processo pai ID %d tem %d anos\n", getppid(),i);
}
// Filho1
if (son1 == getpid() && i <= 23 && i > 18) {
    printf("processo filho1 ID %d tem %d anos\n", getpid(), i - 18);

    // Morre filho1
    if (i == 23) {
        printf("Morreu filho1 id %d\n", getpid());
        kill(getpid(), SIGKILL);
    }
}

// Filho2
if (son2 == getpid() && i <= 40 && i > 20) {
    printf("processo filho2 ID %d tem %d anos\n", getpid(), i - 20);

    // Neto01
    if (i==35) {
        idNeto1 = fork();
        if (idNeto1 == 0) {
            gson = getpid();
            printf("Nasce o Neto1\n");
        }
    }
    // Morre pai
    if (i == 33) {
        printf("Morreu pai id %d\n", getppid());
        kill(getppid(), SIGKILL);
    }
    // Morre filho2
    if (i == 40) {
        printf("Morreu filho2 id %d\n", getpid());
        kill(getpid(), SIGKILL);
    }
}
...
```

No código acima nós garantimos que cada parente, seja ele pai, filho ou neto execute apenas a mensagem e os comandos a eles destinados, observa-se também a criação do `neto1` já dentro do `filho2`. O comando para encerrar a execução do pai encontra-se no `filho2`, já que este será o parente com maior tempo de vida.

Abaixo segue o código destinado aos netos, a ideia é basicamente a mesma do código abaixo.

```cpp
...
// Neto01
if (gson == getpid() && i <= 40 && i > 35) {
    printf("processo neto1 ID %d tem %d anos\n", getpid(), i - 35);
    if (i == 40) {
        printf("Morreu neto1 id %d\n", getpid());
        kill(getpid(), SIGKILL);
    }
}
// Neto02
if (gson2 == getpid() && i <= 34 && i > 24) {
    printf("processo neto2 ID %d tem %d anos\n", getpid(), i - 24);
    if (i == 34) {
        printf("Morreu neto2 id %d\n", getpid());
        kill(getpid(), SIGKILL);
    }
}
...
```
