object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1083#1105' '#1057#1087#1080#1089#1086#1082
  ClientHeight = 400
  ClientWidth = 353
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    353
    400)
  PixelsPerInch = 96
  TextHeight = 13
  object ButtonAdd: TButton
    Left = 8
    Top = 8
    Width = 106
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1095#1080#1089#1083#1086
    TabOrder = 0
    OnClick = ButtonAddClick
  end
  object ButtonDel: TButton
    Left = 127
    Top = 8
    Width = 106
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1095#1080#1089#1083#1086
    TabOrder = 1
    TabStop = False
    OnClick = ButtonDelClick
  end
  object ListBox: TListBox
    Left = 8
    Top = 47
    Width = 160
    Height = 345
    TabStop = False
    Anchors = [akLeft, akTop, akRight, akBottom]
    ItemHeight = 13
    TabOrder = 2
  end
  object ListBoxPos: TListBox
    Left = 184
    Top = 48
    Width = 161
    Height = 170
    ItemHeight = 13
    TabOrder = 3
  end
  object ListBoxNeg: TListBox
    Left = 184
    Top = 224
    Width = 161
    Height = 168
    ItemHeight = 13
    TabOrder = 4
  end
  object ButtonMake: TButton
    Left = 239
    Top = 8
    Width = 106
    Height = 25
    Caption = #1056#1072#1079#1076#1077#1083#1080#1090#1100' '#1095#1080#1089#1083#1072
    TabOrder = 5
    OnClick = ButtonMakeClick
  end
end
