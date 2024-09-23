#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdbool.h>

int main() {
    int s = socket(2, 1, 0);

    struct sockaddr_in addr = {0};
    addr.sin_family = 2;
    addr.sin_port = htons(25565);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // ip adress/ip адрес

    connect(s, &addr, 16);

    while (true) {
        char str[1000];
        scanf("%s", str);
        write(s, str, 1000);
    }
}

