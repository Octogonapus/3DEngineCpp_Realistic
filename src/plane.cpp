#include "plane.h"

IntersectData Plane::IntersectWithBoundingSphere(const BoundingSphere& other) const
{
	float distanceFromSphereCenter = (float)fabs(m_normal.Dot(other.GetCenter()) + m_distance);

	float distanceFromSphere = distanceFromSphereCenter - other.GetRadius();

	return IntersectData(distanceFromSphere < 0, m_normal * distanceFromSphere);
}