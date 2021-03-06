#pragma once

#include <memory>
namespace sqf
{
	class virtualmachine;
}
#ifdef _WIN32
#define DLLEXPORT_PREFIX __declspec(dllexport)
#else
#define DLLEXPORT_PREFIX __attribute__((visibility("default")))
#endif

static std::shared_ptr<sqf::virtualmachine> py_virtualmachine;
extern "C" {
	DLLEXPORT_PREFIX void py_init(unsigned long long);
	DLLEXPORT_PREFIX void py_exec(char*, char*, unsigned int);
	DLLEXPORT_PREFIX void py_loadconfig(char* cfg);
	DLLEXPORT_PREFIX void py_uninit(void);
}