//
// Created by andre on 13.05.16.
//

#include "DaedalusStdlib.h"
#include "DATFile.h"
#include "DaedalusVM.h"
#include <utils/logger.h>

#define REGISTER(cname, var)           datFile.registerMember(#cname "." #var, &cname::var, false)
#define REGISTER_IF_EXISTS(cname, var) datFile.registerMember(#cname "." #var, &cname::var, true )

void Daedalus::registerGothicEngineClasses(DaedalusVM& vm) {
  using namespace GEngineClasses;
  auto& datFile = vm.getDATFile();

  // the vm of the GOTHIC.DAT does not contain C_Menu and MENU.DAT's vm does not contain C_NPC
  // so we need to register only class members of existing classes
  auto classExists = [&vm](const char* className) {
    bool exists = vm.getDATFile().hasSymbolName(className);
    return exists && (vm.getDATFile().getSymbolByName(className).properties.elemProps.type==EParType_Class);
    };

  if(classExists("C_Npc")) {
    REGISTER(C_Npc, id);
    REGISTER(C_Npc, name);
    REGISTER(C_Npc, slot);
    REGISTER_IF_EXISTS(C_Npc, effect);
    REGISTER(C_Npc, npcType);
    REGISTER(C_Npc, flags);
    REGISTER(C_Npc, attribute);
    REGISTER_IF_EXISTS(C_Npc, hitChance);
    REGISTER(C_Npc, protection);
    REGISTER(C_Npc, damage);
    REGISTER(C_Npc, damagetype);
    REGISTER(C_Npc, guild);
    REGISTER(C_Npc, level);
    REGISTER(C_Npc, mission);
    REGISTER(C_Npc, fight_tactic);
    REGISTER(C_Npc, weapon);
    REGISTER(C_Npc, voice);
    REGISTER(C_Npc, voicePitch);
    REGISTER(C_Npc, bodymass);
    REGISTER(C_Npc, daily_routine);
    REGISTER(C_Npc, start_aistate);
    REGISTER(C_Npc, spawnPoint);
    REGISTER(C_Npc, spawnDelay);
    REGISTER(C_Npc, senses);
    REGISTER(C_Npc, senses_range);
    REGISTER(C_Npc, aivar);
    REGISTER(C_Npc, wp);
    REGISTER(C_Npc, exp);
    REGISTER(C_Npc, exp_next);
    REGISTER(C_Npc, lp);
    REGISTER_IF_EXISTS(C_Npc, bodyStateInterruptableOverride);
    REGISTER_IF_EXISTS(C_Npc, noFocus);
    }

  if(classExists("C_Focus")) {
    REGISTER(C_Focus, npc_longrange);
    REGISTER(C_Focus, npc_range1);
    REGISTER(C_Focus, npc_range2);
    REGISTER(C_Focus, npc_azi);
    REGISTER(C_Focus, npc_elevdo);
    REGISTER(C_Focus, npc_elevup);
    REGISTER(C_Focus, npc_prio);
    REGISTER(C_Focus, item_range1);
    REGISTER(C_Focus, item_range2);
    REGISTER(C_Focus, item_azi);
    REGISTER(C_Focus, item_elevdo);
    REGISTER(C_Focus, item_elevup);
    REGISTER(C_Focus, item_prio);
    REGISTER(C_Focus, mob_range1);
    REGISTER(C_Focus, mob_range2);
    REGISTER(C_Focus, mob_azi);
    REGISTER(C_Focus, mob_elevdo);
    REGISTER(C_Focus, mob_elevup);
    REGISTER(C_Focus, mob_prio);
    }

  if(classExists("C_Info")) {
    REGISTER(C_Info, npc);
    REGISTER(C_Info, nr);
    REGISTER(C_Info, important);
    REGISTER(C_Info, condition);
    REGISTER(C_Info, information);
    REGISTER(C_Info, description);
    REGISTER(C_Info, trade);
    REGISTER(C_Info, permanent);
    }

  if(classExists("C_ItemReact")) {
    REGISTER(C_ItemReact, npc);
    REGISTER(C_ItemReact, trade_item);
    REGISTER(C_ItemReact, trade_amount);
    REGISTER(C_ItemReact, requested_cat);
    REGISTER(C_ItemReact, requested_item);
    REGISTER(C_ItemReact, requested_amount);
    REGISTER(C_ItemReact, reaction);
    }

  if(classExists("C_Item")) {
    REGISTER(C_Item, id);
    REGISTER(C_Item, name);
    REGISTER(C_Item, nameID);
    REGISTER(C_Item, hp);
    REGISTER(C_Item, hp_max);
    REGISTER(C_Item, mainflag);
    REGISTER(C_Item, flags);
    REGISTER(C_Item, weight);
    REGISTER(C_Item, value);
    REGISTER(C_Item, damageType);
    REGISTER(C_Item, damageTotal);
    REGISTER(C_Item, damage);
    REGISTER(C_Item, wear);
    REGISTER(C_Item, protection);
    REGISTER(C_Item, nutrition);
    REGISTER(C_Item, cond_atr);
    REGISTER(C_Item, cond_value);
    REGISTER(C_Item, change_atr);
    REGISTER(C_Item, change_value);
    REGISTER(C_Item, magic);
    REGISTER(C_Item, on_equip);
    REGISTER(C_Item, on_unequip);
    REGISTER(C_Item, on_state);
    REGISTER(C_Item, owner);
    REGISTER(C_Item, ownerGuild);
    REGISTER(C_Item, disguiseGuild);
    REGISTER(C_Item, visual);
    REGISTER(C_Item, visual_change);
    REGISTER_IF_EXISTS(C_Item, effect);
    REGISTER(C_Item, visual_skin);
    REGISTER(C_Item, scemeName);
    REGISTER(C_Item, material);
    REGISTER(C_Item, munition);
    REGISTER(C_Item, spell);
    REGISTER(C_Item, range);
    REGISTER(C_Item, mag_circle);
    REGISTER(C_Item, description);
    REGISTER(C_Item, text);
    REGISTER(C_Item, count);
    REGISTER_IF_EXISTS(C_Item, inv_zbias);
    REGISTER_IF_EXISTS(C_Item, inv_rotx);
    REGISTER_IF_EXISTS(C_Item, inv_roty);
    REGISTER_IF_EXISTS(C_Item, inv_rotz);
    REGISTER_IF_EXISTS(C_Item, inv_animate);
    }

  if(classExists("C_Spell")) {
    REGISTER_IF_EXISTS(C_Spell, time_per_mana);
    REGISTER_IF_EXISTS(C_Spell, damage_per_level);
    REGISTER_IF_EXISTS(C_Spell, damageType);
    REGISTER_IF_EXISTS(C_Spell, spellType);
    REGISTER_IF_EXISTS(C_Spell, canTurnDuringInvest);
    REGISTER_IF_EXISTS(C_Spell, canChangeTargetDuringInvest);
    REGISTER_IF_EXISTS(C_Spell, isMultiEffect);
    REGISTER_IF_EXISTS(C_Spell, targetCollectAlgo);
    REGISTER_IF_EXISTS(C_Spell, targetCollectType);
    REGISTER_IF_EXISTS(C_Spell, targetCollectRange);
    REGISTER_IF_EXISTS(C_Spell, targetCollectAzi);
    REGISTER_IF_EXISTS(C_Spell, targetCollectElev);
    }

  if(classExists("C_Mission")) {
    REGISTER(C_Mission, name);
    REGISTER(C_Mission, description);
    REGISTER(C_Mission, duration);
    REGISTER(C_Mission, important);
    REGISTER(C_Mission, offerConditions);
    REGISTER(C_Mission, offer);
    REGISTER(C_Mission, successConditions);
    REGISTER(C_Mission, success);
    REGISTER(C_Mission, failureConditions);
    REGISTER(C_Mission, failure);
    REGISTER(C_Mission, obsoleteConditions);
    REGISTER(C_Mission, obsolete);
    REGISTER(C_Mission, running);
    }

  if(classExists("C_Menu")) {
    REGISTER(C_Menu, backPic);
    REGISTER(C_Menu, backWorld);
    REGISTER(C_Menu, posx);
    REGISTER(C_Menu, posy);
    REGISTER(C_Menu, dimx);
    REGISTER(C_Menu, dimy);
    REGISTER(C_Menu, alpha);
    REGISTER(C_Menu, musicTheme);
    REGISTER(C_Menu, eventTimerMSec);
    REGISTER(C_Menu, items);
    REGISTER(C_Menu, flags);
    REGISTER(C_Menu, defaultOutGame);
    REGISTER(C_Menu, defaultInGame);
    }

  if(classExists("C_Menu_Item")) {
    REGISTER(C_Menu_Item, fontName);
    REGISTER(C_Menu_Item, text);
    REGISTER(C_Menu_Item, backPic);
    REGISTER(C_Menu_Item, alphaMode);
    REGISTER(C_Menu_Item, alpha);
    REGISTER(C_Menu_Item, type);
    REGISTER(C_Menu_Item, onSelAction);
    REGISTER(C_Menu_Item, onSelAction_S);
    REGISTER(C_Menu_Item, onChgSetOption);
    REGISTER(C_Menu_Item, onChgSetOptionSection);
    REGISTER(C_Menu_Item, onEventAction);
    REGISTER(C_Menu_Item, posx);
    REGISTER(C_Menu_Item, posy);
    REGISTER(C_Menu_Item, dimx);
    REGISTER(C_Menu_Item, dimy);
    REGISTER(C_Menu_Item, sizeStartScale);
    REGISTER(C_Menu_Item, flags);
    REGISTER(C_Menu_Item, openDelayTime);
    REGISTER(C_Menu_Item, openDuration);
    REGISTER(C_Menu_Item, userfloat);
    REGISTER(C_Menu_Item, userString);
    REGISTER(C_Menu_Item, frameSizeX);
    REGISTER(C_Menu_Item, frameSizeY);
    REGISTER_IF_EXISTS(C_Menu_Item, hideIfOptionSectionSet);
    REGISTER_IF_EXISTS(C_Menu_Item, hideIfOptionSet);
    REGISTER_IF_EXISTS(C_Menu_Item, hideOnValue);
    }

  if(classExists("C_SFX")) {
    REGISTER(C_SFX, file);
    REGISTER(C_SFX, pitchOff);
    REGISTER(C_SFX, pitchVar);
    REGISTER(C_SFX, vol);
    REGISTER(C_SFX, loop);
    REGISTER(C_SFX, loopStartOffset);
    REGISTER(C_SFX, loopEndOffset);
    REGISTER(C_SFX, reverbLevel);
    REGISTER(C_SFX, pfxName);
    }

  if(classExists("CFx_Base")) {
    REGISTER(CFx_Base, visName_S);
    REGISTER(CFx_Base, visSize_S);
    REGISTER(CFx_Base, visAlpha);
    REGISTER(CFx_Base, visAlphaBlendFunc_S);
    REGISTER(CFx_Base, visTexAniFPS);
    REGISTER(CFx_Base, visTexAniIsLooping);
    REGISTER(CFx_Base, emTrjMode_S);
    REGISTER(CFx_Base, emTrjOriginNode);
    REGISTER(CFx_Base, emTrjTargetNode);
    REGISTER(CFx_Base, emTrjTargetRange);
    REGISTER(CFx_Base, emTrjTargetAzi);
    REGISTER(CFx_Base, emTrjTargetElev);
    REGISTER(CFx_Base, emTrjNumKeys);
    REGISTER(CFx_Base, emTrjNumKeysVar);
    REGISTER(CFx_Base, emTrjAngleElevVar);
    REGISTER(CFx_Base, emTrjAngleHeadVar);
    REGISTER(CFx_Base, emTrjKeyDistVar);
    REGISTER(CFx_Base, emTrjLoopMode_S);
    REGISTER(CFx_Base, emTrjEaseFunc_S);
    REGISTER(CFx_Base, emTrjEaseVel);
    REGISTER(CFx_Base, emTrjDynUpdateDelay);
    REGISTER(CFx_Base, emTrjDynUpdateTargetOnly);
    REGISTER(CFx_Base, emFXCreate_S);
    REGISTER(CFx_Base, emFXInvestOrigin_S);
    REGISTER(CFx_Base, emFXInvestTarget_S);
    REGISTER(CFx_Base, emFXTriggerDelay);
    REGISTER(CFx_Base, emFXCreatedOwnTrj);
    REGISTER(CFx_Base, emActionCollDyn_S);
    REGISTER(CFx_Base, emActionCollStat_S);
    REGISTER(CFx_Base, emFXCollStat_S);
    REGISTER(CFx_Base, emFXCollDyn_S);
    REGISTER(CFx_Base, emFXCollDynPerc_S);
    REGISTER(CFx_Base, emFXCollStatAlign_S);
    REGISTER(CFx_Base, emFXCollDynAlign_S);
    REGISTER(CFx_Base, emFXLifeSpan);
    REGISTER(CFx_Base, emCheckCollision);
    REGISTER(CFx_Base, emAdjustShpToOrigin);
    REGISTER(CFx_Base, emInvestNextKeyDuration);
    REGISTER(CFx_Base, emFlyGravity);
    REGISTER(CFx_Base, emSelfRotVel_S);
    REGISTER(CFx_Base, userString);
    REGISTER(CFx_Base, lightPresetName);
    REGISTER(CFx_Base, sfxID);
    REGISTER(CFx_Base, sfxIsAmbient);
    REGISTER(CFx_Base, sendAssessMagic);
    REGISTER(CFx_Base, secsPerDamage);
    }

  if(classExists("C_ParticleFX")) {
    REGISTER(C_ParticleFX, ppsValue);
    REGISTER(C_ParticleFX, ppsScaleKeys_S);
    REGISTER(C_ParticleFX, ppsIsLooping);
    REGISTER(C_ParticleFX, ppsIsSmooth);
    REGISTER(C_ParticleFX, ppsFPS);
    REGISTER(C_ParticleFX, ppsCreateEm_S);
    REGISTER(C_ParticleFX, ppsCreateEmDelay);
    REGISTER(C_ParticleFX, shpType_S);
    REGISTER(C_ParticleFX, shpFOR_S);
    REGISTER(C_ParticleFX, shpOffsetVec_S);
    REGISTER(C_ParticleFX, shpDistribType_S);
    REGISTER(C_ParticleFX, shpDistribWalkSpeed);
    REGISTER(C_ParticleFX, shpIsVolume);
    REGISTER(C_ParticleFX, shpDim_S);
    REGISTER(C_ParticleFX, shpMesh_S);
    REGISTER(C_ParticleFX, shpMeshRender_B);
    REGISTER(C_ParticleFX, shpScaleKeys_S);
    REGISTER(C_ParticleFX, shpScaleIsLooping);
    REGISTER(C_ParticleFX, shpScaleIsSmooth);
    REGISTER(C_ParticleFX, shpScaleFPS);
    REGISTER(C_ParticleFX, dirMode_S);
    REGISTER(C_ParticleFX, dirFOR_S);
    REGISTER(C_ParticleFX, dirModeTargetFOR_S);
    REGISTER(C_ParticleFX, dirModeTargetPos_S);
    REGISTER(C_ParticleFX, dirAngleHead);
    REGISTER(C_ParticleFX, dirAngleHeadVar);
    REGISTER(C_ParticleFX, dirAngleElev);
    REGISTER(C_ParticleFX, dirAngleElevVar);
    REGISTER(C_ParticleFX, velAvg);
    REGISTER(C_ParticleFX, velVar);
    REGISTER(C_ParticleFX, lspPartAvg);
    REGISTER(C_ParticleFX, lspPartVar);
    REGISTER(C_ParticleFX, flyGravity_S);
    REGISTER(C_ParticleFX, flyCollDet_B);
    REGISTER(C_ParticleFX, visName_S);
    REGISTER(C_ParticleFX, visOrientation_S);
    REGISTER(C_ParticleFX, visTexIsQuadPoly);
    REGISTER(C_ParticleFX, visTexAniFPS);
    REGISTER(C_ParticleFX, visTexAniIsLooping);
    REGISTER(C_ParticleFX, visTexColorStart_S);
    REGISTER(C_ParticleFX, visTexColorEnd_S);
    REGISTER(C_ParticleFX, visSizeStart_S);
    REGISTER(C_ParticleFX, visSizeEndScale);
    REGISTER(C_ParticleFX, visAlphaFunc_S);
    REGISTER(C_ParticleFX, visAlphaStart);
    REGISTER(C_ParticleFX, visAlphaEnd);
    REGISTER(C_ParticleFX, trlFadeSpeed);
    REGISTER(C_ParticleFX, trlTexture_S);
    REGISTER(C_ParticleFX, trlWidth);
    REGISTER(C_ParticleFX, mrkFadeSpeed);
    REGISTER(C_ParticleFX, mrkTexture_S);
    REGISTER(C_ParticleFX, mrkSize);
    REGISTER_IF_EXISTS(C_ParticleFX, flockMode);
    REGISTER_IF_EXISTS(C_ParticleFX, flockStrength);
    REGISTER_IF_EXISTS(C_ParticleFX, useEmittersFOR);
    REGISTER_IF_EXISTS(C_ParticleFX, timeStartEnd_S);
    REGISTER_IF_EXISTS(C_ParticleFX, m_bIsAmbientPFX);
    }

  if(classExists("C_MusicTheme")) {
    REGISTER(C_MusicTheme, file);
    REGISTER(C_MusicTheme, vol);
    REGISTER(C_MusicTheme, loop);
    REGISTER(C_MusicTheme, reverbMix);
    REGISTER(C_MusicTheme, reverbTime);
    REGISTER(C_MusicTheme, transType);
    REGISTER(C_MusicTheme, transSubType);
    }

  if(classExists("C_GilValues")) {
    REGISTER          (C_GilValues, water_depth_knee);
    REGISTER          (C_GilValues, water_depth_chest);
    REGISTER          (C_GilValues, jumpup_height);
    REGISTER          (C_GilValues, swim_time);
    REGISTER          (C_GilValues, dive_time);
    REGISTER          (C_GilValues, step_height);
    REGISTER          (C_GilValues, jumplow_height);
    REGISTER          (C_GilValues, jumpmid_height);
    REGISTER          (C_GilValues, slide_angle);
    REGISTER          (C_GilValues, slide_angle2);
    REGISTER          (C_GilValues, disable_autoroll);
    REGISTER          (C_GilValues, surface_align);
    REGISTER          (C_GilValues, climb_heading_angle);
    REGISTER          (C_GilValues, climb_horiz_angle);
    REGISTER          (C_GilValues, climb_ground_angle);
    REGISTER          (C_GilValues, fight_range_base);
    REGISTER          (C_GilValues, fight_range_fist);
    REGISTER_IF_EXISTS(C_GilValues, fight_range_g);
    REGISTER          (C_GilValues, fight_range_1hs);
    REGISTER          (C_GilValues, fight_range_1ha);
    REGISTER          (C_GilValues, fight_range_2hs);
    REGISTER          (C_GilValues, fight_range_2ha);
    REGISTER          (C_GilValues, falldown_height);
    REGISTER          (C_GilValues, falldown_damage);
    REGISTER          (C_GilValues, blood_disabled);
    REGISTER          (C_GilValues, blood_max_distance);
    REGISTER          (C_GilValues, blood_amount);
    REGISTER          (C_GilValues, blood_flow);
    REGISTER          (C_GilValues, blood_emitter);
    REGISTER          (C_GilValues, blood_texture);
    REGISTER          (C_GilValues, turn_speed);
    }

  if(classExists("C_FightAI")) {
    REGISTER(C_FightAI, move);
    }

  if(classExists("CCamSys")) {
    REGISTER(CCamSys, bestRange);
    REGISTER(CCamSys, minRange);
    REGISTER(CCamSys, maxRange);
    REGISTER(CCamSys, bestElevation);
    REGISTER(CCamSys, minElevation);
    REGISTER(CCamSys, maxElevation);
    REGISTER(CCamSys, bestAzimuth);
    REGISTER(CCamSys, minAzimuth);
    REGISTER(CCamSys, maxAzimuth);
    REGISTER(CCamSys, bestRotZ);
    REGISTER(CCamSys, minRotZ);
    REGISTER(CCamSys, maxRotZ);
    REGISTER(CCamSys, rotOffsetX);
    REGISTER(CCamSys, rotOffsetY);
    REGISTER(CCamSys, rotOffsetZ);
    REGISTER(CCamSys, targetOffsetX);
    REGISTER(CCamSys, targetOffsetY);
    REGISTER(CCamSys, targetOffsetZ);
    REGISTER(CCamSys, veloTrans);
    REGISTER(CCamSys, veloRot);
    REGISTER(CCamSys, translate);
    REGISTER(CCamSys, rotate);
    REGISTER(CCamSys, collision);
    }

  if(classExists("C_SVM")) {
    REGISTER_IF_EXISTS(C_SVM, MILGreetings);
    REGISTER_IF_EXISTS(C_SVM, PALGreetings);
    REGISTER_IF_EXISTS(C_SVM, Weather);
    REGISTER_IF_EXISTS(C_SVM, IGetYouStill);
    REGISTER_IF_EXISTS(C_SVM, DieEnemy);
    REGISTER_IF_EXISTS(C_SVM, DieMonster);
    REGISTER_IF_EXISTS(C_SVM, Addon_DieMonster);
    REGISTER_IF_EXISTS(C_SVM, Addon_DieMonster2);
    REGISTER          (C_SVM, DirtyThief);
    REGISTER          (C_SVM, HandsOff);
    REGISTER_IF_EXISTS(C_SVM, SheepKiller);
    REGISTER_IF_EXISTS(C_SVM, SheepKillerMonster);
    REGISTER_IF_EXISTS(C_SVM, YouMurderer);
    REGISTER_IF_EXISTS(C_SVM, DieStupidBeast);
    REGISTER_IF_EXISTS(C_SVM, YouDareHitMe);
    REGISTER          (C_SVM, YouAskedForIt);
    REGISTER_IF_EXISTS(C_SVM, ThenIBeatYouOutOfHere);
    REGISTER_IF_EXISTS(C_SVM, WhatDidYouDoInThere);
    REGISTER_IF_EXISTS(C_SVM, WillYouStopFighting);
    REGISTER_IF_EXISTS(C_SVM, KillEnemy);
    REGISTER_IF_EXISTS(C_SVM, EnemyKilled);
    REGISTER_IF_EXISTS(C_SVM, MonsterKilled);
    REGISTER_IF_EXISTS(C_SVM, Addon_MonsterKilled);
    REGISTER_IF_EXISTS(C_SVM, Addon_MonsterKilled2);
    REGISTER_IF_EXISTS(C_SVM, ThiefDown);
    REGISTER_IF_EXISTS(C_SVM, RumfummlerDown);
    REGISTER_IF_EXISTS(C_SVM, SheepAttackerDown);
    REGISTER_IF_EXISTS(C_SVM, KillMurderer);
    REGISTER_IF_EXISTS(C_SVM, StupidBeastKilled);
    REGISTER_IF_EXISTS(C_SVM, NeverHitMeAgain);
    REGISTER_IF_EXISTS(C_SVM, YouBetterShouldHaveListened);
    REGISTER_IF_EXISTS(C_SVM, GetUpAndBeGone);
    REGISTER_IF_EXISTS(C_SVM, NeverEnterRoomAgain);
    REGISTER_IF_EXISTS(C_SVM, ThereIsNoFightingHere);
    REGISTER_IF_EXISTS(C_SVM, SpareMe);
    REGISTER_IF_EXISTS(C_SVM, RunAway);
    REGISTER          (C_SVM, Alarm);
    REGISTER_IF_EXISTS(C_SVM, Guards);
    REGISTER          (C_SVM, Help);
    REGISTER_IF_EXISTS(C_SVM, GoodMonsterKill);
    REGISTER_IF_EXISTS(C_SVM, GoodKill);
    REGISTER          (C_SVM, notnow);
    REGISTER          (C_SVM, RunCoward);
    REGISTER          (C_SVM, GetOutOfHere);
    REGISTER          (C_SVM, WhyAreYouInHere);
    REGISTER_IF_EXISTS(C_SVM, YesGoOutOfHere);
    REGISTER          (C_SVM, WhatsThisSupposedToBe);
    REGISTER          (C_SVM, YouDisturbedMySlumber);
    REGISTER_IF_EXISTS(C_SVM, ITookYourGold);
    REGISTER_IF_EXISTS(C_SVM, ShitNoGold);
    REGISTER          (C_SVM, ITakeYourWeapon);
    REGISTER          (C_SVM, WhatAreYouDoing);
    REGISTER          (C_SVM, LookingForTroubleAgain);
    REGISTER          (C_SVM, StopMagic);
    REGISTER          (C_SVM, ISaidStopMagic);
    REGISTER          (C_SVM, WeaponDown);
    REGISTER          (C_SVM, ISaidWeaponDown);
    REGISTER          (C_SVM, WiseMove);
    REGISTER_IF_EXISTS(C_SVM, NextTimeYoureInForIt);
    REGISTER_IF_EXISTS(C_SVM, OhMyHead);
    REGISTER          (C_SVM, TheresAFight);
    REGISTER_IF_EXISTS(C_SVM, OhMyGodItsAFight);
    REGISTER_IF_EXISTS(C_SVM, GoodVictory);
    REGISTER_IF_EXISTS(C_SVM, NotBad);
    REGISTER_IF_EXISTS(C_SVM, OhMyGodHesDown);
    REGISTER_IF_EXISTS(C_SVM, CheerFriend01);
    REGISTER_IF_EXISTS(C_SVM, CheerFriend02);
    REGISTER_IF_EXISTS(C_SVM, CheerFriend03);
    REGISTER_IF_EXISTS(C_SVM, Ooh01);
    REGISTER_IF_EXISTS(C_SVM, Ooh02);
    REGISTER_IF_EXISTS(C_SVM, Ooh03);
    REGISTER_IF_EXISTS(C_SVM, WhatWasThat);
    REGISTER_IF_EXISTS(C_SVM, GetOutOfMyBed);
    REGISTER          (C_SVM, Awake);
    REGISTER_IF_EXISTS(C_SVM, abs_commander);
    REGISTER_IF_EXISTS(C_SVM, abs_monastery);
    REGISTER_IF_EXISTS(C_SVM, abs_farm);
    REGISTER_IF_EXISTS(C_SVM, abs_good);
    REGISTER_IF_EXISTS(C_SVM, sheepkiller_crime);
    REGISTER_IF_EXISTS(C_SVM, attack_crime);
    REGISTER_IF_EXISTS(C_SVM, theft_crime);
    REGISTER_IF_EXISTS(C_SVM, murder_crime);
    REGISTER_IF_EXISTS(C_SVM, pal_city_crime);
    REGISTER_IF_EXISTS(C_SVM, mil_city_crime);
    REGISTER_IF_EXISTS(C_SVM, city_crime);
    REGISTER_IF_EXISTS(C_SVM, mona_crime);
    REGISTER_IF_EXISTS(C_SVM, farm_crime);
    REGISTER_IF_EXISTS(C_SVM, oc_crime);
    REGISTER_IF_EXISTS(C_SVM, toughguy_attacklost);
    REGISTER_IF_EXISTS(C_SVM, toughguy_attackwon);
    REGISTER_IF_EXISTS(C_SVM, toughguy_playerattack);
    REGISTER_IF_EXISTS(C_SVM, gold_1000);
    REGISTER_IF_EXISTS(C_SVM, gold_950);
    REGISTER_IF_EXISTS(C_SVM, gold_900);
    REGISTER_IF_EXISTS(C_SVM, gold_850);
    REGISTER_IF_EXISTS(C_SVM, gold_800);
    REGISTER_IF_EXISTS(C_SVM, gold_750);
    REGISTER_IF_EXISTS(C_SVM, gold_700);
    REGISTER_IF_EXISTS(C_SVM, gold_650);
    REGISTER_IF_EXISTS(C_SVM, gold_600);
    REGISTER_IF_EXISTS(C_SVM, gold_550);
    REGISTER_IF_EXISTS(C_SVM, gold_500);
    REGISTER_IF_EXISTS(C_SVM, gold_450);
    REGISTER_IF_EXISTS(C_SVM, gold_400);
    REGISTER_IF_EXISTS(C_SVM, gold_350);
    REGISTER_IF_EXISTS(C_SVM, gold_300);
    REGISTER_IF_EXISTS(C_SVM, gold_250);
    REGISTER_IF_EXISTS(C_SVM, gold_200);
    REGISTER_IF_EXISTS(C_SVM, gold_150);
    REGISTER_IF_EXISTS(C_SVM, gold_100);
    REGISTER_IF_EXISTS(C_SVM, gold_90);
    REGISTER_IF_EXISTS(C_SVM, gold_80);
    REGISTER_IF_EXISTS(C_SVM, gold_70);
    REGISTER_IF_EXISTS(C_SVM, gold_60);
    REGISTER_IF_EXISTS(C_SVM, gold_50);
    REGISTER_IF_EXISTS(C_SVM, gold_40);
    REGISTER_IF_EXISTS(C_SVM, gold_30);
    REGISTER_IF_EXISTS(C_SVM, gold_20);
    REGISTER_IF_EXISTS(C_SVM, gold_10);
    REGISTER          (C_SVM, Smalltalk01);
    REGISTER          (C_SVM, Smalltalk02);
    REGISTER          (C_SVM, Smalltalk03);
    REGISTER          (C_SVM, Smalltalk04);
    REGISTER          (C_SVM, Smalltalk05);
    REGISTER          (C_SVM, Smalltalk06);
    REGISTER          (C_SVM, Smalltalk07);
    REGISTER          (C_SVM, Smalltalk08);
    REGISTER          (C_SVM, Smalltalk09);
    REGISTER          (C_SVM, Smalltalk10);
    REGISTER          (C_SVM, Smalltalk11);
    REGISTER          (C_SVM, Smalltalk12);
    REGISTER          (C_SVM, Smalltalk13);
    REGISTER          (C_SVM, Smalltalk14);
    REGISTER          (C_SVM, Smalltalk15);
    REGISTER          (C_SVM, Smalltalk16);
    REGISTER          (C_SVM, Smalltalk17);
    REGISTER          (C_SVM, Smalltalk18);
    REGISTER          (C_SVM, Smalltalk19);
    REGISTER          (C_SVM, Smalltalk20);
    REGISTER          (C_SVM, Smalltalk21);
    REGISTER          (C_SVM, Smalltalk22);
    REGISTER          (C_SVM, Smalltalk23);
    REGISTER          (C_SVM, Smalltalk24);
    REGISTER_IF_EXISTS(C_SVM, Smalltalk25);
    REGISTER_IF_EXISTS(C_SVM, Smalltalk26);
    REGISTER_IF_EXISTS(C_SVM, Smalltalk27);
    REGISTER_IF_EXISTS(C_SVM, Smalltalk28);
    REGISTER_IF_EXISTS(C_SVM, Smalltalk29);
    REGISTER_IF_EXISTS(C_SVM, Smalltalk30);
    REGISTER          (C_SVM, NoLearnNoPoints);
    REGISTER_IF_EXISTS(C_SVM, NoLearnOverPersonalMAX);
    REGISTER          (C_SVM, NoLearnYoureBetter);
    REGISTER_IF_EXISTS(C_SVM, YouLearnedSomething);
    REGISTER_IF_EXISTS(C_SVM, unterstadt);
    REGISTER_IF_EXISTS(C_SVM, oberstadt);
    REGISTER_IF_EXISTS(C_SVM, tempel);
    REGISTER_IF_EXISTS(C_SVM, markt);
    REGISTER_IF_EXISTS(C_SVM, galgen);
    REGISTER_IF_EXISTS(C_SVM, kaserne);
    REGISTER_IF_EXISTS(C_SVM, hafen);
    REGISTER_IF_EXISTS(C_SVM, whereto);
    REGISTER_IF_EXISTS(C_SVM, oberstadt_2_unterstadt);
    REGISTER_IF_EXISTS(C_SVM, unterstadt_2_oberstadt);
    REGISTER_IF_EXISTS(C_SVM, unterstadt_2_tempel);
    REGISTER_IF_EXISTS(C_SVM, unterstadt_2_hafen);
    REGISTER_IF_EXISTS(C_SVM, tempel_2_unterstadt);
    REGISTER_IF_EXISTS(C_SVM, tempel_2_markt);
    REGISTER_IF_EXISTS(C_SVM, tempel_2_galgen);
    REGISTER_IF_EXISTS(C_SVM, markt_2_tempel);
    REGISTER_IF_EXISTS(C_SVM, markt_2_kaserne);
    REGISTER_IF_EXISTS(C_SVM, markt_2_galgen);
    REGISTER_IF_EXISTS(C_SVM, galgen_2_tempel);
    REGISTER_IF_EXISTS(C_SVM, galgen_2_markt);
    REGISTER_IF_EXISTS(C_SVM, galgen_2_kaserne);
    REGISTER_IF_EXISTS(C_SVM, kaserne_2_markt);
    REGISTER_IF_EXISTS(C_SVM, kaserne_2_galgen);
    REGISTER_IF_EXISTS(C_SVM, hafen_2_unterstadt);
    REGISTER          (C_SVM, Dead);
    REGISTER          (C_SVM, Aargh_1);
    REGISTER          (C_SVM, Aargh_2);
    REGISTER          (C_SVM, Aargh_3);
    REGISTER_IF_EXISTS(C_SVM, addon_wrongarmor);
    REGISTER_IF_EXISTS(C_SVM, addon_wrongarmor_sld);
    REGISTER_IF_EXISTS(C_SVM, addon_wrongarmor_mil);
    REGISTER_IF_EXISTS(C_SVM, addon_wrongarmor_kdf);
    REGISTER_IF_EXISTS(C_SVM, addon_noarmor_bdt);
    REGISTER_IF_EXISTS(C_SVM, addon_diebandit);
    REGISTER_IF_EXISTS(C_SVM, addon_dirtypirate);
    REGISTER          (C_SVM, SC_HeyTurnAround);
    REGISTER_IF_EXISTS(C_SVM, SC_HeyTurnAround02);
    REGISTER_IF_EXISTS(C_SVM, SC_HeyTurnAround03);
    REGISTER_IF_EXISTS(C_SVM, SC_HeyTurnAround04);
    REGISTER          (C_SVM, SC_HeyWaitASecond);
    REGISTER          (C_SVM, DoesntWork);
    REGISTER          (C_SVM, PickBroke);
    REGISTER          (C_SVM, NeedKey);
    REGISTER          (C_SVM, NoMorePicks);
    REGISTER_IF_EXISTS(C_SVM, NoPickLockTalent);
    REGISTER_IF_EXISTS(C_SVM, NoSweeping);
    REGISTER_IF_EXISTS(C_SVM, picklockorkeymissing);
    REGISTER_IF_EXISTS(C_SVM, keymissing);
    REGISTER_IF_EXISTS(C_SVM, picklockmissing);
    REGISTER_IF_EXISTS(C_SVM, neveropen);
    REGISTER_IF_EXISTS(C_SVM, missingitem);
    REGISTER_IF_EXISTS(C_SVM, dontknow);
    REGISTER_IF_EXISTS(C_SVM, nothingtoget);
    REGISTER_IF_EXISTS(C_SVM, nothingtoget02);
    REGISTER_IF_EXISTS(C_SVM, nothingtoget03);
    REGISTER_IF_EXISTS(C_SVM, healshrine);
    REGISTER_IF_EXISTS(C_SVM, heallastshrine);
    REGISTER_IF_EXISTS(C_SVM, irdoraththereyouare);
    REGISTER_IF_EXISTS(C_SVM, scopensirdorathbook);
    REGISTER_IF_EXISTS(C_SVM, scopenslastdoor);
    REGISTER_IF_EXISTS(C_SVM, trade_1);
    REGISTER_IF_EXISTS(C_SVM, trade_2);
    REGISTER_IF_EXISTS(C_SVM, trade_3);
    REGISTER_IF_EXISTS(C_SVM, verstehe);
    REGISTER_IF_EXISTS(C_SVM, foundtreasure);
    REGISTER_IF_EXISTS(C_SVM, cantunderstandthis);
    REGISTER_IF_EXISTS(C_SVM, cantreadthis);
    REGISTER_IF_EXISTS(C_SVM, stoneplate_1);
    REGISTER_IF_EXISTS(C_SVM, stoneplate_2);
    REGISTER_IF_EXISTS(C_SVM, stoneplate_3);
    REGISTER_IF_EXISTS(C_SVM, cough);
    REGISTER_IF_EXISTS(C_SVM, hui);
    REGISTER_IF_EXISTS(C_SVM, Addon_ThisLittleBastard);
    REGISTER_IF_EXISTS(C_SVM, addon_openadanostemple);
    REGISTER_IF_EXISTS(C_SVM, attentat_addon_description);
    REGISTER_IF_EXISTS(C_SVM, attentat_addon_description2);
    REGISTER_IF_EXISTS(C_SVM, attentat_addon_pro);
    REGISTER_IF_EXISTS(C_SVM, attentat_addon_contra);
    REGISTER_IF_EXISTS(C_SVM, mine_addon_description);
    REGISTER_IF_EXISTS(C_SVM, addon_summonancientghost);
    REGISTER_IF_EXISTS(C_SVM, addon_ancientghost_notnear);
    REGISTER_IF_EXISTS(C_SVM, addon_gold_description);
    }
  }
