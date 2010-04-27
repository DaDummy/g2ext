/** @page ext_daedalus G2Ext externals
 *
 *  G2Ext provides a set of new externals to help you improve your mods.
 *
 * @section ext_daedalus_float IEEE Float
 *
 * @code
 * // Creates a float out of a specified integer
 * func int ex_fmk(var int a);
 * @endcode
 * 
 * @code
 * // Converts a specified float to an integer
 * func int ex_ftoi(var int a);
 * @endcode
 *
 * @code
 * // Adds the specified floats (a + b)
 * func int ex_fadd(var int a, var int b);
 * @endcode
 *
 * @code
 * // Subtracts the specified floats (a - b)
 * func int ex_fsub(var int a, var int b);
 * @endcode
 *
 * @code
 * // Multiplies the specified floats (a * b)
 * func int ex_fmul(var int a, var int b);
 * @endcode
 *
 * @code
 * // Divides the specified floats (a / b)
 * func int ex_fdiv(var int a, var int b);
 * @endcode
 *
 * @code
 * // Returns the remainder of the specified floats
 * func int ex_frem(var int a, var int b);
 * @endcode
 *
 * @code
 * // Returns the square root of the specified float
 * func int ex_fsqrt(var int a);
 * @endcode
 *
 * @code
 * // rounds the float (all after comma digits will be zero)
 * func int ex_frnd(var int a);
 * @endcode
 *
 * @code
 * // Returns 1 if float 'a' is equal the corresponding value 'b', and 0 otherwise.
 * func int ex_feq(var int a, var int b);
 * @endcode
 *
 * @code
 * // Returns 1 if float 'a' is less than or equal the corresponding value 'b', and 0 otherwise.
 * func int ex_fle(var int a, var int b);
 * @endcode
 *
 * @code
 * // Returns 1 if float 'a' is less than the corresponding value 'b', and 0 otherwise.
 * func int ex_flt(var int a, var int b);
 * @endcode
 *
 * @section ext_daedalus_array Arrays
 *
 * @code
 * // Creates an array. Returns the array instance. -1 in case the array creation failed.
 * func int iadim(var int size, var int dimensions);
 * @endcode
 *
 * @code
 * // Resizes an array. Returns false in case the action failed.
 * func int iaredim(var int instance, var int size);
 * @endcode
 *
 * @code
 * // Destroys array. Always returns 0.
 * func int iafree(var int instance);
 * @endcode
 *
 * @code
 * // Returns data from array.
 * func int iaget(var int instance, var int idx);
 * @endcode
 *
 * @code
 * // Sets data into array. Returns true if successful.
 * func int iaget(var int instance, var int idx, var int data);
 * @endcode
 *
 */