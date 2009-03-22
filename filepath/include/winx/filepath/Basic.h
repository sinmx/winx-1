/* -------------------------------------------------------------------------
// WINX: a C++ template GUI library - MOST SIMPLE BUT EFFECTIVE
// 
// This file is a part of the WINX Library.
// The use and distribution terms for this software are covered by the
// Common Public License 1.0 (http://opensource.org/licenses/cpl.php)
// which can be found in the file CPL.txt at this distribution. By using
// this software in any fashion, you are agreeing to be bound by the terms
// of this license. You must not remove this notice, or any other, from
// this software.
// 
// Module: winx/filepath/Basic.h
// Creator: xushiwei
// Email: xushiweizh@gmail.com
// Date: 2006-8-19 14:23:22
// 
// $Id: Basic.h,v 1.9 2006/12/22 10:22:28 xushiwei Exp $
// -----------------------------------------------------------------------*/
#ifndef WINX_FILEPATH_BASIC_H
#define WINX_FILEPATH_BASIC_H

#ifndef STDEXT_BASIC_H
#include "../../../../stdext/include/stdext/Basic.h"
#endif

#ifndef NS_FILEPATH
#define NS_FILEPATH			winx
#define NS_FILEPATH_BEGIN	namespace winx {
#define NS_FILEPATH_END		}
#endif

NS_FILEPATH_BEGIN

// -------------------------------------------------------------------------
// IsFileExist

inline bool IsFileExist(LPCSTR szFile)
{
	DWORD dw = GetFileAttributesA(szFile);
	if (dw == (DWORD)-1)
		return false;
	
	return !(dw & FILE_ATTRIBUTE_DIRECTORY);
}

inline bool IsFileExist(LPCWSTR szFile)
{
	DWORD dw = GetFileAttributesW(szFile);
	if (dw == (DWORD)-1)
		return false;
	
	return !(dw & FILE_ATTRIBUTE_DIRECTORY);
}

// -------------------------------------------------------------------------
// $Log: Basic.h,v $

NS_FILEPATH_END

#endif /* WINX_FILEPATH_BASIC_H */
