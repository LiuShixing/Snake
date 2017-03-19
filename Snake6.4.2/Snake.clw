; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=EnterHero
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Snake.h"
LastPage=0

ClassCount=8
Class1=CSnakeApp
Class2=CSnakeDoc
Class3=CSnakeView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_DIALOG2
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CEnter
Resource3=IDD_ABOUTBOX
Class7=Enter2
Resource4=IDD_DIALOG1
Class8=EnterHero
Resource5=IDD_GETNAME

[CLS:CSnakeApp]
Type=0
HeaderFile=Snake.h
ImplementationFile=Snake.cpp
Filter=N

[CLS:CSnakeDoc]
Type=0
HeaderFile=SnakeDoc.h
ImplementationFile=SnakeDoc.cpp
Filter=N

[CLS:CSnakeView]
Type=0
HeaderFile=SnakeView.h
ImplementationFile=SnakeView.cpp
Filter=C
LastObject=CSnakeView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Snake.cpp
ImplementationFile=Snake.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=CEnter
ControlCount=18
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342178055
Control5=IDC_Shanks,button,1342308361
Control6=IDC_Space,button,1342177289
Control7=IDC_Unkown,button,1342177289
Control8=IDC_SnakeI,button,1342177289
Control9=IDC_SnakeII,button,1342177289
Control10=IDC_STATIC,button,1342177543
Control11=IDC_OPEN,button,1342308361
Control12=IDC_OFF,button,1342177289
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,button,1342177287
Control15=IDC_EASY,button,1342308361
Control16=IDC_HARD,button,1342177289
Control17=IDC_VERYHARD,button,1342177289
Control18=IDC_MOST,button,1342177289

[CLS:CEnter]
Type=0
HeaderFile=Enter.h
ImplementationFile=Enter.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_OFF
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=Enter2
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342312449
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_NAME1,static,1342308352
Control11=IDC_MARK1,static,1342308352
Control12=IDC_MARK2,static,1342308352
Control13=IDC_NAME2,static,1342308352
Control14=IDC_NAME3,static,1342308352
Control15=IDC_NAME4,static,1342308352
Control16=IDC_MARK4,static,1342308352
Control17=IDC_MARK3,static,1342308352

[CLS:Enter2]
Type=0
HeaderFile=Enter2.h
ImplementationFile=Enter2.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_NAME1
VirtualFilter=dWC

[DLG:IDD_GETNAME]
Type=1
Class=EnterHero
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_NAME,edit,1350762624
Control5=IDC_STATIC,static,1342308352

[CLS:EnterHero]
Type=0
HeaderFile=EnterHero.h
ImplementationFile=EnterHero.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

