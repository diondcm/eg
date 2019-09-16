//---------------------------------------------------------------------------

#ifndef FormMainAsyncH
#define FormMainAsyncH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Winapi.WebRT.hpp"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmMainSync : public TForm
{
__published:	// IDE-managed Components
	TMemo *MemoFeed;
	TPanel *PanelHeader;
	TButton *ButtonGetAsyncFeed;
	TButton *ButtonShowFeed;
	void __fastcall ButtonGetAsyncFeedClick(TObject *Sender);
	void __fastcall ButtonShowFeedClick(TObject *Sender);
private:	// User declarations
	Winapi::Webrt::_di_IAsyncOperationWithProgress_2__Syndication_ISyndicationFeed__Syndication_RetrievalProgress FAsyncGet;
public:		// User declarations
	__fastcall TfrmMainSync(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMainSync *frmMainSync;
//---------------------------------------------------------------------------
#endif
