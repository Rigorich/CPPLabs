object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1083#1105' '#1057#1090#1077#1082
  ClientHeight = 231
  ClientWidth = 505
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ErrorInVar: TPaintBox
    Left = 8
    Top = 158
    Width = 489
    Height = 39
    Color = clRed
    ParentColor = False
  end
  object Edit1: TEdit
    Left = 16
    Top = 96
    Width = 225
    Height = 21
    TabOrder = 0
    TextHint = 'Mathematical expression'
  end
  object EditRes: TEdit
    Left = 294
    Top = 96
    Width = 187
    Height = 21
    TabStop = False
    ReadOnly = True
    TabOrder = 7
    Text = 'Calculation result'
  end
  object Button1: TButton
    Left = 255
    Top = 94
    Width = 25
    Height = 25
    Caption = '='
    TabOrder = 6
    OnClick = Button1Click
  end
  object EditA: TEdit
    Left = 17
    Top = 168
    Width = 81
    Height = 21
    TabOrder = 1
    TextHint = 'a ='
  end
  object EditB: TEdit
    Left = 112
    Top = 168
    Width = 82
    Height = 21
    TabOrder = 2
    TextHint = 'b = '
  end
  object EditC: TEdit
    Left = 209
    Top = 168
    Width = 81
    Height = 21
    TabOrder = 3
    TextHint = 'c = '
  end
  object EditD: TEdit
    Left = 305
    Top = 168
    Width = 81
    Height = 21
    TabOrder = 4
    TextHint = 'd = '
  end
  object EditE: TEdit
    Left = 400
    Top = 168
    Width = 81
    Height = 21
    TabOrder = 5
    TextHint = 'e = '
  end
  object EditRPN: TEdit
    Left = 168
    Top = 48
    Width = 201
    Height = 21
    TabStop = False
    ReadOnly = True
    TabOrder = 8
    Text = 'Reverse polish notation'
  end
  object Button8: TButton
    Left = 16
    Top = 16
    Width = 130
    Height = 25
    Caption = #1044#1072#1085#1085#1099#1077' 8 '#1074#1072#1088#1080#1072#1085#1090#1072
    TabOrder = 9
    OnClick = Button8Click
  end
end
