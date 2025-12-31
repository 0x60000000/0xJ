#pragma once

namespace IW3
{
	namespace Nightly
	{
		namespace Types
		{
			enum trType_t : __int32
			{
			  TR_STATIONARY = 0x0,
			  TR_INTERPOLATE = 0x1,
			  TR_LINEAR = 0x2,
			  TR_LINEAR_STOP = 0x3,
			  TR_SINE = 0x4,
			  TR_GRAVITY = 0x5,
			  TR_ACCELERATE = 0x6,
			  TR_DECELERATE = 0x7,
			  TR_PHYSICS = 0x8,
			  TR_FIRST_RAGDOLL = 0x9,
			  TR_RAGDOLL = 0x9,
			  TR_RAGDOLL_GRAVITY = 0xA,
			  TR_RAGDOLL_INTERPOLATE = 0xB,
			  TR_LAST_RAGDOLL = 0xB,
			};

			struct trajectory_t
			{
			  trType_t trType;
			  int trTime;
			  int trDuration;
			  float trBase[3];
			  float trDelta[3];
			};

			struct LerpEntityStateTurret
			{
			  float gunAngles[3];
			};

			struct LerpEntityStateLoopFx
			{
			  float cullDist;
			  int period;
			};

			struct LerpEntityStatePrimaryLight
			{
			  unsigned __int8 colorAndExp[4];
			  float intensity;
			  float radius;
			  float cosHalfFovOuter;
			  float cosHalfFovInner;
			};

			struct LerpEntityStatePlayer
			{
			  float leanf;
			  int movementDir;
			};

			struct LerpEntityStateVehicle
			{
			  float bodyPitch;
			  float bodyRoll;
			  float steerYaw;
			  int materialTime;
			  float gunPitch;
			  float gunYaw;
			  int teamAndOwnerIndex;
			};

			struct LerpEntityStateMissile
			{
			  int launchTime;
			};

			struct LerpEntityStateSoundBlend
			{
			  float lerp;
			};

			struct LerpEntityStateBulletHit
			{
			  float start[3];
			};

			struct LerpEntityStateEarthquake
			{
			  float scale;
			  float radius;
			  int duration;
			};

			struct LerpEntityStateCustomExplode
			{
			  int startTime;
			};

			struct LerpEntityStateExplosion
			{
			  float innerRadius;
			  float magnitude;
			};

			struct LerpEntityStateExplosionJolt
			{
			  float innerRadius;
			  float impulse[3];
			};

			struct LerpEntityStatePhysicsJitter
			{
			  float innerRadius;
			  float minDisplacement;
			  float maxDisplacement;
			};

			struct LerpEntityStateAnonymous
			{
			  int data[7];
			};

			union LerpEntityStateTypeUnion
			{
			  LerpEntityStateTurret turret;
			  LerpEntityStateLoopFx loopFx;
			  LerpEntityStatePrimaryLight primaryLight;
			  LerpEntityStatePlayer player;
			  LerpEntityStateVehicle vehicle;
			  LerpEntityStateMissile missile;
			  LerpEntityStateSoundBlend soundBlend;
			  LerpEntityStateBulletHit bulletHit;
			  LerpEntityStateEarthquake earthquake;
			  LerpEntityStateCustomExplode customExplode;
			  LerpEntityStateExplosion explosion;
			  LerpEntityStateExplosionJolt explosionJolt;
			  LerpEntityStatePhysicsJitter physicsJitter;
			  LerpEntityStateAnonymous anonymous;
			};

			struct LerpEntityState
			{
			  int eFlags;
			  trajectory_t pos;
			  trajectory_t apos;
			  LerpEntityStateTypeUnion u;
			};

			union entityState_s_unnamed_tag
			{
			  int brushmodel;
			  int item;
			  int xmodel;
			  int primaryLight;
			};

			struct entityState_s
			{
			  int number;
			  int eType;
			  LerpEntityState lerp;
			  int time2;
			  int otherEntityNum;
			  int attackerEntityNum;
			  int groundEntityNum;
			  int loopSound;
			  int surfType;
			  entityState_s_unnamed_tag index;
			  int clientNum;
			  int iHeadIcon;
			  int iHeadIconTeam;
			  int solid;
			  unsigned int eventParm;
			  int eventSequence;
			  int events[4];
			  int eventParms[4];
			  int weapon;
			  int weaponModel;
			  int legsAnim;
			  int torsoAnim;
			  entityState_s_unnamed_tag un1;
			  entityState_s_unnamed_tag un2;
			  float fTorsoPitch;
			  float fWaistPitch;
			  unsigned int partBits[4];
			};

			struct EntHandle
			{
			  unsigned __int16 number;
			  unsigned __int16 infoIndex;
			};

			struct entityShared_t
			{
			  unsigned __int8 linked;
			  unsigned __int8 bmodel;
			  unsigned __int8 svFlags;
			  int clientMask[2];
			  unsigned __int8 inuse;
			  int broadcastTime;
			  float mins[3];
			  float maxs[3];
			  int contents;
			  float absmin[3];
			  float absmax[3];
			  float currentOrigin[3];
			  float currentAngles[3];
			  EntHandle ownerNum;
			  int eventTime;
			};

			enum OffhandSecondaryClass : __int32
			{
			  PLAYER_OFFHAND_SECONDARY_SMOKE = 0x0,
			  PLAYER_OFFHAND_SECONDARY_FLASH = 0x1,
			  PLAYER_OFFHAND_SECONDARIES_TOTAL = 0x2,
			};

			enum ViewLockTypes : __int32
			{
			  PLAYERVIEWLOCK_NONE = 0x0,
			  PLAYERVIEWLOCK_FULL = 0x1,
			  PLAYERVIEWLOCK_WEAPONJITTER = 0x2,
			  PLAYERVIEWLOCKCOUNT = 0x3,
			};

			struct SprintState
			{
			  int sprintButtonUpRequired;
			  int sprintDelay;
			  int lastSprintStart;
			  int lastSprintEnd;
			  int sprintStartMaxLength;
			};

			struct MantleState
			{
			  float yaw;
			  int timer;
			  int transIndex;
			  int flags;
			};

			enum ActionSlotType : __int32
			{
			  ACTIONSLOTTYPE_DONOTHING = 0x0,
			  ACTIONSLOTTYPE_SPECIFYWEAPON = 0x1,
			  ACTIONSLOTTYPE_ALTWEAPONTOGGLE = 0x2,
			  ACTIONSLOTTYPE_NIGHTVISION = 0x3,
			  ACTIONSLOTTYPECOUNT = 0x4,
			};

			struct ActionSlotParam_SpecifyWeapon
			{
			  unsigned int index;
			};

			struct ActionSlotParam
			{
			  ActionSlotParam_SpecifyWeapon specifyWeapon;
			};

			enum objectiveState_t : __int32
			{
			  OBJST_EMPTY = 0x0,
			  OBJST_ACTIVE = 0x1,
			  OBJST_INVISIBLE = 0x2,
			  OBJST_DONE = 0x3,
			  OBJST_CURRENT = 0x4,
			  OBJST_FAILED = 0x5,
			  OBJST_NUMSTATES = 0x6,
			};

			struct objective_t
			{
			  objectiveState_t state;
			  float origin[3];
			  int entNum;
			  int teamNum;
			  int icon;
			};

			enum he_type_t : __int32
			{
			  HE_TYPE_FREE = 0x0,
			  HE_TYPE_TEXT = 0x1,
			  HE_TYPE_VALUE = 0x2,
			  HE_TYPE_PLAYERNAME = 0x3,
			  HE_TYPE_MAPNAME = 0x4,
			  HE_TYPE_GAMETYPE = 0x5,
			  HE_TYPE_MATERIAL = 0x6,
			  HE_TYPE_TIMER_DOWN = 0x7,
			  HE_TYPE_TIMER_UP = 0x8,
			  HE_TYPE_TENTHS_TIMER_DOWN = 0x9,
			  HE_TYPE_TENTHS_TIMER_UP = 0xA,
			  HE_TYPE_CLOCK_DOWN = 0xB,
			  HE_TYPE_CLOCK_UP = 0xC,
			  HE_TYPE_WAYPOINT = 0xD,
			  HE_TYPE_COUNT = 0xE,
			};

			struct $0D0CB43DF22755AD856C77DD3F304010
			{
			  unsigned __int8 r;
			  unsigned __int8 g;
			  unsigned __int8 b;
			  unsigned __int8 a;
			};

			union hudelem_color_t
			{
			  $0D0CB43DF22755AD856C77DD3F304010 __s0;
			  int rgba;
			};

			struct hudelem_s
			{
			  he_type_t type;
			  float x;
			  float y;
			  float z;
			  int targetEntNum;
			  float fontScale;
			  int font;
			  int alignOrg;
			  int alignScreen;
			  hudelem_color_t color;
			  hudelem_color_t fromColor;
			  int fadeStartTime;
			  int fadeTime;
			  int label;
			  int width;
			  int height;
			  int materialIndex;
			  int offscreenMaterialIdx;
			  int fromWidth;
			  int fromHeight;
			  int scaleStartTime;
			  int scaleTime;
			  float fromX;
			  float fromY;
			  int fromAlignOrg;
			  int fromAlignScreen;
			  int moveStartTime;
			  int moveTime;
			  int time;
			  int duration;
			  float value;
			  int text;
			  float sort;
			  hudelem_color_t glowColor;
			  int fxBirthTime;
			  int fxLetterTime;
			  int fxDecayStartTime;
			  int fxDecayDuration;
			  int soundID;
			  int flags;
			};

			struct playerState_s_unnamed_tag
			{
			  hudelem_s current[31];
			  hudelem_s archival[31];
			};

			struct playerState_s
			{
			  int commandTime;
			  int pm_type;
			  int bobCycle;
			  int pm_flags;
			  int weapFlags;
			  int otherFlags;
			  int pm_time;
			  float origin[3];
			  float velocity[3];
			  float oldVelocity[2];
			  int weaponTime;
			  int weaponDelay;
			  int grenadeTimeLeft;
			  int throwBackGrenadeOwner;
			  int throwBackGrenadeTimeLeft;
			  int weaponRestrictKickTime;
			  int foliageSoundTime;
			  int gravity;
			  float leanf;
			  int speed;
			  float delta_angles[3];
			  int groundEntityNum;
			  float vLadderVec[3];
			  int jumpTime;
			  float jumpOriginZ;
			  int legsTimer;
			  int legsAnim;
			  int torsoTimer;
			  int torsoAnim;
			  int legsAnimDuration;
			  int torsoAnimDuration;
			  int damageTimer;
			  int damageDuration;
			  int flinchYawAnim;
			  int movementDir;
			  int eFlags;
			  int eventSequence;
			  int events[4];
			  unsigned int eventParms[4];
			  int oldEventSequence;
			  int clientNum;
			  int offHandIndex;
			  OffhandSecondaryClass offhandSecondary;
			  unsigned int weapon;
			  int weaponstate;
			  unsigned int weaponShotCount;
			  float fWeaponPosFrac;
			  int adsDelayTime;
			  int spreadOverride;
			  int spreadOverrideState;
			  int viewmodelIndex;
			  float viewangles[3];
			  int viewHeightTarget;
			  float viewHeightCurrent;
			  int viewHeightLerpTime;
			  int viewHeightLerpTarget;
			  int viewHeightLerpDown;
			  float viewAngleClampBase[2];
			  float viewAngleClampRange[2];
			  int damageEvent;
			  int damageYaw;
			  int damagePitch;
			  int damageCount;
			  int stats[5];
			  int ammo[128];
			  int ammoclip[128];
			  unsigned int weapons[4];
			  unsigned int weaponold[4];
			  unsigned int weaponrechamber[4];
			  float proneDirection;
			  float proneDirectionPitch;
			  float proneTorsoPitch;
			  ViewLockTypes viewlocked;
			  int viewlocked_entNum;
			  int cursorHint;
			  int cursorHintString;
			  int cursorHintEntIndex;
			  int iCompassPlayerInfo;
			  int radarEnabled;
			  int locationSelectionInfo;
			  SprintState sprintState;
			  float fTorsoPitch;
			  float fWaistPitch;
			  float holdBreathScale;
			  int holdBreathTimer;
			  float moveSpeedScaleMultiplier;
			  MantleState mantleState;
			  float meleeChargeYaw;
			  int meleeChargeDist;
			  int meleeChargeTime;
			  int perks;
			  ActionSlotType actionSlotType[4];
			  ActionSlotParam actionSlotParam[4];
			  int entityEventSequence;
			  int weapAnim;
			  float aimSpreadScale;
			  int shellshockIndex;
			  int shellshockTime;
			  int shellshockDuration;
			  float dofNearStart;
			  float dofNearEnd;
			  float dofFarStart;
			  float dofFarEnd;
			  float dofNearBlur;
			  float dofFarBlur;
			  float dofViewmodelStart;
			  float dofViewmodelEnd;
			  int hudElemLastAssignedSoundID;
			  objective_t objective[16];
			  unsigned __int8 weaponmodels[128];
			  int deltaTime;
			  int killCamEntity;
			  playerState_s_unnamed_tag hud;
			};

			enum sessionState_t : __int32
			{
			  SESS_STATE_PLAYING = 0x0,
			  SESS_STATE_DEAD = 0x1,
			  SESS_STATE_SPECTATOR = 0x2,
			  SESS_STATE_INTERMISSION = 0x3,
			};

			enum clientConnected_t : __int32
			{
			  CON_DISCONNECTED = 0x0,
			  CON_CONNECTING = 0x1,
			  CON_CONNECTED = 0x2,
			};

			struct __declspec(align(2)) usercmd_s
			{
			  int serverTime;
			  int buttons;
			  int angles[3];
			  unsigned __int8 weapon;
			  unsigned __int8 offHandIndex;
			  char forwardmove;
			  char rightmove;
			  float meleeChargeYaw;
			  unsigned __int8 meleeChargeDist;
			  char selectedLocation[2];
			};

			struct playerTeamState_t
			{
			  int location;
			};

			enum team_t : __int32
			{
			  TEAM_FREE = 0x0,
			  TEAM_AXIS = 0x1,
			  TEAM_ALLIES = 0x2,
			  TEAM_SPECTATOR = 0x3,
			  TEAM_NUM_TEAMS = 0x4,
			};

			struct clientState_s
			{
			  int clientIndex;
			  team_t team;
			  int modelindex;
			  int attachModelIndex[6];
			  int attachTagIndex[6];
			  char name[32];
			  float maxSprintTimeMultiplier;
			  int rank;
			  int prestige;
			  int perks;
			  int voiceConnectivityBits;
			  char clanAbbrev[8];
			  int attachedVehEntNum;
			  int attachedVehSlotIndex;
};

			struct clientSession_t
			{
			  sessionState_t sessionState;
			  int forceSpectatorClient;
			  int killCamEntity;
			  int status_icon;
			  int archiveTime;
			  int score;
			  int deaths;
			  int kills;
			  int assists;
			  unsigned __int16 scriptPersId;
			  clientConnected_t connected;
			  usercmd_s cmd;
			  usercmd_s oldcmd;
			  int localClient;
			  int predictItemPickup;
			  char newnetname[32];
			  int maxHealth;
			  int enterTime;
			  playerTeamState_t teamState;
			  int voteCount;
			  int teamVoteCount;
			  float moveSpeedScaleMultiplier;
			  int viewmodelIndex;
			  int noSpectate;
			  int teamInfo;
			  clientState_s cs;
			  int psOffsetTime;
			};

			struct turretInfo_s;
			struct scr_vehicle_s;
			struct gentity_s;

			struct gclient_s
			{
			  playerState_s ps;
			  clientSession_t sess;
			  int spectatorClient;
			  int noclip;
			  int ufo;
			  int bFrozen;
			  int lastCmdTime;
			  int buttons;
			  int oldbuttons;
			  int latched_buttons;
			  int buttonsSinceLastFrame;
			  float oldOrigin[3];
			  float fGunPitch;
			  float fGunYaw;
			  int damage_blood;
			  float damage_from[3];
			  int damage_fromWorld;
			  int accurateCount;
			  int accuracy_shots;
			  int accuracy_hits;
			  int inactivityTime;
			  int inactivityWarning;
			  int lastVoiceTime;
			  int switchTeamTime;
			  float currentAimSpreadScale;
			  gentity_s *persistantPowerup;
			  int portalID;
			  int dropWeaponTime;
			  int sniperRifleFiredTime;
			  float sniperRifleMuzzleYaw;
			  int PCSpecialPickedUpCount;
			  EntHandle useHoldEntity;
			  int useHoldTime;
			  int useButtonDone;
			  int iLastCompassPlayerInfoEnt;
			  int compassPingTime;
			  int damageTime;
			  float v_dmg_roll;
			  float v_dmg_pitch;
			  float swayViewAngles[3];
			  float swayOffset[3];
			  float swayAngles[3];
			  float vLastMoveAng[3];
			  float fLastIdleFactor;
			  float vGunOffset[3];
			  float vGunSpeed[3];
			  int weapIdleTime;
			  int lastServerTime;
			  int lastSpawnTime;
			  unsigned int lastWeapon;
			  bool previouslyFiring;
			  bool previouslyUsingNightVision;
			  bool previouslySprinting;
			  int hasRadar;
			  int lastStand;
			  int lastStandTime;
			};

			struct item_ent_t
			{
			  int ammoCount;
			  int clipAmmoCount;
			  int index;
			};

			struct __declspec(align(4)) trigger_ent_t
			{
			  int threshold;
			  int accumulate;
			  int timestamp;
			  int singleUserEntIndex;
			  bool requireLookAt;
			};

			struct mover_ent_t
			{
			  float decelTime;
			  float aDecelTime;
			  float speed;
			  float aSpeed;
			  float midTime;
			  float aMidTime;
			  float pos1[3];
			  float pos2[3];
			  float pos3[3];
			  float apos1[3];
			  float apos2[3];
			  float apos3[3];
			};

			struct corpse_ent_t
			{
			  int deathAnimStartTime;
			};

			enum MissileStage : __int32
			{
			  MISSILESTAGE_SOFTLAUNCH = 0x0,
			  MISSILESTAGE_ASCENT = 0x1,
			  MISSILESTAGE_DESCENT = 0x2,
			};

			enum MissileFlightMode : __int32
			{
			  MISSILEFLIGHTMODE_TOP = 0x0,
			  MISSILEFLIGHTMODE_DIRECT = 0x1,
			};

			struct missile_ent_t
			{
			  float time;
			  int timeOfBirth;
			  float travelDist;
			  float surfaceNormal[3];
			  team_t team;
			  float curvature[3];
			  float targetOffset[3];
			  MissileStage stage;
			  MissileFlightMode flightMode;
			};

			union $80213B501A63687F5C8B2FA6F5D82AFE
			{
			  item_ent_t item[2];
			  trigger_ent_t trigger;
			  mover_ent_t mover;
			  corpse_ent_t corpse;
			  missile_ent_t missile;
			};

			struct tagInfo_s
			{
			  gentity_s *parent;
			  gentity_s *next;
			  unsigned __int16 name;
			  int index;
			  float axis[4][3];
			  float parentInvAxis[4][3];
			};

			struct gentity_s
			{
			  entityState_s s;
			  entityShared_t r;
			  gclient_s *client;
			  turretInfo_s *pTurretInfo;
			  scr_vehicle_s *scr_vehicle;
			  unsigned __int16 model;
			  unsigned __int8 physicsObject;
			  unsigned __int8 takedamage;
			  unsigned __int8 active;
			  unsigned __int8 nopickup;
			  unsigned __int8 handler;
			  unsigned __int8 team;
			  unsigned __int16 classname;
			  unsigned __int16 target;
			  unsigned __int16 targetname;
			  unsigned int attachIgnoreCollision;
			  int spawnflags;
			  int flags;
			  int eventTime;
			  int freeAfterEvent;
			  int unlinkAfterEvent;
			  int clipmask;
			  int processedFrame;
			  EntHandle parent;
			  int nextthink;
			  int health;
			  int maxHealth;
			  int damage;
			  int count;
			  gentity_s *chain;
			  $80213B501A63687F5C8B2FA6F5D82AFE ___u30;
			  EntHandle missileTargetEnt;
			  tagInfo_s *tagInfo;
			  gentity_s *tagChildren;
			  unsigned __int16 attachModelNames[19];
			  unsigned __int16 attachTagNames[19];
			  int useCount;
			  gentity_s *nextFree;
			};

			enum svscmd_type : __int32
			{
			  SV_CMD_CAN_IGNORE = 0x0,
			  SV_CMD_RELIABLE = 0x1,
			};

			enum netsrc_t : __int32
			{
			  NS_CLIENT1 = 0x0,
			  NS_CLIENT2 = 0x1,
			  NS_CLIENT3 = 0x2,
			  NS_CLIENT4 = 0x3,
			  NS_SERVER = 0x4,
			  NS_MAXCLIENTS = 0x4,
			  NS_PACKET = 0x5,
			};

			enum netadrtype_t : __int32
			{
			  NA_BOT = 0x0,
			  NA_BAD = 0x1,
			  NA_LOOPBACK = 0x2,
			  NA_BROADCAST = 0x3,
			  NA_IP = 0x4,
			};

			struct __declspec(align(4)) netadr_t
			{
			  netadrtype_t type;
			  unsigned __int8 ip[4];
			  unsigned __int16 port;
			};

			struct netProfilePacket_t
			{
			  int iTime;
			  int iSize;
			  int bFragment;
			};

			struct netProfileStream_t
			{
			  netProfilePacket_t packets[60];
			  int iCurrPacket;
			  int iBytesPerSecond;
			  int iLastBPSCalcTime;
			  int iCountedPackets;
			  int iCountedFragments;
			  int iFragmentPercentage;
			  int iLargestPacket;
			  int iSmallestPacket;
			};

			struct netProfileInfo_t
			{
			  netProfileStream_t send;
			  netProfileStream_t recieve;
			};

			struct netchan_t
			{
			  int outgoingSequence;
			  netsrc_t sock;
			  int dropped;
			  int incomingSequence;
			  netadr_t remoteAddress;
			  int fragmentSequence;
			  int fragmentLength;
			  unsigned __int8 *fragmentBuffer;
			  int fragmentBufferSize;
			  int unsentFragments;
			  int unsentFragmentStart;
			  int unsentLength;
			  unsigned __int8 *unsentBuffer;
			  int unsentBufferSize;
			  netProfileInfo_t prof;
			};

			const struct clientHeader_t
			{
			  int state;
			  int sendAsActive;
			  int deltaMessage;
			  int rateDelayed;
			  netchan_t netchan;
			  float predictedOrigin[3];
			  int predictedOriginServerTime;
			};

			struct svscmd_info_t
			{
			  char cmd[1024];
			  int time;
			  int type;
			};

			struct clientSnapshot_t
			{
			  playerState_s ps;
			  int num_entities;
			  int num_clients;
			  int first_entity;
			  int first_client;
			  int messageSent;
			  int messageAcked;
			  int messageSize;
			  int serverTime;
			};

			struct __declspec(align(4)) client_t
			{
			  clientHeader_t header;
			  const char *dropReason;
			  char userinfo[1024];
			  svscmd_info_t reliableCommandInfo[128];
			  int reliableSequence;
			  int reliableAcknowledge;
			  int reliableSent;
			  int messageAcknowledge;
			  int gamestateMessageNum;
			  int challenge;
			  usercmd_s lastUsercmd;
			  int lastClientCommand;
			  char lastClientCommandString[1024];
			  gentity_s *gentity;
			  char name[32];
			  char clanAbbrev[5];
			  char downloadName[64];
			  void *download;
			  int downloadSize;
			  int downloadCount;
			  int downloadClientBlock;
			  int downloadCurrentBlock;
			  int downloadXmitBlock;
			  unsigned __int8 *downloadBlocks[8];
			  int downloadBlockSize[8];
			  int downloadEOF;
			  int downloadSendTime;
			  int nextReliableTime;
			  int lastPacketTime;
			  int lastConnectTime;
			  int nextSnapshotTime;
			  int timeoutCount;
			  clientSnapshot_t frames[32];
			  int ping;
			  int rate;
			  int snapshotMsec;
			  int pureAuthentic;
			  char netchanOutgoingBuffer[131072];
			  char netchanIncomingBuffer[2048];
			  int guid;
			  unsigned __int16 scriptId;
			  int bIsTestClient;
			  int serverId;
			  int natType;
			  unsigned __int8 stats[8192];
			  unsigned __int8 statPacketsReceived;
			};
		}

		namespace Defs
		{
			typedef int  (__fastcall *CHEATSOK)(Types::gentity_s *ent);
			extern CHEATSOK CheatsOk;

			typedef void (__fastcall *CLIENTCOMMAND)(int clientNum);
			extern CLIENTCOMMAND ClientCommand;

			typedef void (__fastcall *CL_CONSOLEPRINT)(int localClientNum, int channel, const char *txt, int duration, int pixelWidth, int flags);
			extern CL_CONSOLEPRINT CL_ConsolePrint;

			typedef int (__fastcall *I_STRNICMP)(const char *s0, const char *s1, int n);
			extern I_STRNICMP I_strnicmp;

			typedef void (__fastcall *SV_CMD_ARGVBUFFER)(int arg, char *buffer, int bufferLength);
			extern SV_CMD_ARGVBUFFER SV_Cmd_ArgvBuffer;

			typedef void (__fastcall *SV_GAMESENDSERVERCOMMAND)(int clientNum, Types::svscmd_type type, const char *text);
			extern SV_GAMESENDSERVERCOMMAND SV_GameSendServerCommand;

			typedef void (*SV_SENDSERVERCOMMAND)(Types::client_t *cl, Types::svscmd_type type, const char *fmt, ...);
			extern SV_SENDSERVERCOMMAND SV_SendServerCommand;

			typedef char* (*VA)(const char *format, ...);
			extern VA va;
		}

		namespace Detours
		{
			extern Detour ClientCommand_Detour;
			extern Detour CL_ConsolePrint_Detour;
		}

		namespace Hooks
		{
			void __fastcall Cmd_UFO_f(Types::gentity_s *ent);

			void __fastcall ClientCommand_Hook(int clientNum);

			void __fastcall CL_ConsolePrint_Hook(int localClientNum, int channel, const char *txt, int duration, int pixelWidth, int flags);
		}
	}

	/* First, check build. Then, check MP or SP. */
	void Initialize();
}
