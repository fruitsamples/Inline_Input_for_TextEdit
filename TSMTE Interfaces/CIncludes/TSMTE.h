/*	File:		TSMTE.h	Contains:	Definitions for TSMTE	Copyright:	�1991-1993 Apple Technology, Inc.				All rights reserved.*/#ifndef __TSMTE__#define __TSMTE__#ifndef __TEXTEDIT__#include <TextEdit.h>#endif#ifndef __DIALOGS__#include <Dialogs.h>#endif#ifndef __TEXTSERVICES__#include <TextServices.h>#endif// signature, interface typesenum {	kTSMTESignature = 'tmTE',	kTSMTEInterfaceType = kTSMTESignature,	kTSMTEDialog = 'tmDI'};// Gestaltenum {	gestaltTSMTEAttr = kTSMTESignature,	gestaltTSMTEPresent = 0,	gestaltTSMTE = gestaltTSMTEPresent,	// old name, for compatibility only	gestaltTSMTEVersion = 'tmTV',	gestaltTSMTE1 = 0x100};// update flag for TSMTERecenum {	kTSMTEAutoScroll = 1};// callback procedure definitionstypedef pascal void (*TSMTEPreUpdateProcPtr)(TEHandle textH, long refCon);typedef pascal void (*TSMTEPostUpdateProcPtr)(TEHandle textH, long fixLen,		long inputAreaStart, long inputAreaEnd,		long pinStart, long pinEnd, long refCon);// data typesstruct TSMTERec{	TEHandle				textH;	TSMTEPreUpdateProcPtr	preUpdateProc;	TSMTEPostUpdateProcPtr	postUpdateProc;	long					updateFlag;	long					refCon;};typedef struct TSMTERec TSMTERec, *TSMTERecPtr, **TSMTERecHandle;struct TSMDialogRecord{	DialogRecord	fDialog;	TSMDocumentID	fDocID;	TSMTERecHandle	fTSMTERecH;	long			fTSMTERsvd[3];			// reserved};typedef struct TSMDialogRecord TSMDialogRecord, *TSMDialogPeek;#endif