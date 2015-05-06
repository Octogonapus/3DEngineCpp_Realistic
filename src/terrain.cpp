#include <iostream>
#include <fstream>
#include <sstream>

#include "terrain.h"

float Terrain::GetHeightAtPoint(const Vector2i& coord)
{
	std::ifstream file(m_heightmapName);

	std::string ch;

	if (file.is_open())
	{
		std::cout << "File opened" << std::endl;

		while (!file.eof())
		{
			file >> ch;
		}
	}

	file.close();

	std::stringstream ss(ch);
	std::string token;

	while (std::getline(ss, token, ','))
	{
		std::cout << token << std::endl;
	}

	return -1;
}