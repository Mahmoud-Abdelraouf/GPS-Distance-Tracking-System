u8 UART_recieveByte(void){

while (UARTO_FR_R & 0x0010 != 0); //check if the buffor is empty 
return (UARTO_DR_R & OxFF);

}
