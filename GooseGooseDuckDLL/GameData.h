#pragma once

namespace Offset
{
	namespace UnityPlayer
	{
		_int64 GetSwapChain = 0x759A30; // 48 83EC 28 E8 ???????? 48 8B80 20030000 4883C4 28 C3
	}

	namespace PlayerController
	{
		_int64 bodyCollider = 0xA8; // CapsuleCollider2D
		_int64 isSilenced = 0xC1; // bool
		_int64 isHelium = 0xC2; // bool
		_int64 isInfected = 0xC3; // bool
		_int64 inSmog = 0xC5; // bool
		_int64 killedBy = 0xC8; // string
		_int64 playerRole = 0xE8; // ptr
		_int64 playerRoleSet = 0xF0; // bool
		_int64 inVent = 0xF1; // bool
		_int64 hasBomb = 0x134; // bool
		_int64 isGhost = 0x188; // bool
		_int64 timeOfDeath = 0x18C; // int
		_int64 nickname = 0x1D0; // string
		_int64 hasKilledThisRound = 0x2EC; // bool
	}

	namespace LocalPlayer
	{
		_int64 Player = 0x18; // PlayerController
		_int64 fogOfWar = 0x20; // FogOfWarHandler
		_int64 disableMovement = 0x60; // bool
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

	void GetNameById(int id, const wchar_t* str)
	{
		switch (id)
		{
		case None:
			str = L"空";
			break;
		case Goose:
		case GHGoose:
		case HNSGoose:
		case FPGoose:
			str = L"鹅";
			break;
		case Duck:
		case GHDuck:
		case HNSDuck:
		case DNDDuck:
			str = L"鸭";
			break;
		case Dodo:
			str = L"呆呆鸟";
			break;
		case Bounty:
		case GHBounty:
		case HNSBounty:
			str = L"肉汁";
			break;
		case Mechanic:
			str = L"Mechanic"; // 已移除
			break;
		case Vigilante:
			str = L"正义使者";
			break;
		case Cannibal:
			str = L"食鸟鸭";
			break;
		case Morphling:
		case DNDMorphling:
			str = L"变形";
			break;
		case Sheriff:
			str = L"警长";
			break;
		case Silencer:
			str = L"静语者";
			break;
		case Canadian:
			str = L"加拿大鹅";
			break;
		case LoverDuck:
			str = L"恋人[鸭]";
			break;
		case LoverGoose:
			str = L"恋人[鹅]";
			break;
		case Vulture:
		case DNDVulture:
			str = L"秃鹫";
			break;
		case Professional:
			str = L"专业杀手";
			break;
		case Spy:
			str = L"间谍";
			break;
		case Mimic:
			str = L"模仿者";
			break;
		case Detective:
			str = L"侦探";
			break;
		case Pigeon:
			str = L"鸽子";
			break;
		case Birdwatcher:
			str = L"观鸟者";
			break;
		case Assassin:
			str = L"刺客";
			break;
		case Falcon:
		case DNDFalcon:
			str = L"猎鹰";
			break;
		case Hitman:
			str = L"雇佣杀手";
			break;
		case Bodyguard:
			str = L"保镖";
			break;
		case Snitch:
			str = L"告密者";
			break;
		case Politician:
			str = L"政治家";
			break;
		case Locksmith:
			str = L"锁匠";
			break;
		case Mortician:
			str = L"殡仪员";
			break;
		case Celebrity:
			str = L"网红";
			break;
		case Party:
			str = L"派对";
			break;
		case Demolitionist:
			str = L"爆炸王";
			break;
		case DuelingDodo:
			str = L"决斗呆呆鸟";
			break;
		case ExploreGoose:
			str = L"ExploreGoose"; // 未知
			break;
		case TTVampire:
			str = L"吸血鬼";
			break;
		case TTPeasant:
			str = L"村民";
			break;
		case TTThrall:
		case TTEThrall:
			str = L"鬼奴";
			break;
		case Spectator:
			str = L"旁观";
			break;
		case IdentityThief:
			str = L"身份窃贼";
			break;
		case Adventurer:
			str = L"冒险家";
			break;
		case Avenger:
			str = L"复仇者";
			break;
		case Ninja:
			str = L"忍者";
			break;
		case Undertaker:
			str = L"丧葬者";
			break;
		case Snoop:
			str = L"Snoop"; // 已移除
			break;
		case Esper:
			str = L"超能力";
			break;
		case Invisibility:
			str = L"隐形者";
			break;
		case Astral:
			str = L"星界行者";
			break;
		case Pelican:
			str = L"鹈鹕";
			break;
		case TTMummy:
			str = L"木乃伊";
			break;
		case SerialKiller:
			str = L"连环杀手";
			break;
		case Engineer:
			str = L"工程师";
			break;
		case Warlock:
			str = L"术士";
			break;
		case StreetUrchin:
			str = L"流浪儿童";
			break;
		case Tracker:
			str = L"追踪器";
			break;
		default:
			str = L"未知";
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
		BOOL IsRoleSet;
		WCHAR Name[128];
		WCHAR Role[128];
	};

	OtherPlayer_T OtherPlayer[16] = { };

	static void UpdateGameData()
	{
		__try
		{
			PCHAR LocalPlayerPtr1 = *(PCHAR*)((PCHAR)GameAssembly + 0x3C3A608);
			if (LocalPlayerPtr1)
			{
				PCHAR LocalPlayerPtr2 = *(PCHAR*)(LocalPlayerPtr1 + 0xB8);
				if (LocalPlayerPtr2)
				{
					PCHAR LocalPlayer = *(PCHAR*)(LocalPlayerPtr2 + 0x20);
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

			PCHAR OtherPlayerPtr1 = *(PCHAR*)((PCHAR)GameAssembly + 0x3C869B0);
			if (OtherPlayerPtr1)
			{
				PCHAR OtherPlayerPtr2 = *(PCHAR*)(OtherPlayerPtr1 + 0xB8);
				if (OtherPlayerPtr2)
				{
					PCHAR OtherPlayerPtr3 = *(PCHAR*)(OtherPlayerPtr2 + 0x20);
					if (OtherPlayerPtr3)
					{
						PCHAR OtherPlayerControllerArray = *(PCHAR*)(OtherPlayerPtr3 + 0x18);
						if (OtherPlayerControllerArray)
						{
							for (SIZE_T Index = 0; Index < 16; Index++)
							{
								PCHAR OtherPlayerController = *(PCHAR*)(OtherPlayerControllerArray + 0x30 + Index * 0x18);
								if (OtherPlayerController)
								{
									OtherPlayer[Index].IsRoleSet = *(PBOOL)(OtherPlayerController + Offset::PlayerController::playerRoleSet);
									if (!OtherPlayer[Index].IsRoleSet)
									{
										continue;
									}

									PCHAR NickNameObject = *(PCHAR*)(OtherPlayerController + Offset::PlayerController::nickname);
									INT NickNameLenght = *(PINT)(NickNameObject + 0x10);
									if (NickNameLenght < 64)
									{
										WCHAR NickName[128] = { 0 };
										memcpy(NickName, NickNameObject + 0x14, NickNameLenght * sizeof(WCHAR));
										memcpy(OtherPlayer[Index].Name, NickName, 128 * sizeof(WCHAR));
									}

									PCHAR RoleObject = *(PCHAR*)(OtherPlayerController + Offset::PlayerController::playerRole);
									Role::GetNameById(*(PINT)(RoleObject + 0x10), OtherPlayer[Index].Role);
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
