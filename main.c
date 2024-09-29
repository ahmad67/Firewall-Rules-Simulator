#include <stdio.h>
#include <string.h>

struct Rule {
    char ip[16];
    int port;
    int allow;  // 1 for allow, 0 for block
};

void apply_rule(struct Rule rule, char* packet_ip, int packet_port) {
    if (strcmp(rule.ip, packet_ip) == 0 && rule.port == packet_port) {
        if (rule.allow)
            printf("Packet allowed: IP %s, Port %d\n", packet_ip, packet_port);
        else
            printf("Packet blocked: IP %s, Port %d\n", packet_ip, packet_port);
    }
}

int main() {
    struct Rule rule1 = {"192.168.1.10", 80, 1};  // Allow
    struct Rule rule2 = {"192.168.1.20", 22, 0};  // Block
    
    // Example packet
    char packet_ip[] = "192.168.1.10";
    int packet_port = 80;

    printf("Simulating firewall...\n");
    apply_rule(rule1, packet_ip, packet_port);
    apply_rule(rule2, packet_ip, packet_port);

    return 0;
}
