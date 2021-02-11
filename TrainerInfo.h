#ifndef GBA_TRAINERINFO_H
#define GBA_TRAINERINFO_H

struct FireRed_LeafGreen_TrainerInfo
{
	uint8_t NAME[7];
	uint8_t Gender;
	uint8_t ID[4];
	uint8_t TimePlayed[5];
	uint8_t Options[3];
	uint8_t GameCode[4];
	uint8_t SecurityKey[4];
};

#endif