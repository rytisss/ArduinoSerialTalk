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
#include <mutex>
#include <string>
#include <thread>
#include <boost/asio.hpp>
#include <boost/signals2.hpp>

//class that does nothing
class SERIALCOMMANDER_API SerialCommander
{
public:
	SerialCommander();
	~SerialCommander();
	// Start listening asynchronouosly
	void StartListening(std::string com);
	// Stop listening for comport
	void StopListening();
	// Is listening status
	bool IsListening();
	// Send command
	void SendCommand(const std::string& command);
	// retrieves the latest discovered comports
	std::vector<std::string> GetComports();
	// Scan for comports (async)
	void ScanForComPorts();
	// Status if the scanning of com port is ongoing
	bool IsScanningComports();

private:
	// latest discovered comports
	std::vector<std::string> m_comPorts;
	// comport update lock
	std::mutex m_comPortUpdateLock;
	// [thread-safe] update comports
	void UpdataComports(std::vector<std::string>& newComPorts);
	// Blocking ports scan. Externally should be accessed through GetComports()
	void GetComportsBlocking();
	// Lets start listening and commanding specified comport synchrinouosly
	void StartListeningSync(std::string com);
	// listening thread
	std::jthread m_listeningThread;
	// com ports scanning flag, indicated if com ports scanning is active at the moment
	std::atomic_bool m_comPortsAreScanned;
	// flag indicating if comport port is listened
	std::atomic_bool m_isComPortListened;
	// currently listened comport
	std::string m_currentComPort;
	// I/O for port listening access
	boost::asio::io_service m_io;
	// port listener
	boost::asio::serial_port m_port;

	// send command setting lock
	std::mutex m_commandLock;
	// command itself
	std::string m_command;
	// [thread-safe] set command
	void SetCommand(const std::string& command);
	// [thread-safe] get command and reset the to "" (empty)
	std::string GetCommand();
};

#endif //SERIALCOMMANDER_H