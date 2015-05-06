#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED

#include "math3d.h"
#include "intersectData.h"
#include "boundingSphere.h"

class Plane : public Collider
{
public:
	Plane(const Vector3f& centerPos, const Quaternion& rotation) :
		Collider(TYPE_PLANE),
		m_centerPos(centerPos),
		m_rotation(rotation) {}

	Plane Normalized() const;
	IntersectData IntersectWithBoundingSphere(const BoundingSphere& other) const;

	Vector3f GetCenter() const { return m_centerPos; }
	inline const Quaternion& GetRotation() const { return m_rotation; }
	void SetCenter(const Vector3f& center) { m_centerPos = center; }
protected:
private:
	Vector3f   m_centerPos;
	Quaternion m_rotation;
};

#endif