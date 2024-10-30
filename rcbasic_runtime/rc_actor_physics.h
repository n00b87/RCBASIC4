#ifndef RC_ACTOR_PHYSICS_H_INCLUDED
#define RC_ACTOR_PHYSICS_H_INCLUDED

void rc_setActorGravity(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setGravity(irr::core::vector3df(x, y, z));
	}
}

void rc_getActorGravity(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df gvec = rc_actor[actor].physics.rigid_body->getGravity();
		*x = gvec.X;
		*y = gvec.Y;
		*z = gvec.Z;
	}
}

void rc_setActorDamping(int actor, double lin_damping, double ang_damping)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setDamping(lin_damping, ang_damping);
	}
}

double rc_getActorLinearDamping(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->getLinearDamping();
	}
	return 0;
}

double rc_getActorAngularDamping(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->getAngularDamping();
	}
	return 0;
}

double rc_getActorLinearSleepThreshold(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->getLinearSleepingThreshold();
	}
	return 0;
}

double rc_getActorAngularSleepThreshold(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_util_degrees(rc_actor[actor].physics.rigid_body->getAngularSleepingThreshold()); //convert to degrees per second
	}
	return 0;
}

void rc_applyActorDamping(int actor, double timeStep)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyDamping(timeStep);
	}
}

void rc_setActorMassProperties(int actor, double mass, double inertia_x, double inertia_y, double inertia_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_physics3D.world->removeCollisionObject(rc_actor[actor].physics.rigid_body, false);
		rc_actor[actor].physics.rigid_body->setMassProps(mass, irr::core::vector3df(inertia_x, inertia_y, inertia_z));
		rc_physics3D.world->addRigidBody(rc_actor[actor].physics.rigid_body);
	}
	rc_actor[actor].physics.mass = mass;
}

void rc_getActorLinearFactor(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df lf = rc_actor[actor].physics.rigid_body->getLinearFactor();
		*x = lf.X;
		*y = lf.Y;
		*z = lf.Z;
	}
}

void rc_setActorLinearFactor(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setLinearFactor(irr::core::vector3df(x, y, z));
	}
}

double rc_getActorInverseMass(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->getInvMass();
	}
	return 0;
}

void rc_integrateActorVelocities(int actor, double step)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->integrateVelocities(step);
	}
}

void rc_applyActorCentralForceLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyCentralForce(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorCentralForceWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyCentralForce(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_getActorTotalForce(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df f = rc_actor[actor].physics.rigid_body->getTotalForce();
		*x = f.X;
		*y = f.Y;
		*z = f.Z;
	}
}

void rc_getActorTotalTorque(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df f = rc_actor[actor].physics.rigid_body->getTotalTorque();
		*x = f.X;
		*y = f.Y;
		*z = f.Z;
	}
}

void rc_getActorInverseInertiaDiagLocal(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df f = rc_actor[actor].physics.rigid_body->getInvInertiaDiagLocal();
		*x = f.X;
		*y = f.Y;
		*z = f.Z;
	}
}

void rc_setActorInverseInertiaDiagLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setInvInertiaDiagLocal(irr::core::vector3df(x,y,z));
	}
}

void rc_setActorSleepThresholds(int actor, double linear, double angular)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setSleepingThresholds(linear, rc_util_radians(angular));
	}
}

void rc_applyActorTorqueLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyTorque(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorTorqueWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyTorque(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_applyActorForceLocal(int actor, double x, double y, double z, double rel_x, double rel_y, double rel_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyForce(irr::core::vector3df(x,y,z), irr::core::vector3df(rel_x, rel_y, rel_z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorForceWorld(int actor, double x, double y, double z, double rel_x, double rel_y, double rel_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyForce(irr::core::vector3df(x,y,z), irr::core::vector3df(rel_x, rel_y, rel_z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_applyActorCentralImpulseLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyCentralImpulse(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorCentralImpulseWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyCentralImpulse(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_applyActorTorqueImpulseLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyTorqueImpulse(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorTorqueImpulseWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyTorqueImpulse(irr::core::vector3df(x,y,z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_applyActorImpulseLocal(int actor, double x, double y, double z, double rel_x, double rel_y, double rel_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyImpulse(irr::core::vector3df(x,y,z), irr::core::vector3df(rel_x, rel_y, rel_z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_applyActorImpulseWorld(int actor, double x, double y, double z, double rel_x, double rel_y, double rel_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->applyImpulse(irr::core::vector3df(x,y,z), irr::core::vector3df(rel_x, rel_y, rel_z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_clearActorForces(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->clearForces();
	}
}

void rc_updateActorInertiaTensor(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->updateInertiaTensor();
	}
}

void rc_getActorCenter(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df pos = rc_actor[actor].physics.rigid_body->getCenterOfMassPosition();
		*x = pos.X;
		*y = pos.Y;
		*z = pos.Z;
	}
}

void rc_getActorRotationQ(int actor, double* x, double* y, double* z, double* w)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;
    *w = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::quaternion q = rc_actor[actor].physics.rigid_body->getOrientation();
		*x = q.X;
		*y = q.Y;
		*z = q.Z;
		*w = q.W;
	}
}

void rc_getActorLinearVelocityWorld(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df pos = rc_actor[actor].physics.rigid_body->getLinearVelocity();
		*x = pos.X;
		*y = pos.Y;
		*z = pos.Z;
	}
}

void rc_getActorAngularVelocityWorld(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df pos = rc_actor[actor].physics.rigid_body->getAngularVelocity();
		*x = rc_util_degrees(pos.X);
		*y = rc_util_degrees(pos.Y);
		*z = rc_util_degrees(pos.Z);
	}
}

void rc_setActorLinearVelocityLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setLinearVelocity(irr::core::vector3df(x, y, z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_setActorLinearVelocityWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setLinearVelocity(irr::core::vector3df(x, y, z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_setActorAngularVelocityLocal(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		x = rc_util_radians(x);
		y = rc_util_radians(y);
		z = rc_util_radians(z);
		rc_actor[actor].physics.rigid_body->setAngularVelocity(irr::core::vector3df(x, y, z), ERBTransformSpace::ERBTS_LOCAL);
	}
}

void rc_setActorAngularVelocityWorld(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		x = rc_util_radians(x);
		y = rc_util_radians(y);
		z = rc_util_radians(z);
		rc_actor[actor].physics.rigid_body->setAngularVelocity(irr::core::vector3df(x, y, z), ERBTransformSpace::ERBTS_WORLD);
	}
}

void rc_getActorVelocityInLocalPoint(int actor, double rel_x, double rel_y, double rel_z, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df pos = rc_actor[actor].physics.rigid_body->getVelocityInLocalPoint(irr::core::vector3df(rel_x, rel_y, rel_z));
		*x = pos.X;
		*y = pos.Y;
		*z = pos.Z;
	}
}

void rc_getActorLinearVelocityLocal(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		btVector3 v = rc_actor[actor].physics.rigid_body->getPointer()->getWorldTransform().getBasis().transpose() * rc_actor[actor].physics.rigid_body->getPointer()->getLinearVelocity();
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

void rc_getActorAngularVelocityLocal(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *x = 0;
    *y = 0;
    *z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		btVector3 v = rc_actor[actor].physics.rigid_body->getPointer()->getWorldTransform().getBasis().transpose() * rc_actor[actor].physics.rigid_body->getPointer()->getAngularVelocity();
		*x = rc_util_degrees(v.getX());
		*y = rc_util_degrees(v.getY());
		*z = rc_util_degrees(v.getZ());
	}
}

void rc_getActorAABB(int actor, double* min_x, double* min_y, double* min_z, double* max_x, double* max_y, double* max_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    *min_x = 0;
	*min_y = 0;
	*min_z = 0;
	*max_x = 0;
	*max_y = 0;
	*max_z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df min_aabb;
		irr::core::vector3df max_aabb;
		rc_actor[actor].physics.rigid_body->getAabb(min_aabb, max_aabb);
		*min_x = min_aabb.X;
		*min_y = min_aabb.Y;
		*min_z = min_aabb.Z;
		*max_x = max_aabb.X;
		*max_y = max_aabb.Y;
		*max_z = max_aabb.Z;
	}
}

double rc_computeActorImpulseDenominator(int actor, double pos_x, double pos_y, double pos_z, double normal_x, double normal_y, double normal_z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->computeImpulseDenominator(irr::core::vector3df(pos_x, pos_y, pos_z), irr::core::vector3df(normal_x, normal_y, normal_z));
	}

	return 0;
}

double rc_computeActorAngularImpulseDenominator(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		return rc_actor[actor].physics.rigid_body->computeAngularImpulseDenominator(irr::core::vector3df(x, y, z));
	}

	return 0;
}

void rc_setActorAngularFactor(int actor, double x, double y, double z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

    if(rc_actor[actor].physics.rigid_body)
	{
		rc_actor[actor].physics.rigid_body->setAngularFactor(irr::core::vector3df(x, y, z));
	}
}

void rc_getActorAngularFactor(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		irr::core::vector3df af = rc_actor[actor].physics.rigid_body->getAngularFactor();
		*x = af.X;
		*y = af.Y;
		*z = af.Z;
	}
}

void rc_computeActorGyroImpulseLocal(int actor, double step, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		btVector3 v = rc_actor[actor].physics.rigid_body->getPointer()->computeGyroscopicImpulseImplicit_Body(step);
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

void rc_computeActorGyroImpulseWorld(int actor, double dt, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		btVector3 v = rc_actor[actor].physics.rigid_body->getPointer()->computeGyroscopicImpulseImplicit_World(dt);
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

void rc_getActorLocalInertia(int actor, double* x, double* y, double* z)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

    if(rc_actor[actor].physics.rigid_body)
	{
		btVector3 v = rc_actor[actor].physics.rigid_body->getPointer()->getLocalInertia();
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}


#endif // RC_ACTOR_PHYSICS_H_INCLUDED
