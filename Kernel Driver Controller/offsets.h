#pragma once


#include <cstddef>

namespace Offsets {
	namespace Client {
        constexpr std::ptrdiff_t dwEntityList = 0x18B3FA8;
        constexpr std::ptrdiff_t dwForceAttack = 0x17221D0;
        constexpr std::ptrdiff_t dwForceAttack2 = 0x1722260;
        constexpr std::ptrdiff_t dwForceBackward = 0x17224A0;
        constexpr std::ptrdiff_t dwForceCrouch = 0x1722770;
        constexpr std::ptrdiff_t dwForceForward = 0x1722410;
        constexpr std::ptrdiff_t dwForceJump = 0x17226E0;
        constexpr std::ptrdiff_t dwForceLeft = 0x1722530;
        constexpr std::ptrdiff_t dwForceRight = 0x17225C0;
        constexpr std::ptrdiff_t dwGameEntitySystem = 0x19D1980;
        constexpr std::ptrdiff_t dwGameEntitySystem_getHighestEntityIndex = 0x1510;
        constexpr std::ptrdiff_t dwGameRules = 0x1910FC0;
        constexpr std::ptrdiff_t dwGlobalVars = 0x171CE70;
        constexpr std::ptrdiff_t dwGlowManager = 0x19113E0;
        constexpr std::ptrdiff_t dwInterfaceLinkList = 0x1A029D8;
        constexpr std::ptrdiff_t dwLocalPlayerController = 0x19038F8;
        constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x1729348;
        constexpr std::ptrdiff_t dwPlantedC4 = 0x191B508;
        constexpr std::ptrdiff_t dwPrediction = 0x1729210;
        constexpr std::ptrdiff_t dwSensitivity = 0x1911D08;
        constexpr std::ptrdiff_t dwSensitivity_sensitivity = 0x40;
        constexpr std::ptrdiff_t dwViewAngles = 0x19233E0;
        constexpr std::ptrdiff_t dwViewMatrix = 0x19154C0;
        constexpr std::ptrdiff_t dwViewRender = 0x1915D40;



        namespace CCSPlayerController {
            constexpr std::ptrdiff_t m_pInGameMoneyServices = 0x6F8; // CCSPlayerController_InGameMoneyServices*
            constexpr std::ptrdiff_t m_pInventoryServices = 0x700; // CCSPlayerController_InventoryServices*
            constexpr std::ptrdiff_t m_pActionTrackingServices = 0x708; // CCSPlayerController_ActionTrackingServices*
            constexpr std::ptrdiff_t m_pDamageServices = 0x710; // CCSPlayerController_DamageServices*
            constexpr std::ptrdiff_t m_iPing = 0x718; // uint32_t
            constexpr std::ptrdiff_t m_bHasCommunicationAbuseMute = 0x71C; // bool
            constexpr std::ptrdiff_t m_szCrosshairCodes = 0x720; // CUtlSymbolLarge
            constexpr std::ptrdiff_t m_iPendingTeamNum = 0x728; // uint8_t
            constexpr std::ptrdiff_t m_flForceTeamTime = 0x72C; // GameTime_t
            constexpr std::ptrdiff_t m_iCompTeammateColor = 0x730; // int32_t
            constexpr std::ptrdiff_t m_bEverPlayedOnTeam = 0x734; // bool
            constexpr std::ptrdiff_t m_flPreviousForceJoinTeamTime = 0x738; // GameTime_t
            constexpr std::ptrdiff_t m_szClan = 0x740; // CUtlSymbolLarge
            constexpr std::ptrdiff_t m_sSanitizedPlayerName = 0x748; // CUtlString
            constexpr std::ptrdiff_t m_iCoachingTeam = 0x750; // int32_t
            constexpr std::ptrdiff_t m_nPlayerDominated = 0x758; // uint64_t
            constexpr std::ptrdiff_t m_nPlayerDominatingMe = 0x760; // uint64_t
            constexpr std::ptrdiff_t m_iCompetitiveRanking = 0x768; // int32_t
            constexpr std::ptrdiff_t m_iCompetitiveWins = 0x76C; // int32_t
            constexpr std::ptrdiff_t m_iCompetitiveRankType = 0x770; // int8_t
            constexpr std::ptrdiff_t m_iCompetitiveRankingPredicted_Win = 0x774; // int32_t
            constexpr std::ptrdiff_t m_iCompetitiveRankingPredicted_Loss = 0x778; // int32_t
            constexpr std::ptrdiff_t m_iCompetitiveRankingPredicted_Tie = 0x77C; // int32_t
            constexpr std::ptrdiff_t m_nEndMatchNextMapVote = 0x780; // int32_t
            constexpr std::ptrdiff_t m_unActiveQuestId = 0x784; // uint16_t
            constexpr std::ptrdiff_t m_nQuestProgressReason = 0x788; // QuestProgress::Reason
            constexpr std::ptrdiff_t m_unPlayerTvControlFlags = 0x78C; // uint32_t
            constexpr std::ptrdiff_t m_iDraftIndex = 0x7B8; // int32_t
            constexpr std::ptrdiff_t m_msQueuedModeDisconnectionTimestamp = 0x7BC; // uint32_t
            constexpr std::ptrdiff_t m_uiAbandonRecordedReason = 0x7C0; // uint32_t
            constexpr std::ptrdiff_t m_bCannotBeKicked = 0x7C4; // bool
            constexpr std::ptrdiff_t m_bEverFullyConnected = 0x7C5; // bool
            constexpr std::ptrdiff_t m_bAbandonAllowsSurrender = 0x7C6; // bool
            constexpr std::ptrdiff_t m_bAbandonOffersInstantSurrender = 0x7C7; // bool
            constexpr std::ptrdiff_t m_bDisconnection1MinWarningPrinted = 0x7C8; // bool
            constexpr std::ptrdiff_t m_bScoreReported = 0x7C9; // bool
            constexpr std::ptrdiff_t m_nDisconnectionTick = 0x7CC; // int32_t
            constexpr std::ptrdiff_t m_bControllingBot = 0x7D8; // bool
            constexpr std::ptrdiff_t m_bHasControlledBotThisRound = 0x7D9; // bool
            constexpr std::ptrdiff_t m_bHasBeenControlledByPlayerThisRound = 0x7DA; // bool
            constexpr std::ptrdiff_t m_nBotsControlledThisRound = 0x7DC; // int32_t
            constexpr std::ptrdiff_t m_bCanControlObservedBot = 0x7E0; // bool
            constexpr std::ptrdiff_t m_hPlayerPawn = 0x7E4; // CHandle<C_CSPlayerPawn>
            constexpr std::ptrdiff_t m_hObserverPawn = 0x7E8; // CHandle<C_CSObserverPawn>
            constexpr std::ptrdiff_t m_bPawnIsAlive = 0x7EC; // bool
            constexpr std::ptrdiff_t m_iPawnHealth = 0x7F0; // uint32_t
            constexpr std::ptrdiff_t m_iPawnArmor = 0x7F4; // int32_t
            constexpr std::ptrdiff_t m_bPawnHasDefuser = 0x7F8; // bool
            constexpr std::ptrdiff_t m_bPawnHasHelmet = 0x7F9; // bool
            constexpr std::ptrdiff_t m_nPawnCharacterDefIndex = 0x7FA; // uint16_t
            constexpr std::ptrdiff_t m_iPawnLifetimeStart = 0x7FC; // int32_t
            constexpr std::ptrdiff_t m_iPawnLifetimeEnd = 0x800; // int32_t
            constexpr std::ptrdiff_t m_iPawnBotDifficulty = 0x804; // int32_t
            constexpr std::ptrdiff_t m_hOriginalControllerOfCurrentPawn = 0x808; // CHandle<CCSPlayerController>
            constexpr std::ptrdiff_t m_iScore = 0x80C; // int32_t
            constexpr std::ptrdiff_t m_vecKills = 0x810; // C_NetworkUtlVectorBase<EKillTypes_t>
            constexpr std::ptrdiff_t m_iMVPs = 0x828; // int32_t
            constexpr std::ptrdiff_t m_bIsPlayerNameDirty = 0x82C; // bool
        }
	
        namespace CGameSceneNode {
            constexpr std::ptrdiff_t m_nodeToWorld = 0x10; // CTransform
            constexpr std::ptrdiff_t m_pOwner = 0x30; // CEntityInstance*
            constexpr std::ptrdiff_t m_pParent = 0x38; // CGameSceneNode*
            constexpr std::ptrdiff_t m_pChild = 0x40; // CGameSceneNode*
            constexpr std::ptrdiff_t m_pNextSibling = 0x48; // CGameSceneNode*
            constexpr std::ptrdiff_t m_hParent = 0x70; // CGameSceneNodeHandle
            constexpr std::ptrdiff_t m_vecOrigin = 0x80; // CNetworkOriginCellCoordQuantizedVector
            constexpr std::ptrdiff_t m_angRotation = 0xB8; // QAngle
            constexpr std::ptrdiff_t m_flScale = 0xC4; // float
            constexpr std::ptrdiff_t m_vecAbsOrigin = 0xC8; // Vector
            constexpr std::ptrdiff_t m_angAbsRotation = 0xD4; // QAngle
            constexpr std::ptrdiff_t m_flAbsScale = 0xE0; // float
            constexpr std::ptrdiff_t m_nParentAttachmentOrBone = 0xE4; // int16_t
            constexpr std::ptrdiff_t m_bDebugAbsOriginChanges = 0xE6; // bool
            constexpr std::ptrdiff_t m_bDormant = 0xE7; // bool
            constexpr std::ptrdiff_t m_bForceParentToBeNetworked = 0xE8; // bool
            constexpr std::ptrdiff_t m_bDirtyHierarchy = 0x0; // bitfield:1
            constexpr std::ptrdiff_t m_bDirtyBoneMergeInfo = 0x0; // bitfield:1
            constexpr std::ptrdiff_t m_bNetworkedPositionChanged = 0x0; // bitfield:1
            constexpr std::ptrdiff_t m_bNetworkedAnglesChanged = 0x0; // bitfield:1
            constexpr std::ptrdiff_t m_bNetworkedScaleChanged = 0x0; // bitfield:1
            constexpr std::ptrdiff_t m_bWillBeCallingPostDataUpdate = 0x0; // bitfield:1
            constexpr std::ptrdiff_t m_bBoneMergeFlex = 0x0; // bitfield:1
            constexpr std::ptrdiff_t m_nLatchAbsOrigin = 0x0; // bitfield:2
            constexpr std::ptrdiff_t m_bDirtyBoneMergeBoneToRoot = 0x0; // bitfield:1
            constexpr std::ptrdiff_t m_nHierarchicalDepth = 0xEB; // uint8_t
            constexpr std::ptrdiff_t m_nHierarchyType = 0xEC; // uint8_t
            constexpr std::ptrdiff_t m_nDoNotSetAnimTimeInInvalidatePhysicsCount = 0xED; // uint8_t
            constexpr std::ptrdiff_t m_name = 0xF0; // CUtlStringToken
            constexpr std::ptrdiff_t m_hierarchyAttachName = 0x130; // CUtlStringToken
            constexpr std::ptrdiff_t m_flZOffset = 0x134; // float
            constexpr std::ptrdiff_t m_vRenderOrigin = 0x138; // Vector


            //custom

            constexpr std::ptrdiff_t m_bonesCount = 0x1BC; // int32_t
            constexpr std::ptrdiff_t m_pModelState = 0x310; // QAngle
        }
    
        namespace CSkeletonInstance { // CGameSceneNode
            constexpr std::ptrdiff_t m_modelState = 0x160; // CModelState
            constexpr std::ptrdiff_t m_bIsAnimationEnabled = 0x370; // bool
            constexpr std::ptrdiff_t m_bUseParentRenderBounds = 0x371; // bool
            constexpr std::ptrdiff_t m_bDisableSolidCollisionsForHierarchy = 0x372; // bool
            constexpr std::ptrdiff_t m_bDirtyMotionType = 0x0; // bitfield:1
            constexpr std::ptrdiff_t m_bIsGeneratingLatchedParentSpaceState = 0x0; // bitfield:1
            constexpr std::ptrdiff_t m_materialGroup = 0x374; // CUtlStringToken
            constexpr std::ptrdiff_t m_nHitboxSet = 0x378; // uint8_t
        }

        namespace CBodyComponent { // CEntityComponent
            constexpr std::ptrdiff_t m_pSceneNode = 0x8; // CGameSceneNode* / SkeletonInstance*
            constexpr std::ptrdiff_t __m_pChainEntity = 0x20; // CNetworkVarChainer
        }
        
        namespace C_BaseEntity { // CEntityInstance
            constexpr std::ptrdiff_t m_CBodyComponent = 0x38; // CBodyComponent*
            constexpr std::ptrdiff_t m_NetworkTransmitComponent = 0x40; // CNetworkTransmitComponent
            constexpr std::ptrdiff_t m_nLastThinkTick = 0x310; // GameTick_t
            constexpr std::ptrdiff_t m_pGameSceneNode = 0x318; // CGameSceneNode*
            constexpr std::ptrdiff_t m_pRenderComponent = 0x320; // CRenderComponent*
            constexpr std::ptrdiff_t m_pCollision = 0x328; // CCollisionProperty*
            constexpr std::ptrdiff_t m_iMaxHealth = 0x330; // int32_t
            constexpr std::ptrdiff_t m_iHealth = 0x334; // int32_t
            constexpr std::ptrdiff_t m_lifeState = 0x338; // uint8_t
            constexpr std::ptrdiff_t m_bTakesDamage = 0x339; // bool
            constexpr std::ptrdiff_t m_nTakeDamageFlags = 0x33C; // TakeDamageFlags_t
            constexpr std::ptrdiff_t m_bIsPlatform = 0x340; // bool
            constexpr std::ptrdiff_t m_ubInterpolationFrame = 0x341; // uint8_t
            constexpr std::ptrdiff_t m_hSceneObjectController = 0x344; // CHandle<C_BaseEntity>
            constexpr std::ptrdiff_t m_nNoInterpolationTick = 0x348; // int32_t
            constexpr std::ptrdiff_t m_nVisibilityNoInterpolationTick = 0x34C; // int32_t
            constexpr std::ptrdiff_t m_flProxyRandomValue = 0x350; // float
            constexpr std::ptrdiff_t m_iEFlags = 0x354; // int32_t
            constexpr std::ptrdiff_t m_nWaterType = 0x358; // uint8_t
            constexpr std::ptrdiff_t m_bInterpolateEvenWithNoModel = 0x359; // bool
            constexpr std::ptrdiff_t m_bPredictionEligible = 0x35A; // bool
            constexpr std::ptrdiff_t m_bApplyLayerMatchIDToModel = 0x35B; // bool
            constexpr std::ptrdiff_t m_tokLayerMatchID = 0x35C; // CUtlStringToken
            constexpr std::ptrdiff_t m_nSubclassID = 0x360; // CUtlStringToken
            constexpr std::ptrdiff_t m_nSimulationTick = 0x370; // int32_t
            constexpr std::ptrdiff_t m_iCurrentThinkContext = 0x374; // int32_t
            constexpr std::ptrdiff_t m_aThinkFunctions = 0x378; // CUtlVector<thinkfunc_t>
            constexpr std::ptrdiff_t m_nDisableContextThinkStartTick = 0x390; // GameTick_t
            constexpr std::ptrdiff_t m_flAnimTime = 0x394; // float
            constexpr std::ptrdiff_t m_flSimulationTime = 0x398; // float
            constexpr std::ptrdiff_t m_nSceneObjectOverrideFlags = 0x39C; // uint8_t
            constexpr std::ptrdiff_t m_bHasSuccessfullyInterpolated = 0x39D; // bool
            constexpr std::ptrdiff_t m_bHasAddedVarsToInterpolation = 0x39E; // bool
            constexpr std::ptrdiff_t m_bRenderEvenWhenNotSuccessfullyInterpolated = 0x39F; // bool
            constexpr std::ptrdiff_t m_nInterpolationLatchDirtyFlags = 0x3A0; // int32_t[2]
            constexpr std::ptrdiff_t m_ListEntry = 0x3A8; // uint16_t[11]
            constexpr std::ptrdiff_t m_flCreateTime = 0x3C0; // GameTime_t
            constexpr std::ptrdiff_t m_flSpeed = 0x3C4; // float
            constexpr std::ptrdiff_t m_EntClientFlags = 0x3C8; // uint16_t
            constexpr std::ptrdiff_t m_bClientSideRagdoll = 0x3CA; // bool
            constexpr std::ptrdiff_t m_iTeamNum = 0x3CB; // uint8_t
            constexpr std::ptrdiff_t m_spawnflags = 0x3CC; // uint32_t
            constexpr std::ptrdiff_t m_nNextThinkTick = 0x3D0; // GameTick_t
            constexpr std::ptrdiff_t m_fFlags = 0x3D4; // uint32_t
            constexpr std::ptrdiff_t m_vecAbsVelocity = 0x3D8; // Vector
            constexpr std::ptrdiff_t m_vecVelocity = 0x3E8; // CNetworkVelocityVector
            constexpr std::ptrdiff_t m_vecBaseVelocity = 0x418; // Vector
            constexpr std::ptrdiff_t m_hEffectEntity = 0x424; // CHandle<C_BaseEntity>
            constexpr std::ptrdiff_t m_hOwnerEntity = 0x428; // CHandle<C_BaseEntity>
            constexpr std::ptrdiff_t m_MoveCollide = 0x42C; // MoveCollide_t
            constexpr std::ptrdiff_t m_MoveType = 0x42D; // MoveType_t
            constexpr std::ptrdiff_t m_nActualMoveType = 0x42E; // MoveType_t
            constexpr std::ptrdiff_t m_flWaterLevel = 0x430; // float
            constexpr std::ptrdiff_t m_fEffects = 0x434; // uint32_t
            constexpr std::ptrdiff_t m_hGroundEntity = 0x438; // CHandle<C_BaseEntity>
            constexpr std::ptrdiff_t m_flFriction = 0x43C; // float
            constexpr std::ptrdiff_t m_flElasticity = 0x440; // float
            constexpr std::ptrdiff_t m_flGravityScale = 0x444; // float
            constexpr std::ptrdiff_t m_flTimeScale = 0x448; // float
            constexpr std::ptrdiff_t m_bAnimatedEveryTick = 0x44C; // bool
            constexpr std::ptrdiff_t m_flNavIgnoreUntilTime = 0x450; // GameTime_t
            constexpr std::ptrdiff_t m_hThink = 0x454; // uint16_t
            constexpr std::ptrdiff_t m_fBBoxVisFlags = 0x460; // uint8_t
            constexpr std::ptrdiff_t m_bPredictable = 0x461; // bool
            constexpr std::ptrdiff_t m_bRenderWithViewModels = 0x462; // bool
            constexpr std::ptrdiff_t m_nSplitUserPlayerPredictionSlot = 0x464; // CSplitScreenSlot
            constexpr std::ptrdiff_t m_nFirstPredictableCommand = 0x468; // int32_t
            constexpr std::ptrdiff_t m_nLastPredictableCommand = 0x46C; // int32_t
            constexpr std::ptrdiff_t m_hOldMoveParent = 0x470; // CHandle<C_BaseEntity>
            constexpr std::ptrdiff_t m_Particles = 0x478; // CParticleProperty
            constexpr std::ptrdiff_t m_vecPredictedScriptFloats = 0x4A0; // CUtlVector<float>
            constexpr std::ptrdiff_t m_vecPredictedScriptFloatIDs = 0x4B8; // CUtlVector<int32_t>
            constexpr std::ptrdiff_t m_nNextScriptVarRecordID = 0x4E8; // int32_t
            constexpr std::ptrdiff_t m_vecAngVelocity = 0x4F8; // QAngle
            constexpr std::ptrdiff_t m_DataChangeEventRef = 0x504; // int32_t
            constexpr std::ptrdiff_t m_dependencies = 0x508; // CUtlVector<CEntityHandle>
            constexpr std::ptrdiff_t m_nCreationTick = 0x520; // int32_t
            constexpr std::ptrdiff_t m_bAnimTimeChanged = 0x539; // bool
            constexpr std::ptrdiff_t m_bSimulationTimeChanged = 0x53A; // bool
            constexpr std::ptrdiff_t m_sUniqueHammerID = 0x548; // CUtlString
        }

        namespace C_BasePlayerPawn { // C_BaseCombatCharacter
            constexpr std::ptrdiff_t m_pWeaponServices = 0x1100; // CPlayer_WeaponServices*
            constexpr std::ptrdiff_t m_pItemServices = 0x1108; // CPlayer_ItemServices*
            constexpr std::ptrdiff_t m_pAutoaimServices = 0x1110; // CPlayer_AutoaimServices*
            constexpr std::ptrdiff_t m_pObserverServices = 0x1118; // CPlayer_ObserverServices*
            constexpr std::ptrdiff_t m_pWaterServices = 0x1120; // CPlayer_WaterServices*
            constexpr std::ptrdiff_t m_pUseServices = 0x1128; // CPlayer_UseServices*
            constexpr std::ptrdiff_t m_pFlashlightServices = 0x1130; // CPlayer_FlashlightServices*
            constexpr std::ptrdiff_t m_pCameraServices = 0x1138; // CPlayer_CameraServices*
            constexpr std::ptrdiff_t m_pMovementServices = 0x1140; // CPlayer_MovementServices*
            constexpr std::ptrdiff_t m_ServerViewAngleChanges = 0x1150; // C_UtlVectorEmbeddedNetworkVar<ViewAngleServerChange_t>
            constexpr std::ptrdiff_t m_nHighestConsumedServerViewAngleChangeIndex = 0x11A0; // uint32_t
            constexpr std::ptrdiff_t v_angle = 0x11A4; // QAngle
            constexpr std::ptrdiff_t v_anglePrevious = 0x11B0; // QAngle
            constexpr std::ptrdiff_t m_iHideHUD = 0x11BC; // uint32_t
            constexpr std::ptrdiff_t m_skybox3d = 0x11C0; // sky3dparams_t
            constexpr std::ptrdiff_t m_flDeathTime = 0x1250; // GameTime_t
            constexpr std::ptrdiff_t m_vecPredictionError = 0x1254; // Vector
            constexpr std::ptrdiff_t m_flPredictionErrorTime = 0x1260; // GameTime_t
            constexpr std::ptrdiff_t m_vecLastCameraSetupLocalOrigin = 0x1264; // Vector
            constexpr std::ptrdiff_t m_flLastCameraSetupTime = 0x1270; // GameTime_t
            constexpr std::ptrdiff_t m_flFOVSensitivityAdjust = 0x1274; // float
            constexpr std::ptrdiff_t m_flMouseSensitivity = 0x1278; // float
            constexpr std::ptrdiff_t m_vOldOrigin = 0x127C; // Vector
            constexpr std::ptrdiff_t m_flOldSimulationTime = 0x1288; // float
            constexpr std::ptrdiff_t m_nLastExecutedCommandNumber = 0x128C; // int32_t
            constexpr std::ptrdiff_t m_nLastExecutedCommandTick = 0x1290; // int32_t
            constexpr std::ptrdiff_t m_hController = 0x1294; // CHandle<CBasePlayerController>
            constexpr std::ptrdiff_t m_bIsSwappingToPredictableController = 0x1298; // bool
        }

        namespace C_CSPlayerPawnBase { // C_BasePlayerPawn
            constexpr std::ptrdiff_t m_pPingServices = 0x12C0; // CCSPlayer_PingServices*
            constexpr std::ptrdiff_t m_pViewModelServices = 0x12C8; // CPlayer_ViewModelServices*
            constexpr std::ptrdiff_t m_fRenderingClipPlane = 0x12D8; // float[4]
            constexpr std::ptrdiff_t m_nLastClipPlaneSetupFrame = 0x12E8; // int32_t
            constexpr std::ptrdiff_t m_vecLastClipCameraPos = 0x12EC; // Vector
            constexpr std::ptrdiff_t m_vecLastClipCameraForward = 0x12F8; // Vector
            constexpr std::ptrdiff_t m_bClipHitStaticWorld = 0x1304; // bool
            constexpr std::ptrdiff_t m_bCachedPlaneIsValid = 0x1305; // bool
            constexpr std::ptrdiff_t m_pClippingWeapon = 0x1308; // C_CSWeaponBase*
            constexpr std::ptrdiff_t m_previousPlayerState = 0x1310; // CSPlayerState
            constexpr std::ptrdiff_t m_flLastCollisionCeiling = 0x1314; // float
            constexpr std::ptrdiff_t m_flLastCollisionCeilingChangeTime = 0x1318; // float
            constexpr std::ptrdiff_t m_grenadeParameterStashTime = 0x1338; // GameTime_t
            constexpr std::ptrdiff_t m_bGrenadeParametersStashed = 0x133C; // bool
            constexpr std::ptrdiff_t m_angStashedShootAngles = 0x1340; // QAngle
            constexpr std::ptrdiff_t m_vecStashedGrenadeThrowPosition = 0x134C; // Vector
            constexpr std::ptrdiff_t m_vecStashedVelocity = 0x1358; // Vector
            constexpr std::ptrdiff_t m_angShootAngleHistory = 0x1364; // QAngle[2]
            constexpr std::ptrdiff_t m_vecThrowPositionHistory = 0x137C; // Vector[2]
            constexpr std::ptrdiff_t m_vecVelocityHistory = 0x1394; // Vector[2]
            constexpr std::ptrdiff_t m_thirdPersonHeading = 0x13B0; // QAngle
            constexpr std::ptrdiff_t m_flSlopeDropOffset = 0x13C8; // float
            constexpr std::ptrdiff_t m_flSlopeDropHeight = 0x13D8; // float
            constexpr std::ptrdiff_t m_vHeadConstraintOffset = 0x13E8; // Vector
            constexpr std::ptrdiff_t m_bIsScoped = 0x1400; // bool
            constexpr std::ptrdiff_t m_bIsWalking = 0x1401; // bool
            constexpr std::ptrdiff_t m_bResumeZoom = 0x1402; // bool
            constexpr std::ptrdiff_t m_iPlayerState = 0x1404; // CSPlayerState
            constexpr std::ptrdiff_t m_bIsDefusing = 0x1408; // bool
            constexpr std::ptrdiff_t m_bIsGrabbingHostage = 0x1409; // bool
            constexpr std::ptrdiff_t m_iBlockingUseActionInProgress = 0x140C; // CSPlayerBlockingUseAction_t
            constexpr std::ptrdiff_t m_bIsRescuing = 0x1410; // bool
            constexpr std::ptrdiff_t m_fImmuneToGunGameDamageTime = 0x1414; // GameTime_t
            constexpr std::ptrdiff_t m_fImmuneToGunGameDamageTimeLast = 0x1418; // GameTime_t
            constexpr std::ptrdiff_t m_bGunGameImmunity = 0x141C; // bool
            constexpr std::ptrdiff_t m_GunGameImmunityColor = 0x141D; // Color
            constexpr std::ptrdiff_t m_bHasMovedSinceSpawn = 0x1421; // bool
            constexpr std::ptrdiff_t m_fMolotovUseTime = 0x1424; // float
            constexpr std::ptrdiff_t m_fMolotovDamageTime = 0x1428; // float
            constexpr std::ptrdiff_t m_nWhichBombZone = 0x142C; // int32_t
            constexpr std::ptrdiff_t m_bInNoDefuseArea = 0x1430; // bool
            constexpr std::ptrdiff_t m_iThrowGrenadeCounter = 0x1434; // int32_t
            constexpr std::ptrdiff_t m_bWaitForNoAttack = 0x1438; // bool
            constexpr std::ptrdiff_t m_flGuardianTooFarDistFrac = 0x143C; // float
            constexpr std::ptrdiff_t m_flDetectedByEnemySensorTime = 0x1440; // GameTime_t
            constexpr std::ptrdiff_t m_flNextGuardianTooFarWarning = 0x1444; // float
            constexpr std::ptrdiff_t m_bSuppressGuardianTooFarWarningAudio = 0x1448; // bool
            constexpr std::ptrdiff_t m_bKilledByTaser = 0x1449; // bool
            constexpr std::ptrdiff_t m_iMoveState = 0x144C; // int32_t
            constexpr std::ptrdiff_t m_bCanMoveDuringFreezePeriod = 0x1450; // bool
            constexpr std::ptrdiff_t m_flLowerBodyYawTarget = 0x1454; // float
            constexpr std::ptrdiff_t m_bStrafing = 0x1458; // bool
            constexpr std::ptrdiff_t m_flLastSpawnTimeIndex = 0x145C; // GameTime_t
            constexpr std::ptrdiff_t m_flEmitSoundTime = 0x1460; // GameTime_t
            constexpr std::ptrdiff_t m_iAddonBits = 0x1464; // int32_t
            constexpr std::ptrdiff_t m_iPrimaryAddon = 0x1468; // int32_t
            constexpr std::ptrdiff_t m_iSecondaryAddon = 0x146C; // int32_t
            constexpr std::ptrdiff_t m_iProgressBarDuration = 0x1470; // int32_t
            constexpr std::ptrdiff_t m_flProgressBarStartTime = 0x1474; // float
            constexpr std::ptrdiff_t m_iDirection = 0x1478; // int32_t
            constexpr std::ptrdiff_t m_iShotsFired = 0x147C; // int32_t
            constexpr std::ptrdiff_t m_bNightVisionOn = 0x1480; // bool
            constexpr std::ptrdiff_t m_bHasNightVision = 0x1481; // bool
            constexpr std::ptrdiff_t m_flVelocityModifier = 0x1484; // float
            constexpr std::ptrdiff_t m_flHitHeading = 0x1488; // float
            constexpr std::ptrdiff_t m_nHitBodyPart = 0x148C; // int32_t
            constexpr std::ptrdiff_t m_iStartAccount = 0x1490; // int32_t
            constexpr std::ptrdiff_t m_vecIntroStartEyePosition = 0x1494; // Vector
            constexpr std::ptrdiff_t m_vecIntroStartPlayerForward = 0x14A0; // Vector
            constexpr std::ptrdiff_t m_flClientDeathTime = 0x14AC; // GameTime_t
            constexpr std::ptrdiff_t m_flNightVisionAlpha = 0x14B0; // float
            constexpr std::ptrdiff_t m_bScreenTearFrameCaptured = 0x14B4; // bool
            constexpr std::ptrdiff_t m_flFlashBangTime = 0x14B8; // float
            constexpr std::ptrdiff_t m_flFlashScreenshotAlpha = 0x14BC; // float
            constexpr std::ptrdiff_t m_flFlashOverlayAlpha = 0x14C0; // float
            constexpr std::ptrdiff_t m_bFlashBuildUp = 0x14C4; // bool
            constexpr std::ptrdiff_t m_bFlashDspHasBeenCleared = 0x14C5; // bool
            constexpr std::ptrdiff_t m_bFlashScreenshotHasBeenGrabbed = 0x14C6; // bool
            constexpr std::ptrdiff_t m_flFlashMaxAlpha = 0x14C8; // float
            constexpr std::ptrdiff_t m_flFlashDuration = 0x14CC; // float
            constexpr std::ptrdiff_t m_lastStandingPos = 0x14D0; // Vector
            constexpr std::ptrdiff_t m_vecLastMuzzleFlashPos = 0x14DC; // Vector
            constexpr std::ptrdiff_t m_angLastMuzzleFlashAngle = 0x14E8; // QAngle
            constexpr std::ptrdiff_t m_hMuzzleFlashShape = 0x14F4; // CHandle<C_BaseEntity>
            constexpr std::ptrdiff_t m_iHealthBarRenderMaskIndex = 0x14F8; // int32_t
            constexpr std::ptrdiff_t m_flHealthFadeValue = 0x14FC; // float
            constexpr std::ptrdiff_t m_flHealthFadeAlpha = 0x1500; // float
            constexpr std::ptrdiff_t m_nMyCollisionGroup = 0x1504; // int32_t
            constexpr std::ptrdiff_t m_ignoreLadderJumpTime = 0x1508; // float
            constexpr std::ptrdiff_t m_ladderSurpressionTimer = 0x1510; // CountdownTimer
            constexpr std::ptrdiff_t m_lastLadderNormal = 0x1528; // Vector
            constexpr std::ptrdiff_t m_lastLadderPos = 0x1534; // Vector
            constexpr std::ptrdiff_t m_flDeathCCWeight = 0x1548; // float
            constexpr std::ptrdiff_t m_bOldIsScoped = 0x154C; // bool
            constexpr std::ptrdiff_t m_flPrevRoundEndTime = 0x1550; // float
            constexpr std::ptrdiff_t m_flPrevMatchEndTime = 0x1554; // float
            constexpr std::ptrdiff_t m_unCurrentEquipmentValue = 0x1558; // uint16_t
            constexpr std::ptrdiff_t m_unRoundStartEquipmentValue = 0x155A; // uint16_t
            constexpr std::ptrdiff_t m_unFreezetimeEndEquipmentValue = 0x155C; // uint16_t
            constexpr std::ptrdiff_t m_vecThirdPersonViewPositionOverride = 0x1560; // Vector
            constexpr std::ptrdiff_t m_nHeavyAssaultSuitCooldownRemaining = 0x156C; // int32_t
            constexpr std::ptrdiff_t m_ArmorValue = 0x1570; // int32_t
            constexpr std::ptrdiff_t m_angEyeAngles = 0x1578; // QAngle
            constexpr std::ptrdiff_t m_fNextThinkPushAway = 0x1590; // float
            constexpr std::ptrdiff_t m_bShouldAutobuyDMWeapons = 0x1594; // bool
            constexpr std::ptrdiff_t m_bShouldAutobuyNow = 0x1595; // bool
            constexpr std::ptrdiff_t m_bHud_MiniScoreHidden = 0x1596; // bool
            constexpr std::ptrdiff_t m_bHud_RadarHidden = 0x1597; // bool
            constexpr std::ptrdiff_t m_nLastKillerIndex = 0x1598; // CEntityIndex
            constexpr std::ptrdiff_t m_nLastConcurrentKilled = 0x159C; // int32_t
            constexpr std::ptrdiff_t m_nDeathCamMusic = 0x15A0; // int32_t
            constexpr std::ptrdiff_t m_iIDEntIndex = 0x15A4; // CEntityIndex
            constexpr std::ptrdiff_t m_delayTargetIDTimer = 0x15A8; // CountdownTimer
            constexpr std::ptrdiff_t m_iTargetedWeaponEntIndex = 0x15C0; // CEntityIndex
            constexpr std::ptrdiff_t m_iOldIDEntIndex = 0x15C4; // CEntityIndex
            constexpr std::ptrdiff_t m_holdTargetIDTimer = 0x15C8; // CountdownTimer
            constexpr std::ptrdiff_t m_flCurrentMusicStartTime = 0x15E4; // float
            constexpr std::ptrdiff_t m_flMusicRoundStartTime = 0x15E8; // float
            constexpr std::ptrdiff_t m_bDeferStartMusicOnWarmup = 0x15EC; // bool
            constexpr std::ptrdiff_t m_cycleLatch = 0x15F0; // int32_t
            constexpr std::ptrdiff_t m_serverIntendedCycle = 0x15F4; // float
            constexpr std::ptrdiff_t m_vecPlayerPatchEconIndices = 0x15F8; // uint32_t[5]
            constexpr std::ptrdiff_t m_bHideTargetID = 0x1614; // bool
            constexpr std::ptrdiff_t m_flLastSmokeOverlayAlpha = 0x1618; // float
            constexpr std::ptrdiff_t m_vLastSmokeOverlayColor = 0x161C; // Vector
            constexpr std::ptrdiff_t m_nPlayerSmokedFx = 0x1628; // ParticleIndex_t
            constexpr std::ptrdiff_t m_nPlayerInfernoBodyFx = 0x162C; // ParticleIndex_t
            constexpr std::ptrdiff_t m_nPlayerInfernoFootFx = 0x1630; // ParticleIndex_t
            constexpr std::ptrdiff_t m_flNextMagDropTime = 0x1634; // float
            constexpr std::ptrdiff_t m_nLastMagDropAttachmentIndex = 0x1638; // int32_t
            constexpr std::ptrdiff_t m_vecBulletHitModels = 0x1640; // CUtlVector<C_BulletHitModel*>
            constexpr std::ptrdiff_t m_vecPickupModelSlerpers = 0x1658; // CUtlVector<C_PickUpModelSlerper*>
            constexpr std::ptrdiff_t m_vecLastAliveLocalVelocity = 0x1670; // Vector
            constexpr std::ptrdiff_t m_entitySpottedState = 0x1698; // EntitySpottedState_t
            constexpr std::ptrdiff_t m_nSurvivalTeamNumber = 0x16B0; // int32_t
            constexpr std::ptrdiff_t m_bGuardianShouldSprayCustomXMark = 0x16B4; // bool
            constexpr std::ptrdiff_t m_bHasDeathInfo = 0x16B5; // bool
            constexpr std::ptrdiff_t m_flDeathInfoTime = 0x16B8; // float
            constexpr std::ptrdiff_t m_vecDeathInfoOrigin = 0x16BC; // Vector
            constexpr std::ptrdiff_t m_bKilledByHeadshot = 0x16C8; // bool
            constexpr std::ptrdiff_t m_hOriginalController = 0x16CC; // CHandle<CCSPlayerController>
        }

        namespace C_CSPlayerPawn { // C_CSPlayerPawnBase
            constexpr std::ptrdiff_t m_pBulletServices = 0x1718; // CCSPlayer_BulletServices*
            constexpr std::ptrdiff_t m_pHostageServices = 0x1720; // CCSPlayer_HostageServices*
            constexpr std::ptrdiff_t m_pBuyServices = 0x1728; // CCSPlayer_BuyServices*
            constexpr std::ptrdiff_t m_pGlowServices = 0x1730; // CCSPlayer_GlowServices*
            constexpr std::ptrdiff_t m_pActionTrackingServices = 0x1738; // CCSPlayer_ActionTrackingServices*
            constexpr std::ptrdiff_t m_flHealthShotBoostExpirationTime = 0x1740; // GameTime_t
            constexpr std::ptrdiff_t m_flLastFiredWeaponTime = 0x1744; // GameTime_t
            constexpr std::ptrdiff_t m_bHasFemaleVoice = 0x1748; // bool
            constexpr std::ptrdiff_t m_flLandseconds = 0x174C; // float
            constexpr std::ptrdiff_t m_flOldFallVelocity = 0x1750; // float
            constexpr std::ptrdiff_t m_szLastPlaceName = 0x1754; // char[18]
            constexpr std::ptrdiff_t m_bPrevDefuser = 0x1766; // bool
            constexpr std::ptrdiff_t m_bPrevHelmet = 0x1767; // bool
            constexpr std::ptrdiff_t m_nPrevArmorVal = 0x1768; // int32_t
            constexpr std::ptrdiff_t m_nPrevGrenadeAmmoCount = 0x176C; // int32_t
            constexpr std::ptrdiff_t m_unPreviousWeaponHash = 0x1770; // uint32_t
            constexpr std::ptrdiff_t m_unWeaponHash = 0x1774; // uint32_t
            constexpr std::ptrdiff_t m_bInBuyZone = 0x1778; // bool
            constexpr std::ptrdiff_t m_bPreviouslyInBuyZone = 0x1779; // bool
            constexpr std::ptrdiff_t m_aimPunchAngle = 0x177C; // QAngle
            constexpr std::ptrdiff_t m_aimPunchAngleVel = 0x1788; // QAngle
            constexpr std::ptrdiff_t m_aimPunchTickBase = 0x1794; // int32_t
            constexpr std::ptrdiff_t m_aimPunchTickFraction = 0x1798; // float
            constexpr std::ptrdiff_t m_aimPunchCache = 0x17A0; // CUtlVector<QAngle>
            constexpr std::ptrdiff_t m_bInLanding = 0x17C0; // bool
            constexpr std::ptrdiff_t m_flLandingTime = 0x17C4; // float
            constexpr std::ptrdiff_t m_bInHostageRescueZone = 0x17C8; // bool
            constexpr std::ptrdiff_t m_bInBombZone = 0x17C9; // bool
            constexpr std::ptrdiff_t m_bIsBuyMenuOpen = 0x17CA; // bool
            constexpr std::ptrdiff_t m_flTimeOfLastInjury = 0x17CC; // GameTime_t
            constexpr std::ptrdiff_t m_flNextSprayDecalTime = 0x17D0; // GameTime_t
            constexpr std::ptrdiff_t m_iRetakesOffering = 0x18E8; // int32_t
            constexpr std::ptrdiff_t m_iRetakesOfferingCard = 0x18EC; // int32_t
            constexpr std::ptrdiff_t m_bRetakesHasDefuseKit = 0x18F0; // bool
            constexpr std::ptrdiff_t m_bRetakesMVPLastRound = 0x18F1; // bool
            constexpr std::ptrdiff_t m_iRetakesMVPBoostItem = 0x18F4; // int32_t
            constexpr std::ptrdiff_t m_RetakesMVPBoostExtraUtility = 0x18F8; // loadout_slot_t
            constexpr std::ptrdiff_t m_bNeedToReApplyGloves = 0x1918; // bool
            constexpr std::ptrdiff_t m_EconGloves = 0x1920; // C_EconItemView
            constexpr std::ptrdiff_t m_nEconGlovesChanged = 0x1D68; // uint8_t
            constexpr std::ptrdiff_t m_bMustSyncRagdollState = 0x1D69; // bool
            constexpr std::ptrdiff_t m_nRagdollDamageBone = 0x1D6C; // int32_t
            constexpr std::ptrdiff_t m_vRagdollDamageForce = 0x1D70; // Vector
            constexpr std::ptrdiff_t m_vRagdollDamagePosition = 0x1D7C; // Vector
            constexpr std::ptrdiff_t m_szRagdollDamageWeaponName = 0x1D88; // char[64]
            constexpr std::ptrdiff_t m_bRagdollDamageHeadshot = 0x1DC8; // bool
            constexpr std::ptrdiff_t m_vRagdollServerOrigin = 0x1DCC; // Vector
            constexpr std::ptrdiff_t m_bLastHeadBoneTransformIsValid = 0x23E0; // bool
            constexpr std::ptrdiff_t m_lastLandTime = 0x23E4; // GameTime_t
            constexpr std::ptrdiff_t m_bOnGroundLastTick = 0x23E8; // bool
            constexpr std::ptrdiff_t m_qDeathEyeAngles = 0x2404; // QAngle
            constexpr std::ptrdiff_t m_bSkipOneHeadConstraintUpdate = 0x2410; // bool
        }

        namespace C_C4 { // C_CSWeaponBase
            constexpr std::ptrdiff_t m_szScreenText = 0x1A70; // char[32]
            constexpr std::ptrdiff_t m_activeLightParticleIndex = 0x1A90; // ParticleIndex_t
            constexpr std::ptrdiff_t m_eActiveLightEffect = 0x1A94; // C4LightEffect_t
            constexpr std::ptrdiff_t m_bStartedArming = 0x1A98; // bool
            constexpr std::ptrdiff_t m_fArmedTime = 0x1A9C; // GameTime_t
            constexpr std::ptrdiff_t m_bBombPlacedAnimation = 0x1AA0; // bool
            constexpr std::ptrdiff_t m_bIsPlantingViaUse = 0x1AA1; // bool
            constexpr std::ptrdiff_t m_entitySpottedState = 0x1AA8; // EntitySpottedState_t
            constexpr std::ptrdiff_t m_nSpotRules = 0x1AC0; // int32_t
            constexpr std::ptrdiff_t m_bPlayedArmingBeeps = 0x1AC4; // bool[7]
            constexpr std::ptrdiff_t m_bBombPlanted = 0x1ACB; // bool
            constexpr std::ptrdiff_t m_bDroppedFromDeath = 0x1ACC; // bool
        }

        namespace CModelState {
            constexpr std::ptrdiff_t m_hModel = 0xA0; // CStrongHandle<InfoForResourceTypeCModel>
            constexpr std::ptrdiff_t m_ModelName = 0xA8; // CUtlSymbolLarge
            constexpr std::ptrdiff_t m_bClientClothCreationSuppressed = 0xE8; // bool
            constexpr std::ptrdiff_t m_MeshGroupMask = 0x180; // uint64_t
            constexpr std::ptrdiff_t m_nIdealMotionType = 0x202; // int8_t
            constexpr std::ptrdiff_t m_nForceLOD = 0x203; // int8_t
            constexpr std::ptrdiff_t m_nClothUpdateFlags = 0x204; // int8_t

            constexpr std::ptrdiff_t m_pBoneMatrix = 0x80; // int8_t
        }

    }

    namespace Engine {

        constexpr std::ptrdiff_t dwBuildNumber = 0x513564;
        constexpr std::ptrdiff_t dwNetworkGameClient = 0x512AC8;
        constexpr std::ptrdiff_t dwNetworkGameClient_getLocalPlayer = 0xF0;
        constexpr std::ptrdiff_t dwNetworkGameClient_maxClients = 0x250;
        constexpr std::ptrdiff_t dwNetworkGameClient_signOnState = 0x240;
        constexpr std::ptrdiff_t dwWindowHeight = 0x5CABC4;
        constexpr std::ptrdiff_t dwWindowWidth = 0x5CABC0;
    }

    namespace InputSystem {
        constexpr std::ptrdiff_t dwInputSystem = 0x367A0;
    }




    constexpr std::ptrdiff_t buildNumber = 0x36AA; // Game build number
}