#include <iostream>

#include "collider.h"
#include "boundingSphere.h"
#include "aabb.h"
#include "plane.h"

IntersectData Collider::HandleIntersection(const Collider& other) const
{
	if (m_type == TYPE_SPHERE)
	{
		if (other.GetType() == TYPE_SPHERE)
		{
			return ((BoundingSphere*)this)->IntersectWithBoundingSphere((BoundingSphere&)other);
		}
		else if (other.GetType() == TYPE_PLANE)
		{
			return ((BoundingSphere*)this)->IntersectWithPlane((Plane&)other);
		}
	}
	else if (m_type == TYPE_AABB)
	{
		if (other.GetType() == TYPE_AABB)
		{
			return ((AABB*)this)->IntersectWithAABB((AABB&)other);
		}
	}
	else if (m_type == TYPE_PLANE)
	{
		if (other.GetType() == TYPE_SPHERE)
		{
			return ((Plane*)this)->IntersectWithBoundingSphere((BoundingSphere&)other);
		}
	}

	std::cerr << "Error: Intersection could not be handled between colliders of types " << std::to_string(m_type) << " and " << std::to_string(other.GetType()) << std::endl;
	exit(1);

	//To make the compiler happy; This should never execute
	return IntersectData(false, 0);
}