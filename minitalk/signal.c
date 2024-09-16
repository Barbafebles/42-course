
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigusr1(int signum) {
    (void)signum;  // Ignora el parámetro
    printf("Recibí SIGUSR1\n");
}

void handle_sigusr2(int signum) {
    (void)signum;  // Ignora el parámetro
    printf("Recibí SIGUSR2\n");
}

int main() {
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);

    printf("PID: %d\n", getpid());
    while (1) {
        pause(); // Espera a recibir una señal
    }
    return 0;
}

