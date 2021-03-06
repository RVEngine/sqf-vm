#pragma once
#include <memory>
#include <queue>
#include <string>
#include "varscope.h"

namespace sqf
{
	class instruction;
	class virtualmachine;
	class sqfnamespace;


	class callstack : public varscope
	{
	private:
		std::queue<std::shared_ptr<sqf::instruction>> mstack;
		std::shared_ptr<sqf::sqfnamespace> mwith;
	public:
		callstack();
		callstack(std::shared_ptr<sqf::sqfnamespace>);
		inline void pushinst(std::shared_ptr<sqf::instruction> value) { mstack.push(value); }
		virtual std::shared_ptr<sqf::instruction> popinst(sqf::virtualmachine* vm) { if (mstack.empty()) return std::shared_ptr<sqf::instruction>(); auto ret = mstack.front(); mstack.pop(); return ret; }
		std::shared_ptr<sqf::instruction> peekinst(void) { if (mstack.empty()) return std::shared_ptr<sqf::instruction>(); auto front = mstack.front(); return front; }
		inline std::shared_ptr<sqf::sqfnamespace> getnamespace(void) const { return mwith; }
		inline size_t inststacksize(void) const { return mstack.size(); }
		inline void setnamespace(std::shared_ptr<sqf::sqfnamespace> ns) { mwith = ns; }
	};
}
