#include "stm32f0xx.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_usart.h"


int main(void)
{
	ErrorStatus HSIStartUpStatus;




	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	GPIO_InitTypeDef GPIOA_init_structure;

	GPIOA_init_structure.GPIO_Pin = GPIO_Pin_7;
	GPIOA_init_structure.GPIO_Mode = GPIO_Mode_OUT;
	GPIOA_init_structure.GPIO_OType = GPIO_OType_PP;
	GPIOA_init_structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOA_init_structure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_0);
	GPIOA_init_structure.GPIO_Pin = GPIO_Pin_9;
	GPIOA_init_structure.GPIO_Mode = GPIO_Mode_AF;
	GPIOA_init_structure.GPIO_OType = GPIO_OType_PP;
	GPIOA_init_structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOA_init_structure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_0);
	GPIOA_init_structure.GPIO_Pin = GPIO_Pin_10;
	GPIOA_init_structure.GPIO_Mode = GPIO_Mode_IN;
	GPIOA_init_structure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIOA_init_structure);


	USART_InitTypeDef USART_init_structure;
	USART_init_structure.USART_BaudRate = 115200;
	USART_init_structure.USART_WordLength = USART_WordLength_8b;
	USART_init_structure.USART_StopBits = USART_StopBits_1;
	USART_init_structure.USART_Parity = USART_Parity_No;
	USART_init_structure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_init_structure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART1, &USART_init_structure);

	USART_Cmd(USART1, ENABLE);



    while(1)
    {
    	USART_SendData(USART1, 'H');
    	USART_SendData(USART1, 'e');
    	USART_SendData(USART1, 'l');
    	USART_SendData(USART1, 'l');
    	USART_SendData(USART1, 'o');
    	USART_SendData(USART1, '\r');
    	USART_SendData(USART1, '\n');

    	GPIO_SetBits(GPIOA, GPIO_Pin_7);
    	for (int i=0; i<0x100000; i++);
    	GPIO_ResetBits(GPIOA, GPIO_Pin_7);
    	for (int i=0; i<0x100000; i++);
    }
}
