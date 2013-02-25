; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=ShadowDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BaeTree.h"

ClassCount=4
Class1=CBaeTreeApp
Class2=CBaeTreeDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_BAETREE_DIALOG
Resource2=IDR_MAINFRAME
Class4=ShadowDlg
Resource3=IDD_ABOUTBOX
Resource4=IDD_SHADOW_DIALOG

[CLS:CBaeTreeApp]
Type=0
HeaderFile=BaeTree.h
ImplementationFile=BaeTree.cpp
Filter=N

[CLS:CBaeTreeDlg]
Type=0
HeaderFile=BaeTreeDlg.h
ImplementationFile=BaeTreeDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CBaeTreeDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=BaeTreeDlg.h
ImplementationFile=BaeTreeDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BAETREE_DIALOG]
Type=1
Class=CBaeTreeDlg
ControlCount=2
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_BUTTON1,button,1342242816

[DLG:IDD_SHADOW_DIALOG]
Type=1
Class=ShadowDlg
ControlCount=0

[CLS:ShadowDlg]
Type=0
HeaderFile=ShadowDlg.h
ImplementationFile=ShadowDlg.cpp
BaseClass=CDialog
Filter=W
LastObject=ShadowDlg
VirtualFilter=dWC

