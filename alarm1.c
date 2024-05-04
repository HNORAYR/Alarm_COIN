#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void alarm_handler(int sig);

int main() {
    signal(SIGALRM, alarm_handler);
    int seconds;

    printf("Enter number of seconds to set the alarm: ");
    scanf("%d", &seconds);

    alarm(seconds);
    printf("Alarm set for %d seconds. Waiting...\n", seconds);

    while(1)
        ;

    return 0;
}

void alarm_handler(int sig) {
    printf("Alarm! Wake up!\n");
    system("aplay signal_coin.wav");    
    exit(0);
}

