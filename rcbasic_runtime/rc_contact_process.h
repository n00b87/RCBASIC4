#ifndef RC_CONTACT_PROCESS_H_INCLUDED
#define RC_CONTACT_PROCESS_H_INCLUDED

int rc_createActorContactProcess(int actorA, int actorB)
{
    if(actorA < 0 || actorA >= rc_actor.size())
        return -1;

    if(actorB < 0 || actorB >= rc_actor.size())
        return -1;

    int id = -1;

    int a_index = -1;
    int b_index = -1;

    for(int i = 0; i < rc_actor[actorA].physics.custom_contact.size(); i++)
    {
        int cc_id = rc_actor[actorA].physics.custom_contact[i];

        if(cc_id < 0 || cc_id >= rc_contact_process.size())
            continue;

        if(rc_contact_process[cc_id].actorA == actorA && rc_contact_process[cc_id].actorB == actorB)
        {
            id = cc_id;

            a_index = rc_contact_process[cc_id].index_a;
            b_index = rc_contact_process[cc_id].index_b;

            break;
        }
    }

    if(id < 0)
    {
        for(int i = 0; i < rc_contact_process.size(); i++)
        {
            if(rc_contact_process[i].actorA < 0)
            {
                id = i;
                break;
            }
        }
    }

    if(id < 0)
    {
        id = rc_contact_process.size();
        rc_custom_contact c;
        rc_contact_process.push_back(c);

        if(a_index < 0 || a_index >= rc_actor[actorA].physics.custom_contact.size())
        {
            for(int i = 0; i < rc_actor[actorA].physics.custom_contact.size(); i++)
            {
                if(rc_actor[actorA].physics.custom_contact[i] < 0)
                {
                    a_index = i;
                    break;
                }
            }

            if(a_index < 0)
            {
                a_index = rc_actor[actorA].physics.custom_contact.size();
                rc_actor[actorA].physics.custom_contact.push_back(id);
            }
            else
            {
                rc_actor[actorA].physics.custom_contact[a_index] = id;
            }
        }
        else
        {
            rc_actor[actorA].physics.custom_contact[a_index] = id;
        }

        if(b_index < 0 || b_index >= rc_actor[actorB].physics.custom_contact.size())
        {
            for(int i = 0; i < rc_actor[actorB].physics.custom_contact.size(); i++)
            {
                if(rc_actor[actorB].physics.custom_contact[i] < 0)
                {
                    b_index = i;
                    break;
                }
            }

            if(b_index < 0)
            {
                b_index = rc_actor[actorB].physics.custom_contact.size();
                rc_actor[actorB].physics.custom_contact.push_back(id);
            }
            else
            {
                rc_actor[actorB].physics.custom_contact[b_index] = id;
            }
        }
        else
        {
            rc_actor[actorB].physics.custom_contact[b_index] = id;
        }
    }

    rc_contact_process[id].actorA = actorA;
    rc_contact_process[id].actorB = actorB;
    rc_contact_process[id].index_a = a_index;
    rc_contact_process[id].index_b = b_index;
    rc_contact_process[id].use_appliedImpulse = false;
    rc_contact_process[id].use_combinedFriction = false;
    rc_contact_process[id].use_combinedRestitution = false;
    rc_contact_process[id].use_combinedRollingFriction = false;
    rc_contact_process[id].use_combinedSpinningFriction = false;
    rc_contact_process[id].use_contactCFM = false;
    rc_contact_process[id].use_contactERP = false;
    rc_contact_process[id].use_frictionCFM = false;
    rc_contact_process[id].use_lifeTime = false;

    rc_contact_process[id].m_appliedImpulse = -1;
    rc_contact_process[id].m_combinedFriction = -1;
    rc_contact_process[id].m_combinedRestitution = -1;
    rc_contact_process[id].m_combinedRollingFriction = -1;
    rc_contact_process[id].m_combinedSpinningFriction = -1;
    rc_contact_process[id].m_contactCFM = -1;
    rc_contact_process[id].m_contactERP = -1;
    rc_contact_process[id].m_frictionCFM = -1;
    rc_contact_process[id].m_lifeTime = -1;


    return id;
}

void rc_deleteActorContactProcess(int contact_id)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return;

    int actorA = rc_contact_process[contact_id].actorA;
    int actorB = rc_contact_process[contact_id].actorB;
    int indexA = rc_contact_process[contact_id].index_a;
    int indexB = rc_contact_process[contact_id].index_b;

    if(indexA >= 0 && indexA < rc_actor[actorA].physics.custom_contact.size())
    {
        rc_actor[actorA].physics.custom_contact[indexA] = -1;
    }

    if(indexB >= 0 && indexB < rc_actor[actorB].physics.custom_contact.size())
    {
        rc_actor[actorB].physics.custom_contact[indexB] = -1;
    }

    rc_contact_process[contact_id].actorA = -1;
    rc_contact_process[contact_id].actorB = -1;

    rc_contact_process[contact_id].index_a = -1;
    rc_contact_process[contact_id].index_b = -1;
}

int rc_getActorContactProcess(int actorA, int actorB)
{
    if(actorA < 0 || actorA >= rc_actor.size())
        return -1;

    if(actorB < 0 || actorB >= rc_actor.size())
        return -1;

    int id = -1;

    for(int i = 0; i < rc_contact_process.size(); i++)
    {
        if(rc_contact_process[i].actorA == actorA && rc_contact_process[i].actorB == actorB)
        {
            id = i;
            break;
        }
    }


    return id;
}

void rc_setActorContactImpulse(int contact_id, double impulse)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return;

    rc_contact_process[contact_id].m_appliedImpulse = impulse;
    rc_contact_process[contact_id].use_appliedImpulse = true;
}

void rc_setActorContactFriction(int contact_id, double friction)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return;

    rc_contact_process[contact_id].m_combinedFriction = friction;
    rc_contact_process[contact_id].use_combinedFriction = true;
}

void rc_setActorContactRestitution(int contact_id, double restitution)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return;

    rc_contact_process[contact_id].m_combinedRestitution = restitution;
    rc_contact_process[contact_id].use_combinedRestitution = true;
}

void rc_setActorContactRollingFriction(int contact_id, double roll_friction)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return;

    rc_contact_process[contact_id].m_combinedRollingFriction = roll_friction;
    rc_contact_process[contact_id].use_combinedRollingFriction = true;
}

void rc_setActorContactSpinningFriction(int contact_id, double spin_friction)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return;

    rc_contact_process[contact_id].m_combinedSpinningFriction = spin_friction;
    rc_contact_process[contact_id].use_combinedSpinningFriction = true;
}

void rc_setActorContactERP(int contact_id, double erp)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return;

    rc_contact_process[contact_id].m_contactERP = erp;
    rc_contact_process[contact_id].use_contactERP = true;
}

void rc_setActorContactCFM(int contact_id, double cfm)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return;

    rc_contact_process[contact_id].m_contactCFM = cfm;
    rc_contact_process[contact_id].use_contactCFM = true;
}

void rc_setActorContactFrictionCFM(int contact_id, double friction_cfm)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return;

    rc_contact_process[contact_id].m_frictionCFM = friction_cfm;
    rc_contact_process[contact_id].use_frictionCFM = true;
}

void rc_setActorContactLifeTime(int contact_id, double lifeTime)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return;

    rc_contact_process[contact_id].m_lifeTime = lifeTime;
    rc_contact_process[contact_id].use_lifeTime = true;
}




double rc_getActorContactImpulse(int contact_id)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return -1;

    return rc_contact_process[contact_id].m_appliedImpulse;
}

double rc_getActorContactFriction(int contact_id)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return -1;

    return rc_contact_process[contact_id].m_combinedFriction;
}


double rc_getActorContactRestitution(int contact_id)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return -1;

    return rc_contact_process[contact_id].m_combinedRestitution;
}

double rc_getActorContactRollingFriction(int contact_id)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return -1;

    return rc_contact_process[contact_id].m_combinedRollingFriction;
}

double rc_getActorContactSpinningFriction(int contact_id)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return -1;

    return rc_contact_process[contact_id].m_combinedSpinningFriction;
}

double rc_getActorContactERP(int contact_id)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return -1;

    return rc_contact_process[contact_id].m_contactERP;
}

double rc_getActorContactCFM(int contact_id)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return -1;

    return rc_contact_process[contact_id].m_contactCFM;
}

double rc_getActorContactFrictionCFM(int contact_id)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return -1;

    return rc_contact_process[contact_id].m_frictionCFM;
}

int rc_getActorContactLifeTime(int contact_id)
{
    if(contact_id < 0 || contact_id >= rc_contact_process.size())
        return -1;

    return rc_contact_process[contact_id].m_lifeTime;
}


#endif // RC_CONTACT_PROCESS_H_INCLUDED
