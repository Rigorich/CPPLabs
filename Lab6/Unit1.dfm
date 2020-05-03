object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1083#1105' '#1044#1077#1088#1077#1074#1086
  ClientHeight = 550
  ClientWidth = 750
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    750
    550)
  PixelsPerInch = 96
  TextHeight = 13
  object TreeView1: TTreeView
    Left = 8
    Top = 8
    Width = 310
    Height = 465
    Anchors = [akLeft, akTop, akRight, akBottom]
    Indent = 19
    ReadOnly = True
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 324
    Top = 8
    Width = 267
    Height = 320
    Anchors = [akTop, akRight]
    ColCount = 2
    DefaultColWidth = 115
    DefaultRowHeight = 25
    FixedColor = clSilver
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing]
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object ButtonAdd: TButton
    Left = 597
    Top = 278
    Width = 145
    Height = 50
    Anchors = [akTop, akRight]
    Caption = 'Add new to Tree'
    TabOrder = 2
    OnClick = ButtonAddClick
    ExplicitLeft = 547
  end
  object ButtonClear: TButton
    Left = 597
    Top = 479
    Width = 145
    Height = 50
    Anchors = [akTop, akRight]
    Caption = 'Clear'
    TabOrder = 3
    OnClick = ButtonClearClick
    ExplicitLeft = 547
  end
  object ButtonDelete: TButton
    Left = 672
    Top = 409
    Width = 70
    Height = 50
    Anchors = [akTop, akRight]
    Caption = 'Delete'
    TabOrder = 4
    OnClick = ButtonDeleteClick
  end
  object EditKey: TEdit
    Left = 597
    Top = 224
    Width = 145
    Height = 21
    Anchors = [akTop, akRight]
    MaxLength = 9
    NumbersOnly = True
    ParentShowHint = False
    ShowHint = False
    TabOrder = 5
    TextHint = 'New key'
    ExplicitLeft = 547
  end
  object EditValue: TEdit
    Left = 597
    Top = 251
    Width = 145
    Height = 21
    Anchors = [akTop, akRight]
    ParentShowHint = False
    ShowHint = False
    TabOrder = 6
    TextHint = 'New value'
    ExplicitLeft = 547
  end
  object ButtonMove: TButton
    Left = 597
    Top = 145
    Width = 145
    Height = 50
    Anchors = [akTop, akRight]
    Caption = 'StringGrid -> Tree'
    TabOrder = 7
    OnClick = ButtonMoveClick
    ExplicitLeft = 547
  end
  object EditDelKey: TEdit
    Left = 597
    Top = 382
    Width = 145
    Height = 21
    Anchors = [akTop, akRight]
    MaxLength = 9
    NumbersOnly = True
    ParentShowHint = False
    ShowHint = False
    TabOrder = 8
    TextHint = 'Key to find/delete'
  end
  object ButtonNew: TButton
    Left = 597
    Top = 16
    Width = 145
    Height = 50
    Anchors = [akTop, akRight]
    Caption = 'New empty cell'
    TabOrder = 9
    OnClick = ButtonNewClick
    ExplicitLeft = 547
  end
  object ButtonRandom: TButton
    Left = 597
    Top = 72
    Width = 145
    Height = 50
    Anchors = [akTop, akRight]
    Caption = 'New random cell'
    TabOrder = 10
    OnClick = ButtonRandomClick
    ExplicitLeft = 547
  end
  object StringGridLevels: TStringGrid
    Left = 8
    Top = 492
    Width = 310
    Height = 50
    Anchors = [akLeft, akRight, akBottom]
    ColCount = 2
    DefaultColWidth = 25
    DefaultRowHeight = 20
    RowCount = 2
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
    ScrollBars = ssNone
    TabOrder = 11
  end
  object Memo1: TMemo
    Left = 324
    Top = 382
    Width = 267
    Height = 160
    Anchors = [akTop, akRight, akBottom]
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 12
  end
  object RadioGroup1: TRadioGroup
    Left = 324
    Top = 334
    Width = 267
    Height = 42
    Anchors = [akTop, akRight]
    Caption = 'Traversing '
    Columns = 3
    Items.Strings = (
      'direct'
      'reverse'
      'increasing')
    TabOrder = 13
    OnClick = RadioGroup1Click
  end
  object ButtonFind: TButton
    Left = 597
    Top = 409
    Width = 69
    Height = 50
    Anchors = [akTop, akRight]
    Caption = 'Find'
    TabOrder = 14
    OnClick = ButtonFindClick
  end
end
