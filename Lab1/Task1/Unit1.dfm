object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 700
  ClientWidth = 700
  Color = clBtnFace
  DoubleBuffered = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object RightHandTrackBar: TTrackBar
    Left = 662
    Top = 440
    Width = 30
    Height = 252
    Max = 180
    Orientation = trVertical
    PageSize = 1
    Frequency = 30
    ShowSelRange = False
    TabOrder = 1
    TickMarks = tmTopLeft
    OnChange = RightHandTrackBarChange
  end
  object LeftHandTrackBar: TTrackBar
    Left = 8
    Top = 440
    Width = 30
    Height = 252
    DragKind = dkDock
    Max = 12
    Orientation = trVertical
    PageSize = 1
    Frequency = 30
    ShowSelRange = False
    TabOrder = 0
    OnChange = LeftHandTrackBarChange
  end
  object Timer1: TTimer
    Interval = 1
    OnTimer = Timer1Timer
    Left = 672
  end
end