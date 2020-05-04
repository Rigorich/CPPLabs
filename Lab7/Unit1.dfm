object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1083#1105' '#1061#1101#1096'-'#1090#1072#1073#1083#1080#1094#1072
  ClientHeight = 414
  ClientWidth = 334
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    334
    414)
  PixelsPerInch = 96
  TextHeight = 13
  object LabelHash: TLabel
    Left = 192
    Top = 235
    Width = 76
    Height = 13
    Anchors = [akRight, akBottom]
    Caption = 'Hash table size:'
    ExplicitLeft = 218
  end
  object Memo1: TMemo
    Left = 15
    Top = 16
    Width = 300
    Height = 200
    Anchors = [akLeft, akTop, akRight, akBottom]
    Lines.Strings = (
      'Memo1')
    ReadOnly = True
    TabOrder = 0
  end
  object ButtonRandomize: TButton
    Left = 165
    Top = 307
    Width = 150
    Height = 42
    Anchors = [akRight, akBottom]
    Caption = 'Add random numbers'
    TabOrder = 1
    OnClick = ButtonRandomizeClick
    ExplicitLeft = 191
  end
  object ButtonClear: TButton
    Left = 179
    Top = 259
    Width = 123
    Height = 42
    Anchors = [akRight, akBottom]
    Caption = 'Clear hash table'
    TabOrder = 2
    OnClick = ButtonClearClick
    ExplicitLeft = 205
  end
  object ButtonDelete: TButton
    Left = 15
    Top = 307
    Width = 100
    Height = 42
    Anchors = [akLeft, akBottom]
    Caption = 'Delete number'
    TabOrder = 3
    OnClick = ButtonDeleteClick
  end
  object EditNumber: TEdit
    Left = 41
    Top = 232
    Width = 50
    Height = 21
    Anchors = [akLeft, akBottom]
    TabOrder = 4
    TextHint = 'Number'
  end
  object EditHash: TEdit
    Left = 274
    Top = 232
    Width = 21
    Height = 21
    Anchors = [akRight, akBottom]
    NumbersOnly = True
    TabOrder = 5
    Text = '10'
    ExplicitLeft = 300
  end
  object ButtonFindMax: TButton
    Left = 165
    Top = 355
    Width = 150
    Height = 42
    Anchors = [akRight, akBottom]
    Caption = 'Find max number'
    TabOrder = 6
    OnClick = ButtonFindMaxClick
    ExplicitLeft = 191
  end
  object ButtonAdd: TButton
    Left = 15
    Top = 259
    Width = 100
    Height = 42
    Anchors = [akLeft, akBottom]
    Caption = 'Add number'
    TabOrder = 7
    OnClick = ButtonAddClick
  end
  object ButtonFind: TButton
    Left = 15
    Top = 355
    Width = 100
    Height = 42
    Anchors = [akLeft, akBottom]
    Caption = 'Find number'
    TabOrder = 8
    OnClick = ButtonFindClick
  end
end
