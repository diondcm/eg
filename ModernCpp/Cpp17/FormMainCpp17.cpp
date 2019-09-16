//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormMainCpp17.h"
#include <variant>
#include <optional>
#include <any>
#include <vector>
#include <map>
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
void TfrmMain::LogString(System::UnicodeString msg) {
	MemoResult->Lines->Insert(0, msg);
}

template <typename T>
struct NewType {
  T val;
  NewType() : val() {}
  NewType(T val) : val(val) {}
};

void __fastcall TfrmMain::ButtonTemplateInductionClick(TObject *Sender)
{
	NewType byInt {42342};
	LogString(byInt.val);
	NewType byFloat { 0.6 };
	LogString(FloatToStr(byFloat.val));
	NewType byStr { "Test" };
	LogString(byStr.val);
}
//---------------------------------------------------------------------------

template<typename... Args>
bool logicalAnd(Args... args) {
	return (true && ... && args);
}

template<typename... Args>
auto sum(Args... args) {
	return (... + args);
}

void __fastcall TfrmMain::ButtonFoldExprClick(TObject *Sender)
{
	bool b = true;
	bool& b2 = b;
	logicalAnd(b, b2, true);
	sum(1.0, 2.0f, 3);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ButtonConstExprClick(TObject *Sender)
{
	auto identity = [](int n) constexpr { return n; };
	static_assert(identity(123) == 123);

	constexpr auto add = [](int x, int y) {
	  auto L = [=] { return x; };
	  auto R = [=] { return y; };
	  return [=] { return L() + R(); };
	};
	static_assert(add(1, 2)() == 3);
}
//---------------------------------------------------------------------------


struct MyObj {
  int value { 123 };

  auto getValueCopy() {
	return [*this] { return value; };
  }

  auto getValueRef() {
	return [this] { return value; };
  }
};

void __fastcall TfrmMain::ButtonCaptureThisByValueClick(TObject *Sender)
{
	MyObj mo;
	auto valueCopy = mo.getValueCopy();
	auto valueRef = mo.getValueRef();
	mo.value = 321;
	LogString("Copy: " + IntToStr(valueCopy()));
	LogString("Ref: " + IntToStr(valueRef()));
}
//---------------------------------------------------------------------------

//namespace Base {
//	namespace Classes {
//		namespace Types {

namespace Base::Classes::Types {
  typedef int NewInt;
}

void __fastcall TfrmMain::ButtonNestedNameClick(TObject *Sender)
{
	Base::Classes::Types::NewInt i{ 2 };
	LogString(i);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ButtonStructureBindClick(TObject *Sender)
{
	std::pair<int, int> val { 200, 100};
	auto [ x, y ] = val;
	LogString("X: " + IntToStr(x) + " Y: " + IntToStr(y));
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ButtonStatsWithInitializerClick(TObject *Sender)
{
	if (true; false) {
		LogString("Both true");
	} else {
		LogString("Less one false");
	}

	struct LocalStatus {
		enum stat {OK, Bad};
		stat get_status() { return OK; }
	};

	switch (LocalStatus loc; auto s = loc.get_status()) {
	  case LocalStatus::stat::OK: LogString("Ok!"); break;
	  case LocalStatus::stat::Bad: LogString("Bad");
	}

}
//---------------------------------------------------------------------------

template <typename T>
constexpr bool isIntegral() {
  if constexpr (std::is_integral<T>::value) {
	return true;
  } else {
	return false;
  }
}

void __fastcall TfrmMain::ButtonIfConstExpClick(TObject *Sender)
{
	auto localBoolToStr = [](bool b, String tp) { if (b) { return tp + ": True"; } else { return tp + ": False"; } };
	LogString(localBoolToStr(isIntegral<int>() == true, "int"));
	LogString(localBoolToStr(isIntegral<char>() == true, "char"));
	LogString(localBoolToStr(isIntegral<double>() == true, "double"));
	struct S {};
	LogString(localBoolToStr(isIntegral<S>() == true, "struct"));
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ButtonEnumListInitClick(TObject *Sender)
{
	enum byte : unsigned char {};
	byte b {0};
	byte c {-1};
	byte d = byte{1};
	byte e = byte{255};
}
//---------------------------------------------------------------------------
[[nodiscard]] int must_take_return() { return -1; };

void __fastcall TfrmMain::ButtonStdAttributesClick(TObject *Sender)
{
  must_take_return(); // generates warning

  int a {1};
  switch (a) {
	  // Indicates that falling through on case 1 is intentional
	  case 1: [[fallthrough]];
	  case 2:
	  // Indicates that b might be unused, such as on production builds
		[[maybe_unused]] int b = must_take_return();
		assert(b < 0);
		break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ButtonStdVariantClick(TObject *Sender)
{
	std::variant<int, double> v;
	LogString(IntToStr(std::get<int>(v)));
	LogString(IntToStr(std::get<0>(v)));
	LogString(IntToStr((int)std::get<double>(v)));
	LogString(IntToStr((int)std::get<1>(v)));
}
//---------------------------------------------------------------------------

std::optional<System::UnicodeString> OptCreate(bool b) {
	if (b) {
		std::optional<System::UnicodeString> str("C++Builder on Win10");
		return { str };
	} else {
		return std::nullopt;// the same { }
	}
}

void __fastcall TfrmMain::ButtonStdOptionalClick(TObject *Sender)
{
	LogString(OptCreate(false).value_or("empty"));
	LogString(OptCreate(true).value());
	std::optional<System::UnicodeString> str = OptCreate(true);
	if (str) {
	  LogString(*str);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ButtonStdAnyClick(TObject *Sender)
{
	std::any x {5};
	if (x.has_value()) {
		LogString("Any<Int>: " + IntToStr(std::any_cast<int>(x)));
		std::any_cast<int&>(x) = 222;
		LogString("Any<Int>: " + IntToStr(std::any_cast<int>(x)));
		try {
			LogString("AnyCast<string>: " +  std::any_cast<System::UnicodeString>(x));
		}
		catch(const std::bad_any_cast& e) {
			System::UnicodeString str {e.what()};
			LogString("AnyErr: " + str);
		}
	}

	std::map<std::string, std::any> m;
	m["integer"] = 10;
	m["string"] = "Hello World";
	m["float"] = 1.0f;

	for (auto &[key, val] : m)
	{
		if (val.type() == typeid(int))
			LogString("int: " + IntToStr(std::any_cast<int>(val)));
		else if (val.type() == typeid(std::string))
			LogString("string: " + std::any_cast<System::UnicodeString>(val));
		else if (val.type() == typeid(float))
			LogString("float: " + FloatToStr(std::any_cast<float>(val)));
	}
}
//---------------------------------------------------------------------------

