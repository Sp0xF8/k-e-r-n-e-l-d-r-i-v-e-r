#include "visuals.h"
#include "draw.h"
#include "RepeatableData.h"
#include "offsets.h"

#include <string>


#include "config.h"


void Visuals::ESP() {

	if (Data::ProcessID == 0) return;

	uintptr_t local_player = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, Data::client_dll + Offsets::Client::dwLocalPlayerPawn, sizeof(uintptr_t));

	if (local_player == NULL) return;
	

	Draw::Text({ 10, 10 }, std::to_string(local_player).c_str(), Colour(255, 255, 255, 255), true);
	
	/*
	uintptr_t pGameSceneNode = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, local_player + Offsets::Client::C_BaseEntity::m_pGameSceneNode, sizeof(uintptr_t));

	Vector3 local_position = Data::Driver->ReadVirtualMemory<Vector3>(Data::ProcessID, pGameSceneNode + Offsets::Client::CGameSceneNode::m_vecOrigin, sizeof(Vector3));

	view_matrix_t view_matrix = Data::Driver->ReadVirtualMemory<view_matrix_t>(Data::ProcessID, Data::client_dll + Offsets::Client::dwViewMatrix, sizeof(view_matrix_t));

	uintptr_t entity_list = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, Data::client_dll + Offsets::Client::dwEntityList, sizeof(uintptr_t));

	int local_team = Data::Driver->ReadVirtualMemory<int>(Data::ProcessID, local_player + Offsets::Client::C_BaseEntity::m_iTeamNum, sizeof(int));

	for (int entries = 1; entries < 32; entries++) {



		
		uintptr_t entity = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, entity_list + (8 * (entries & 0x7FFF) >> 9) + 16, sizeof(uintptr_t));

		if (entity == NULL) continue;

		uintptr_t entity_controller = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, entity + 120 * (entries & 0x1FF), sizeof(uintptr_t));

		if (entity_controller == NULL) continue;

		uintptr_t entity_controller_pawn = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, entity_controller + Offsets::Client::CCSPlayerController::m_hPlayerPawn, sizeof(uintptr_t));

		if (entity_controller_pawn == NULL) continue;

		entity = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, entity + (8 * ((entity_controller_pawn & 0x7FFF) >> 9) + 16), sizeof(uintptr_t));

		if (entity == NULL) continue;

		uintptr_t entity_pawn = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, entity + (120) * (entity_controller_pawn & 0x1FF), sizeof(uintptr_t));

		if (entity_pawn == NULL) continue;
		


		uint16_t entity_team = Data::Driver->ReadVirtualMemory<uint16_t>(Data::ProcessID, entity_pawn + Offsets::Client::C_BaseEntity::m_iTeamNum, sizeof(uint16_t));

		if (entity_team == local_team) continue;

		int entity_health = Data::Driver->ReadVirtualMemory<int>(Data::ProcessID, entity_pawn + Offsets::Client::C_BaseEntity::m_iHealth, sizeof(int));

		if (entity_health < 1) continue;




		if (Config::Visuals::bBones == true) {


			uintptr_t CBodyComponent = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, entity_pawn + Offsets::Client::C_BaseEntity::m_CBodyComponent, sizeof(uintptr_t));

			if (CBodyComponent == NULL) continue;

			uintptr_t CSkeletonInstance = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, CBodyComponent + Offsets::Client::CBodyComponent::m_pSceneNode, sizeof(uintptr_t));

			if (CSkeletonInstance == NULL) continue;

			uintptr_t ModelState = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, CSkeletonInstance + Offsets::Client::CGameSceneNode::m_pModelState, sizeof(uintptr_t));

			if (ModelState == NULL) continue;

			Bones bones = Data::Driver->ReadVirtualMemory<Bones>(Data::ProcessID, ModelState + Offsets::Client::CModelState::m_pBoneMatrix, sizeof(Bones));

			for (int i = 0; i < 104; i++) {
				
				Vector3 bonePos = bones.bones[i].WTS(view_matrix);

				Draw::Text({ bonePos.x, bonePos.y }, (const char*)i, Colour(255, 255, 255, 255), true);
			}


		}


	}


	*/
	
}