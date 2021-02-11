#include <fstream>
#include <iostream>
#include "TrainerInfo.h"
#include "SaveSection.h"
#include <string.h>
#include <experimental/filesystem>


int main(int argc, char const *argv[])
{
	// setlocale();

	std::ifstream * SaveFile = (new std::ifstream("./PokemonFireRed(R).sav"));

	// SaveFile->ignore(0x1000);

	SaveFile->seekg(0, std::ios::end);

	int SaveFile_LENGTH = SaveFile->tellg();

	std::cout<<SaveFile_LENGTH<<'\n';

	char * SaveFile_BUFFER = new char[SaveFile_LENGTH];

	SaveFile->seekg (0, SaveFile->beg);

	SaveFile->read(SaveFile_BUFFER, SaveFile_LENGTH);

	SaveFile->close();

	strcpy((char*)((FireRed_LeafGreen_TrainerInfo*)(SaveFile_BUFFER+0x1000))->NAME, "asdsiii");

	calculatePokemonSaveSectionChecksumm(((PokemonSaveSection*)(SaveFile_BUFFER+0x1000))[0]);

	delete SaveFile;

	std::ofstream * SaveFile_O = (new std::ofstream("./PokemonFireRed(R).sav"));

	SaveFile_O->write(SaveFile_BUFFER, SaveFile_LENGTH);

	SaveFile_O->close();

	return 0;
}