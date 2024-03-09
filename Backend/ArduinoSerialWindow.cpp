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
		m_coms = SerialCommander::GetComports();
	}
	ImGui::Text("Available COMs:");
	for (size_t i = 0; i < m_coms.size(); i++)
	{
		ImGui::Text(m_coms[i].c_str());
	}
	if (ImGui::Button("Start Listening"))
	{
		// pick last
		if (m_coms.size() > 0)
		{
			SerialCommander commander;
			commander.StartListening(m_coms[m_coms.size() - 1]);
		}
	}
	ImGui::End();
}
