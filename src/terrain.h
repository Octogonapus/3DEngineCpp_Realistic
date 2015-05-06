#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <string>
#include <vector>

#include "math3d.h"

class Terrain
{
public:
	Terrain(const std::string& heightmapName) :
		m_heightmapName(heightmapName) {}

	float GetHeightAtPoint(const Vector2i& coord);
protected:
private:
	std::string m_heightmapName;
	std::vector<float> m_heightmap;
	float       m_heightmapWidth;
	float       m_heightmapHeight;
};

#endif