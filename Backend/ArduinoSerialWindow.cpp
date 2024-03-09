#include "ArduinoSerialWindow.h"
#include "imgui.h"

ArduinoSerialWindow::ArduinoSerialWindow()
{
}

ArduinoSerialWindow::~ArduinoSerialWindow()
{
}

std::string ArduinoSerialWindow::GetConfig()
{
	return std::string();
}

void ArduinoSerialWindow::SetConfig(std::string& config)
{
}

void ArduinoSerialWindow::InitInternal()
{
}

void ArduinoSerialWindow::DeinitInternal()
{
}

void ArduinoSerialWindow::RenderInternal()
{
	ImGui::Begin("Arduino Serial", NULL, ImGuiWindowFlags_NoCollapse);
	ImGui::Text("Implement...");
	ImGui::End();
}
