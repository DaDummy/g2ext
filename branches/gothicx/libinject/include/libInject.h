#ifndef __LIBINJECT_H__
#define __LIBINJECT_H__
/*
        libInject


        Copyright (c) 2008-2010, Daniel Diepold

        All Rights reserved.

        THE WORK (AS DEFINED BELOW) IS PROVIDED
        UNDER THE TERMS OF THIS CREATIVE COMMONS
        PUBLIC LICENSE ("CCPL" OR "LICENSE").
        THE WORK IS PROTECTED BY COPYRIGHT AND/OR
        OTHER APPLICABLE LAW. ANY USE OF THE WORK
        OTHER THAN AS AUTHORIZED UNDER THIS LICENSE
        OR COPYRIGHT LAW IS PROHIBITED.

        BY EXERCISING ANY RIGHTS TO THE WORK PROVIDED
        HERE, YOU ACCEPT AND AGREE TO BE BOUND BY THE
        TERMS OF THIS LICENSE. TO THE EXTENT THIS
        LICENSE MAY BE CONSIDERED TO BE A CONTRACT,
        THE LICENSOR GRANTS YOU THE RIGHTS CONTAINED
        HERE IN CONSIDERATION OF YOUR ACCEPTANCE OF
        SUCH TERMS AND CONDITIONS.

        Full license at http://creativecommons.org/licenses/by-nc-sa/3.0/
*/

#include "common/osheader.h"


#define IMPORT __declspec(dllimport)

enum eRegs
{
    ER_EAX = 0,
    ER_ECX = 1,
    ER_EDX = 2,
    ER_EBX = 3,
    ER_ESP = 4,
    ER_EBP = 5,
    ER_ESI = 6,
    ER_EDI = 7,
    ER_MAX = 8
};

struct sRegs
{
    int* EIP;
    int EDI,
        ESI,
        EBP,
        ESP,
        EBX,
        EDX,
        ECX,
        EAX;
};

extern "C"
{
namespace libInject
{
    /**
    *   \brief  Places a function hook.
    *
    *   \anchor INTOPS \attention
    *           Callbacks \b with \b parameters must always be declared as follows:
    *           - with \b stdcall calling convention
    *           - the parameters must be declared as \b references
    *   \attention \n
    *           Before the callback's execution, the following operations are performed:
    *           - The registers EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI will be saved
    *           - The parameters of the hooked function are put as references onto the stack
    *           - The register EAX gets overwritten with the callback address
    *   \attention \n
    *           After the callback's execution, the following operations are performed:
    *           - The registers EAX, ECX, EDX, EBX, ESP, EBP, ESI, EDI will be recovered
    *
    *   \param  Destination The function to be hooked.
    *   \param  CallBack The callback function.
    *   \param  WantRegisterAccess Gives access to the saved registers over a sRegs-struct.
    *   \param  ParamCount The target function's parameter count.
    *   \return a operation handle.
    *
    *           \b Sample:
    *   \code
    *           int sampleclass::samplefunc(char* text, int& a, int b)
    *           {
    *               //does something...
    *           };
    *
    *           static __stdcall void foo::cbfunc(char** text, int** a, int& b)
    *           {
    *           };
    *
    *           void foo()
    *           {
    *               CreateHook(&samplefunc, &cbfunc, false, 3);
    *           };
    *   \endcode
    *
    *           \b Sample (with register access):
    *   \code
    *           int sampleclass::samplefunc(char* text, int& a, int b)
    *           {
    *               //does something...
    *           };
    *
    *           static __stdcall void foo::cbfunc(csRegs& Register, char** text, int** a, int& b)
    *           {
    *               static foo MyClass;
    *               //Makes this to MyClass
    *               Register.ECX = &MyClass;
    *           };
    *
    *           void foo()
    *           {
    *               CreateHook(&samplefunc, &cbfunc, true, 3);
    *           };
    *   \endcode
    **/
    int IMPORT CreateHook(void* Destination, void* CallBack, bool WantRegisterAccess = false, size_t ParamCount = 0);

    /**
    *   \brief  Places a conditional function hook.
    *
    *   \remarks
    *           The callback function is called only, if the following condition is fulfilled:
    *           - \a Caller == \a ConditionVar
    *
    *   \attention
    *           Look at \ref INTOPS "this".
    *
    *   \param  Destination The function to be hooked.
    *   \param  CallBack The callback function.
    *   \param  ConditionVar The calling condition value.
    *   \param  WantRegisterAccess Gives access to the saved registers over a sRegs-struct.
    *   \param  ParamCount The target function's parameter count.
    *   \return a operation handle.
    *
    *           \b Sample:
    *   \code
    *           int sampleclass::samplefunc(char* text, int& a, int b)
    *           {
    *               //does something...
    *           };
    *
    *           void sampleclass::caller()
    *           {
    *               int a = 1;
    *               this->samplefunc("test", a, 0);
    *           };
    *
    *           static __stdcall void foo::cbfunc(char** text, int** a, int& b)
    *           {
    *           };
    *
    *           void foo()
    *           {
    *               ConditionalHook_C(&samplefunc, &cbfunc, &caller, false, 3);
    *           };
    *   \endcode
    *
    *   \sa CreateHook, ConditionalHook_C_N
    **/
    int IMPORT ConditionalHook_C(void* Destination, void* CallBack, void* ConditionVar, bool WantRegisterAccess = false, size_t ParamCount = 0);

    /**
    *   \brief  Places a conditional function hook.
    *
    *   \remarks
    *           Same as #ConditionalHook_C, with the following condition:
    *           - \a Caller != \a ConditionVar
    *
    *   \sa CreateHook, ConditionalHook_C
    **/
    int IMPORT ConditionalHook_C_N(void* Destination, void* CallBack, void* ConditionVar, bool WantRegisterAccess = false, size_t ParamCount = 0);

    /**
    *   \brief  Places a conditional function hook.
    *
    *   \remarks
    *           The callback function is called only, if the following condition is fulfilled:
    *           - \a Register == \a ConditionVar
    *
    *   \attention
    *           Look at \ref INTOPS "this".
    *
    *   \param  Destination The function to be hooked.
    *   \param  CallBack The callback function.
    *   \param  Register The register to compare with.
    *   \param  ConditionVar The calling condition value.
    *   \param  WantRegisterAccess Gives access to the saved registers over a sRegs-struct.
    *   \param  ParamCount The target function's parameter count.
    *   \return a operation handle.
    *
    *           \b Sample (Register ECX):
    *   \code
	*           int sampleclass::samplefunc(char* text, int& a, int b)
    *           {
    *               //does something...
    *           };
    *
    *           static __stdcall void foo::cbfunc(char** text, int** a, int& b)
    *           {
    *           };
    *
    *           void foo()
    *           {
    *               sampleclass* bar = new sampleclass;
    *               ConditionalHook_R(&samplefunc, &cbfunc, ER_ECX, bar, false, 3);
    *               bar->samplefunc("test", a, 0);
    *           };
    *   \endcode
    *
    *   \sa CreateHook
    **/
    int IMPORT ConditionalHook_R(void* Destination, void* CallBack, eRegs Register, int ConditionVar, bool WantRegisterAccess = false, size_t ParamCount = 0);

    /**
    *   \brief  Replaces a function by your own.
    *
    *   \attention
    *           The function to replace with must be declared just like the original function.
    *
    *   \param  Destination The function to replace.
    *   \param  NewFunc The function to replace with.
    *   \return a operation handle.
    *
    *           \b Sample:
    *   \code
    *           int __cdecl sampleclass::samplefunc(char* text, int& a, int b)
    *           {
    *               //does something...
    *           };
    *
    *           static __cdecl int foo::NewFunc(char* text, int& a, int b)
    *           {
    *               //does something else...
    *           };
    *
    *           void foo()
    *           {
    *               ReplaceFunction(&samplefunc, &NewFunc);
    *           };
    *   \endcode
    **/
    int IMPORT ReplaceFunction(void* Destination, void* NewFunc);

    /**
    *   \brief  Redirects a function call.
    *
    *   \attention
    *           The function to replace with must be declared just like the original function.
    *
    *   \param  Destination The call to redirect.
    *   \param  NewFunc The function to redirect to.
    *   \return a operation handle.
    *
    *           \b Sample:
    *   \code
    *           int __cdecl sampleclass::samplefunc(char* text, int& a, int b)
    *           {
    *               //does something...
    *           };
    *
    *           static __cdecl int foo::NewFunc(char* text, int& a, int b)
    *           {
    *               //does something else...
    *           };
    *
    *           // some assembler code
    *           0x452475    inc edx
    *           0x452476    call 0x402416 (sampleclass::samplefunc)
    *
    *           void foo()
    *           {
    *               RedirectCall( (void*)0x452476, &NewFunc );
    *           };
    *   \endcode
    **/
    int IMPORT RedirectCall(void* Destination, void* NewFunc);

    /**
    *   \brief  Performs a operation rollback.
    *
    *   \param  hOperation A handle to the operation to undo.
    **/
    void IMPORT PerformRollback(int hOperation);

    /**
    *   \brief Patches secured memory, application code for example.
    *
    *   \param  Destination The memory address to patch.
    *   \param  Buffer The patch data buffer.
    *   \param  Length The buffer length.
    *   \return Success
    **/
    bool IMPORT PatchSecuredMem(void* Destination, const void* Buffer, size_t Length);

    /**
    *   \brief Initializes secured memory, application code for example.
    *
    *   \param  Destination The memory address to initialize.
    *   \param  Length The length of memory to initialize.
    *   \param  Value The initialization value.
    *   \return Success
    **/
    bool IMPORT EraseSecuredMem(void* Destination, size_t Length, int Value);
}
}

#endif // __LIBINJECT_H__
