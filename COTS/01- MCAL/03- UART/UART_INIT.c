void UART_INIT(){
  SYSCTL_RCGCUART_R |= 0x01;            // activate UART0
  SYSCTL_RCGCGPIO_R |= 0x01;            // activate port A //gpio team might provide a function for that
  while((SYSCTL_PRGPIO_R&0x01) == 0);   //gpio team might make a function for both
  
  UART0_CTL_R &= ~UART_CTL_UARTEN;      // disable UART 3obal ma azbt tazbetate //uartctl responsible for uart control //lazem a3mlo clear abl ma azbt ay haga
  UART0_IBRD_R = 104;                    // IBRD = int(16,000,000 / (16 * 9600)) = int(104.166)
  UART0_FBRD_R = 11;                     // FBRD = int(0.16667 * 64 + 0.5) = 8
                                        // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART0_LCRH_R = (UART_LCRH_WLEN_8|UART_LCRH_FEN); //8 bit, no parity not equal //msh fahmah awee
  UART0_CTL_R |= UART_CTL_UARTEN;       // enable UART
  GPIO_PORTA_DEN_R |= 0x03;             // enable digital I/O on PA1-0
                                        // configure PA1-0 as UART
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00)+0x00000011; //aseeb el qayam el 3ala ba2e port a + amsah el qayam bta3t a0 w a1 w ba3d kda a5lehom bwhayed
  GPIO_PORTA_AMSEL_R &= ~0x03;          // disable analog functionality on PA A1 A0
}

