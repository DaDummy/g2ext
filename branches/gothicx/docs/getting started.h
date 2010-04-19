/** @page getting_started Getting Started
 *
 * @section startover_sec_00 Starting over - Introduction
 *
 * On this page, you can find various examples, snippets and information to help you getting started with G2Ext.<br />
 * If you don't think, this page is not enough help for you to start over with G2Ext, then <i>take a look at the SDK's examples folder</i>.<br />
 *
 * In case, that you still have absolutely no clue, questions or anything is unclear, just take a look at <a href="http://forum.worldofplayers.de/forum/forumdisplay.php?f=104" target="_blank">World of Gothic's Editing board</a>. Just go ahead and ask. The community won't bite (much...).<br />
 *
 * <br />
 * @section startover_sec_01 Starting over - Setting up a mod dll
 *
 * At first, you have to set up a new, empty dll project...<br />
 *
 * Step 1: <b>Create a new project.</b>
 * @image html new.jpg
 * <br />
 * Step 2: <b>Create a Win32 project.</b>
 * @image html dll1.jpg
 * <br />
 * @image html dll2.jpg
 * <br />
 * Step 2: <b>Select an empty DLL.</b>
 * @image html dll3.jpg
 * <br />
 * Step 3: <b>Create/add needed source files.</b><br />
 *
 * @image html dllAdd.jpg
 * <br />
 * @image html dllAddDlg.jpg
 * <br />
 *
 * @note Now, that you have set-up the new project, you have to create a dllmain.cpp and a msvc export definition (*.def) file.
 *
 * Step 4: <b>The base code.</b>
 *
 * <b>dllmain.cpp</b>:
 * @code
 *
 * #include "api/g2ext.h" // main G2Ext include
 *
 * // Tell the compiler that this is a g2ext mod
 * G2EXT_DECLARE_MOD;
 * 
 * // This Function is called when the gothic2.exe is beeing prepared (outgame)
 * HRESULT G2EXT_API G2Ext_ModPrepare(ICoreOutgame* pCore) 
 * {
 * 	// code	
 * 
 * 	return S_OK;
 * };
 * 
 * // This Function is called when g2ext is initializing inside the gothic2-process but before
 * // gothic2 itself starts initializing (ingame)
 * HRESULT G2EXT_API G2Ext_ModInit(ICoreIngame* pCore) 
 * {
 * 	// code
 * 	
 * 	return S_OK;
 * };
 * 
 * @endcode
 * 
 * <b>exports.def</b>:
 * @code
 * LIBRARY	"your_mod_dll_file_name_without_extension"
 * EXPORTS
 * 	G2Ext_ModVersion
 * 	G2Ext_ModPrepare
 * 	G2Ext_ModInit
 * @endcode
 * 
 *
 * Step 5: <b>Compiling the code.</b>
 *
 * @image html build.jpg
 * <br />
 *
 * @note: After project was build without errors, you can find the dll in the debug/release folder of your project.
 *
 * <br /><br />
 * @section startover_sec_02 Starting over - Using the callback system
 * 
 * G2Ext provides a callback system, which should be used for ingame functions. 
 * (Missing callbacks can be compensated with simple function hooks)
 * 
 * @bug: Please be aware, that, if you use hooks, it is impossible to hook in-function, because of a severe bug in libinject. You can only hook at the beginning of functions! (Will be fixed in next libinject version.)
 * 
 *
 * <b>The different callback types:</b>
 * @code
 * 	G2EXT_CB_ON_PAUSE
 * 	G2EXT_CB_ON_UNPAUSE
 * 	G2EXT_CB_ON_OPEN_LOADSCREEN
 * 	G2EXT_CB_ON_OPEN_SAVESCREEN
 * 	G2EXT_CB_ON_CLOSE_LOADSCREEN
 * 	G2EXT_CB_ON_CLOSE_SAVESCREEN
 * 	G2EXT_CB_ON_INGAME
 * 	G2EXT_CB_ON_RENDER
 * 	G2EXT_CB_ON_REGISTER_EXTERNALS
 * 	G2EXT_CB_ON_REGISTER_MENU_EXTERNALS
 * 	G2EXT_CB_ON_INIT_HUD
 * 	G2EXT_CB_ON_INPUT
 * 	G2EXT_CB_ON_DONE
 * 	G2EXT_CB_ON_LOAD_WORLD
 * 	G2EXT_CB_ON_REGISTER_CLASSES
 * @endcode
 *
 * <b>Example code:</b>
 * @code
 * #include "api/g2ext.h"
 * 
 * CCoreIngame* pCore = ...; // lets assume this has been initialized somehow...
 *
 * void __stdcall CallbackFunc(void) // this is a "standard" callback function. Watch out for different kinds of callback functions (see listing below).
 * {
 * 	// code
 * };
 * 
 * pCore->RegisterCallback(L"My callback", &CallbackFunc, G2EXT_CB_ON_RENDER, true); // Register the callback in the system
 * 
 * @endcode
 * 
 * @note Please be aware, that callback functions don't always share the same "standard" shape as above! There are exceptions:
 * Some callback types use parameters to hand instances and values over to the callback function.
 * 
 * @attention Using the wrong function type on your callback will make G2Ext crash!
 * 
 * @code
 * #include "api/g2/zcparser.h"
 * #include "api/g2/zcview.h"
 * 
 * // G2EXT_CB_ON_INIT_HUD
 * 
 * void __stdcall CallbackFunc(zCView* pView)
 * {
 * 	// code
 * }
 * 
 * //////////////////////////////////////////////////////
 * 
 * // G2EXT_CB_ON_REGISTER_EXTERNALS
 * // G2EXT_CB_ON_REGISTER_MENU_EXTERNALS
 * // G2EXT_CB_ON_REGISTER_CLASSES
 * 
 * void __stdcall CallbackFunc(zCParser* pView)
 * {
 * 	// code
 * }
 * 
 * //////////////////////////////////////////////////////
 * 
 * // G2EXT_CB_ON_INPUT
 * 
 * void __stdcall CallbackFunc(unsigned int uKey)
 * {
 * 	// code
 * }
 * 
 * @endcode
 * 
 * <br /><br />
 * @section startover_sec_03 Starting over - Exporting C++ functions to Daedalus
 * 
 * Exporting functions to Daedalus is actually a really easy and powerful thing:
 * 
 * @code
 * #include "api/g2/zcparser.h"
 * #include "api/g2/zstring.h"
 *
 * zCParser* g_pParser = NULL; // Init global parser var
 * 
 *  int Mod_ExternalFunction() // func void test();
 * {
 * 	MessageBox(0, L"Hello world!", 0, 0);
 * 	return 0;
 * };
 * 
 * int Mod_ExternalFunction2() // func int test2(string);
 * {
 * 	zSTRING zsParam1;
 * 
 * 	g_pParser->GetParameter(zsParam1);
 * 
 * 	MessageBoxA(0, zsParam1.ToChar(), 0, 0);
 * 	
 * 	g_pParser->SetReturn(42);
 * 
 * 	return 0;
 * };
 *
 * // We assume you have registred this callback correctly - for more info have a look at the previous "getting started" section
 * void __stdcall Mod_OnRegisterExternals(zCParser* pParser)
 * {
 * 	g_pParser = pParser;
 * 	pParser->DefineExternal(zSTRING("test"), Mod_ExternalFunction, zCPVOID, zCPVOID);
 * 	pParser->DefineExternal(zSTRING("test2"), Mod_ExternalFunction2, zCPINT, zCPSTRING, zCPVOID);
 * };
 *
 * @endcode
 *
 * Now, you have exported the two functions "func void test()" and "func int test2(string)", which can now be called by Daedalus.
 *
 * @attention The last param of zCParser::DefineExternal(...) must <b>always</b> be zCPVOID, otherwise Gothic II will crash.
 *
 * @note For more information on zCParser::DefineExternal(...), have a look at the zCParser class documentation
 * 
 * 
 * @section startover_sec_99 More tutorials ...
 *
 * <i>... to come in the next revisions!</i>
 *
 */