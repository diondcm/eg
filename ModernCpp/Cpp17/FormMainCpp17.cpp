//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMainCpp17.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

template <typename T>
struct NewType {
  T val;
  NewType() : val() {}
  NewType(T val) : val(val) {}
};

void TfrmMain::LogString(System::UnicodeString msg) {
    MemoResult->Lines->Insert(0, msg);
}

void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
	NewType byInt {42342};
	LogString(byInt.val);
	NewType byFloat { 0.6 };
	LogString(FloatToStr(byFloat.val));
	NewType byStr { "Test" };
	LogString(byStr.val);

}
//---------------------------------------------------------------------------
