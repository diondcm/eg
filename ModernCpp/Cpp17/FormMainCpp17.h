//---------------------------------------------------------------------------

#ifndef FormMainCpp17H
#define FormMainCpp17H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
	TFlowPanel *FlowPanel1;
	TButton *ButtonTemplateInduction;
	TMemo *MemoResult;
	TButton *ButtonFoldExpr;
	TButton *ButtonConstExpr;
	TLabel *Label1;
	TButton *ButtonCaptureThisByValue;
	TButton *ButtonNestedName;
	TButton *ButtonStructureBind;
	TButton *ButtonStatsWithInitializer;
	TButton *ButtonIfConstExp;
	TButton *ButtonEnumListInit;
	TButton *ButtonStdAttributes;
	TButton *ButtonStdVariant;
	TButton *ButtonStdOptional;
	TButton *ButtonStdAny;
	void __fastcall ButtonTemplateInductionClick(TObject *Sender);
	void __fastcall ButtonFoldExprClick(TObject *Sender);
	void __fastcall ButtonConstExprClick(TObject *Sender);
	void __fastcall ButtonCaptureThisByValueClick(TObject *Sender);
	void __fastcall ButtonNestedNameClick(TObject *Sender);
	void __fastcall ButtonStructureBindClick(TObject *Sender);
	void __fastcall ButtonStatsWithInitializerClick(TObject *Sender);
	void __fastcall ButtonIfConstExpClick(TObject *Sender);
	void __fastcall ButtonEnumListInitClick(TObject *Sender);
	void __fastcall ButtonStdAttributesClick(TObject *Sender);
	void __fastcall ButtonStdVariantClick(TObject *Sender);
	void __fastcall ButtonStdOptionalClick(TObject *Sender);
	void __fastcall ButtonStdAnyClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmMain(TComponent* Owner);
	void LogString(System::UnicodeString msg);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
