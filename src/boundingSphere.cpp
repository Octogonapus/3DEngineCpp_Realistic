#include "boundingSphere.h"

IntersectData BoundingSphere::IntersectWithBoundingSphere(const BoundingSphere& other)
{
	float radiusDistance = m_radius + other.GetRadius();
	Vector3f direction = (other.GetCenter() - m_centerPos);
	float centerDistance = direction.Length();
	direction /= centerDistance;

	float distance = centerDistance - radiusDistance;

	return IntersectData(distance < 0, direction * distance);
}

IntersectData BoundingSphere::IntersectWithPlane(const Plane& other)
{
	/*
	float distanceFromSphereCenter = (float)fabs(m_normal.Dot(other.GetCenter()) + m_distance);
	float distanceFromSphere = distanceFromSphereCenter - other.GetRadius();
	return IntersectData(distanceFromSphere < 0, m_normal * distanceFromSphere);
	*/
}

void BoundingSphere::Translate(const Vector3f& translation)
{
	m_centerPos += translation;
}