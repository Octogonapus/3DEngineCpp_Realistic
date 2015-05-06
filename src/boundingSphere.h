#ifndef BOUNDINGSPHERE_H_INCLUDED
#define BOUNDINGSPHERE_H_INCLUDED

#include "collider.h"
#include "math3d.h"
#include "intersectData.h"
#include "plane.h"

class BoundingSphere : public Collider
{
public:
	BoundingSphere(const float radius, const Vector3f& centerPos = Vector3f(0, 0, 0)) :
		Collider(Collider::TYPE_SPHERE),
		m_radius(radius),
		m_centerPos(centerPos) {}

	IntersectData IntersectWithBoundingSphere(const BoundingSphere& other);
	IntersectData IntersectWithPlane(const Plane& other);
	virtual void Translate(const Vector3f& translation);

	Vector3f GetCenter() const { return m_centerPos; }
	void SetCenter(const Vector3f& center) { m_centerPos = center; }
	inline float GetRadius() const { return m_radius; }
protected:
private:
	Vector3f m_centerPos;
	float    m_radius;
};

#endif