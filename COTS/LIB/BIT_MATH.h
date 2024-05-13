/****************************************************************/
/******* Author    : Mahmoud Abdelraouf Mahmoud *****************/
/******* Date      : 26 Aug 2023                *****************/
/******* Version   : 0.2                        *****************/
/******* File Name : BIT_MATH.h                 *****************/
/****************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/**
 * @brief Set a specific bit in a register.
 *
 * This macro sets the specified bit at the given position in a register to 1.
 *
 * @param[in,out] REG The register in which to set the bit.
 * @param[in] BIT_NUMBER The position of the bit to set (0 to 31).
 */
#define SET_BIT(REG, BIT_NUMBER)  REG |= (1 << BIT_NUMBER)

/**
 * @brief Clear a specific bit in a register.
 *
 * This macro clears (sets to 0) the specified bit at the given position in a register.
 *
 * @param[in,out] REG The register in which to clear the bit.
 * @param[in] BIT_NUMBER The position of the bit to clear (0 to 31).
 */
#define CLR_BIT(REG, BIT_NUMBER)  REG &= ~(1 << BIT_NUMBER)

/**
 * @brief Toggle a specific bit in a register.
 *
 * This macro toggles (inverts) the state of the specified bit at the given position in a register.
 *
 * @param[in,out] REG The register in which to toggle the bit.
 * @param[in] BIT_NUMBER The position of the bit to toggle (0 to 31).
 */
#define TOG_BIT(REG, BIT_NUMBER)  REG ^= (1 << BIT_NUMBER)

/**
 * @brief Get the value of a specific bit in a register.
 *
 * This macro retrieves the value (0 or 1) of the specified bit at the given position in a register.
 *
 * @param[in] REG The register from which to get the bit value.
 * @param[in] BIT_NUMBER The position of the bit to get (0 to 31).
 * @return The value of the specified bit (0 or 1).
 */
#define GET_BIT(REG, BIT_NUMBER)  ((REG & (1 << BIT_NUMBER)) >> BIT_NUMBER)


#endif /* BIT_MATH_H_ */