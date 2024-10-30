#ifndef RC_CONSTRAINT_H_INCLUDED
#define RC_CONSTRAINT_H_INCLUDED

int getConstraintId()
{
	int cid = -1;
	for(int i = 0; i < rc_physics3D.constraints.size(); i++)
	{
		if(rc_physics3D.constraints[i].type <= 0)
		{
			cid = i;
			break;
		}
	}

	if(cid >= 0)
		return cid;

	rc_constraint_obj constraint;
	cid = rc_physics3D.constraints.size();
	rc_physics3D.constraints.push_back(constraint);
	return cid;
}

int rc_createPointConstraint(int actorA, double pxA, double pyA, double pzA)
{
	if(actorA < 0 || actorA >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body)
	{
		rc_constraint_obj p2p;
		p2p.type = RC_CONSTRAINT_TYPE_POINT;
		btVector3 pvtA(pxA, pyA, pzA);
		p2p.constraint = new btPoint2PointConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), pvtA);
		rc_physics3D.world->getPointer()->addConstraint(p2p.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = p2p;
		return constraint_id;
	}

	return -1;
}

int rc_createPointConstraintEx(int actorA, int actorB, double pxA, double pyA, double pzA, double pxB, double pyB, double pzB)
{
	if(actorA < 0 || actorA >= rc_actor.size() || actorB < 0 || actorB >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body && rc_actor[actorB].physics.rigid_body)
	{
		rc_constraint_obj p2p;
		p2p.type = RC_CONSTRAINT_TYPE_POINT;
		btVector3 pvtA(pxA, pyA, pzA);
		btVector3 pvtB(pxB, pyB, pzB);
		p2p.constraint = new btPoint2PointConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), *rc_actor[actorB].physics.rigid_body->getPointer(),
														pvtA, pvtB);
		rc_physics3D.world->getPointer()->addConstraint(p2p.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = p2p;
		return constraint_id;
	}

	return -1;
}

void rc_setPointPivotA(int constraint_id, double x, double y, double z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

    if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* c = (btPoint2PointConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		c->setPivotA(btVector3(x, y, z));
	}
}

void rc_setPointPivotB(int constraint_id, double x, double y, double z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

    if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* c = (btPoint2PointConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		c->setPivotB(btVector3(x, y, z));
	}
}

int rc_createHingeConstraint(int actorA, int frameInA_matrix, bool useReferenceFrameA)
{
	if(actorA < 0 || actorA >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body)
	{
		rc_constraint_obj hinge;
		hinge.type = RC_CONSTRAINT_TYPE_HINGE;

		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(frameInA_matrix);
		btTransform frameInA;
		btTransformFromIrrlichtMatrix(irr_matA, frameInA);

		hinge.constraint = new btHingeConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), frameInA, useReferenceFrameA);
		rc_physics3D.world->getPointer()->addConstraint(hinge.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = hinge;
		return constraint_id;
	}

	return -1;
}


int rc_createHingeConstraintEx(int actorA, int actorB, int frameInA_matrix, int frameInB_matrix, bool useReferenceFrameA)
{
	if(actorA < 0 || actorA >= rc_actor.size() || actorB < 0 || actorB >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body && rc_actor[actorB].physics.rigid_body)
	{
		rc_constraint_obj hinge;
		hinge.type = RC_CONSTRAINT_TYPE_HINGE;

		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(frameInA_matrix);
		irr::core::matrix4 irr_matB = rc_convertToIrrMatrix(frameInB_matrix);

		btTransform frameInA, frameInB;
		btTransformFromIrrlichtMatrix(irr_matA, frameInA);
		btTransformFromIrrlichtMatrix(irr_matB, frameInB);

		hinge.constraint = new btHingeConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), *rc_actor[actorB].physics.rigid_body->getPointer(), frameInA, frameInB, useReferenceFrameA);
		rc_physics3D.world->getPointer()->addConstraint(hinge.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = hinge;
		return constraint_id;
	}

	return -1;
}

int rc_createSlideConstraint(int actorA, int frameInB_matrix, bool useLinearReferenceFrameA)
{
	if(actorA < 0 || actorA >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body)
	{
		rc_constraint_obj slide;
		slide.type = RC_CONSTRAINT_TYPE_SLIDER;

		irr::core::matrix4 irr_mat = rc_convertToIrrMatrix(frameInB_matrix);
		btTransform frameInB;
		btTransformFromIrrlichtMatrix(irr_mat, frameInB);

		slide.constraint = new btSliderConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), frameInB, useLinearReferenceFrameA);
		rc_physics3D.world->getPointer()->addConstraint(slide.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = slide;
		return constraint_id;
	}

	return -1;
}

int rc_createSlideConstraintEx(int actorA, int actorB, int frameInA_matrix, int frameInB_matrix, bool useLinearReferenceFrameA)
{
	if(actorA < 0 || actorA >= rc_actor.size() || actorB < 0 || actorB >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body && rc_actor[actorB].physics.rigid_body)
	{
		rc_constraint_obj slide;
		slide.type = RC_CONSTRAINT_TYPE_SLIDER;

		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(frameInA_matrix);
		irr::core::matrix4 irr_matB = rc_convertToIrrMatrix(frameInB_matrix);

		btTransform frameInA, frameInB;
		btTransformFromIrrlichtMatrix(irr_matA, frameInA);
		btTransformFromIrrlichtMatrix(irr_matB, frameInB);

		slide.constraint = new btSliderConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), *rc_actor[actorB].physics.rigid_body->getPointer(), frameInA, frameInB, useLinearReferenceFrameA);
		rc_physics3D.world->getPointer()->addConstraint(slide.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = slide;
		return constraint_id;
	}

	return -1;
}


int rc_createConeConstraint(int actorA, int rbAFrame_matrix)
{
	if(actorA < 0 || actorA >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body)
	{
		rc_constraint_obj cone;
		cone.type = RC_CONSTRAINT_TYPE_CONE;

		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(rbAFrame_matrix);

		btTransform rba;
		btTransformFromIrrlichtMatrix(irr_matA, rba);

		cone.constraint = new btConeTwistConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), rba);
		rc_physics3D.world->getPointer()->addConstraint(cone.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = cone;
		return constraint_id;
	}

	return -1;
}

int rc_createConeConstraintEx(int actorA, int actorB, int rbAFrame_matrix, int rbBFrame_matrix)
{
	if(actorA < 0 || actorA >= rc_actor.size() || actorB < 0 || actorB >= rc_actor.size())
        return -1;

    if(rc_actor[actorA].physics.rigid_body && rc_actor[actorB].physics.rigid_body)
	{
		rc_constraint_obj cone;
		cone.type = RC_CONSTRAINT_TYPE_CONE;

		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(rbAFrame_matrix);
		irr::core::matrix4 irr_matB = rc_convertToIrrMatrix(rbBFrame_matrix);

		btTransform rba, rbb;
		btTransformFromIrrlichtMatrix(irr_matA, rba);
		btTransformFromIrrlichtMatrix(irr_matB, rbb);

		cone.constraint = new btConeTwistConstraint(*rc_actor[actorA].physics.rigid_body->getPointer(), *rc_actor[actorB].physics.rigid_body->getPointer(), rba, rbb);
		rc_physics3D.world->getPointer()->addConstraint(cone.constraint);
		int constraint_id = getConstraintId();
		rc_physics3D.constraints[constraint_id] = cone;
		return constraint_id;
	}

	return -1;
}

void rc_deleteConstraint(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

    if(rc_physics3D.constraints[constraint_id].constraint)
	{
		rc_physics3D.world->getPointer()->removeConstraint(rc_physics3D.constraints[constraint_id].constraint);
		rc_physics3D.constraints[constraint_id].constraint = NULL;
		rc_physics3D.constraints[constraint_id].type = 0;
	}
}

bool rc_constraintExists(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return false;

    if(rc_physics3D.constraints[constraint_id].constraint)
		return true;

	return false;
}


void rc_getConstraintFrameOffsetA(int constraint_id, double* x, double* y, double* z, double* rx, double* ry, double* rz)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	*rx = 0;
	*ry = 0;
	*rz = 0;

    if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		//btTransform t = hinge->getFrameOffsetA();
		//t.getBasis().getEulerZYX()
		*x = hinge->getFrameOffsetA().getOrigin().getX();
		*y = hinge->getFrameOffsetA().getOrigin().getY();
		*z = hinge->getFrameOffsetA().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		hinge->getFrameOffsetA().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = rc_util_degrees(roll);
		*ry = rc_util_degrees(pitch);
		*rz = rc_util_degrees(yaw);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		*x = cone->getFrameOffsetA().getOrigin().getX();
		*y = cone->getFrameOffsetA().getOrigin().getY();
		*z = cone->getFrameOffsetA().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		cone->getFrameOffsetA().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = rc_util_degrees(roll);
		*ry = rc_util_degrees(pitch);
		*rz = rc_util_degrees(yaw);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		*x = slide->getFrameOffsetA().getOrigin().getX();
		*y = slide->getFrameOffsetA().getOrigin().getY();
		*z = slide->getFrameOffsetA().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		slide->getFrameOffsetA().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = rc_util_degrees(roll);
		*ry = rc_util_degrees(pitch);
		*rz = rc_util_degrees(yaw);
	}
}

void rc_getConstraintFrameOffsetB(int constraint_id, double* x, double* y, double* z, double* rx, double* ry, double* rz)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	*rx = 0;
	*ry = 0;
	*rz = 0;

    if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		*x = hinge->getFrameOffsetB().getOrigin().getX();
		*y = hinge->getFrameOffsetB().getOrigin().getY(); btTransform:
		*z = hinge->getFrameOffsetB().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		hinge->getFrameOffsetB().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = rc_util_degrees(roll);
		*ry = rc_util_degrees(pitch);
		*rz = rc_util_degrees(yaw);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		*x = cone->getFrameOffsetB().getOrigin().getX();
		*y = cone->getFrameOffsetB().getOrigin().getY();
		*z = cone->getFrameOffsetB().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		cone->getFrameOffsetB().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = rc_util_degrees(roll);
		*ry = rc_util_degrees(pitch);
		*rz = rc_util_degrees(yaw);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*)rc_physics3D.constraints[constraint_id].constraint;
		*x = slide->getFrameOffsetB().getOrigin().getX();
		*y = slide->getFrameOffsetB().getOrigin().getY();
		*z = slide->getFrameOffsetB().getOrigin().getZ();

		btScalar yaw, pitch, roll;
		slide->getFrameOffsetB().getBasis().getEulerZYX(yaw, pitch, roll);
		*rx = rc_util_degrees(roll);
		*ry = rc_util_degrees(pitch);
		*rz = rc_util_degrees(yaw);
	}
}


void rc_useConstraintFrameOffset(int constraint_id, bool flag)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setUseFrameOffset(flag);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setUseFrameOffset(flag);
	}
}

//btHingeConstraint::getHingeAngle()
double rc_getHingeAngle(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(hinge->getHingeAngle());
	}

	return 0;
}

double rc_getHingeAngleEx(int constraint_id, int t_matrixA, int t_matrixB)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform transformA, transformB;
		irr::core::matrix4 irr_matA = rc_convertToIrrMatrix(t_matrixA);
		irr::core::matrix4 irr_matB = rc_convertToIrrMatrix(t_matrixB);
		btTransformFromIrrlichtMatrix(irr_matA, transformA);
		btTransformFromIrrlichtMatrix(irr_matB, transformB);
		return rc_util_degrees(hinge->getHingeAngle(transformA, transformB));
	}

	return 0;
}

//btHingeConstraint::getBreakingImpulseThreshold()
double rc_getConstraintBreakingImpulseThreshold(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getBreakingImpulseThreshold();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return p2p->getBreakingImpulseThreshold();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getBreakingImpulseThreshold();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getBreakingImpulseThreshold();
	}

	return 0;
}

//btHingeConstraint::getAFrame()
int rc_getConstraintAFrame(int constraint_id, int mA)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return -1;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform aframe = hinge->getAFrame();
		irr::core::matrix4 irr_mat;
		btTransformToIrrlichtMatrix(aframe, irr_mat);
		mA = rc_convertFromIrrMatrix(irr_mat, mA);
		return mA;
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform aframe = cone->getAFrame();
		irr::core::matrix4 irr_mat;
		btTransformToIrrlichtMatrix(aframe, irr_mat);
		mA = rc_convertFromIrrMatrix(irr_mat, mA);
		return mA;
	}

	return -1;
}

//btHingeConstraint::getBFrame()
int rc_getConstraintBFrame(int constraint_id, int mA)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return -1;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform bframe = hinge->getBFrame();
		irr::core::matrix4 irr_mat;
		btTransformToIrrlichtMatrix(bframe, irr_mat);
		mA = rc_convertFromIrrMatrix(irr_mat, mA);
		return mA;
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform bframe = cone->getBFrame();
		irr::core::matrix4 irr_mat;
		btTransformToIrrlichtMatrix(bframe, irr_mat);
		mA = rc_convertFromIrrMatrix(irr_mat, mA);
		return mA;
	}

	return -1;
}

//btHingeConstraint::setAxis()
void rc_setHingeAxis(int constraint_id, double x, double y, double z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 axis(x,y,z);
		hinge->setAxis(axis);
	}
}

//btHingeConstraint::setBreakingImpulseThreshold()
void rc_setConstraintBreakingImpulseThreshold(int constraint_id, double threshold)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setBreakingImpulseThreshold(threshold);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		p2p->setBreakingImpulseThreshold(threshold);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setBreakingImpulseThreshold(threshold);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setBreakingImpulseThreshold(threshold);
	}
}

//btHingeConstraint::setFrames()
void rc_setConstraintFrames(int constraint_id, int frameA_matrix, int frameB_matrix)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform frameA, frameB;
		irr::core::matrix4 irr_matA, irr_matB;
		irr_matA = rc_convertToIrrMatrix(frameA_matrix);
		irr_matB = rc_convertToIrrMatrix(frameB_matrix);
		btTransformFromIrrlichtMatrix(irr_matA, frameA);
		btTransformFromIrrlichtMatrix(irr_matB, frameB);
		hinge->setFrames(frameA, frameB);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform frameA, frameB;
		irr::core::matrix4 irr_matA, irr_matB;
		irr_matA = rc_convertToIrrMatrix(frameA_matrix);
		irr_matB = rc_convertToIrrMatrix(frameB_matrix);
		btTransformFromIrrlichtMatrix(irr_matA, frameA);
		btTransformFromIrrlichtMatrix(irr_matB, frameB);
		cone->setFrames(frameA, frameB);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btTransform frameA, frameB;
		irr::core::matrix4 irr_matA, irr_matB;
		irr_matA = rc_convertToIrrMatrix(frameA_matrix);
		irr_matB = rc_convertToIrrMatrix(frameB_matrix);
		btTransformFromIrrlichtMatrix(irr_matA, frameA);
		btTransformFromIrrlichtMatrix(irr_matB, frameB);
		slide->setFrames(frameA, frameB);
	}
}

//btHingeConstraint::setLimit();
void rc_setHingeLimit(int constraint_id, double low, double high, double softness, double bias_factor, double relaxation_factor)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setLimit(rc_util_radians(low), rc_util_radians(high), softness, bias_factor, relaxation_factor);
	}
}

void rc_setConeLimit(int constraint_id, double swingSpan1, double swingSpan2, double twistSpan, double softness, double bias_factor, double relaxation_factor)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setLimit(rc_util_radians(swingSpan1), rc_util_radians(swingSpan2), rc_util_radians(twistSpan), softness, bias_factor, relaxation_factor);
	}
}

//btHingeConstraint::getLimitBiasFactor()
double rc_getHingeLimitBiasFactor(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getLimitBiasFactor();
	}

	return 0;
}

//btHingeConstraint::getLimitRelaxationFactor()
double rc_getHingeLimitRelaxationFactor(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getLimitRelaxationFactor();
	}

	return 0;
}

//btHingeConstraint::getLimitSign()
double rc_getHingeLimitSign(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getLimitSign();
	}

	return 0;
}

//btHingeConstraint::getSolveLimit()
int rc_getHingeSolveLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getSolveLimit();
	}

	return 0;
}

//btHingeConstraint::setUseReferenceFrameA()
void rc_useHingeReferenceFrameA(int constraint_id, bool flag)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setUseReferenceFrameA(flag);
	}
}


//
//btPoint2PointConstraint::getAppliedImpulse()
double rc_getConstraintAppliedImpulse(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getAppliedImpulse();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return p2p->getAppliedImpulse();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getAppliedImpulse();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getAppliedImpulse();
	}

	return 0;
}


//btPoint2PointConstraint::getFixedBody()
int rc_getConstraintFixedActor(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return -1;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = hinge->getFixedBody();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = p2p->getFixedBody();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = cone->getFixedBody();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = slide->getFixedBody();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}

	return -1;
}

//btPoint2PointConstraint::getPivotInA()
void rc_getPointPivotA(int constraint_id, double* x, double* y, double* z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 pivot = p2p->getPivotInA();
		*x = pivot.getX();
		*y = pivot.getY();
		*z = pivot.getZ();
	}
}

//btPoint2PointConstraint::getPivotInB()
void rc_getPointPivotB(int constraint_id, double* x, double* y, double* z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 pivot = p2p->getPivotInB();
		*x = pivot.getX();
		*y = pivot.getY();
		*z = pivot.getZ();
	}
}

//btPoint2PointConstraint::getRigidBodyA()
int rc_getConstraintActorA(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return -1;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = hinge->getRigidBodyA();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = p2p->getRigidBodyA();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = cone->getRigidBodyA();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = slide->getRigidBodyA();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}

	return -1;
}

//btPoint2PointConstraint::getRigidBodyB()
int rc_getConstraintActorB(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return -1;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = hinge->getRigidBodyB();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = p2p->getRigidBodyB();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = cone->getRigidBodyB();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btRigidBody body = slide->getRigidBodyB();
		SCollisionObjectIdentification* identification = (SCollisionObjectIdentification*)body.getUserPointer();
		return identification->getId();
	}

	return -1;
}

//btPoint2PointConstraint::setOverrideNumSolverIterations()
void rc_setConstraintSolverIterations(int constraint_id, int num)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setOverrideNumSolverIterations(num);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		p2p->setOverrideNumSolverIterations(num);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setOverrideNumSolverIterations(num);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setOverrideNumSolverIterations(num);
	}
}

//
//btConeTwistConstraint::getBiasFactor()
double rc_getConeBiasFactor(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getBiasFactor();
	}

	return 0;
}

//btConeTwistConstraint::getDamping()
double rc_getConeDamping(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getDamping();
	}

	return 0;
}

//btConeTwistConstraint::getFixThresh()
double rc_getConeFixThresh(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getFixThresh();
	}

	return 0;
}

//btConeTwistConstraint::getLimit()
double rc_getConeLimit(int constraint_id, int limit_index)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(cone->getLimit(limit_index));
	}

	return 0;
}

//btConeTwistConstraint::getLimitSoftness()
double rc_getConstraintLimitSoftness(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getLimitSoftness();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getLimitSoftness();
	}

	return 0;
}

//btConeTwistConstraint::getOverrideNumSolverIterations()
double rc_getConstraintSolverIterations(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getOverrideNumSolverIterations();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_POINT)
	{
		btPoint2PointConstraint* p2p = (btPoint2PointConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return p2p->getOverrideNumSolverIterations();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getOverrideNumSolverIterations();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getOverrideNumSolverIterations();
	}

	return 0;
}

//btConeTwistConstraint::GetPointForAngle()
void rc_getConeAnglePoint(int constraint_id, double angle, double len, double* x, double* y, double* z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 v = cone->GetPointForAngle( radians(angle), len);
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

//btConeTwistConstraint::getAngularOnly()
bool rc_getConstraintAngularOnly(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return false;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return hinge->getAngularOnly();
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getAngularOnly();
	}

	return false;
}

//btConeTwistConstraint::getSolveSwingLimit()
int rc_getConeSolveSwingLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getSolveSwingLimit();
	}

	return 0;
}

int rc_getConeSolveTwistLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getSolveTwistLimit();
	}

	return 0;
}

//btConeTwistConstraint::getSwingSpan1()
double rc_getConeSwingSpan1(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(cone->getSwingSpan1());
	}

	return 0;
}

//btConeTwistConstraint::getSwingSpan2()
int rc_getConeSwingSpan2(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(cone->getSwingSpan2());
	}

	return 0;
}

//btConeTwistConstraint::getTwistAngle()
double rc_getConeTwistAngle(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(cone->getTwistAngle());
	}

	return 0;
}


//btConeTwistConstraint::getTwistLimitSign()
double rc_getConeTwistLimitSign(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return cone->getTwistLimitSign();
	}

	return 0;
}

//btConeTwistConstraint::getTwistSpan()
int rc_getConeTwistSpan(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(cone->getTwistSpan());
	}

	return 0;
}

//btConeTwistConstraint::setAngularOnly()
void rc_setConstraintAngularOnly(int constraint_id, bool flag)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_HINGE)
	{
		btHingeConstraint* hinge = (btHingeConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		hinge->setAngularOnly(flag);
	}
	else if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setAngularOnly(flag);
	}
}

//btConeTwistConstraint::setDamping()
void rc_setConeDamping(int constraint_id, double damping)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setDamping(damping);
	}
}

//btConeTwistConstraint::setFixThresh()
void rc_setConeFixThresh(int constraint_id, double fixThresh)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_CONE)
	{
		btConeTwistConstraint* cone = (btConeTwistConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		cone->setFixThresh(fixThresh);
	}
}


//btSliderConstraint::getAncorInA()
void rc_getSlideAnchorA(int constraint_id, double* x, double* y, double* z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 v = slide->getAncorInA();
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

//btSliderConstraint::getAncorInB()
void rc_getSlideAnchorB(int constraint_id, double* x, double* y, double* z)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	*x = 0;
	*y = 0;
	*z = 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		btVector3 v = slide->getAncorInB();
		*x = v.getX();
		*y = v.getY();
		*z = v.getZ();
	}
}

//btSliderConstraint::getAngDepth()
double rc_getSlideAngDepth(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(slide->getAngDepth());
	}

	return 0;
}

//btSliderConstraint::getAngularPos()
double rc_getSlideAngularPos(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(slide->getAngularPos());
	}

	return 0;
}

//btSliderConstraint::getDampingDirAng()
double rc_getSlideDampingDirAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(slide->getDampingDirAng());
	}

	return 0;
}

//btSliderConstraint::getDampingDirLin()
double rc_getSlideDampingDirLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getDampingDirLin();
	}

	return 0;
}

//btSliderConstraint::getDampingLimAng()
double rc_getSlideDampingLimAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(slide->getDampingLimAng());
	}

	return 0;
}

//btSliderConstraint::getDampingLimLin()
double rc_getSlideDampingLimLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getDampingLimLin();
	}

	return 0;
}

//btSliderConstraint::getDampingOrthoAng()
double rc_getSlideDampingOrthoAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(slide->getDampingOrthoAng());
	}

	return 0;
}

//btSliderConstraint::getDampingOrthoLin()
double rc_getSlideDampingOrthoLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getDampingOrthoLin();
	}

	return 0;
}

//btSliderConstraint::getLinearPos()
double rc_getSlideLinearPos(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getLinearPos();
	}

	return 0;
}

//btSliderConstraint::getLinDepth()
double rc_getSlideLinDepth(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getLinDepth();
	}

	return 0;
}

//btSliderConstraint::getLowerAngLimit()
double rc_getSlideLowerAngLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(slide->getLowerAngLimit());
	}

	return 0;
}

//btSliderConstraint::getLowerLinLimit()
double rc_getSlideLowerLinLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getLowerLinLimit();
	}

	return 0;
}

//btSliderConstraint::getRestitutionDirAng()
double rc_getSlideRestitutionDirAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionDirAng();
	}

	return 0;
}

//btSliderConstraint::getRestitutionDirLin()
double rc_getSlideRestitutionDirLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionDirLin();
	}

	return 0;
}

//btSliderConstraint::getRestitutionLimAng()
double rc_getSlideRestitutionLimAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionLimAng();
	}

	return 0;
}

//btSliderConstraint::getRestitutionLimLin()
double rc_getSlideRestitutionLimLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionLimLin();
	}

	return 0;
}

//btSliderConstraint::getRestitutionOrthoAng()
double rc_getSlideRestitutionOrthoAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionOrthoAng();
	}

	return 0;
}

//btSliderConstraint::getRestitutionOrthoLin()
double rc_getSlideRestitutionOrthoLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getRestitutionOrthoLin();
	}

	return 0;
}

//btSliderConstraint::getSoftnessDirAng()
double rc_getSlideSoftnessDirAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessDirAng();
	}

	return 0;
}

//btSliderConstraint::getSoftnessDirLin()
double rc_getSlideSoftnessDirLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessDirLin();
	}

	return 0;
}

//btSliderConstraint::getSoftnessLimAng()
double rc_getSlideSoftnessLimAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessLimAng();
	}

	return 0;
}

//btSliderConstraint::getSoftnessLimLin()
double rc_getSlideSoftnessLimLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessLimLin();
	}

	return 0;
}

//btSliderConstraint::getSoftnessOrthoAng()
double rc_getSlideSoftnessOrthoAng(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessOrthoAng();
	}

	return 0;
}

//btSliderConstraint::getSoftnessOrthoLin()
double rc_getSlideSoftnessOrthoLin(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSoftnessOrthoLin();
	}

	return 0;
}

//btSliderConstraint::getSolveAngLimit()
bool rc_getSlideSolveAngLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(slide->getSolveAngLimit());
	}

	return 0;
}

//btSliderConstraint::getSolveLinLimit()
bool rc_getSlideSolveLinLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getSolveLinLimit();
	}

	return 0;
}

//btSliderConstraint::getUpperAngLimit()
double rc_getSlideUpperAngLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return rc_util_degrees(slide->getUpperAngLimit());
	}

	return 0;
}

//btSliderConstraint::getUpperLinLimit()
double rc_getSlideUpperLinLimit(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getUpperLinLimit();
	}

	return 0;
}

//btSliderConstraint::getUseFrameOffset()
bool rc_getSlideUseFrameOffset(int constraint_id)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return 0;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		return slide->getUseFrameOffset();
	}

	return 0;
}

//btSliderConstraint::setDampingDirAng()
void rc_setSlideDampingDirAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingDirAng(rc_util_radians(n));
	}
}

//btSliderConstraint::setDampingDirLin()
void rc_setSlideDampingDirLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingDirLin(n);
	}
}

//btSliderConstraint::setDampingLimAng()
void rc_setSlideDampingLimAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingLimAng(rc_util_radians(n));
	}
}

//btSliderConstraint::setDampingLimLin()
void rc_setSlideDampingLimLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingLimLin(n);
	}
}

//btSliderConstraint::setDampingOrthoAng()
void rc_setSlideDampingOrthoAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingOrthoAng(rc_util_radians(n));
	}
}

//btSliderConstraint::setDampingOrthoLin()
void rc_setSlideDampingOrthoLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setDampingOrthoLin(n);
	}
}

//btSliderConstraint::setLowerAngLimit()
void rc_setSlideLowerAngLimit(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setLowerAngLimit(rc_util_radians(n));
	}
}

//btSliderConstraint::setLowerLinLimit()
void rc_setSlideLowerLinLimit(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setLowerLinLimit(n);
	}
}

//btSliderConstraint::setRestitutionDirAng()
void rc_setSlideRestitutionDirAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionDirAng(n);
	}
}

//btSliderConstraint::setRestitutionDirLin()
void rc_setSlideRestitutionDirLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionDirLin(n);
	}
}

//btSliderConstraint::setRestitutionLimAng()
void rc_setSlideRestitutionLimAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionLimAng(n);
	}
}

//btSliderConstraint::setRestitutionLimLin()
void rc_setSlideRestitutionLimLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionLimLin(n);
	}
}

//btSliderConstraint::setRestitutionOrthoAng()
void rc_setSlideRestitutionOrthoAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionOrthoAng(n);
	}
}

//btSliderConstraint::setRestitutionOrthoLin()
void rc_setSlideRestitutionOrthoLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setRestitutionOrthoLin(n);
	}
}

//btSliderConstraint::setSoftnessDirAng()
void rc_setSlideSoftnessDirAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessDirAng(n);
	}
}

//btSliderConstraint::setSoftnessDirLin()
void rc_setSlideSoftnessDirLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessDirLin(n);
	}
}

//btSliderConstraint::setSoftnessLimAng()
void rc_setSlideSoftnessLimAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessLimAng(n);
	}
}

//btSliderConstraint::setSoftnessLimLin()
void rc_setSlideSoftnessLimLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessLimLin(n);
	}
}

//btSliderConstraint::setSoftnessOrthoAng()
void rc_setSlideSoftnessOrthoAng(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessOrthoAng(n);
	}
}

//btSliderConstraint::setSoftnessOrthoLin()
void rc_setSlideSoftnessOrthoLin(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setSoftnessOrthoLin(n);
	}
}

//btSliderConstraint::setUpperAngLimit()
void rc_setSlideUpperAngLimit(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setUpperAngLimit(rc_util_radians(n));
	}
}

//btSliderConstraint::setUpperLinLimit()
void rc_setSlideUpperLinLimit(int constraint_id, double n)
{
	if(constraint_id < 0 || constraint_id >= rc_physics3D.constraints.size())
        return;

	if(rc_physics3D.constraints[constraint_id].type == RC_CONSTRAINT_TYPE_SLIDER)
	{
		btSliderConstraint* slide = (btSliderConstraint*) rc_physics3D.constraints[constraint_id].constraint;
		slide->setUpperLinLimit(n);
	}
}



#endif // RC_CONSTRAINT_H_INCLUDED
