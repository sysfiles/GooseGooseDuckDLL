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

	void GetNameById(int id, LPCSTR str)
	{
		switch (id)
		{
		case None:
			str = u8"空";
			break;
		case Goose:
		case GHGoose:
		case HNSGoose:
		case FPGoose:
			str = u8"鹅";
			break;
		case Duck:
		case GHDuck:
		case HNSDuck:
		case DNDDuck:
			str = u8"鸭";
			break;
		case Dodo:
			str = u8"呆呆鸟";
			break;
		case Bounty:
		case GHBounty:
		case HNSBounty:
			str = u8"肉汁";
			break;
		case Mechanic:
			str = u8"Mechanic"; // 已移除
			break;
		case Vigilante:
			str = u8"正义使者";
			break;
		case Cannibal:
			str = u8"食鸟鸭";
			break;
		case Morphling:
		case DNDMorphling:
			str = u8"变形";
			break;
		case Sheriff:
			str = u8"警长";
			break;
		case Silencer:
			str = u8"静语者";
			break;
		case Canadian:
			str = u8"加拿大鹅";
			break;
		case LoverDuck:
			str = u8"恋人[鸭]";
			break;
		case LoverGoose:
			str = u8"恋人[鹅]";
			break;
		case Vulture:
		case DNDVulture:
			str = u8"秃鹫";
			break;
		case Professional:
			str = u8"专业杀手";
			break;
		case Spy:
			str = u8"间谍";
			break;
		case Mimic:
			str = u8"模仿者";
			break;
		case Detective:
			str = u8"侦探";
			break;
		case Pigeon:
			str = u8"鸽子";
			break;
		case Birdwatcher:
			str = u8"观鸟者";
			break;
		case Assassin:
			str = u8"刺客";
			break;
		case Falcon:
		case DNDFalcon:
			str = u8"猎鹰";
			break;
		case Hitman:
			str = u8"雇佣杀手";
			break;
		case Bodyguard:
			str = u8"保镖";
			break;
		case Snitch:
			str = u8"告密者";
			break;
		case Politician:
			str = u8"政治家";
			break;
		case Locksmith:
			str = u8"锁匠";
			break;
		case Mortician:
			str = u8"殡仪员";
			break;
		case Celebrity:
			str = u8"网红";
			break;
		case Party:
			str = u8"派对";
			break;
		case Demolitionist:
			str = u8"爆炸王";
			break;
		case DuelingDodo:
			str = u8"决斗呆呆鸟";
			break;
		case ExploreGoose:
			str = u8"ExploreGoose"; // 未知
			break;
		case TTVampire:
			str = u8"吸血鬼";
			break;
		case TTPeasant:
			str = u8"村民";
			break;
		case TTThrall:
		case TTEThrall:
			str = u8"鬼奴";
			break;
		case Spectator:
			str = u8"旁观";
			break;
		case IdentityThief:
			str = u8"身份窃贼";
			break;
		case Adventurer:
			str = u8"冒险家";
			break;
		case Avenger:
			str = u8"复仇者";
			break;
		case Ninja:
			str = u8"忍者";
			break;
		case Undertaker:
			str = u8"丧葬者";
			break;
		case Snoop:
			str = u8"Snoop"; // 已移除
			break;
		case Esper:
			str = u8"超能力";
			break;
		case Invisibility:
			str = u8"隐形者";
			break;
		case Astral:
			str = u8"星界行者";
			break;
		case Pelican:
			str = u8"鹈鹕";
			break;
		case TTMummy:
			str = u8"木乃伊";
			break;
		case SerialKiller:
			str = u8"连环杀手";
			break;
		case Engineer:
			str = u8"工程师";
			break;
		case Warlock:
			str = u8"术士";
			break;
		case StreetUrchin:
			str = u8"流浪儿童";
			break;
		case Tracker:
			str = u8"追踪器";
			break;
		default:
			str = u8"未知";
			break;
		}
	}
}
