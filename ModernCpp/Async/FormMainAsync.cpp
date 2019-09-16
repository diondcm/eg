//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMainAsync.h"
#include "Winapi.CommonTypes.hpp"
#include "Winapi.WinRT.hpp"
#include "Winapi.WebRT.hpp"
#include "Winapi.Foundation.hpp"
#include "WinAPI.HSTRINGIterables.hpp"
#include "WinAPI.Security.Credentials.hpp"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMainSync *frmMainSync;
//---------------------------------------------------------------------------
__fastcall TfrmMainSync::TfrmMainSync(TComponent* Owner)
	: TForm(Owner)
{
}

using namespace System::Win::Winrt;
//---------------------------------------------------------------------------
void __fastcall TfrmMainSync::ButtonGetAsyncFeedClick(TObject *Sender)
{
  HSTRING url = CreateHSTRING("https://blogs.windows.com/feed");
  HSTRING res = CreateHSTRING("MyResource");
  HSTRING usr = CreateHSTRING("User");
  HSTRING pas = CreateHSTRING("Pass");

  auto uri = Winapi::Foundation::TUri::CreateUri(url);
  auto pwcred = Winapi::Security::Credentials::TPasswordCredential::CreatePasswordCredential(res, usr, pas);
  auto client = Winapi::Webrt::TSyndication_SyndicationClient::CreateSyndicationClient(pwcred);
  client->RetrieveFeedAsync(uri, FAsyncGet);

  DeleteHSTRING(url);
  DeleteHSTRING(res);
  DeleteHSTRING(usr);
  DeleteHSTRING(pas);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMainSync::ButtonShowFeedClick(TObject *Sender)
{
  Winapi::Webrt::_di_Syndication_ISyndicationFeed resource = nullptr;
  FAsyncGet->GetResults(resource);

  Winapi::Webrt::_di_IVector_1__Syndication_ISyndicationItem items = nullptr;
  resource->get_Items(items);

  Winapi::Webrt::_di_Syndication_ISyndicationText title = nullptr;
  resource->get_Title(title);
  HSTRING ltext;
  title->get_Text(ltext);
  System::UnicodeString text = HSTRINGToString(ltext);
  MemoFeed->Lines->Add(text);

  for(int i = 0; i < items->Size; i++) {
	  Winapi::Webrt::_di_Syndication_ISyndicationItem feed_item = nullptr;
	  items->GetAt(i, feed_item);

	  Winapi::Webrt::_di_Syndication_ISyndicationText item_title = nullptr;
	  feed_item->get_Title(item_title);
	  HSTRING ltext;
	  item_title->get_Text(ltext);
	  System::UnicodeString text = HSTRINGToString(ltext);
	  MemoFeed->Lines->Add(text);
  }
}
//---------------------------------------------------------------------------

