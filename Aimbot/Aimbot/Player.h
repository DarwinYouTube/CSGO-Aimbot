
class Vector3;
class Player
{
	Player();
	public:
	static int* GetMaxPlayer();
	static Player* GetPlayer(int index);

	int* GetHealth();
	int* GetTeam();
	Vector3* GetOrigin();
	Vector3* GetViewOffset();
	Vector3* GetBonePos(int boneID);
};