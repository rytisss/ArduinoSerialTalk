#ifndef ARDUINOSERIALWINDOW_H
#define ARDUINOSERIALWINDOW_H

#include "GraphicalElement.h"

class ArduinoSerialWindow : public GraphicalElement
{
public:
	ArduinoSerialWindow();
	~ArduinoSerialWindow();

	// Inherited via GraphicalElement
	std::string GetConfig() override;

	void SetConfig(std::string& config) override;

	void InitInternal() override;

	void DeinitInternal() override;

	void RenderInternal() override;

};

#endif //GRAPHICALBACKENDIMPL_H