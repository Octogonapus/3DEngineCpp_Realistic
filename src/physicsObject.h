#ifndef PHYSICSOBJECT_H_INCLUDED
#define PHYSICSOBJECT_H_INCLUDED

#include "math3d.h"
#include "entity.h"
#include "collider.h"

class PhysicsObject
{
public:
	PhysicsObject(Entity* entity, Collider* collider, const Vector3f& velocity, const Vector3f& accel, const Vector3f& rotVelocity, const Vector3f& rotAccel, const float mass, const bool hasGravity) :
		m_entity(entity),
		m_collider(collider),
		m_velocity(velocity),
		m_accel(accel),
		m_oldAccel(accel),
		m_rotVelocity(rotVelocity),
		m_rotAccel(rotAccel),
		m_mass(mass),
		m_hasGravity(hasGravity) {}

	PhysicsObject(const PhysicsObject& other);
	PhysicsObject& operator=(PhysicsObject other);

	//Simulate forces to update position and velocity
	void Simulate(float delta);

	inline void SetVelocity(const Vector3f& velocity) { m_velocity = velocity; }
	inline const Vector3f& GetVelocity() const { return m_velocity; }
	inline void SetSpeed(const float speed) { m_velocity = m_velocity.Normalized() * speed; }
	inline const float GetSpeed() const { return m_velocity.Length(); }
	inline const float GetCurvature(const int sigma) const { sigma * (m_velocity.Cross(m_accel).Length() / pow(m_velocity.Length(), 3)); }
	inline const Vector3f& GetNormalVector(const int sigma) const { ((m_velocity.Cross(m_accel) * sigma).Cross(m_velocity)) / (m_velocity.Cross(m_accel).Length() * m_velocity.Length()); }
	inline const Vector3f& GetTangentVector() const { return m_velocity.Normalized(); }
	inline const Vector3f& GetBinormalVector(const int sigma) const { GetTangentVector().Cross(GetNormalVector(sigma)); }
	inline const float GetTorsion() const { return m_torsion; }

	inline void SetAccel(const Vector3f& accel) { m_accel = accel; }
	inline const Vector3f& GetAccel() const { return m_accel; }

	inline void SetRotVelocity(const Vector3f& velocity) { m_rotVelocity = velocity; }
	inline const Vector3f& GetRotVelocity() const { return m_rotVelocity; }

	inline void SetRotAccel(const Vector3f& accel) { m_rotAccel = accel; }
	inline const Vector3f& GetRotAccel() const { return m_rotAccel; }

	inline const float GetMass() const { return m_mass; }

	inline Entity* GetEntity() const { return m_entity; }

	//Update collider position only when we need to
	inline Collider* GetCollider()
	{
		m_collider->SetCenter(*m_entity->GetTransform()->GetPos());
		return m_collider;
	}
protected:
private:
	Entity*   m_entity;
	Collider* m_collider;
	Vector3f  m_velocity;
	Vector3f  m_accel;
	Vector3f  m_oldAccel;
	Vector3f  m_rotVelocity;
	Vector3f  m_rotAccel;
	float     m_mass;
	float     m_torsion;
	bool      m_hasGravity;
	const Vector3f m_gravity = Vector3f(0, -0.3f, 0);
};

#endif