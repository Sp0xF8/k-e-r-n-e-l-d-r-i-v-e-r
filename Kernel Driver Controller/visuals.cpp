#include "visuals.h"
#include "draw.h"
#include "RepeatableData.h"
#include "offsets.h"

#include <string>
#include <iostream>

#include "config.h"


void Visuals::ESP() {

	if (Data::ProcessID == 0) return;

	uintptr_t local_player = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, Data::client_dll + Offsets::Client::dwLocalPlayerPawn, sizeof(uintptr_t));

	if (local_player == NULL) return;

	int local_health = Data::Driver->ReadVirtualMemory<int>(Data::ProcessID, local_player + Offsets::Client::C_BaseEntity::m_iHealth, sizeof(int));

	Draw::Text({ 10, 10 }, std::to_string(local_health).c_str(), Colour(255, 255, 255, 255), true);
	
	uintptr_t pGameSceneNode = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, local_player + Offsets::Client::C_BaseEntity::m_pGameSceneNode, sizeof(uintptr_t));

	if (pGameSceneNode == NULL) return;

	Vector3 local_position = Data::Driver->ReadVirtualMemory<Vector3>(Data::ProcessID, pGameSceneNode + Offsets::Client::CGameSceneNode::m_vecOrigin, sizeof(Vector3));

	Draw::Text({ 10, 30 }, std::to_string(local_position.x).c_str(), Colour(255, 255, 255, 255), true);
	Draw::Text({ 10, 50 }, std::to_string(local_position.y).c_str(), Colour(255, 255, 255, 255), true);
	Draw::Text({ 10, 70 }, std::to_string(local_position.z).c_str(), Colour(255, 255, 255, 255), true);


	view_matrix_t view_matrix = Data::Driver->ReadVirtualMemory<view_matrix_t>(Data::ProcessID, Data::client_dll + Offsets::Client::dwViewMatrix, sizeof(view_matrix_t));

	if (view_matrix[0][0] == NULL) return;

	uintptr_t entity_list = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, Data::client_dll + Offsets::Client::dwEntityList, sizeof(uintptr_t));

	if (entity_list == NULL) return;

	int local_team = Data::Driver->ReadVirtualMemory<int>(Data::ProcessID, local_player + Offsets::Client::C_BaseEntity::m_iTeamNum, sizeof(int));

	if (local_team == NULL) return;

	Draw::Text({ 10, 90 }, std::to_string(local_team).c_str(), Colour(255, 255, 255, 255), true);

	


	for (ULONG64 entities = 1; entities < 32; entities++) {

		uintptr_t list_entry = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, entity_list + 0x10, sizeof(uintptr_t));

		if (!list_entry) return;

		uintptr_t player = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, list_entry + 120 * (entities & 0x1FF), sizeof(uintptr_t));

		if (!player) continue;

		int player_health = Data::Driver->ReadVirtualMemory<int>(Data::ProcessID, player + Offsets::Client::C_BaseEntity::m_iHealth, sizeof(int));

		if(player_health <= 0 || player_health > 100) continue;

		std::cout << player_health << std::endl;

	}





	/*
	




	
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