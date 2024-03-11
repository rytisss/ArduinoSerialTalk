#ifndef ARDUINOSERIALWINDOW_H
#define ARDUINOSERIALWINDOW_H

#include "GraphicalElement.h"
#include "SerialCommander.h"

class ArduinoSerialWindow : public GraphicalElement
{
public:
	ArduinoSerialWindow();
	~ArduinoSerialWindow();

	// Inherited via GraphicalElement
	std::string GetConfig() override;

	void SetConfig(std::string& config) override;

private:
	void InitInternal() override;

	void DeinitInternal() override;

	void RenderInternal() override;

	std::vector<std::string> m_coms;

	SerialCommander m_commander;

};

#endif //GRAPHICALBACKENDIMPL_H