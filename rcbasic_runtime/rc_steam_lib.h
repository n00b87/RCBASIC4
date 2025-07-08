#ifndef RC_STEAM_LIB_H_INCLUDED
#define RC_STEAM_LIB_H_INCLUDED

#if defined(RC_WINDOWS) || defined(RC_LINUX) || defined(RC_MAC)

#include <iostream>
#include <vector>
#include "rc_steam.h"

// Achievement array which will hold data about the achievements and their state
std::vector<Achievement_t> rc_achievements;

// Global access to Achievements object
CSteamAchievements*	g_SteamAchievements = NULL;


void rc_addSteamAchievement(std::string achievement_id_var, std::string achievement_name)
{
    int n = (int)rc_achievements.size();

    Achievement_t ach_n;
    ach_n.m_eAchievementID = n;
    ach_n.m_pchAchievementID = achievement_id_var.c_str();

    for(int i = 0; i < 128; i++)
        ach_n.m_rgchName[i] = achievement_name.substr(i, 1).c_str()[0];

    for(int i = 0; i < 256; i++)
        ach_n.m_rgchDescription[i] = '\0';

    ach_n.m_bAchieved = false;
    ach_n.m_iIconImage = 0;

    rc_achievements.push_back( ach_n );
}

void rc_clearSteamAchievements()
{
    rc_achievements.clear();
}

void rc_finalizeSteamAchievements()
{
    if(!g_SteamAchievements)
    {
        int ach_count = (int)rc_achievements.size();
        Achievement_t ach_array[ach_count];

        for(int i = 0; i < ach_count; i++)
            ach_array[i] = rc_achievements[i];

        g_SteamAchievements = new CSteamAchievements(ach_array, ach_count);
    }
}

bool rc_triggerSteamAchievement(std::string ach_name)
{
    if(!g_SteamAchievements)
    {
        return false;
    }

    return g_SteamAchievements->SetAchievement(ach_name.c_str());
}

#else

void rc_addSteamAchievement(std::string achievement_id_var, std::string achievement_name)
{
}

void rc_clearSteamAchievements()
{
}

void rc_finalizeSteamAchievements()
{
}

bool rc_triggerSteamAchievement(std::string ach_name)
{
    return false;
}

#endif // defined

#endif // RC_STEAM_LIB_H_INCLUDED
