#include "CH4.h"

bool CH4::Interface::Enable = true;

int* Money = 0;
float* Health = 0;
float* Armor = 0;
//int* Ammo = 0;

void CH4::Interface::GetPointers()
{
	static HMODULE hGTAexe = GetModuleHandle(NULL);
	Money = (int*)((DWORD)hGTAexe + (DWORD)0x810188);
	//Health
	if (IsBadReadPtr((LPCVOID)((DWORD)hGTAexe + 0x007FC7D8), sizeof(float*)))
		Health = 0;
	else if (IsBadReadPtr((LPCVOID)((*(PDWORD)((DWORD)hGTAexe + 0x007FC7D8)) + 0x540), sizeof(float*)))
		Health = 0;
	else
		Health = (float*)((*(PDWORD)((DWORD)hGTAexe + 0x007FC7D8)) + 0x540);
	//Armor
	if (IsBadReadPtr((LPCVOID)((DWORD)hGTAexe + 0x007FC7D8), sizeof(float*)))
		Armor = 0;
	else if (IsBadReadPtr((LPCVOID)((*(PDWORD)((DWORD)hGTAexe + 0x007FC7D8)) + 0x548), sizeof(float*)))
		Armor = 0;
	else
		Armor = (float*)((*(PDWORD)((DWORD)hGTAexe + 0x007FC7D8)) + 0x548);
	//Ammo
	/*
	if (IsBadReadPtr((LPCVOID)((DWORD)hGTAexe + 0x00801A44), sizeof(int*)))
		Ammo = 0;
	else if (IsBadReadPtr((LPCVOID)((*(PDWORD)((DWORD)hGTAexe + 0x00801A44)) + 0x94), sizeof(int*)))
		Ammo = 0;
	else
		Ammo = (int*)((*(PDWORD)((DWORD)hGTAexe + 0x00801A44)) + 0x94);
	*/
}

void CH4::Interface::Render::Initialize()
{
	ImGui::GetStyle().WindowTitleAlign = ImVec2(0.5f, 0.5f);
}

void CH4::Interface::Render::Background()
{
	CH4::Interface::GetPointers();

	ImGui::GetIO().MouseDrawCursor = CH4::Interface::Enable;

	if (Money && Health && Armor)
	{
		if (CH4::Settings::InfiniteLife)
			*Health = 100.0f;
		if (CH4::Settings::InfiniteMoney)
			*Money = 99999999;
		if (CH4::Settings::InfiniteArmor)
			*Armor = 100.0f;
	}
}

void CH4::Interface::Render::Interface()
{
	if (CH4::Interface::Enable)
	{
		ImGui::SetNextWindowSize(ImVec2(600, 400), ImGuiCond_Once);
		ImGui::SetNextWindowPosCenter(ImGuiCond_Once);
		if (ImGui::Begin("Crianosfera Hack for GTA-SA - BloodSharp", 0, ImGuiWindowFlags_NoCollapse))
		{
			ImGui::BeginGroup();
			ImGui::Checkbox("Infinite money", &CH4::Settings::InfiniteMoney);
			ImGui::Checkbox("Infinite life", &CH4::Settings::InfiniteLife);
			ImGui::Checkbox("Infinite armor", &CH4::Settings::InfiniteArmor);
			ImGui::EndGroup();

			ImGui::SameLine();
			ImGui::BeginGroup();
			ImGui::PushItemWidth(300);
			if (Money && Health && Armor)
			{
				ImGui::SliderInt("Money", Money, 0, 99999999);
				ImGui::SliderFloat("Health", Health, 0, 100, "%.0f");
				ImGui::SliderFloat("Armor", Armor, 0, 100, "%.0f");
				//ImGui::SliderInt("Ammo", Ammo, 0, 100);
			}
			ImGui::PopItemWidth();
			ImGui::EndGroup();

			ImGui::End();
		}
	}
}