#include "aimbot.h"

float forward[3], right[3], up[3];
void GetAimAngles(unsigned char index, float* out)
{
	float yaw, pitch;

	Engine.pfnAngleVectors((float*)&Players[index].entity->angles, forward, right, up);

	out[0] = Players[index].bones[Settings.bone][0] + forward[0] + right[0] + up[0] - Me.eye[0];
	out[1] = Players[index].bones[Settings.bone][1] + forward[1] + right[1] + up[1] - Me.eye[1];
	out[2] = Players[index].bones[Settings.bone][2] + forward[2] + right[2] + up[2] - Me.eye[2];

	if (out[1] == 0 && out[0] == 0)
	{
		yaw = 0;
		if (out[2] > 0)
			pitch = 270;
		else
			pitch = 90;
	}
	else
	{
		yaw = atan2f(out[1], out[0]) * 180 / M_PI;
		if (yaw < 0)
			yaw += 360;

		pitch = atan2f(-out[2], sqrtf(out[0] * out[0] + out[1] * out[1])) * 180 / M_PI;
		if (pitch < 0)
			pitch += 360;
	}

	out[0] = pitch;
	out[1] = yaw;

	while (out[0] < -89)  { out[0] += 180; out[1] += 180; }
	while (out[0] > 89)   { out[0] -= 180; out[1] += 180; }
	while (out[1] < -180) { out[1] += 360; }
	while (out[1] > 180)  { out[1] -= 360; }
}

void GetBoneOrigin(unsigned char index)
{
	TransformMatrix* bonetransform;

	Studio.SetupPlayerModel(index);
	bonetransform = (TransformMatrix*)Studio.StudioGetBoneTransform();

	Players[index].bones[Settings.bone][0] = (*bonetransform)[Settings.bone][0][3] + Players[index].velocity[0] * Players[index].frametime;
	Players[index].bones[Settings.bone][1] = (*bonetransform)[Settings.bone][1][3] + Players[index].velocity[1] * Players[index].frametime;
	Players[index].bones[Settings.bone][2] = (*bonetransform)[Settings.bone][2][3] + Players[index].velocity[2] * Players[index].frametime;
}