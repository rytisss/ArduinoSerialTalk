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

	static int selectedComPortIndex = -1;
	if (m_coms.size() > 0)
	{
		for (int n = 0; n < m_coms.size(); n++)
		{
			if (ImGui::Selectable(m_coms[n].c_str(), selectedComPortIndex == n))
			{
				selectedComPortIndex = n;
			}
		}
		if (!m_commander.IsListening())
		{
			if (selectedComPortIndex != -1)
			{
				if (ImGui::Button("Start Listening"))
				{
					if (selectedComPortIndex >= 0 && selectedComPortIndex < m_coms.size())
					{
						m_commander.StartListening(m_coms[selectedComPortIndex]);
					}
				}
			}
		}
		else
		{
			if (ImGui::Button("Stop Listening"))
			{
				m_commander.StopListening();
			}
		}
	}
	if (m_commander.IsListening())
	{
		if (ImGui::Button("Start"))
		{
			m_commander.SendCommand("start");
		}
		if (ImGui::Button("Stop"))
		{
			m_commander.SendCommand("stop");
		}
		if (ImGui::Button("Calibrate"))
		{
			m_commander.SendCommand("calibrate");
		}
		if (ImGui::Button("Position"))
		{
			m_commander.SendCommand("position");
		}
		if (ImGui::Button("Singlerun"))
		{
			m_commander.SendCommand("singlerun");
		}
	}
	ImGui::End();
}
