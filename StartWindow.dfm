object StartForm: TStartForm
  Left = 0
  Top = 0
  Caption = 'Moara'
  ClientHeight = 485
  ClientWidth = 308
  Color = clAppWorkSpace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 48
    Top = 72
    Width = 201
    Height = 74
    Caption = 'MOARA'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -53
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object btnPickServer: TButton
    Left = 80
    Top = 200
    Width = 129
    Height = 41
    Caption = 'I want to be server'
    TabOrder = 0
    OnClick = btnPickServerClick
  end
  object btnPickClient: TButton
    Left = 80
    Top = 288
    Width = 129
    Height = 41
    Caption = 'I want to be client'
    TabOrder = 1
    OnClick = btnPickClientClick
  end
end
