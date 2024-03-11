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
	if (ImGui::Button("Scan COM ports"))
	{
		m_commander.ScanForComPorts();
	}
	if (m_commander.IsScanningComports())
	{
		// dot dot dot dot dot for to indicate scanning
		double to = ImGui::GetTime();
		int timeStateStatus = (int)(ImGui::GetTime()) % 5 + 1;
		for (size_t i = 0; i < timeStateStatus; i++)
		{
			ImGui::SameLine();
			ImGui::Text(".");
		}
	}
	m_coms = m_commander.GetComports();
	ImGui::Text("Available COMs:");
	for (size_t i = 0; i < m_coms.size(); i++)
	{
		ImGui::Text(m_coms[i].c_str());
	}
	if (ImGui::Button("Start Listening"))
	{
	}
	ImGui::End();
}
