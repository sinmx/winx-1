
extern dom::NodeMark tagSentences("sentences", true);
extern dom::NodeMark tagBaseClasses("bases", true);
extern dom::NodeMark tagArgs("args", true);

extern dom::NodeMark tagTemplate("template");
extern dom::NodeMark tagClass("class");
extern dom::NodeMark tagMember("member");
extern dom::NodeMark tagGlobal("global");
extern dom::NodeMark tagConstructor("ctor");
extern dom::NodeMark tagDestructor("dtor");
extern dom::NodeMark tagTypeCast("typecast");
extern dom::NodeMark tagTypedef("type");
extern dom::NodeMark tagEnum("enum");
extern dom::NodeMark tagMacro("macro");
extern dom::NodeMark tagMacroArgList("arglist");

extern dom::Mark tagClassKeyword("keyword");
extern dom::Mark tagHeader("header");
extern dom::Mark tagAccess("access");
extern dom::Mark tagType("type");
extern dom::Mark tagCallType("calltype");
extern dom::Mark tagName("name");
extern dom::Mark tagAttr2("funcattr");
extern dom::Mark tagDefVal("defval");
extern dom::Mark tagMacroBody("body");
extern dom::Mark tagMacroArgs("args", true);

impl::Allocator alloc;
impl::MarkedGrammar rCppSymbol(alloc, cppsymbol);
impl::MarkedGrammar rType(alloc, type);
impl::MarkedGrammar rClass(alloc, classdef);
String className;
String encoding;

dom::Document doc(alloc);
