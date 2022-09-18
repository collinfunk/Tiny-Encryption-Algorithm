#ifndef _TEA_H_
#define _TEA_H_

#include <stdint.h>

void tea_encrypt(uint32_t *v, uint32_t *k);
void tea_decrypt(uint32_t *v, uint32_t *k);


#endif

