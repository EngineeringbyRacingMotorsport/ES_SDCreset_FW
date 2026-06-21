#include <f2p.h>

void DMA2DICCF(DICCF_t *DICCF, uint32_t *buffer){
	DICCF->SfSHU = buffer[0];
}

void DIG2DICCF(DICCF_t *DICCF){
	DICCF->SfERRbms     = HAL_GPIO_ReadPin(GPIOC, SfERRbms_Pin   );
	DICCF->SfERRimd     = HAL_GPIO_ReadPin(GPIOC, SfERRimd_Pin   );
	DICCF->SfLCHebms    = HAL_GPIO_ReadPin(GPIOA, SfLCHebms_Pin  );
	DICCF->SfLCHeimd    = HAL_GPIO_ReadPin(GPIOA, SfLCHeimd_Pin  );
	DICCF->SfINTresbut  = HAL_GPIO_ReadPin(GPIOA, SfINTresbut_Pin);
	DICCF->SfSDCbms     = HAL_GPIO_ReadPin(GPIOA, SfSDCbms_Pin   );
	DICCF->SfSDCimd     = HAL_GPIO_ReadPin(GPIOA, SfSDCimd_Pin   );
};

void DICCF2DICCP(DICCF_t *DICCF, DICCP_t *DICCP) {
	DICCP->SpERRbms      = !DICCF->SfERRbms;
	DICCP->SpERRimd      = !DICCF->SfERRimd ;
	DICCP->SpLCHebms     = !DICCF->SfLCHebms;
	DICCP->SpLCHeimd     = !DICCF->SfLCHeimd;
	DICCP->SpINTresbut   = DICCF->SfINTresbut;
	DICCP->SpSDCbms      = !DICCF->SfSDCbms;
	DICCP->SpSDCimd      = !DICCF->SfSDCimd ;
	DICCP->SpSHU		 = ((DICCF->SfSHU*3.3)/4095)/(0.130*100)*1000 ;
};
