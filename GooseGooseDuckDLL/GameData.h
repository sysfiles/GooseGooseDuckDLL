#pragma once

namespace Offset
{
	namespace UnityPlayer
	{
		_int64 GetSwapChain = 0x759A30; // 48 83EC 28 E8 ???????? 48 8B80 20030000 4883C4 28 C3
	}

	namespace GameAssembly
	{
		_int64 PlayerController = 0x3C98478;
		_int64 LocalPlayer = 0x3C6B510;
	}

	namespace Class
	{
		_int64 StaticFields = 0xB8;
	}

	namespace PlayerController
	{
		_int64 Static_playersList = 0x10; // Dictionary<string, PlayerController>
		_int64 Static_playersListWithAgoraIDs = 0x20; // Dictionary<int, PlayerController>
		_int64 bodyCollider = 0xA8; // CapsuleCollider2D
		_int64 isSilenced = 0xD1; // bool
		_int64 isHelium = 0xD2; // bool
		_int64 isInfected = 0xD3; // bool
		_int64 inSmog = 0xD5; // bool
		_int64 killedBy = 0xD8; // string
		_int64 playerRole = 0xF8; // ptr
		_int64 playerRoleSet = 0x100; // bool
		_int64 inVent = 0xF1; // bool
		_int64 hasBomb = 0x144; // bool
		_int64 isGhost = 0x198; // bool
		_int64 timeOfDeath = 0x19C; // int
		_int64 nickname = 0x1E0; // string
		_int64 hasKilledThisRound = 0x2FC; // bool
	}

	namespace LocalPlayer
	{
		_int64 Static_Instance = 0x0; // LocalPlayer
		_int64 Player = 0x18; // PlayerController
		_int64 fogOfWar = 0x20; // FogOfWarHandler
		_int64 disableMovement = 0x60; // bool
		_int64 Method_Update = 0xFA04C0; // void Update() { }
	}

	namespace FogOfWarHandler
	{
		_int64 layerMask = 0x18; // LayerMask (int)
		_int64 baseViewDistance = 0x2C; // float
		_int64 viewDistanceMultiplier = 0x38; // float
		_int64 targetPlayerSet = 0x50; // bool
	}
}

namespace Role
{
	enum
	{
		None = 0,
		Goose = 1,
		Duck = 2,
		Dodo = 3,
		Bounty = 4,
		Mechanic = 5,
		Technician = 6,
		Medium = 7,
		Vigilante = 8,
		Cannibal = 9,
		Morphling = 10,
		Sheriff = 11,
		Silencer = 12,
		Canadian = 13,
		LoverDuck = 14,
		LoverGoose = 15,
		Vulture = 16,
		Professional = 17,
		Spy = 18,
		Mimic = 19,
		Detective = 20,
		Pigeon = 21,
		Birdwatcher = 22,
		Assassin = 23,
		Falcon = 24,
		Hitman = 25,
		Bodyguard = 26,
		Snitch = 27,
		Politician = 28,
		Locksmith = 29,
		Mortician = 30,
		Celebrity = 31,
		Party = 32,
		Demolitionist = 33,
		DuelingDodo = 34,
		GHGoose = 35,
		GHDuck = 36,
		GHBounty = 37,
		HNSGoose = 38,
		HNSDuck = 39,
		HNSBounty = 40,
		DNDDuck = 41,
		DNDFalcon = 42,
		DNDVulture = 43,
		DNDMorphling = 44,
		FPGoose = 45,
		ExploreGoose = 46,
		TTVampire = 47,
		TTPeasant = 48,
		TTThrall = 49,
		Spectator = 50,
		IdentityThief = 51,
		Adventurer = 52,
		Avenger = 53,
		Ninja = 54,
		Undertaker = 55,
		Snoop = 56,
		Esper = 57,
		Invisibility = 58,
		Astral = 59,
		Pelican = 60,
		TTEThrall = 61,
		TTMummy = 62,
		SerialKiller = 63,
		Engineer = 64,
		Warlock = 65,
		StreetUrchin = 66,
		Tracker = 67
	};

	void GetNameById(int id, wchar_t* str)
	{
		wchar_t name[16] = {0};
		switch (id)
		{
		case None:
			wcscpy_s(str, 256, L"空");
			break;
		case Goose:
		case GHGoose:
		case HNSGoose:
		case FPGoose:
			wcscpy_s(str, 256, L"鹅");
			break;
		case Duck:
		case GHDuck:
		case HNSDuck:
		case DNDDuck:
			wcscpy_s(str, 256, L"鸭");
			break;
		case Dodo:
			wcscpy_s(str, 256, L"呆呆鸟");
			break;
		case Bounty:
		case GHBounty:
		case HNSBounty:
			wcscpy_s(str, 256, L"肉汁");
			break;
		case Mechanic:
			wcscpy_s(str, 256, L"Mechanic"); // 已移除
			break;
		case Vigilante:
			wcscpy_s(str, 256, L"正义使者");
			break;
		case Cannibal:
			wcscpy_s(str, 256, L"食鸟鸭");
			break;
		case Morphling:
		case DNDMorphling:
			wcscpy_s(str, 256, L"变形");
			break;
		case Sheriff:
			wcscpy_s(str, 256, L"警长");
			break;
		case Silencer:
			wcscpy_s(str, 256, L"静语者");
			break;
		case Canadian:
			wcscpy_s(str, 256, L"加拿大鹅");
			break;
		case LoverDuck:
			wcscpy_s(str, 256, L"恋人[鸭]");
			break;
		case LoverGoose:
			wcscpy_s(str, 256, L"恋人[鹅]");
			break;
		case Vulture:
		case DNDVulture:
			wcscpy_s(str, 256, L"秃鹫");
			break;
		case Professional:
			wcscpy_s(str, 256, L"专业杀手");
			break;
		case Spy:
			wcscpy_s(str, 256, L"间谍");
			break;
		case Mimic:
			wcscpy_s(str, 256, L"模仿者");
			break;
		case Detective:
			wcscpy_s(str, 256, L"侦探");
			break;
		case Pigeon:
			wcscpy_s(str, 256, L"鸽子");
			break;
		case Birdwatcher:
			wcscpy_s(str, 256, L"观鸟者");
			break;
		case Assassin:
			wcscpy_s(str, 256, L"刺客");
			break;
		case Falcon:
		case DNDFalcon:
			wcscpy_s(str, 256, L"猎鹰");
			break;
		case Hitman:
			wcscpy_s(str, 256, L"雇佣杀手");
			break;
		case Bodyguard:
			wcscpy_s(str, 256, L"保镖");
			break;
		case Snitch:
			wcscpy_s(str, 256, L"告密者");
			break;
		case Politician:
			wcscpy_s(str, 256, L"政治家");
			break;
		case Locksmith:
			wcscpy_s(str, 256, L"锁匠");
			break;
		case Mortician:
			wcscpy_s(str, 256, L"殡仪员");
			break;
		case Celebrity:
			wcscpy_s(str, 256, L"网红");
			break;
		case Party:
			wcscpy_s(str, 256, L"派对");
			break;
		case Demolitionist:
			wcscpy_s(str, 256, L"爆炸王");
			break;
		case DuelingDodo:
			wcscpy_s(str, 256, L"决斗呆呆鸟");
			break;
		case ExploreGoose:
			wcscpy_s(str, 256, L"ExploreGoose"); // 未知
			break;
		case TTVampire:
			wcscpy_s(str, 256, L"吸血鬼");
			break;
		case TTPeasant:
			wcscpy_s(str, 256, L"村民");
			break;
		case TTThrall:
		case TTEThrall:
			wcscpy_s(str, 256, L"鬼奴");
			break;
		case Spectator:
			wcscpy_s(str, 256, L"旁观");
			break;
		case IdentityThief:
			wcscpy_s(str, 256, L"身份窃贼");
			break;
		case Adventurer:
			wcscpy_s(str, 256, L"冒险家");
			break;
		case Avenger:
			wcscpy_s(str, 256, L"复仇者");
			break;
		case Ninja:
			wcscpy_s(str, 256, L"忍者");
			break;
		case Undertaker:
			wcscpy_s(str, 256, L"丧葬者");
			break;
		case Snoop:
			wcscpy_s(str, 256, L"Snoop"); // 已移除
			break;
		case Esper:
			wcscpy_s(str, 256, L"超能力");
			break;
		case Invisibility:
			wcscpy_s(str, 256, L"隐形者");
			break;
		case Astral:
			wcscpy_s(str, 256, L"星界行者");
			break;
		case Pelican:
			wcscpy_s(str, 256, L"鹈鹕");
			break;
		case TTMummy:
			wcscpy_s(str, 256, L"木乃伊");
			break;
		case SerialKiller:
			wcscpy_s(str, 256, L"连环杀手");
			break;
		case Engineer:
			wcscpy_s(str, 256, L"工程师");
			break;
		case Warlock:
			wcscpy_s(str, 256, L"术士");
			break;
		case StreetUrchin:
			wcscpy_s(str, 256, L"流浪儿童");
			break;
		case Tracker:
			wcscpy_s(str, 256, L"追踪器");
			break;
		default:
			wcscpy_s(str, 256, L"未知");
			break;
		}
	}
}

namespace MenuData
{
	struct Menu_T
	{
		BOOL PlayerInfo;
		BOOL NoFog;
		BOOL SuperSpeed;
		BOOL NoCooldown;
		BOOL NoCollider;
		BOOL ForceMove;
	};

	Menu_T Menu = { TRUE, FALSE, FALSE, FALSE, FALSE, FALSE};
}

namespace GameData
{
	PVOID BaseModule = NULL;
	PVOID UnityPlayer = NULL;
	PVOID GameAssembly = NULL;

	struct OtherPlayer_T
	{
		BOOL HasPlayer;
		WCHAR Name[128];
		WCHAR Role[128];
	};

	OtherPlayer_T OtherPlayer[16] = { };

	static void UpdateGameData()
	{
		__try
		{
			PCHAR LocalPlayerClass = *(PCHAR*)((PCHAR)GameAssembly + Offset::GameAssembly::LocalPlayer);
			if (LocalPlayerClass)
			{
				PCHAR LocalPlayerStaticFields = *(PCHAR*)(LocalPlayerClass + Offset::Class::StaticFields);
				if (LocalPlayerStaticFields)
				{
					PCHAR LocalPlayer = *(PCHAR*)(LocalPlayerStaticFields + Offset::LocalPlayer::Static_Instance);
					if (LocalPlayer)
					{
						if (MenuData::Menu.NoFog)
						{
							PCHAR FogOfWarHandler = *(PCHAR*)(LocalPlayer + Offset::LocalPlayer::fogOfWar);
							if (FogOfWarHandler)
							{
								if (*(PBOOL)(FogOfWarHandler + Offset::FogOfWarHandler::targetPlayerSet))
								{
									*(PINT)(FogOfWarHandler + Offset::FogOfWarHandler::layerMask) = 0;
									if (*(PFLOAT)(FogOfWarHandler + Offset::FogOfWarHandler::viewDistanceMultiplier) != 0.f)
									{
										*(PFLOAT)(FogOfWarHandler + Offset::FogOfWarHandler::baseViewDistance) = 7.5f / *(PFLOAT)(FogOfWarHandler + Offset::FogOfWarHandler::viewDistanceMultiplier);
									}
								}
							}
						}
						if (MenuData::Menu.SuperSpeed)
						{

						}
						if (MenuData::Menu.NoCooldown)
						{

						}
						if (MenuData::Menu.NoCollider)
						{

						}
						if (MenuData::Menu.ForceMove)
						{
							*(PBOOL)(LocalPlayer + Offset::LocalPlayer::disableMovement) = FALSE;
						}
					}
					else
					{
						return;
					}
				}
			}

			PCHAR PlayerControllerClass = *(PCHAR*)((PCHAR)GameAssembly + Offset::GameAssembly::PlayerController);
			if (PlayerControllerClass)
			{
				PCHAR PlayerControllerStaticFields = *(PCHAR*)(PlayerControllerClass + Offset::Class::StaticFields);
				if (PlayerControllerStaticFields)
				{
					PCHAR PlayersListWithAgoraIDs = *(PCHAR*)(PlayerControllerStaticFields + Offset::PlayerController::Static_playersListWithAgoraIDs);
					if (PlayersListWithAgoraIDs)
					{
						PCHAR PlayerControllerArray = *(PCHAR*)(PlayersListWithAgoraIDs + 0x18);
						if (PlayerControllerArray)
						{
							for (SIZE_T Index = 0; Index < 16; Index++)
							{
								PCHAR OtherPlayerController = *(PCHAR*)(PlayerControllerArray + 0x30 + Index * 0x18);
								if (OtherPlayerController)
								{
									OtherPlayer[Index].HasPlayer = TRUE;

									PCHAR NickNameObject = *(PCHAR*)(OtherPlayerController + Offset::PlayerController::nickname);
									if (NickNameObject)
									{
										INT NickNameLenght = *(PINT)(NickNameObject + 0x10);
										if (NickNameLenght < 64)
										{
											WCHAR NickName[128] = { 0 };
											memcpy(NickName, NickNameObject + 0x14, NickNameLenght * sizeof(WCHAR));
											memcpy(OtherPlayer[Index].Name, NickName, 128 * sizeof(WCHAR));
										}
									}

									BOOL IsRoleSet = *(PBOOL)(OtherPlayerController + Offset::PlayerController::playerRoleSet);
									PCHAR RoleObject = *(PCHAR*)(OtherPlayerController + Offset::PlayerController::playerRole);
									if (IsRoleSet && RoleObject)
									{
										Role::GetNameById(*(PINT)(RoleObject + 0x10), OtherPlayer[Index].Role);
									}
									else
									{
										Role::GetNameById(0, OtherPlayer[Index].Role);
									}
								}
								else
								{
									OtherPlayer[Index].HasPlayer = FALSE;
								}
							}
						}
					}
				}
			}
		}
		__except(EXCEPTION_EXECUTE_HANDLER)
		{
		}
	}
}
