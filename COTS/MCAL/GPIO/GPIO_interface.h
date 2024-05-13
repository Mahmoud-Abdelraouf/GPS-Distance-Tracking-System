/**************************************************************/
/********** Name    : ASU_EMBEDDED_TEAM_NO?!		    ***********/
/********** Date    : 14/04/2023              	    ***********/
/********** SWC     : MCAL_GPIO                  	  ***********/
/********** Version : 1.0                    		    ***********/
/**************************************************************/
/**
 * @file gpio_definitions.h
 * @brief Definitions for GPIO port IDs, pin IDs, and pin configurations.
 */
#ifndef MCAL_GPIO_INTERFACE_C_H__
#define MCAL_GPIO_INTERFACE_C_H__

/** @defgroup GPIO_Definitions GPIO Definitions
 * Definitions for GPIO port IDs, pin IDs, and pin configurations.
 * @{
 */

/** @name GPIO Port IDs */
/** @{ */
#define GPIO_PORTA      0 /**< GPIO Port A */
#define GPIO_PORTB      1 /**< GPIO Port B */
#define GPIO_PORTC      2 /**< GPIO Port C */
#define GPIO_PORTD      3 /**< GPIO Port D */
#define GPIO_PORTE      4 /**< GPIO Port E */
#define GPIO_PORTF      5 /**< GPIO Port F */
/** @} */

/** @name GPIO Pin IDs */
/** @{ */
#define GPIO_PIN0       0 /**< GPIO Pin 0 */
#define GPIO_PIN1       1 /**< GPIO Pin 1 */
#define GPIO_PIN2       2 /**< GPIO Pin 2 */
#define GPIO_PIN3       3 /**< GPIO Pin 3 */
#define GPIO_PIN4       4 /**< GPIO Pin 4 */
#define GPIO_PIN5       5 /**< GPIO Pin 5 */
#define GPIO_PIN6       6 /**< GPIO Pin 6 */
#define GPIO_PIN7       7 /**< GPIO Pin 7 */
/** @} */

/** @name GPIO Pin Configurations */
/** @{ */
#define GPIO_OUTPUT     1 /**< GPIO Pin configured as output */
#define GPIO_INPUT      0 /**< GPIO Pin configured as input */
#define GPIO_HIGH       1 /**< High logic level for GPIO Pin */
#define GPIO_LOW        0 /**< Low logic level for GPIO Pin */
/** @} */

/** @} */

/**
 * @brief Initializes a GPIO port as digital input/output.
 *
 * This function enables the clock for the specified GPIO port, unlocks the GPIOCR
 * register, and sets the GPIO pins to work as digital I/O. The function returns an
 * error status if the input parameter is out of range or if there was an error in
 * the initialization process.
 *
 * @param[in] PortId The ID of the GPIO port to initialize.
 *
 * @return Returns E_OK if the port was successfully initialized, STD_TYPES_NOK
 *         otherwise.
 */
Std_ReturnType GPIO_Init(u8 PortId);
/**
 * @brief Sets the direction of a GPIO pin as input or output.
 *
 * This function sets the direction of a specific GPIO pin in a specified GPIO port as
 * either input or output. The function performs input validation to ensure that the
 * input parameters are within the correct range before setting the direction of the pin.
 * The function returns an error status to indicate whether the operation was successful
 * or not.
 *
 * @param[in] PortId The ID of the GPIO port to work with.
 * @param[in] PinId The ID of the GPIO pin to set its direction.
 * @param[in] PinDirection The direction of the GPIO pin (GPIO_u8_INPUT or GPIO_u8_OUTPUT).
 *
 * @return Returns E_OK if the pin direction was successfully set, STD_TYPES_NOK otherwise.
 */
Std_ReturnType GPIO_SetPinDirection(u8 PortId, u8 PinId, u8 PinDirection);

/**
 * @brief Sets the value of a specified GPIO pin.
 *
 * This function sets the value (either high or low) of a specified GPIO pin.
 *
 * @param PortId The ID of the GPIO port where the pin is located.
 * @param PinId The ID of the GPIO pin to set the value for.
 * @param PinValue The value to set for the pin. Should be either GPIO_HIGH or GPIO_LOW.
 *
 * @return Std_ReturnType Returns E_OK if the operation is successful, otherwise returns E_NOT_OK.
 */
Std_ReturnType GPIO_SetPinValue(u8 PortId, u8 PinId, u8 PinValue);

/**
 * @brief Gets the value of a specified GPIO pin.
 *
 * This function retrieves the value (either high or low) of a specified GPIO pin and stores it in the provided pointer.
 *
 * @param PortId The ID of the GPIO port where the pin is located.
 * @param PinId The ID of the GPIO pin to get the value for.
 * @param ReturnedPinValue Pointer to a variable where the retrieved pin value will be stored.
 *
 * @return Std_ReturnType Returns E_OK if the operation is successful, otherwise returns E_NOT_OK.
 */
Std_ReturnType GPIO_GetPinValue(u8 PortId, u8 PinId, u32 *ReturnedPinValue);

/**
 * @brief Sets the direction of all pins in a specified GPIO port.
 *
 * This function sets the direction of all pins in a specified GPIO port to either input or output.
 *
 * @param PortId The ID of the GPIO port whose pins' direction is to be set.
 * @param PortDirection The direction to set for all pins in the port. Should be either GPIO_INPUT or GPIO_OUTPUT.
 *
 * @return Std_ReturnType Returns E_OK if the operation is successful, otherwise returns E_NOT_OK.
 */
Std_ReturnType GPIO_SetPortDirection(u8 PortId, u8 PortDirection);

/**
 * @brief Sets the value of all pins in a specified GPIO port.
 *
 * This function sets the value (either high or low) of all pins in a specified GPIO port.
 *
 * @param PortId The ID of the GPIO port whose pins' value is to be set.
 * @param PortValue The value to set for all pins in the port. Should be either GPIO_LOW or GPIO_HIGH.
 *
 * @return Std_ReturnType Returns E_OK if the operation is successful, otherwise returns E_NOT_OK.
 */
Std_ReturnType GPIO_SetPortValue(u8 PortId, u8 PortValue);

/**
 * @brief Gets the value of all pins in a specified GPIO port.
 *
 * This function retrieves the value of all pins in a specified GPIO port and stores it in the provided pointer.
 *
 * @param PortId The ID of the GPIO port whose pins' value is to be retrieved.
 * @param ReturnedPortValue Pointer to a variable where the retrieved port value will be stored.
 *
 * @return Std_ReturnType Returns E_OK if the operation is successful, otherwise returns E_NOT_OK.
 */
Std_ReturnType GPIO_GetPortValue(u8 PortId, u32 *ReturnedPortValue);
							
/**
 * @brief Toggles the value of a specified GPIO pin.
 *
 * This function toggles the value (either high to low or low to high) of a specified GPIO pin.
 *
 * @param PortId The ID of the GPIO port where the pin is located.
 * @param PinId The ID of the GPIO pin to toggle the value for.
 *
 * @return Std_ReturnType Returns E_OK if the operation is successful, otherwise returns E_NOT_OK.
 */
Std_ReturnType GPIO_TogglePinValue(u8 PortId, u8 PinId);

#endif /* MCAL_GPIO_INTERFACE_C_H__ */