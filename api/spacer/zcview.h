/*////////////////////////////////////////////////////////////////////////////

This file is part of the G2Ext SDK headers.

//////////////////////////////////////////////////////////////////////////////

The G2Ext SDK headers

Copyright © 2009, 2010 by Paindevs and Patrick Vogel

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

Full license at http://creativecommons.org/licenses/by-nc/3.0/legalcode

/////////////////////////////////////////////////////////////////////////////*/

#ifndef __API_SPACER_ZCVIEW_H__
#define __API_SPACER_ZCVIEW_H__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifndef _G2EXT_COMPILE_SPACER
#error Cannot use spacer headers on non spacer dll (_G2EXT_COMPILE_SPACER not defined)
#endif

#include "api/spacer/ztypes.h"
#include "api/spacer/macros.h"

#define VIEW_VXMAX 8192
#define VIEW_VYMAX 8192

/** Insert description. */
enum zTviewID 
{
	VIEW_SCREEN,
	VIEW_VIEWPORT,
	VIEW_ITEM
};	

/** Insert description. */
enum zTRnd_AlphaBlendFunc;

/** zCView base class. */
class zCViewBase
{
protected:
	char m_data[4];
};

/** Insert description. */
class zCView : public zCViewBase
{
private:
	char m_data[220];
public:
	//.text:00812020 ; public: __thiscall zCView::zCView(int, int, int, int, enum  zTviewID)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCView(int pA, int pB, int pC, int pD, zTviewID pE = VIEW_ITEM)
	{
		XCALL(0x00812020); //spacer
	};

	//.text:00811F60 ; public: __thiscall zCView::zCView(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCView()
	{
		XCALL(0x00811F60); //spacer
	};

	//.text:00813750 ; public: void __thiscall zCView::Close(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Close(void)
	{
		XCALL(0x00813750); //spacer
	};

	//.text:00816A60 ; public: void __thiscall zCView::ClrPrintwin(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ClrPrintwin(void)
	{
		XCALL(0x00816A60); //spacer
	};

	//.text:00813130 ; int __stdcall zCView__Create(int, int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int Create(int pA, int pB, int pC, float pD, int pE)
	{
		XCALL(0x00813130); //spacer
	};

	//.text:00813070 ; public: void __thiscall zCView::DrawItems(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void DrawItems(void)
	{
		XCALL(0x00813070); //spacer
	};

	//.text:00816330 ; public: int __thiscall zCView::FontSize(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int FontSize(zSTRING & pA)
	{
		XCALL(0x00816330); //spacer
	};

	//.text:00816310 ; public: int __thiscall zCView::FontY(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int FontY(void)
	{
		XCALL(0x00816310); //spacer
	};

	//.text:00812440 ; public: void __thiscall zCView::Init(int, int, int, int, enum  zTviewID)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(int pA, int pB, int pC, int pD, zTviewID pE = VIEW_ITEM)
	{
		XCALL(0x00812440); //spacer
	};

	//.text:008125E0 ; public: void __thiscall zCView::Init(int, int, class zSTRING const &, enum  zTviewID)
	/** Insert description. 
	* usable Ingame only
	*/
	void Init(int pA, int pB, zSTRING & pD, zTviewID pE)
	{
		XCALL(0x008125E0); //spacer
	};

	//.text:008122B0 ; public: void __thiscall zCView::Init(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(void)
	{
		XCALL(0x008122B0); //spacer
	};

	//.text:00812A50 ; public: void __thiscall zCView::InsertBack(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void InsertBack(zSTRING const & pA)
	{
		XCALL(0x00812A50); //spacer
	};

	//.text:008183F0 ; public: void __thiscall zCView::InsertItem(class zCView * Element, zBOOL StayOnTop)
	/** Insert description. 
	* @usable Ingame only
	*/
	void InsertItem(void* Element, int StayOnTop = false)
	{
		XCALL(0x008183F0); //spacer
	};

	//.text:008129B0 ; public: struct zCOLOR __thiscall zCView::GetColor(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCOLOR GetColor(void)
	{
		XCALL(0x008129B0); //spacer
	};

	//.text:007A7860 ; public: void __thiscall zCView::GetExtends(int &, int &, int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetExtends(int & x, int & y, int & cx, int & cy)
	{
		XCALL(0x007A7860); //spacer
	};

	//.text:00814180 ; public: void __thiscall zCView::GetPixelExtends(float &, float &, float &, float &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPixelExtends(float & x, float & y, float & cx, float & cy)
	{
		XCALL(0x00814180); //spacer
	};

	//.text:00813FE0 ; public: void __thiscall zCView::GetPixelPos(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPixelPos(int & x, int & y)
	{
		XCALL(0x00813FE0); //spacer
	};

	//.text:00814150 ; public: void __thiscall zCView::GetPixelSize(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPixelSize(int & x, int & y)
	{
		XCALL(0x00814150); //spacer
	};

	//.text:00813F80 ; public: void __thiscall zCView::GetPos(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPos(int & x, int & y)
	{
		XCALL(0x00813F80); //spacer
	};

	//.text:008141C0 ; public: void __thiscall zCView::GetScreenExtends(int &, int &, int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetScreenExtends(int & x, int & y, int & cx, int & cy)
	{
		XCALL(0x008141C0); //spacer
	};

	//.text:00814130 ; public: void __thiscall zCView::GetSize(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetSize(int & x, int & y)
	{
		XCALL(0x00814130); //spacer
	};
	
	//.text:00814000 ; public: void __thiscall zCView::Move(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Move(int pA, int pB)
	{
		XCALL(0x00814000); //spacer
	};

	//.text:00813520 ; public: void __thiscall zCView::Open(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Open(void)
	{
		XCALL(0x00813520); //spacer
	};

	//.text:00816360 ; public: void __thiscall zCView::Print(zINT, zINT, class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Print(zINT p1, zINT p2, const zSTRING & p3)
	{
		XCALL(0x00816360); //spacer
	};

	//.text:00816770 ; public: void __thiscall zCView::PrintCX(int, class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintCX(int pA, const zSTRING & pB)
	{
		XCALL(0x00816770); //spacer
	};

	//.text:00816950 ; public: void __thiscall zCView::PrintCXY(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintCXY(zSTRING const & pA)
	{
		XCALL(0x00816950); //spacer
	};

	//.text:00816860 ; public: void __thiscall zCView::PrintCY(int, class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintCY(int pA, const zSTRING & pB)
	{
		XCALL(0x00816860); //spacer
	};

	//.text:00814A60 ; public: void __thiscall zCView::PrintMessage(class zSTRING const &, class zSTRING const &, float, struct zCOLOR &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintMessage( const zSTRING & pA, const zSTRING & pB, float pC, zCOLOR & pD)
	{
		XCALL(0x00814A60); //spacer
	};

	//.text:00814D70 ; public: void __thiscall zCView::PrintMessageCXY(class zSTRING const &, class zSTRING const &, float, struct zCOLOR &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintMessageCXY(const zSTRING & pA, const zSTRING & pB, float pC, zCOLOR & pD)
	{
		XCALL(0x00814D70); //spacer
	};

	//.text:00818630 ; public: void __thiscall zCView::RemoveItem(class zCView *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RemoveItem(void* Element)
	{
		XCALL(0x00818630); //spacer
	};

	//.text:00818B30 ; public: void __thiscall zCView::Render(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Render(void)
	{
		XCALL(0x00818B30); //spacer
	};

	//.text:00812990 ; public: void __thiscall zCView::SetAlphaBlendFunc(enum  zTRnd_AlphaBlendFunc const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetAlphaBlendFunc(const zTRnd_AlphaBlendFunc & p1)
	{
		XCALL(0x00812990); //spacer
	};

	//.text:00812840 ; int __stdcall zCView__SetAutoScroll(float)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall SetAutoScroll(float p1)
	{
		XCALL(0x00812840); //spacer
	};

	//.text:008129A0 ; public: void __thiscall zCView::SetColor(struct zCOLOR const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetColor(const zCOLOR & p1)
	{
		XCALL(0x008129A0); //spacer
	};

	//.text:00816240 ; public: void __thiscall zCView::SetFont(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFont(const zSTRING & p1)
	{
		XCALL(0x00816240); //spacer
	};

	//.text:00816230 ; public: void __thiscall zCView::SetFontColor(struct zCOLOR const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFontColor(const zCOLOR & p1)
	{
		XCALL(0x00816230); //spacer
	};

	//.text:008129C0 ; public: void __thiscall zCView::SetFlags(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFlags(int p1)
	{
		XCALL(0x008129C0); //spacer
	};

	//.text:00813ED0 ; public: void __thiscall zCView::SetPos(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetPos(int pA, int pB)
	{
		XCALL(0x00813ED0); //spacer
	};

	//.text:008140C0 ; public: void __thiscall zCView::SetSize(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetSize(int pA, int pB)
	{
		XCALL(0x008140C0); //spacer
	};

	//.text:00812980 ; public: void __thiscall zCView::SetTransparency(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetTransparency(int pA)
	{
		XCALL(0x00812980); //spacer
	};

	//.text:008130B0 ; public: void __thiscall zCView::Top(void)
	/** Insert description. 
	* @usable Ingame only
	*/                     
	void Top(void)
	{
		XCALL(0x008130B0); //spacer
	};

	//.text:007A5E80 ; public: int __thiscall zCView::anx(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int anx(int pA)
	{
		XCALL(0x007A5E80); //spacer
	};

	//.text:008127E0 ; public: int __thiscall zCView::any(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int any(int pA)
	{
		XCALL(0x008127E0); //spacer
	};

	//.text:00812720 ; public: int __thiscall zCView::nax(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int nax(int pA)
	{
		XCALL(0x00812720); //spacer
	};

	//.text:00812720 ; public: int __thiscall zCView::nay(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int nay(int pA)
	{
		XCALL(0x00812720); //spacer
	};

	/** This method returns the current screen
	* @usable Ingame only
	*/
	inline static zCView* GetScreen() { return *(zCView**)0x00C2CB20; }; //spacer

	/** This method returns the current viewport
	* @usable Ingame only
	*/
	inline static zCView* GetViewport() { return *(zCView**)0x0099FF58; }; //spacer
};

class zCViewProgressBar
{
private:
	char m_cData[8];
	int  m_nProgress;
	char m_cData2[24];
public:
	//.text:00628FA0 ; public: void __thiscall zCViewProgressBar::SetPercent(int, class zSTRING)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetPercent(int pA, zSTRING pB = zSTRING(""))
	{
		XCALL(0x00628FA0);
	};

	//.text:00629270 ; public: virtual void __thiscall zCViewProgressBar::HandleChange(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void HandleChange(void)
	{
		XCALL(0x00629270);
	};
};

#undef __G2EXT_API_HEADER

#endif // __API_SPACER_ZCVIEW_H__