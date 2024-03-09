#ifndef SERIALCOMMANDER_H
#define SERIALCOMMANDER_H

#if defined (_WIN32) 
#if defined(SERIALCOMMANDER_EXPORT)
#define SERIALCOMMANDER_API __declspec(dllexport)
#else
#define SERIALCOMMANDER_API __declspec(dllimport)
#endif /* SERIALCOMMANDER_API */
#define _sprintf sprintf_s
#endif

#if defined(__GNUC__)
//  GCC
#define SERIALCOMMANDER __attribute__((visibility("default")))
#endif
#include <vector>
#include <string>

//class that does nothing
class SERIALCOMMANDER_API SerialCommander
{
public:
	SerialCommander();
	~SerialCommander();
	static std::vector<std::string> GetComports();
};

#endif //SERIALCOMMANDER_H