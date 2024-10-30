#ifndef RC_ACTOR_ANIMATION_H_INCLUDED
#define RC_ACTOR_ANIMATION_H_INCLUDED

//set actor animation [TODO]
int rc_createActorAnimation(int actor, int start_frame, int end_frame, double speed)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

	rc_actor_animation_obj animation;
	animation.active = true;
	animation.start_frame = start_frame;
	animation.end_frame = end_frame;
	animation.fps = speed;
	animation.frame_swap_time = 1000/speed;

	int animation_id = rc_actor[actor].animation.size();

	if(rc_actor[actor].deleted_animation.size() > 0)
	{
		animation_id = rc_actor[actor].deleted_animation[0];
		rc_actor[actor].deleted_animation.erase(0);
		rc_actor[actor].animation[animation_id] = animation;
	}
	else
		rc_actor[actor].animation.push_back(animation);

	return animation_id;
}

void rc_deleteActorAnimation(int actor, int animation)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(animation < 0 || animation >= rc_actor[actor].animation.size())
		return;

	if(!rc_actor[actor].animation[animation].active)
		return;

	rc_actor[actor].animation[animation].active = false;
	rc_actor[actor].deleted_animation.push_back(animation);
}

void rc_setActorAnimation(int actor, int animation, int num_loops)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

	if(animation < 0 || animation >= rc_actor[actor].animation.size())
		return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            int start_frame = rc_actor[actor].animation[animation].start_frame;
            int end_frame = rc_actor[actor].animation[animation].end_frame;
            rc_actor[actor].current_animation = animation;
            rc_actor[actor].current_animation_loop = 0;
            rc_actor[actor].num_animation_loops = num_loops;
            rc_actor[actor].isPlaying = true;
            node->setCurrentFrame(start_frame);
            node->setFrameLoop((irr::s32)start_frame, (irr::s32)end_frame );
            node->setAnimationSpeed(rc_actor[actor].animation[animation].fps);
            break;
    }
}

int rc_getActorCurrentAnimation(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

	return rc_actor[actor].current_animation;
}

int rc_numActorAnimationLoops(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

	return rc_actor[actor].num_animation_loops;
}

bool rc_actorAnimationIsPlaying(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return -1;

	return rc_actor[actor].isPlaying;
}

void rc_setActorMD2Animation(int actor, int md2_animation, int num_loops)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setMD2Animation( (irr::scene::EMD2_ANIMATION_TYPE) md2_animation );

            //int start_frame = node->getStartFrame();
            //int end_frame = node->getEndFrame();
            rc_actor[actor].current_animation = RC_ANIMATION_MD2;
            rc_actor[actor].current_animation_loop = 0;
            rc_actor[actor].num_animation_loops = num_loops;
            rc_actor[actor].isPlaying = true;
            //node->setCurrentFrame(start_frame);
            //node->setFrameLoop((irr::s32)start_frame, (irr::s32)end_frame );  //setMD2Animation() does this for me
            node->setAnimationSpeed(node->getMesh()->getAnimationSpeed());
            break;
    }
}

void rc_setActorMD2AnimationByName(int actor, std::string animation_name, int num_loops)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setMD2Animation( animation_name.c_str() );

            //int start_frame = node->getStartFrame();
            //int end_frame = node->getEndFrame();
            rc_actor[actor].current_animation = RC_ANIMATION_MD2;
            rc_actor[actor].current_animation_loop = 0;
            rc_actor[actor].num_animation_loops = num_loops;
            rc_actor[actor].isPlaying = true;
            //node->setCurrentFrame(start_frame);
            //node->setFrameLoop((irr::s32)start_frame, (irr::s32)end_frame );  //setMD2Animation() does this for me
            node->setAnimationSpeed(node->getMesh()->getAnimationSpeed());
            break;
    }
}

int rc_getActorAnimationStartFrame(int actor, int animation)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(animation < 0 || animation >= rc_actor[actor].animation.size())
		return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
        	if(rc_actor[actor].current_animation == animation)
            {
            	irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
				return node->getStartFrame();
            }
            else
			{
				return rc_actor[actor].animation[animation].start_frame;
			}
    }

    return 0;
}

int rc_getActorAnimationEndFrame(int actor, int animation)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(animation < 0 || animation >= rc_actor[actor].animation.size())
		return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
        	if(rc_actor[actor].current_animation == animation)
            {
            	irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
				return node->getEndFrame();
            }
            else
			{
				return rc_actor[actor].animation[animation].end_frame;
			}
    }

    return 0;
}

int rc_getActorFrame(int actor)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            return node->getFrameNr();
    }

    return 0;
}

//set actor animation speed
void rc_setActorAnimationSpeed(int actor, int animation, double speed)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

	if(animation < 0 || animation >= rc_actor[actor].animation.size())
		return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            rc_actor[actor].animation[animation].fps = speed;

            if(animation == rc_actor[actor].current_animation)
            {
            	irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
				node->setAnimationSpeed( (irr::f32)speed );
            }
            break;
    }
}

double rc_getActorAnimationSpeed(int actor, int animation)
{
    if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(animation < 0 || animation >= rc_actor[actor].animation.size())
		return 0;

	return rc_actor[actor].animation[animation].fps;
}

void rc_setActorFrame(int actor, int frame)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

    switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            rc_actor[actor].animation[0].start_frame = frame;
            rc_actor[actor].animation[0].end_frame = frame;
            rc_actor[actor].animation[0].fps = 0;
            rc_actor[actor].current_animation_loop = 0;
            rc_actor[actor].isPlaying = true;
            rc_actor[actor].current_animation = 0;
            node->setCurrentFrame(frame);
            break;
    }
}

void rc_setActorAnimationFrames(int actor, int animation, int start_frame, int end_frame)
{
    if(actor < 0 || actor >= rc_actor.size())
        return;

	if(animation < 0 || animation >= rc_actor[actor].animation.size())
		return;

    switch(rc_actor[actor].node_type)
    {
        case RC_NODE_TYPE_MESH:
            rc_actor[actor].animation[animation].start_frame = start_frame;
            rc_actor[actor].animation[animation].end_frame = end_frame;

            if(animation == rc_actor[actor].current_animation)
            {
            	irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
				node->setFrameLoop(start_frame, end_frame);
            }
            break;
    }
}

void rc_startActorTransition(int actor, double frame, double transition_time)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;

	if(rc_actor[actor].transition)
		return;

    switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setTransitionTime(transition_time);
            //node->setJointMode(irr::scene::EJUOR_CONTROL); //This is actually called in setTransitionTime()
            node->setCurrentFrame(frame);
            rc_actor[actor].transition_frame = frame;
            rc_actor[actor].transition = true;
            rc_actor[actor].transition_time = transition_time;
            rc_actor[actor].transition_start_time = ((double)SDL_GetTicks())/1000.0;
            rc_actor[actor].current_animation = RC_ANIMATION_TRANSITION;
            rc_transition_actor.push_back(actor);
    }
}

double rc_getActorTransitionTime(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return 0;

	if(rc_actor[actor].transition)
		return rc_actor[actor].transition_time;

    return 0;
}


void rc_stopActorTransition(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return;


    switch(rc_actor[actor].node_type)
    {
    	case RC_NODE_TYPE_MESH:
            irr::scene::IAnimatedMeshSceneNode* node = (irr::scene::IAnimatedMeshSceneNode*)rc_actor[actor].mesh_node;
            node->setTransitionTime(0);
            node->setJointMode(irr::scene::EJUOR_NONE);
            rc_actor[actor].transition = false;
            rc_actor[actor].transition_time = 0;

            rc_setActorFrame(actor, rc_actor[actor].transition_frame);

            for(int i = 0; i < rc_transition_actor.size();)
			{
				if(rc_transition_actor[i] == actor)
				{
					rc_transition_actor.erase(i);
				}
				else
					i++;
			}
    }
}

bool rc_actorIsInTransition(int actor)
{
	if(actor < 0 || actor >= rc_actor.size())
        return false;

	return rc_actor[actor].transition;
}


#endif // RC_ACTOR_ANIMATION_H_INCLUDED
