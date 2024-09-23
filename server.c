#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int s = socket(2, 1, 0);

    struct sockaddr_in addr = {0};
    addr.sin_family = 2;
    addr.sin_port = htons(25565); // ports/Порт
    addr.sin_addr.s_addr = 0;

    bind(s, &addr, 16);
    listen(s, 10);

    int a = accept(s, 0, 0);

    while (true) {
        char str[1000];
        read(a, str, 1000);
        write(1, str, strlen(str));
        putchar('\n');
    }
}

