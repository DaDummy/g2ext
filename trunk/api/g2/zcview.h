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

#ifndef __ZCVIEW_H_INCLUDED__
#define __ZCVIEW_H_INCLUDED__

#ifndef __G2EXT_API_HEADER
#define __G2EXT_API_HEADER
#endif  //__G2EXT_API_HEADER

#ifdef _G2EXT_COMPILE_SPACER
#error Cannot use gothic headers on spacer dll (_G2EXT_COMPILE_SPACER defined)
#endif

#include "api/g2/ztypes.h"
#include "api/g2/macros.h"

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
enum zTViewFX
{
	VIEW_FX_NONE,
	VIEW_FX_ZOOM,
	VIEW_FX_MAX	
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
	//.text:007A5700 ; public: __thiscall zCView::zCView(int, int, int, int, enum  zTviewID)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCView(int pA, int pB, int pC, int pD, zTviewID pE = VIEW_ITEM)
	{
		XCALL(0x007A5700);
	};

	//.text:007A5640 ; public: __thiscall zCView::zCView(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCView()
	{
		XCALL(0x007A5640);
	};

	//.text:007A6E30 ; public: void __thiscall zCView::Close(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Close(void)
	{
		XCALL(0x007A6E30);
	};

	//.text:007AA140 ; public: void __thiscall zCView::ClrPrintwin(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void ClrPrintwin(void)
	{
		XCALL(0x007AA140);
	};

	//.text:007A6810 ; int __stdcall zCView__Create(int, int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Create(zSTRING& background, zTViewFX fx0, zTViewFX fx1, float unk0, int unk1)
	{
		XCALL(0x007A6810);
	};

	//.text:007A6750 ; public: void __thiscall zCView::DrawItems(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void DrawItems(void)
	{
		XCALL(0x007A6750);
	};

	//.text:007A8D40 ; int __stdcall zCView__Dialog(int, int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Dialog(int x, int y, zSTRING& text, float time, zCOLOR* color)
	{
		XCALL(0x007A8D40);
	};

	//.text:007A8E10 ; int __stdcall zCView__DialogCX(int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void DialogCX(int y, zSTRING& text, float time, zCOLOR* color)
	{
		XCALL(0x007A8E10);
	};

	//.text:007A8F60 ; int __stdcall zCView__DialogCXY(int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void DialogCXY(zSTRING& text, float time, zCOLOR* color)
	{
		XCALL(0x007A8F60);
	};

	//.text:007A8E70 ; int __stdcall zCView__DialogCY(int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void DialogCY(int x, zSTRING& text, float time, zCOLOR* color)
	{
		XCALL(0x007A8E70);
	};

	//.text:007A8FB0 ; int __stdcall zCView__DialogMessage(int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void DialogMessage(zSTRING& headline, zSTRING& text, float time, zCOLOR* color)
	{
		XCALL(0x007A8FB0);
	};

	//.text:007A9240 ; int __stdcall zCView__DialogMessageCXY(int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void DialogMessageCXY(zSTRING& headline, zSTRING& text, float time, zCOLOR* color)
	{
		XCALL(0x007A9240);
	};

	//.text:007A9A10 ; public: int __thiscall zCView::FontSize(class zSTRING &)
	/** Insert description. 
	* @usable Ingame only
	*/
	int FontSize(zSTRING & pA)
	{
		XCALL(0x007A9A10);
	};

	//.text:007A99F0 ; public: int __thiscall zCView::FontY(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	int FontY(void)
	{
		XCALL(0x007A99F0);
	};

	//.text:007A5B20 ; public: void __thiscall zCView::Init(int, int, int, int, enum  zTviewID)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(int pA, int pB, int pC, int pD, zTviewID pE = VIEW_ITEM)
	{
		XCALL(0x007A5B20);
	};

	//.text:007A5CC0 ; public: void __thiscall zCView::Init(int, int, class zSTRING const &, enum  zTviewID)
	/** Insert description. 
	* usable Ingame only
	*/
	void Init(int pA, int pB, zSTRING & pD, zTviewID pE)
	{
		XCALL(0x007A5B20);
	};

	//.text:007A5990 ; public: void __thiscall zCView::Init(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Init(void)
	{
		XCALL(0x007A5990);
	};

	//.text:007A6130 ; public: void __thiscall zCView::InsertBack(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void InsertBack(zSTRING const & pA)
	{
		XCALL(0x007A6130);
	};

	//.text:007ABAD0 ; public: void __thiscall zCView::InsertItem(class zCView * Element, zBOOL StayOnTop)
	/** Insert description. 
	* @usable Ingame only
	*/
	void InsertItem(void* Element, int StayOnTop = false)
	{
		XCALL(0x007ABAD0);
	};

	//.text:007A6090 ; public: struct zCOLOR __thiscall zCView::GetColor(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	zCOLOR GetColor(void)
	{
		XCALL(0x007A6090);
	};

	//.text:007A7860 ; public: void __thiscall zCView::GetExtends(int &, int &, int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetExtends(int & x, int & y, int & cx, int & cy)
	{
		XCALL(0x007A7860);
	};

	//.text:007A7910 ; public: void __thiscall zCView::GetPixelExtends(float &, float &, float &, float &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPixelExtends(float & x, float & y, float & cx, float & cy)
	{
		XCALL(0x007A7910);
	};

	//.text:007A76C0 ; public: void __thiscall zCView::GetPixelPos(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPixelPos(int & x, int & y)
	{
		XCALL(0x007A76C0);
	};

	//.text:007A7830 ; public: void __thiscall zCView::GetPixelSize(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPixelSize(int & x, int & y)
	{
		XCALL(0x007A7830);
	};

	//.text:007A7660 ; public: void __thiscall zCView::GetPos(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetPos(int & x, int & y)
	{
		XCALL(0x007A7660);
	};

	//.text:007A78A0 ; public: void __thiscall zCView::GetScreenExtends(int &, int &, int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetScreenExtends(int & x, int & y, int & cx, int & cy)
	{
		XCALL(0x007A78A0);
	};

	//.text:007A7810 ; public: void __thiscall zCView::GetSize(int &, int &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void GetSize(int & x, int & y)
	{
		XCALL(0x007A7810);
	};

	//.text:007ABF70 ; public: virtual void __thiscall zCView::Line(int, int, int, int, struct zCOLOR const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Line(int x, int y, int x1, int y1, const zCOLOR& col)
	{
		XCALL(0x007ABF70);
	};
	
	//.text:007A76E0 ; public: void __thiscall zCView::Move(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Move(int pA, int pB)
	{
		XCALL(0x007A76E0);
	};

	//.text:007A6C00 ; public: void __thiscall zCView::Open(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Open(void)
	{
		XCALL(0x007A6C00);
	};

	//.text:007A9A40 ; public: void __thiscall zCView::Print(zINT, zINT, class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Print(zINT p1, zINT p2, const zSTRING & p3)
	{
		XCALL(0x007A9A40);
	};

	//.text:007A9E50 ; public: void __thiscall zCView::PrintCX(int, class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintCX(int pA, const zSTRING & pB)
	{
		XCALL(0x007A9E50);
	};

	//.text:007AA030 ; public: void __thiscall zCView::PrintCXY(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintCXY(zSTRING const & pA)
	{
		XCALL(0x007AA030);
	};

	//.text:007A9F40 ; public: void __thiscall zCView::PrintCY(int, class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintCY(int pA, const zSTRING & pB)
	{
		XCALL(0x007A9F40);
	};

	//.text:007A8140 ; public: void __thiscall zCView::PrintMessage(class zSTRING const &, class zSTRING const &, float, struct zCOLOR &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintMessage( const zSTRING & pA, const zSTRING & pB, float pC, zCOLOR & pD)
	{
		XCALL(0x007A8140);
	};

	//.text:007A8450 ; public: void __thiscall zCView::PrintMessageCXY(class zSTRING const &, class zSTRING const &, float, struct zCOLOR &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintMessageCXY(const zSTRING & pA, const zSTRING & pB, float pC, zCOLOR & pD)
	{
		XCALL(0x007A8450);
	};

	//.text:007AA8D0 ; public: void __thiscall zCView::Printwin(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintWin(const zSTRING & text)
	{
		XCALL(0x007AA8D0)
	};

	//.text:007A7D20 ; int __stdcall zCView__PrintTimed(int, int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintTimed(int x, int y, const zSTRING & text, float time, zCOLOR* color)
	{
		XCALL(0x007A7D20)
	};

	//.text:007A7DB0 ; int __stdcall zCView__PrintTimedCX(int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintTimedCX(int y, const zSTRING & text, float time, zCOLOR* color)
	{
		XCALL(0x007A7DB0)
	};

	//.text:007A7F00 ; int __stdcall zCView__PrintTimedCY(int, int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintTimedCY(int x, const zSTRING & text, float time, zCOLOR* color)
	{
		XCALL(0x007A7F00)
	};

	//.text:007A7FC0 ; int __stdcall zCView__PrintTimedCXY(int, float, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintTimedCXY(const zSTRING & text, float time, zCOLOR* color)
	{
		XCALL(0x007A7FC0)
	};

	//.text:007A8140 ; public: void __thiscall zCView::PrintMessage(class zSTRING const &, class zSTRING const &, float, struct zCOLOR &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintMessage(const zSTRING& headline, const zSTRING& text, float time, zCOLOR& color)
	{
		XCALL(0x007A8140)
	};

	//.text:007A8450 ; public: void __thiscall zCView::PrintMessageCXY(class zSTRING const &, class zSTRING const &, float, struct zCOLOR &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void PrintMessageCXY(const zSTRING& headline, const zSTRING& text, float time, zCOLOR& color)
	{
		XCALL(0x007A8450)
	};

	//.text:007ABD10 ; public: void __thiscall zCView::RemoveItem(class zCView *)
	/** Insert description. 
	* @usable Ingame only
	*/
	void RemoveItem(void* Element)
	{
		XCALL(0x007ABD10);
	};

	//.text:007AC210 ; public: void __thiscall zCView::Render(void)
	/** Insert description. 
	* @usable Ingame only
	*/
	void Render(void)
	{
		XCALL(0x007AC210);
	};

	//.text:007A6070 ; public: void __thiscall zCView::SetAlphaBlendFunc(enum  zTRnd_AlphaBlendFunc const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetAlphaBlendFunc(const zTRnd_AlphaBlendFunc & p1)
	{
		XCALL(0x007A6070);
	};

	//.text:007A5F20 ; int __stdcall zCView__SetAutoScroll(float)
	/** Insert description. 
	* @usable Ingame only
	*/
	int __stdcall SetAutoScroll(float p1)
	{
		XCALL(0x007A5F20);
	};

	//.text:007A6080 ; public: void __thiscall zCView::SetColor(struct zCOLOR const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetColor(const zCOLOR & p1)
	{
		XCALL(0x007A6080);
	};

	//.text:007A9920 ; public: void __thiscall zCView::SetFont(class zSTRING const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFont(const zSTRING & p1)
	{
		XCALL(0x007A9920);
	};

	//.text:007A9910 ; public: void __thiscall zCView::SetFontColor(struct zCOLOR const &)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFontColor(const zCOLOR & p1)
	{
		XCALL(0x007A9910);
	};

	//.text:007A60A0 ; public: void __thiscall zCView::SetFlags(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetFlags(int p1)
	{
		XCALL(0x007A60A0);
	};

	//.text:007A75B0 ; public: void __thiscall zCView::SetPos(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetPos(int pA, int pB)
	{
		XCALL(0x007A75B0);
	};

	//.text:007A77A0 ; public: void __thiscall zCView::SetSize(int, int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetSize(int pA, int pB)
	{
		XCALL(0x007A77A0);
	};

	//.text:007A6060 ; public: void __thiscall zCView::SetTransparency(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	void SetTransparency(int pA)
	{
		XCALL(0x007A6060);
	};

	//.text:007A6790 ; public: void __thiscall zCView::Top(void)
	/** Insert description. 
	* @usable Ingame only
	*/                     
	void Top(void)
	{
		XCALL(0x007A6790);
	};

	//.text:007A5E80 ; public: int __thiscall zCView::anx(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int anx(int pA)
	{
		XCALL(0x007A5E80);
	};

	//.text:007A5EC0 ; public: int __thiscall zCView::any(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int any(int pA)
	{
		XCALL(0x007A5EC0);
	};

	//.text:007A5E00 ; public: int __thiscall zCView::nax(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int nax(int pA)
	{
		XCALL(0x007A5E00);
	};

	//.text:007A5E40 ; public: int __thiscall zCView::nay(int)
	/** Insert description. 
	* @usable Ingame only
	*/
	int nay(int pA)
	{
		XCALL(0x007A5E40);
	};

	/** This method returns the current zCView instance
	* @usable Ingame only
	*/
	inline static zCView* GetScreen() { return *(zCView**)0x00AB6468; };
};

/** Insert description */
class zCViewProgressBar
{
private:
	char m_cData[8];
	int  m_nProgress;
	char m_cData2[24];
public:
	//.text:0046EEC0 ; public: void __thiscall zCViewProgressBar::SetPercent(int, class zSTRING)
	void SetPercent(int pA, zSTRING pB = zSTRING(""))
	{
		XCALL(0x0046EEC0);
	};

	//.text:0046F190 ; public: virtual void __thiscall zCViewProgressBar::HandleChange(void)
	void HandleChange(void)
	{
		XCALL(0x0046F190);
	};
};

#undef __G2EXT_API_HEADER

#endif // __ZCVIEW_H_INCLUDED__