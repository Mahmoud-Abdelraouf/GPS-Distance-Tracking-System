// ************************************************************
// ********** Name    : ASU_EMBEDDED_TEAM_NO?!      ***********
// ********** Date    : 14/04/2023                  ***********
// ********** SWC     : LIB_BIT_MATH                ***********
// ********** Version : 1.0                         ***********
// ************************************************************
#ifndef BIT_MATH_H
#define BIT_MATH_H


/** \brief
 *
 * \param
 * \return
 *
 */
#define SET_BIT(REG,BIT_NUMBER) REG|=(1<< BIT_NUMBER)

/** \brief
 *
 * \param
 * \return
 *
 */
#define CLR_BIT(REG,BIT_NUMBER) REG&=~(1<< BIT_NUMBER)

/** \brief
 *
 * \param
 * \return
 *
 */
#define TOG_BIT(REG,BIT_NUMBER) REG^=(1<< BIT_NUMBER)

/** \brief
 *
 * \param
 * \return
 *
 */
#define GET_BIT(REG,BIT_NUMBER) ((REG & (1<< BIT_NUMBER))>>BIT_NUMBER)



#endif
