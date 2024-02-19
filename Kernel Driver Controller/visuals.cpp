#include "visuals.h"
#include "draw.h"
#include "RepeatableData.h"
#include "offsets.h"

#include <string>
#include <iostream>

#include "config.h"



enum boneids : int {
	HEAD = 6,
	NECK = 5,
	SPINE = 4,
	SPINE_BOTTOM = 2,
	LEFT_SHOULDER = 8,
	LEFT_ELBOW = 9,
	LEFT_HAND = 11,
	RIGHT_SHOULDER = 13,
	RIGHT_ELBOW = 14,
	RIGHT_HAND = 16,
	LEFT_HIP = 22,
	LEFT_KNEE = 23,
	LEFT_FOOT = 24,
	RIGHT_HIP = 25,
	RIGHT_KNEE = 26,
	RIGHT_FOOT = 27
};

struct bone_connection {
	int bone1;
	int bone2;

	bone_connection(int bone1, int bone2) : bone1(bone1), bone2(bone2) { }
};

bone_connection bone_connections[] = {
	bone_connection(boneids::HEAD, boneids::NECK),
	bone_connection(boneids::NECK, boneids::SPINE),
	bone_connection(boneids::SPINE, boneids::SPINE_BOTTOM),
	bone_connection(boneids::SPINE, boneids::LEFT_SHOULDER),
	bone_connection(boneids::SPINE, boneids::RIGHT_SHOULDER),
	bone_connection(boneids::LEFT_SHOULDER, boneids::LEFT_ELBOW),
	bone_connection(boneids::LEFT_ELBOW, boneids::LEFT_HAND),
	bone_connection(boneids::RIGHT_SHOULDER, boneids::RIGHT_ELBOW),
	bone_connection(boneids::RIGHT_ELBOW, boneids::RIGHT_HAND),
	bone_connection(boneids::SPINE_BOTTOM, boneids::LEFT_HIP),
	bone_connection(boneids::LEFT_HIP, boneids::LEFT_KNEE),
	bone_connection(boneids::LEFT_KNEE, boneids::LEFT_FOOT),
	bone_connection(boneids::SPINE_BOTTOM, boneids::RIGHT_HIP),
	bone_connection(boneids::RIGHT_HIP, boneids::RIGHT_KNEE),
	bone_connection(boneids::RIGHT_KNEE, boneids::RIGHT_FOOT)
};


void Visuals::ESP() {

	if (Data::ProcessID == 0) return;

	uintptr_t local_player = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, Data::client_dll + Offsets::Client::dwLocalPlayerPawn, sizeof(uintptr_t));

	if (local_player == NULL) return;

	//int local_health = Data::Driver->ReadVirtualMemory<int>(Data::ProcessID, local_player + Offsets::Client::C_BaseEntity::m_iHealth, sizeof(int));

	//Draw::Text({ 10, 10 }, std::to_string(local_health).c_str(), Colour(255, 255, 255, 255), true);
	
	uintptr_t pGameSceneNode = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, local_player + Offsets::Client::C_BaseEntity::m_pGameSceneNode, sizeof(uintptr_t));

	if (pGameSceneNode == NULL) return;

	//Vector3 local_position = Data::Driver->ReadVirtualMemory<Vector3>(Data::ProcessID, pGameSceneNode + Offsets::Client::CGameSceneNode::m_vecOrigin, sizeof(Vector3));

	//Draw::Text({ 10, 30 }, std::to_string(local_position.x).c_str(), Colour(255, 255, 255, 255), true);
	//Draw::Text({ 10, 50 }, std::to_string(local_position.y).c_str(), Colour(255, 255, 255, 255), true);
	//Draw::Text({ 10, 70 }, std::to_string(local_position.z).c_str(), Colour(255, 255, 255, 255), true);


	

	uintptr_t entity_list = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, Data::client_dll + Offsets::Client::dwEntityList, sizeof(uintptr_t));

	if (entity_list == NULL) return;

	int local_team = Data::Driver->ReadVirtualMemory<int>(Data::ProcessID, local_player + Offsets::Client::C_BaseEntity::m_iTeamNum, sizeof(int));

	if (local_team == NULL) return;

	//Draw::Text({ 10, 90 }, std::to_string(local_team).c_str(), Colour(255, 255, 255, 255), true);

	
	//std::cout << "Local Team: " << local_team << std::endl;

	for (ULONG64 entities = 0; entities < 32; entities++) {

		

		uintptr_t Entity = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, Data::client_dll + Offsets::Client::dwEntityList, sizeof(uintptr_t));

		uintptr_t listEntity = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, Entity + ((8 * (entities & 0x7FFF) >> 9) + 16), sizeof(uintptr_t));
		if (listEntity == 0)
			continue;

		uintptr_t entityController = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, listEntity + (120) * (entities & 0x1FF), sizeof(uintptr_t));
		if (entityController == 0)
			continue;

		uintptr_t entityControllerPawn = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, entityController + Offsets::Client::CCSPlayerController::m_hPlayerPawn, sizeof(uintptr_t));
		if (entityControllerPawn == 0)
			continue;

		listEntity = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, Entity + (0x8 * ((entityControllerPawn & 0x7FFF) >> 9) + 16), sizeof(uintptr_t));
		if (listEntity == 0)
			continue;

		uintptr_t entityPawn = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, listEntity + (120) * (entityControllerPawn & 0x1FF), sizeof(uintptr_t));
		if (entityPawn == 0)
			continue;

		int playerTeam = Data::Driver->ReadVirtualMemory<int>(Data::ProcessID, entityPawn + Offsets::Client::C_BaseEntity::m_iTeamNum, sizeof(int));
		if (playerTeam == local_team) continue;
		
		
		int playerHealth = Data::Driver->ReadVirtualMemory<int>(Data::ProcessID, entityPawn + Offsets::Client::C_BaseEntity::m_iHealth, sizeof(int));

		uintptr_t entityNameAddress = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, entityController + Offsets::Client::CCSPlayerController::m_sSanitizedPlayerName, sizeof(uintptr_t));

		char entityName = Data::Driver->ReadVirtualMemory<char>(Data::ProcessID, entityNameAddress, sizeof(char));



		if (playerHealth <= 0 | playerHealth > 100) continue;

		//#ifdef _DEBUG
		//	std::cout << "Player Name: " << entityName << " Health : " << playerHealth << " Team: " << playerTeam << std::endl;
		//#endif


		


		uintptr_t player_node = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, entityPawn + Offsets::Client::C_BaseEntity::m_pGameSceneNode, sizeof(uintptr_t));

		if (player_node == NULL) return;

		uintptr_t player_bones = Data::Driver->ReadVirtualMemory<uintptr_t>(Data::ProcessID, player_node + 0x160 + Offsets::Client::CModelState::m_pBoneMatrix, sizeof(uintptr_t));



		
		Vector3 player_position_head = Data::Driver->ReadVirtualMemory<Vector3>(Data::ProcessID, player_bones + boneids::HEAD * 0x20, sizeof(Vector3));

		Vector3 player_position = Data::Driver->ReadVirtualMemory<Vector3>(Data::ProcessID, player_node + Offsets::Client::CGameSceneNode::m_vecOrigin, sizeof(Vector3));


		//draw box


		//draw bones
		view_matrix_t view_matrix = Data::Driver->ReadVirtualMemory<view_matrix_t>(Data::ProcessID, Data::client_dll + Offsets::Client::dwViewMatrix, sizeof(view_matrix_t));

		if (view_matrix[0][0] == NULL) return;



		Vector2 head_wts = player_position_head.WTS(view_matrix).to_vector2();

		Vector2 feet_wts = player_position.WTS(view_matrix).to_vector2();

		float height = feet_wts.y - head_wts.y;

		float width = height / 2;


	

		Draw::Text({ head_wts.x, head_wts.y - 20 }, std::to_string(playerHealth).c_str(), Colour(0.25f, 0.0f, 0.7f, 1.0f), true);

		Vector2 difference = head_wts - feet_wts;

		difference.y *= (playerHealth /100.0f);


		Colour playerHealthColour = Colour(0.0f, 1.0f, 0.0f, 1.0f);

		if (playerHealth < 75) {
			playerHealthColour = Colour(1.0f, 1.0f, 0.0f, 1.0f);
		}
		else if (playerHealth < 50) {
			playerHealthColour = Colour(1.0f, 0.5f, 0.0f, 1.0f);
		}
		else if (playerHealth < 25) {
			playerHealthColour = Colour(1.0f, 0.0f, 0.0f, 1.0f);
		}

		


		Draw::Line({ feet_wts.x - (width + 10) , feet_wts.y }, { head_wts.x - (width + 10), feet_wts.y + difference.y }, playerHealthColour, 1);


		



		for (int r = 0; r < sizeof(bone_connections) / sizeof(bone_connection); r++) {


			Vector3 bone1 = Data::Driver->ReadVirtualMemory<Vector3>(Data::ProcessID, player_bones + bone_connections[r].bone1 * 0x20, sizeof(Vector3));
			Vector3 bone2 = Data::Driver->ReadVirtualMemory<Vector3>(Data::ProcessID, player_bones + bone_connections[r].bone2 * 0x20, sizeof(Vector3));



			Vector2 bone1_wts = bone1.WTS(view_matrix).to_vector2();
			Vector2 bone2_wts = bone2.WTS(view_matrix).to_vector2();

			Draw::Line(bone1_wts, bone2_wts, Colour(255, 255, 255, 255), 1);
		}


		

		

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