function CreateAnimatedActor( mesh )
function CreateOctreeActor( mesh )
function CreateCubeActor( cube_size )
function CreateSphereActor( radius )
function CreateWaterActor( mesh, waveHeight, waveSpeed, waveLength )
function CreateLightActor( )
function CreateBillboardActor( )
function CreateTerrainActor( hmap_file$ )
function CreateParticleActor( particle_type )
sub DeleteActor( actor )
sub GetActorTransform( actor, matrix )
sub SetActorPosition( actor, x, y, z )
sub TranslateActorLocal( actor, x, y, z )
sub TranslateActorWorld( actor, x, y, z )
sub GetActorPosition( actor, ByRef x, ByRef y, ByRef z )
sub SetActorScale( actor, x, y, z )
sub ScaleActor( actor, x, y, z )
sub GetActorScale( actor, ByRef x, ByRef y, ByRef z )
sub SetActorRotation( actor, x, y, z )
sub RotateActor( actor, x, y, z )
sub GetActorRotation( actor, ByRef x, ByRef y, ByRef z )
sub SetActorVisible( actor, flag )
function ActorIsVisible( actor )
sub SetActorAutoCulling( actor, cull_type )
function GetActorAutoCulling( actor )
sub AddActorShadow( actor )
sub RemoveActorShadow( actor )
function ActorExists( actor )
