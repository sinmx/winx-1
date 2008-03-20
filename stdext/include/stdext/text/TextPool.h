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
// Module: stdext/text/TextPool.h
// Creator: xushiwei
// Email: xushiweizh@gmail.com
// Date: 2006-8-18 18:56:07
// 
// $Id: TextPool.h,v 1.1 2006/10/18 12:13:39 xushiwei Exp $
// -----------------------------------------------------------------------*/
#ifndef __STDEXT_TEXT_TEXTPOOL_H__
#define __STDEXT_TEXT_TEXTPOOL_H__

#ifndef __STDEXT_BASIC_H__
#include "../Basic.h"
#endif

#ifndef __STD_DEQUE_H__
#include "../../std/deque.h"
#endif

__NS_STD_BEGIN

// -------------------------------------------------------------------------
// class TextPool

template <class CharT>
class TextPool : public std::deque<CharT>
{
private:
	typedef std::deque<CharT> _Base;

public:
	typedef typename _Base::size_type size_type;

public:
	TextPool() {}
	explicit TextPool(size_type count, const CharT& ch = CharT())
		: _Base(count, ch) {}
};

// -------------------------------------------------------------------------
// class TestTextPool

template <class LogT>
class TestTextPool : public TestCase
{
	WINX_TEST_SUITE(TestTextPool);
		WINX_TEST(test);
	WINX_TEST_SUITE_END();

public:
	void test(LogT& log)
	{
	}
};

// -------------------------------------------------------------------------
// $Log: TextPool.h,v $

__NS_STD_END

#endif /* __STDEXT_TEXT_TEXTPOOL_H__ */