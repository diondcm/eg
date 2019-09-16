object frmMainSync: TfrmMainSync
  Left = 0
  Top = 0
  Caption = 'Async Feed'
  ClientHeight = 404
  ClientWidth = 595
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
  object MemoFeed: TMemo
    AlignWithMargins = True
    Left = 3
    Top = 50
    Width = 589
    Height = 351
    Align = alClient
    Lines.Strings = (
      'Feed:')
    TabOrder = 0
    ExplicitLeft = 259
    ExplicitTop = 3
    ExplicitWidth = 185
    ExplicitHeight = 195
  end
  object PanelHeader: TPanel
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 589
    Height = 41
    Align = alTop
    TabOrder = 1
    ExplicitLeft = 200
    ExplicitTop = 240
    ExplicitWidth = 185
    object ButtonGetAsyncFeed: TButton
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 113
      Height = 33
      Align = alLeft
      Caption = 'Get Async'
      TabOrder = 0
      OnClick = ButtonGetAsyncFeedClick
      ExplicitLeft = 8
      ExplicitTop = -16
      ExplicitHeight = 57
    end
    object ButtonShowFeed: TButton
      AlignWithMargins = True
      Left = 123
      Top = 4
      Width = 113
      Height = 33
      Align = alLeft
      Caption = 'Show Feed'
      TabOrder = 1
      OnClick = ButtonShowFeedClick
      ExplicitLeft = 8
      ExplicitTop = -16
      ExplicitHeight = 57
    end
  end
end
