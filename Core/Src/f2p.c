#include <f2p.h>

void DMA2DICCF(DICCF_t *DICCF, uint16_t *buffer){
	DICCF->TfSHU = buffer[0];
}

void DIG2DICCF(DICCF_t *DICCF){
	DICCF->TfDIGspre  = HAL_GPIO_ReadPin(GPIOA, TfDIGspre_Pin  );

};

void DICCF2DICCP(DICCF_t *DICCF, DICCP_t *DICCP) {
	DICCP->TpDIGspre   = DICCF->TfDIGspre  ;

};
