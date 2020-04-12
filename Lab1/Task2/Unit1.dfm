object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1088#1099#1089#1072#1074#1072#1083#1082#1072
  ClientHeight = 600
  ClientWidth = 800
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnKeyDown = FormKeyDown
  DesignSize = (
    800
    600)
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Left = 0
    Top = 0
    Width = 600
    Height = 600
    Margins.Left = 0
    Margins.Top = 0
    Margins.Right = 0
    Margins.Bottom = 0
    Anchors = [akLeft, akTop, akRight, akBottom]
    Color = clWhite
    ParentColor = False
    OnClick = PaintBox1Click
    OnMouseDown = PaintBox1MouseDown
    OnMouseUp = PaintBox1MouseUp
  end
  object LabelP: TLabel
    Left = 619
    Top = 496
    Width = 99
    Height = 13
    Caption = #1055#1077#1088#1080#1084#1077#1090#1088' = 0 '#1087#1080#1082#1089'.'
  end
  object LabelS: TLabel
    Left = 619
    Top = 523
    Width = 97
    Height = 13
    Caption = #1055#1083#1086#1097#1072#1076#1100' = 0 '#1087#1080#1082#1089'.'
  end
  object LabelMass: TLabel
    Left = 619
    Top = 375
    Width = 61
    Height = 13
    Caption = #1062#1077#1085#1090#1088' '#1084#1072#1089#1089':'
  end
  object LabelScale: TLabel
    Left = 619
    Top = 405
    Width = 49
    Height = 13
    Caption = #1052#1072#1089#1096#1090#1072#1073':'
  end
  object LabelScale2: TLabel
    Left = 736
    Top = 401
    Width = 11
    Height = 13
    Caption = '%'
  end
  object LabelRotate1: TLabel
    Left = 618
    Top = 430
    Width = 47
    Height = 13
    Caption = #1055#1086#1074#1086#1088#1086#1090':'
  end
  object LabelBorderColor: TLabel
    Left = 619
    Top = 272
    Width = 41
    Height = 13
    Caption = #1050#1086#1085#1090#1091#1088':'
  end
  object InsideColorLabel: TLabel
    Left = 619
    Top = 299
    Width = 46
    Height = 13
    Caption = #1047#1072#1083#1080#1074#1082#1072':'
  end
  object LabelAction: TLabel
    Left = 634
    Top = 8
    Width = 108
    Height = 13
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1086#1087#1077#1088#1072#1094#1080#1102':'
  end
  object LabelColorsR: TLabel
    Left = 710
    Top = 250
    Width = 7
    Height = 13
    Caption = 'R'
  end
  object LabelColorsG: TLabel
    Left = 740
    Top = 250
    Width = 7
    Height = 13
    Caption = 'G'
  end
  object LabelColorsB: TLabel
    Left = 770
    Top = 250
    Width = 6
    Height = 13
    Caption = 'B'
  end
  object LabelMove: TLabel
    Left = 619
    Top = 350
    Width = 74
    Height = 13
    Caption = #1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077':'
  end
  object LabelRotate2: TLabel
    Left = 736
    Top = 425
    Width = 5
    Height = 13
    Caption = #176
  end
  object ButtonClear: TButton
    Left = 667
    Top = 567
    Width = 75
    Height = 25
    Caption = 'Clear'
    TabOrder = 0
    TabStop = False
    OnClick = ButtonClearClick
  end
  object EditMassPosX: TEdit
    Left = 699
    Top = 373
    Width = 31
    Height = 21
    TabStop = False
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 9
    Text = '0'
  end
  object EditMassPosY: TEdit
    Left = 736
    Top = 373
    Width = 31
    Height = 21
    TabStop = False
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 10
    Text = '0'
  end
  object ButtonChange: TButton
    Left = 757
    Top = 454
    Width = 28
    Height = 25
    Caption = #10004
    TabOrder = 11
    TabStop = False
    OnClick = ButtonChangeClick
  end
  object EditScale: TEdit
    Left = 699
    Top = 400
    Width = 31
    Height = 21
    TabStop = False
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 12
    Text = '100'
  end
  object EditRotate: TEdit
    Left = 699
    Top = 426
    Width = 31
    Height = 21
    TabStop = False
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 13
    Text = '0'
  end
  object ActionList: TComboBox
    Left = 634
    Top = 27
    Width = 145
    Height = 21
    AutoCompleteDelay = 0
    AutoDropDown = True
    Style = csDropDownList
    DropDownCount = 10
    TabOrder = 1
    OnChange = ActionListChange
    Items.Strings = (
      #1057#1083#1091#1095#1072#1081#1085#1072#1103' '#1092#1080#1075#1091#1088#1072
      #1055#1083#1072#1074#1085#1086#1091#1075#1086#1083#1100#1085#1080#1082
      #1052#1085#1086#1075#1086#1091#1075#1086#1083#1100#1085#1080#1082
      #1050#1088#1091#1075
      #1048#1079#1084#1077#1085#1077#1085#1080#1077' '#1086#1087#1086#1088#1085#1086#1081' '#1090#1086#1095#1082#1080)
  end
  object BorderColorR: TEdit
    Left = 699
    Top = 269
    Width = 25
    Height = 21
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 3
    Text = '0'
    OnClick = BothColorChange
  end
  object BorderColorG: TEdit
    Left = 730
    Top = 269
    Width = 25
    Height = 21
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 4
    Text = '0'
    OnClick = BothColorChange
  end
  object BorderColorB: TEdit
    Left = 760
    Top = 269
    Width = 25
    Height = 21
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 5
    Text = '0'
    OnClick = BothColorChange
  end
  object InsideColorB: TEdit
    Left = 761
    Top = 296
    Width = 25
    Height = 21
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 8
    Text = '0'
    OnClick = BothColorChange
  end
  object InsideColorG: TEdit
    Left = 730
    Top = 296
    Width = 25
    Height = 21
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 7
    Text = '0'
    OnClick = BothColorChange
  end
  object InsideColorR: TEdit
    Left = 699
    Top = 296
    Width = 26
    Height = 21
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 6
    Text = '0'
    OnClick = BothColorChange
  end
  object InsideTrans: TCheckBox
    Left = 679
    Top = 298
    Width = 14
    Height = 17
    TabStop = False
    TabOrder = 14
    OnClick = BothColorChange
  end
  object BorderWidthEdit: TEdit
    Left = 678
    Top = 269
    Width = 15
    Height = 21
    MaxLength = 1
    NumbersOnly = True
    TabOrder = 2
    Text = '1'
  end
  object EditMove: TEdit
    Left = 699
    Top = 346
    Width = 21
    Height = 21
    ReadOnly = True
    TabOrder = 15
    OnKeyDown = FormKeyDown
  end
  object ButtonChangeCur: TButton
    Left = 642
    Top = 136
    Width = 125
    Height = 25
    Caption = #1057#1084#1077#1085#1080#1090#1100' '#1092#1086#1082#1091#1089
    TabOrder = 16
    OnClick = ButtonChangeCurClick
  end
  object Button1: TButton
    Left = 655
    Top = 176
    Width = 100
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1092#1080#1075#1091#1088#1091
    TabOrder = 17
    OnClick = Button1Click
  end
  object Timer30FPS: TTimer
    Enabled = False
    Interval = 30
    OnTimer = Timer30FPSTimer
    Left = 120
    Top = 40
  end
  object OnceUpon: TTimer
    Interval = 1
    OnTimer = OnceUponTimer
    Left = 40
    Top = 40
  end
end
