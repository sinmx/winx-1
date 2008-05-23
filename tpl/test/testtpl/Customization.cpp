#include "stdafx.h"

// -------------------------------------------------------------------------
// customize

// What we use:
//  * Customization
//	* Rules: RegExp, RegExp0, +, /, %, digit(), repeat(), skipws()
//	* Tags: Leaf*, LeafMark
//	* Matching: RegExp::match()
//	* Result Processing: Document::all()

class My : public tpl::policy::Default
{
public:
	typedef std::AutoFreeAlloc Allocator;
};

void customize()
{
	using namespace tpl;

	typedef Customization<My> impl;

	// ---- define source ----

	char buf[] = "1928-10-1, 97-1-3, 1977/3/28";
	impl::Source source(buf, buf+sizeof(buf));

	// ---- define rules ----

	impl::Allocator alloc;

	impl::Leaf delim;
	impl::LeafMark tagTime;

	impl::RegExp0 rYear( alloc, repeat<1, 2>(repeat<2>(digit())) );
	impl::RegExp0 rMonOrDay( alloc, repeat<1, 2>(digit()) );
	impl::RegExp0 rTime( alloc, rYear + ch<'-', '/'>()/&delim + rMonOrDay + delim + rMonOrDay );
	impl::RegExp rDoc( alloc, rTime/tagTime % (',' + skipws()) );

	// ---- do match ----

	impl::Document doc;
	impl::Context context(alloc, doc);

	if (!rDoc.match(source, context)) {
		std::cout << "match failed\n";
		return;
	}

	// ---- print time ----

	for (impl::Document::cons it = doc.all(); it; it = it.tl()) {
		std::cout << it.hd().leaf().stl_str() << "\n";
	}
}

// -------------------------------------------------------------------------
