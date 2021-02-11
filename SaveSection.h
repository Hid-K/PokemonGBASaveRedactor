#ifndef POKEMON_SAVE_SECTION_FORMAT_H
#define POKEMON_SAVE_SECTION_FORMAT_H

struct PokemonSaveSection
{
	uint8_t  data[4084];
	uint16_t ID;
	uint16_t Checksumm;
	uint32_t SaveIndex;
};

void calculatePokemonSaveSectionChecksumm(PokemonSaveSection & section)
{
	uint32_t checksumm___ = 0;
	// for(uintmax_t i = 0; i<section.ID; ++i)
		for(uintmax_t x = 0; x<sizeof(PokemonSaveSection::data)/4; x++)
			checksumm___ += ((uint32_t*)section.data)[x];

	section.Checksumm = (uint16_t)checksumm___ + (checksumm___>>16);
};

#endif