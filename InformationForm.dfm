object InfoForm: TInfoForm
  Left = 0
  Top = 0
  Caption = 'InfoForm'
  ClientHeight = 154
  ClientWidth = 621
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object InfoLabel: TLabel
    Left = 32
    Top = 48
    Width = 575
    Height = 25
    Caption = 'S-a realizat o moara, te rog sa alegi piesa care sa fie distrusa'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Ok: TButton
    Left = 272
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Ok'
    ModalResult = 1
    TabOrder = 0
  end
end
