#include "tea.h"

void tea_encrypt(uint32_t v[2], uint32_t k[4]) {
    uint32_t v0 = v[0];     /* set temp variables */
    uint32_t v1 = v[1];

    uint32_t sum=0;         /* set sum to zero */
    uint32_t i;             /* loop counter */

    uint32_t delta=0x9e3779b9; /* delta value */

    uint32_t k0=k[0]; /* setup keys */
    uint32_t k1=k[1];
    uint32_t k2=k[2]; 
    uint32_t k3=k[3];

    for (i=0; i < 32; i++) {
        sum += delta;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }
    
    /* store values back in v */
    v[0]=v0;
    v[1]=v1;
}

void tea_decrypt(uint32_t *v, uint32_t *k) {
    uint32_t v0 = v[0];     /* set temp variables */
    uint32_t v1 = v[1];

    uint32_t sum=0xC6EF3720; /* set sum to 0xC6EF3720 */
    uint32_t i;             /* loop counter */

    uint32_t delta=0x9e3779b9; /* delta value */

    uint32_t k0=k[0]; /* setup keys */
    uint32_t k1=k[1];
    uint32_t k2=k[2]; 
    uint32_t k3=k[3];

    for (i=0; i < 32; i++) {
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum -= delta;
    }
    
    /* store values back in v */
    v[0]=v0;
    v[1]=v1;
}
