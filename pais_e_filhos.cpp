#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <csignal>
#include <errno.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int i;
    pid_t idFilho1, idFilho2, idFilho3, idNeto1, idNeto2;
    int father, son1 = 9, son2 = 9, son3 = 9, gson = 9, gson2 = 9;
    int statusRetorno;
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

        // Informa pai
        if (getppid() == father) {
            printf("processo pai ID %d tem %d anos\n", getppid(), i);
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
            printf("processo filho2 ID %d tem %d anos\n", getpid(),i-20);
            // Neto01
            if (i == 35) {
                idNeto1 = fork();
                if (idNeto1 == 0) {
                    gson = getpid();
                    printf("Nasce o Neto1\n");
                }
            }
            // Morre pai
    		if (i == 33) {
    			printf("Morreu pai id %d\n",getppid());
    			//wait(0);

    			kill(getppid(), SIGKILL);
    		}
            // Morre filho2
    		if (i == 40) {
    			printf("Morreu filho2 id %d\n",getpid());
    			kill(getpid(), SIGKILL);
    		}
        }

        // Filho3
        if (son3 == getpid() && i <= 26 && i > 21) {
            printf("processo filho3 ID %d tem %d anos\n", getpid(),i-21);
            // Neto01
            if (i == 24) {
                idNeto2 = fork();
                if (idNeto2 == 0) {
                    gson2 = getpid();
                    printf("Nasce o Neto2\n");
                }
            }
            // Morre filho3
            if (i == 26) {
                printf("Morreu filho3 id %d\n",getpid());
                kill(getpid(), SIGKILL);
            }
        }

        // Neto01
        if (gson == getpid() && i <= 40 && i > 35) {
            printf("processo neto1 ID %d tem %d anos\n", getpid(),i-35);
            if (i == 40) {
                printf("Morreu neto1 id %d\n",getpid());
                kill(getpid(), SIGKILL);
            }
        }

        // Neto02
        if (gson2 == getpid() && i <= 34 && i > 24) {
            printf("processo neto2 ID %d tem %d anos\n", getpid(),i-24);
            if (i == 34) {
                printf("Morreu neto2 id %d\n",getpid());
                kill(getpid(), SIGKILL);
            }
        }
    }

    return 0;
}
