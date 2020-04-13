object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1083#1105' '#1041#1072#1079#1072' '#1044#1072#1085#1085#1099#1093
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
    Left = 8
    Top = 60
    Width = 74
    Height = 13
    Caption = #1048#1084#1103' '#1087#1072#1094#1080#1077#1085#1090#1072':'
  end
  object Label2: TLabel
    Left = 38
    Top = 171
    Width = 44
    Height = 13
    Caption = #1042#1086#1079#1088#1072#1089#1090':'
  end
  object Label3: TLabel
    Left = 36
    Top = 219
    Width = 46
    Height = 13
    Caption = #1044#1080#1072#1075#1085#1086#1079':'
  end
  object Label4: TLabel
    Left = 6
    Top = 267
    Width = 76
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1087#1072#1083#1072#1090#1099':'
  end
  object EditName: TEdit
    Left = 104
    Top = 57
    Width = 281
    Height = 21
    TabOrder = 0
  end
  object RadioGroupSex: TRadioGroup
    Left = 104
    Top = 104
    Width = 201
    Height = 41
    Caption = #1055#1086#1083':'
    Columns = 2
    Items.Strings = (
      #1052#1091#1078#1089#1082#1086#1081
      #1046#1077#1085#1089#1082#1080#1081)
    TabOrder = 1
    TabStop = True
  end
  object EditAge: TEdit
    Left = 104
    Top = 168
    Width = 281
    Height = 21
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 2
    TextHint = #1042#1086#1079#1088#1072#1089#1090' '#1087#1072#1094#1080#1077#1085#1090#1072' '#1074' '#1076#1080#1072#1087#1072#1079#1086#1085#1077' '#1086#1090' 18 '#1076#1086' 150'
  end
  object EditDiagnosis: TEdit
    Left = 104
    Top = 216
    Width = 281
    Height = 21
    TabOrder = 3
  end
  object EditWard: TEdit
    Left = 104
    Top = 264
    Width = 281
    Height = 21
    NumbersOnly = True
    TabOrder = 4
    TextHint = #1053#1086#1084#1077#1088' '#1087#1072#1083#1072#1090#1099' '#1080#1083#1080' 0 '#1076#1083#1103' '#1087#1086#1076#1073#1086#1088#1072
  end
  object ButtonSaveChanges: TButton
    Left = 104
    Top = 312
    Width = 161
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' / '#1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 5
    OnClick = ButtonSaveChangesClick
  end
  object ButtonDelete: TButton
    Left = 104
    Top = 352
    Width = 161
    Height = 25
    Caption = #1042#1099#1087#1080#1089#1072#1090#1100' '#1087#1072#1094#1080#1077#1085#1090#1072
    TabOrder = 6
    TabStop = False
    OnClick = ButtonDeleteClick
  end
  object ComboBoxSearch: TComboBox
    Left = 440
    Top = 64
    Width = 113
    Height = 21
    TabOrder = 7
    Text = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
    OnChange = ButtonSearchClick
    Items.Strings = (
      #1055#1072#1083#1072#1090#1072
      #1044#1080#1072#1075#1085#1086#1079
      #1060#1048#1054)
  end
  object EditSearch: TEdit
    Left = 559
    Top = 64
    Width = 201
    Height = 21
    TabOrder = 8
    TextHint = #1050#1083#1102#1095' '#1087#1086#1080#1089#1082#1072
    OnChange = ButtonSearchClick
  end
  object ListBox: TListBox
    Left = 440
    Top = 103
    Width = 401
    Height = 274
    TabStop = False
    Anchors = [akLeft, akTop, akRight, akBottom]
    ItemHeight = 13
    TabOrder = 9
    OnClick = ListBoxClick
  end
  object ButtonOpenDialog: TButton
    Left = 296
    Top = 312
    Width = 89
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1041#1044
    TabOrder = 10
    OnClick = ButtonOpenDialogClick
  end
  object ButtonSaveDialog: TButton
    Left = 296
    Top = 352
    Width = 89
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1041#1044
    TabOrder = 11
    OnClick = ButtonSaveDialogClick
  end
  object RadioButtonList: TRadioGroup
    Left = 440
    Top = 8
    Width = 401
    Height = 41
    BiDiMode = bdLeftToRight
    Caption = #1057#1087#1080#1089#1086#1082' '#1087#1072#1094#1080#1077#1085#1090#1086#1074':'
    Columns = 2
    Items.Strings = (
      #1058#1077#1082#1091#1097#1080#1077' '#1087#1072#1094#1080#1077#1085#1090#1099
      #1054#1078#1080#1076#1072#1102#1097#1080#1077' '#1088#1072#1079#1084#1077#1097#1077#1085#1080#1103)
    ParentBiDiMode = False
    TabOrder = 12
    OnClick = RadioButtonListClick
  end
  object ButtonFlushList: TButton
    Left = 766
    Top = 62
    Width = 75
    Height = 25
    Caption = #1057#1073#1088#1086#1089#1080#1090#1100
    TabOrder = 13
    OnClick = ButtonFlushListClick
  end
  object CheckBoxAddPatient: TCheckBox
    Left = 104
    Top = 18
    Width = 177
    Height = 17
    Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1085#1086#1074#1086#1075#1086' '#1087#1072#1094#1080#1077#1085#1090#1072
    Checked = True
    State = cbChecked
    TabOrder = 14
    OnClick = CheckBoxAddPatientClick
  end
  object OpenDialog: TOpenDialog
    DefaultExt = 'database'
    Filter = #1041#1072#1079#1072' '#1076#1072#1085#1085#1099#1093'(*.database)|*.database'
    InitialDir = 'C:\BSUIR\CPP\Lab2\Databases'
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093
    Left = 392
    Top = 312
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'database'
    Filter = #1041#1072#1079#1072' '#1076#1072#1085#1085#1099#1093'(*.database)|*.database'
    InitialDir = 'C:\BSUIR\CPP\Lab2\Databases'
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093
    Left = 392
    Top = 352
  end
end
