object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1083#1105' '#1057#1087#1080#1089#1086#1082
  ClientHeight = 400
  ClientWidth = 850
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    850
    400)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 20
    Top = 60
    Width = 52
    Height = 13
    Caption = #1053#1072#1079#1074#1072#1085#1080#1077':'
  end
  object Label2: TLabel
    Left = 8
    Top = 147
    Width = 64
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086':'
  end
  object Label4: TLabel
    Left = 8
    Top = 243
    Width = 62
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1094#1077#1093#1072':'
  end
  object EditName: TEdit
    Left = 104
    Top = 57
    Width = 281
    Height = 21
    TabOrder = 0
  end
  object EditCount: TEdit
    Left = 104
    Top = 144
    Width = 281
    Height = 21
    MaxLength = 16
    NumbersOnly = True
    TabOrder = 1
  end
  object EditNumber: TEdit
    Left = 104
    Top = 240
    Width = 281
    Height = 21
    MaxLength = 9
    NumbersOnly = True
    TabOrder = 2
  end
  object ButtonSaveChanges: TButton
    Left = 104
    Top = 312
    Width = 161
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' / '#1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 3
    OnClick = ButtonSaveChangesClick
  end
  object ButtonDelete: TButton
    Left = 104
    Top = 352
    Width = 161
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
    TabOrder = 4
    TabStop = False
    OnClick = ButtonDeleteClick
  end
  object ComboBoxSearch: TComboBox
    Left = 440
    Top = 18
    Width = 113
    Height = 21
    TabOrder = 5
    Text = #1055#1086#1080#1089#1082' '#1087#1086
    OnChange = ComboBoxSearchChange
    Items.Strings = (
      '---'
      #1053#1072#1079#1074#1072#1085#1080#1077
      #1053#1086#1084#1077#1088' '#1094#1077#1093#1072
      #1057#1091#1084#1084#1072' '#1090#1086#1074#1072#1088#1086#1074)
  end
  object EditSearch: TEdit
    Left = 559
    Top = 18
    Width = 201
    Height = 21
    TabOrder = 6
    TextHint = #1050#1083#1102#1095' '#1087#1086#1080#1089#1082#1072
    OnChange = ButtonSearchClick
  end
  object ListBox: TListBox
    Left = 440
    Top = 45
    Width = 401
    Height = 332
    TabStop = False
    Anchors = [akLeft, akTop, akRight, akBottom]
    ItemHeight = 13
    TabOrder = 7
    OnClick = ListBoxClick
  end
  object ButtonOpenDialog: TButton
    Left = 296
    Top = 312
    Width = 89
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1041#1044
    TabOrder = 8
    OnClick = ButtonOpenDialogClick
  end
  object ButtonSaveDialog: TButton
    Left = 296
    Top = 352
    Width = 89
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1041#1044
    TabOrder = 9
    OnClick = ButtonSaveDialogClick
  end
  object ButtonFlushList: TButton
    Left = 767
    Top = 14
    Width = 75
    Height = 25
    Caption = #1057#1073#1088#1086#1089#1080#1090#1100
    TabOrder = 10
    OnClick = ButtonFlushListClick
  end
  object CheckBoxAddProduct: TCheckBox
    Left = 104
    Top = 18
    Width = 177
    Height = 17
    Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1085#1086#1074#1086#1075#1086' '#1087#1088#1086#1076#1091#1082#1090#1072
    Checked = True
    State = cbChecked
    TabOrder = 11
    OnClick = CheckBoxAddProductClick
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'database'
    Filter = #1041#1072#1079#1072' '#1076#1072#1085#1085#1099#1093'(*.database)|*.database'
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093
    Left = 392
    Top = 312
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'database'
    Filter = #1041#1072#1079#1072' '#1076#1072#1085#1085#1099#1093'(*.database)|*.database'
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093
    Left = 392
    Top = 352
  end
end
