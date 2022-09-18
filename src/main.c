#include <stdio.h>
#include <stdint.h>
#include "tea.h"


int main(int argc, char* argv[]) {
   
    // Enter plaintext here :)
    uint32_t v[2] = {0x00000000, 0x00000000};
    // Enter key here :)
    uint32_t k[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};
    
    uint32_t cyphertext[2];
    uint32_t recovered_plaintext[2];

    // Encrypt
    cyphertext[0] = v[0];
    cyphertext[1] = v[1];
    tea_encrypt(cyphertext, k);

    // Decrypt
    recovered_plaintext[0] = cyphertext[0];
    recovered_plaintext[1] = cyphertext[1];
    tea_decrypt(recovered_plaintext, k);

    // Print results
    printf("Plaintext: %08X%08X\n", v[0], v[1]);
    printf("Cyphertext: %08X%08X\n", cyphertext[0], cyphertext[1]);
    printf("Recovered plaintext: %08X%08X\n", recovered_plaintext[0], recovered_plaintext[1]);
    
    return 0;
}

