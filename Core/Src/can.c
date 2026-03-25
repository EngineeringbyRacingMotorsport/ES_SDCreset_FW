#include <can.h>

void CAN_Msg_Maker(DICCP_t *DICCP, uint8_t *Msg)
{
	Msg[0] |= ((DICCP->SpERRbms    & 0x01) << 0);
	Msg[0] |= ((DICCP->SpERRimd    & 0x01) << 1);
	Msg[0] |= ((DICCP->SpLCHebms   & 0x01) << 2);
	Msg[0] |= ((DICCP->SpLCHeimd   & 0x01) << 3);
	Msg[0] |= ((DICCP->SpINTresbut & 0x01) << 4);
	Msg[0] |= ((DICCP->SpSDCbms    & 0x01) << 5);
	Msg[0] |= ((DICCP->SpSDCimd    & 0x01) << 5);

	Msg[1] |= ((DICCP->SpSHU     & 0x00FF) << 0);
	Msg[2] |= ((DICCP->SpSHU     & 0xFF00) >> 8);
}

HAL_StatusTypeDef CAN_Send(FDCAN_HandleTypeDef *hfdcan, uint32_t id, uint8_t *data, uint32_t len) {
    FDCAN_TxHeaderTypeDef txHeader;
    txHeader.Identifier = id;
    txHeader.IdType = FDCAN_STANDARD_ID;
    txHeader.TxFrameType = FDCAN_DATA_FRAME;
    txHeader.DataLength = len;
    txHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    txHeader.BitRateSwitch = FDCAN_BRS_OFF;
    txHeader.FDFormat = FDCAN_CLASSIC_CAN;
    txHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    txHeader.MessageMarker = 0;

    return HAL_FDCAN_AddMessageToTxFifoQ(hfdcan, &txHeader, data);
}

void CAN_Init_Custom(FDCAN_HandleTypeDef *hfdcan) {
    FDCAN_FilterTypeDef sFilterConfig;

    // 1. Configuració de filtre per acceptar-ho TOT
    sFilterConfig.IdType = FDCAN_STANDARD_ID;
    sFilterConfig.FilterIndex = 0;
    sFilterConfig.FilterType = FDCAN_FILTER_RANGE;
    sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    sFilterConfig.FilterID1 = 0x000;
    sFilterConfig.FilterID2 = 0x7FF;

    if (HAL_FDCAN_ConfigFilter(hfdcan, &sFilterConfig) != HAL_OK) Error_Handler();

    // 2. Activar la interrupció de la FIFO 0
    if (HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK) Error_Handler();

    // 3. Arrencar el perifèric
    if (HAL_FDCAN_Start(hfdcan) != HAL_OK) Error_Handler();
}
