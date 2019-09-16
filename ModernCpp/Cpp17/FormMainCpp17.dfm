object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'C++17'
  ClientHeight = 371
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    AlignWithMargins = True
    Left = 3
    Top = 355
    Width = 618
    Height = 13
    Align = alBottom
    Caption = 
      'Forked at: https://github.com/AnthonyCalandra/modern-cpp-feature' +
      's/blob/master/CPP17.md'
    ExplicitWidth = 451
  end
  object FlowPanel1: TFlowPanel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 618
    Height = 251
    Align = alClient
    TabOrder = 0
    ExplicitHeight = 270
    object ButtonTemplateInduction: TButton
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 133
      Height = 45
      Caption = 'Template Induction'
      TabOrder = 0
      OnClick = ButtonTemplateInductionClick
    end
    object ButtonFoldExpr: TButton
      AlignWithMargins = True
      Left = 143
      Top = 4
      Width = 133
      Height = 45
      Caption = 'Fold Expressions'
      TabOrder = 1
      OnClick = ButtonFoldExprClick
    end
    object ButtonConstExpr: TButton
      AlignWithMargins = True
      Left = 282
      Top = 4
      Width = 133
      Height = 45
      Caption = 'Lambda constexpr'
      TabOrder = 2
      OnClick = ButtonConstExprClick
    end
    object ButtonCaptureThisByValue: TButton
      AlignWithMargins = True
      Left = 421
      Top = 4
      Width = 133
      Height = 45
      Caption = 'Capture this by value'
      TabOrder = 3
      OnClick = ButtonCaptureThisByValueClick
    end
    object ButtonNestedName: TButton
      AlignWithMargins = True
      Left = 4
      Top = 55
      Width = 133
      Height = 45
      Caption = 'Nested Namespace'
      TabOrder = 4
      OnClick = ButtonNestedNameClick
    end
    object ButtonStructureBind: TButton
      AlignWithMargins = True
      Left = 143
      Top = 55
      Width = 133
      Height = 45
      Caption = 'Structure Bind'
      TabOrder = 5
      OnClick = ButtonStructureBindClick
    end
    object ButtonStatsWithInitializer: TButton
      AlignWithMargins = True
      Left = 282
      Top = 55
      Width = 133
      Height = 45
      Caption = 'Statement Initializer'
      TabOrder = 6
      OnClick = ButtonStatsWithInitializerClick
    end
    object ButtonIfConstExp: TButton
      AlignWithMargins = True
      Left = 421
      Top = 55
      Width = 133
      Height = 45
      Caption = 'if constexpr'
      TabOrder = 7
      OnClick = ButtonIfConstExpClick
    end
    object ButtonEnumListInit: TButton
      AlignWithMargins = True
      Left = 4
      Top = 106
      Width = 133
      Height = 45
      Caption = 'Enum List Init'
      TabOrder = 8
      OnClick = ButtonEnumListInitClick
    end
    object ButtonStdAttributes: TButton
      AlignWithMargins = True
      Left = 143
      Top = 106
      Width = 133
      Height = 45
      Caption = 'New Attributes'
      TabOrder = 9
      OnClick = ButtonStdAttributesClick
    end
    object ButtonStdVariant: TButton
      AlignWithMargins = True
      Left = 282
      Top = 106
      Width = 133
      Height = 45
      Caption = 'std::variant'
      TabOrder = 10
      OnClick = ButtonStdVariantClick
    end
    object ButtonStdOptional: TButton
      AlignWithMargins = True
      Left = 421
      Top = 106
      Width = 133
      Height = 45
      Caption = 'std::optional'
      TabOrder = 11
      OnClick = ButtonStdOptionalClick
    end
    object ButtonStdAny: TButton
      AlignWithMargins = True
      Left = 4
      Top = 157
      Width = 133
      Height = 45
      Caption = 'std::any'
      TabOrder = 12
      OnClick = ButtonStdAnyClick
    end
  end
  object MemoResult: TMemo
    AlignWithMargins = True
    Left = 3
    Top = 260
    Width = 618
    Height = 89
    Align = alBottom
    TabOrder = 1
    ExplicitLeft = 8
    ExplicitTop = 103
  end
end
