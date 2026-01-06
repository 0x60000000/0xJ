#pragma once

namespace Types
{
	namespace IW3
	{
		namespace Nightly
		{
			struct TraceExtents
			{
			  float start[3];
			  float end[3];
			  float invDelta[3];
			};
			
			const struct moveclip_t
			{
			  float mins[3];
			  float maxs[3];
			  float outerSize[3];
			  TraceExtents extents;
			  int passEntityNum;
			  int passOwnerNum;
			  int contentmask;
			};
			
			struct entityState_s
			{
			  int number;
			  int eType;
			  //LerpEntityState lerp;
			  int time2;
			  int otherEntityNum;
			  int attackerEntityNum;
			  int groundEntityNum;
			  int loopSound;
			  int surfType;
			  //entityState_s::<unnamed_tag> index;
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
			  //entityState_s::<unnamed_tag> un1;
			  //entityState_s::<unnamed_tag> un2;
			  float fTorsoPitch;
			  float fWaistPitch;
			  unsigned int partBits[4];
			};
			
			struct archivedEntityShared_t
			{
			  int svFlags;
			  int clientMask[2];
			  float absmin[3];
			  float absmax[3];
			};
			
			const struct archivedEntity_s
			{
			  entityState_s s;
			  archivedEntityShared_t r;
			};
			
			struct svEntity_s
			{
			  unsigned __int16 worldSector;
			  unsigned __int16 nextEntityInWorldSector;
			  archivedEntity_s baseline;
			  int numClusters;
			  int clusternums[16];
			  int lastCluster;
			  int linkcontents;
			  float linkmin[2];
			  float linkmax[2];
			};
			
			enum TraceHitType : __int32
			{
			  TRACE_HITTYPE_NONE = 0x0,
			  TRACE_HITTYPE_ENTITY = 0x1,
			  TRACE_HITTYPE_DYNENT_MODEL = 0x2,
			  TRACE_HITTYPE_DYNENT_BRUSH = 0x3,
			};
			
			struct __declspec(align(2)) trace_t
			{
			  float fraction;
			  float normal[3];
			  int surfaceFlags;
			  int contents;
			  const char *material;
			  TraceHitType hitType;
			  unsigned __int16 hitId;
			  unsigned __int16 modelIndex;
			  unsigned __int16 partName;
			  unsigned __int16 partGroup;
			  bool allsolid;
			  bool startsolid;
			  bool walkable;
			};
			
			enum serverState_t : __int32
			{
			  SS_DEAD = 0x0,
			  SS_LOADING = 0x1,
			  SS_GAME = 0x2,
			};
			
			struct gclient_s;
			
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
			
			struct gentity_s
			{
			  entityState_s s;
			  entityShared_t r;
			  gclient_s *client;
			  //turretInfo_s *pTurretInfo;
			  //scr_vehicle_s *scr_vehicle;
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
			  //EntHandle parent;
			  int nextthink;
			  int health;
			  int maxHealth;
			  int damage;
			  int count;
			  gentity_s *chain;
			  //$80213B501A63687F5C8B2FA6F5D82AFE ___u30;
			  //EntHandle missileTargetEnt;
			  //tagInfo_s *tagInfo;
			  gentity_s *tagChildren;
			  unsigned __int16 attachModelNames[19];
			  unsigned __int16 attachTagNames[19];
			  int useCount;
			  gentity_s *nextFree;
			};

			struct playerState_s;
			
			struct server_t
			{
			  serverState_t state;
			  int timeResidual;
			  bool inFrame;
			  bool smp;
			  bool allowNetPackets;
			  int restarting;
			  int start_frameTime;
			  int checksumFeed;
			  //cmodel_t *models[512];
			  unsigned __int16 emptyConfigString;
			  unsigned __int16 configstrings[2350];
			  svEntity_s svEntities[1024];
			  gentity_s *gentities;
			  int gentitySize;
			  int num_entities;
			  playerState_s *gameClients;
			  int gameClientSize;
			  int skelTimeStamp;
			  int skelMemPos;
			  int bpsWindow[20];
			  int bpsWindowSteps;
			  int bpsTotalBytes;
			  int bpsMaxBytes;
			  int ubpsWindow[20];
			  int ubpsTotalBytes;
			  int ubpsMaxBytes;
			  float ucompAve;
			  int ucompNum;
			  char gametype[64];
			  bool killServer;
			  const char *killReason;
			  //recentFrame recentFrameInfo[200];
			  int currentFrameNum;
			};
		}
	}
}
