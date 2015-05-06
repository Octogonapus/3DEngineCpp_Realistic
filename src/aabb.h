#ifndef AABB_H_INCLUDED
#define AABB_H_INCLUDED

#include "math3d.h"
#include "intersectData.h"
#include "collider.h"

class AABB : public Collider
{
public:
	AABB(const Vector3f& centerPos, const Vector3f& dimensions) :
		Collider(Collider::TYPE_AABB),
		m_centerPos(centerPos),
		m_dimensions(dimensions) {}

	IntersectData IntersectWithAABB(const AABB& other);

	//Get coordinates of smallest point
	inline const Vector3f& GetMinExtents() const { return m_centerPos - (m_dimensions / 2); }
	//Get coordinates of largest point
	inline const Vector3f& GetMaxExtents() const { return m_centerPos + (m_dimensions / 2); }
	Vector3f GetCenter() const { return m_centerPos; };
	void SetCenter(const Vector3f& center) { m_centerPos = center; };
protected:
private:
	Vector3f m_centerPos;
	Vector3f m_dimensions;
};

#endif