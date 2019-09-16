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
  object FlowPanel1: TFlowPanel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 618
    Height = 270
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 136
    ExplicitTop = 104
    ExplicitWidth = 185
    ExplicitHeight = 41
    object Button1: TButton
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 133
      Height = 45
      Caption = 'Template Induction'
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object MemoResult: TMemo
    AlignWithMargins = True
    Left = 3
    Top = 279
    Width = 618
    Height = 89
    Align = alBottom
    TabOrder = 1
    ExplicitLeft = 232
    ExplicitTop = 160
    ExplicitWidth = 185
  end
end
