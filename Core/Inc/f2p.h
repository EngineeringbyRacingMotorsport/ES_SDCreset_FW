#ifndef f2p_h
#define f2p_h

#include "main.h"

void DMA2DICCF(DICCF_t *DICCF, uint16_t *buffer);
void DIG2DICCF(DICCF_t *DICCF);
void DICCF2DICCP(DICCF_t *DICCF, DICCP_t *DICCP);

#endif
