function  createPointConstraint( actorA,  pxA,  pyA,  pzA)
function  createPointConstraintEx( actorA,  actorB,  pxA,  pyA,  pzA,  pxB,  pyB,  pzB)
sub  setPointPivotA( constraint_id,  x,  y,  z)
sub  setPointPivotB( constraint_id,  x,  y,  z)
function  createHingeConstraint( actorA, frameA, useReferenceFrameA )
function  createHingeConstraintEx( actorA, actorB, frameA, frameB, useReferenceFrameA)
function  createSlideConstraint( actorA,  frameInB_matrix,  useLinearReferenceFrameA)
function  createSlideConstraintEx( actorA,  actorB,  frameInA_matrix,  frameInB_matrix,  useLinearReferenceFrameA)
function  createConeConstraint( actorA,  rbAFrame_matrix)
function  createConeConstraintEx( actorA,  actorB,  rbAFrame_matrix,  rbBFrame_matrix)
sub  deleteConstraint( constraint_id)
sub  getConstraintFrameOffsetA( constraint_id, ByRef x, ByRef y, ByRef z, ByRef rx, ByRef ry, ByRef rz)
sub  getConstraintFrameOffsetB( constraint_id, ByRef x, ByRef y, ByRef z, ByRef rx, ByRef ry, ByRef rz)
sub  useConstraintFrameOffset( constraint_id,  flag)
function  getHingeAngle( constraint_id)
function  getHingeAngleEx( constraint_id,  t_matrixA,  t_matrixB)
function  getConstraintBreakingImpulseThreshold( constraint_id)
function  getConstraintAFrame( constraint_id,  mA)
function  getConstraintBFrame( constraint_id,  mA)
sub  setHingeAxis( constraint_id,  x,  y,  z)
sub  setConstraintBreakingImpulseThreshold( constraint_id,  threshold)
sub  setConstraintFrames( constraint_id,  frameA_matrix,  frameB_matrix)
sub  setHingeLimit( constraint_id,  low,  high,  softness,  bias_factor,  relaxation_factor)
sub  setConeLimit( constraint_id,  swingSpan1,  swingSpan2,  twistSpan,  softness,  bias_factor,  relaxation_factor)
function  getHingeLimitBiasFactor( constraint_id)
function  getHingeLimitRelaxationFactor( constraint_id)
function  getHingeLimitSign( constraint_id)
function  getHingeSolveLimit( constraint_id)
sub  useHingeReferenceFrameA( constraint_id,  flag)
function  getConstraintAppliedImpulse( constraint_id)
function  getConstraintFixedActor( constraint_id)
sub  getPointPivotA( constraint_id, ByRef x, ByRef y, ByRef z)
sub  getPointPivotB( constraint_id, ByRef x, ByRef y, ByRef z)
function  getConstraintActorA( constraint_id)
function  getConstraintActorB( constraint_id)
sub  setConstraintSolverIterations( constraint_id,  num)
function  getConeBiasFactor( constraint_id)
function  getConeDamping( constraint_id)
function  getConeFixThresh( constraint_id)
function  getConeLimit( constraint_id,  limit_index)
function  getConstraintLimitSoftness( constraint_id)
function  getConstraintSolverIterations( constraint_id)
sub  getConeAnglePoint( constraint_id,  angle,  c_len, ByRef x, ByRef y, ByRef z)
function  getConstraintAngularOnly( constraint_id)
function  getConeSolveSwingLimit( constraint_id)
function  getConeSolveTwistLimit( constraint_id)
function  getConeSwingSpan1( constraint_id)
function  getConeSwingSpan2( constraint_id)
function  getConeTwistAngle( constraint_id)
function  getConeTwistLimitSign( constraint_id)
function  getConeTwistSpan( constraint_id)
sub  setConstraintAngularOnly( constraint_id,  flag)
sub  setConeDamping( constraint_id,  damping)
sub  setConeFixThresh( constraint_id,  fixThresh)
sub  getSlideAnchorA( constraint_id, ByRef x, ByRef y, ByRef z)
sub  getSlideAnchorB( constraint_id, ByRef x, ByRef y, ByRef z)
function  getSlideAngDepth( constraint_id)
function  getSlideAngularPos( constraint_id)
function  getSlideDampingDirAng( constraint_id)
function  getSlideDampingDirLin( constraint_id)
function  getSlideDampingLimAng( constraint_id)
function  getSlideDampingLimLin( constraint_id)
function  getSlideDampingOrthoAng( constraint_id)
function  getSlideDampingOrthoLin( constraint_id)
function  getSlideLinearPos( constraint_id)
function  getSlideLinDepth( constraint_id)
function  getSlideLowerAngLimit( constraint_id)
function  getSlideLowerLinLimit( constraint_id)
function  getSlideRestitutionDirAng( constraint_id)
function  getSlideRestitutionDirLin( constraint_id)
function  getSlideRestitutionLimAng( constraint_id)
function  getSlideRestitutionLimLin( constraint_id)
function  getSlideRestitutionOrthoAng( constraint_id)
function  getSlideRestitutionOrthoLin( constraint_id)
function  getSlideSoftnessDirAng( constraint_id)
function  getSlideSoftnessDirLin( constraint_id)
function  getSlideSoftnessLimAng( constraint_id)
function  getSlideSoftnessLimLin( constraint_id)
function  getSlideSoftnessOrthoAng( constraint_id)
function  getSlideSoftnessOrthoLin( constraint_id)
function  getSlideSolveAngLimit( constraint_id)
function  getSlideSolveLinLimit( constraint_id)
function  getSlideUpperAngLimit( constraint_id)
function  getSlideUpperLinLimit( constraint_id)
function  getSlideUseFrameOffset( constraint_id)
sub  setSlideDampingDirAng( constraint_id,  n)
sub  setSlideDampingDirLin( constraint_id,  n)
sub  setSlideDampingLimAng( constraint_id,  n)
sub  setSlideDampingLimLin( constraint_id,  n)
sub  setSlideDampingOrthoAng( constraint_id,  n)
sub  setSlideDampingOrthoLin( constraint_id,  n)
sub  setSlideLowerAngLimit( constraint_id,  n)
sub  setSlideLowerLinLimit( constraint_id,  n)
sub  setSlideRestitutionDirAng( constraint_id,  n)
sub  setSlideRestitutionDirLin( constraint_id,  n)
sub  setSlideRestitutionLimAng( constraint_id,  n)
sub  setSlideRestitutionLimLin( constraint_id,  n)
sub  setSlideRestitutionOrthoAng( constraint_id,  n)
sub  setSlideRestitutionOrthoLin( constraint_id,  n)
sub  setSlideSoftnessDirAng( constraint_id,  n)
sub  setSlideSoftnessDirLin( constraint_id,  n)
sub  setSlideSoftnessLimAng( constraint_id,  n)
sub  setSlideSoftnessLimLin( constraint_id,  n)
sub  setSlideSoftnessOrthoAng( constraint_id,  n)
sub  setSlideSoftnessOrthoLin( constraint_id,  n)
sub  setSlideUpperAngLimit( constraint_id,  n)
sub  setSlideUpperLinLimit( constraint_id,  n)
function ConstraintExists( constraint_id )