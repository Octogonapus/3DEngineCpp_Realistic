#include "aabb.h"

IntersectData AABB::IntersectWithAABB(const AABB& other)
{
	Vector3f d1 = other.GetMinExtents() - GetMaxExtents();
	Vector3f d2 = GetMinExtents() - other.GetMaxExtents();
	Vector3f distance = Vector3f(d1.Max(d2));
	float maxDistance = distance.Max();

	//TODO: Might need to return minDistance
	return IntersectData(maxDistance < 0, distance);
}