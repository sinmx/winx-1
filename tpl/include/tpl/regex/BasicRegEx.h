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
// Module: tpl/regex/BasicRegEx.h
// Creator: xushiwei
// Email: xushiweizh@gmail.com
// Date: 2006-8-13 9:41:58
// 
// $Id$
// -----------------------------------------------------------------------*/
#ifndef TPL_REGEX_BASICREGEX_H
#define TPL_REGEX_BASICREGEX_H

#ifndef TPL_REGEX_BASIC_H
#include "Basic.h"
#endif

NS_TPL_BEGIN

// -------------------------------------------------------------------------
// class IRegExp

template <class SourceT, class ContextT, bool bManaged = true>
class IRegExp
{
private:
	typedef bool TPL_CALL _FN_match(const void* pThis, SourceT& ar, ContextT& context);
	typedef _FN_match* FN_match;

	const void* m_this;
	FN_match m_fn;

public:
	IRegExp() : m_this(NULL) {}
	
	template <class AllocT, class RegExT>
	IRegExp(AllocT& alloc, const RegExT& x)
	{
		assign(alloc, x);
	}

	bool TPL_CALL match(SourceT& ar, ContextT& context) const {
		TPL_ASSERT(m_this);
		return m_fn(m_this, ar, context);
	}

public:
	template <class RegExT>
	class Impl
	{
	private:
		RegExT m_x;

	public:
		Impl(const Exp<RegExT>& x)
			: m_x(static_cast<const RegExT&>(x)) {
		}

		static bool TPL_CALL match(const void* pThis, SourceT& ar, ContextT& context) {
			const RegExT& x = ((const Impl*)pThis)->m_x;
			return x.match(ar, context);
		}
	};

	template <class AllocT, class RegExT>
	void TPL_CALL assign(AllocT& alloc, const Exp<RegExT>& x)
	{
		typedef Impl<RegExT> Imp;
		if (bManaged)
			m_this = TPL_NEW(alloc, Imp)(x);
		else
			m_this = TPL_UNMANAGED_NEW(alloc, Imp)(x);
	
		m_fn = Imp::match;
	}
};

// -------------------------------------------------------------------------
// class BasicRegEx

#if defined(TPL_HAS_TEMPLATE_TYPEDEF)

template <class SourceT, class ContextT, bool bManaged = true>
typedef Exp<IRegExp<SourceT, ContextT, bManaged> > BasicRegEx;

#else

template <class SourceT, class ContextT, bool bManaged = true>
class BasicRegEx : public Exp<IRegExp<SourceT, ContextT, bManaged> >
{
private:
	typedef Exp<IRegExp<SourceT, ContextT, bManaged> > Base;

public:
	BasicRegEx() {}

	template <class AllocT, class RegExT>
	BasicRegEx(AllocT& alloc, const RegExT& x)
		: Base(alloc, x) {}
};

#endif

// -------------------------------------------------------------------------
// $Log: $

NS_TPL_END

#endif /* TPL_REGEX_BASICREGEX_H */
