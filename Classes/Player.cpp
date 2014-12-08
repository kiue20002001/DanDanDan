//
//  Player.cpp
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//  tag showPlayer 100番台を使用
//player:tag100
//  tag movePlayer 200番台を使用
//うえ:tag 201
//ひだり:tag 202
//みぎ:tag 203
//した:tag 204

#include "DanDan_First.h"
USING_NS_CC;

void DanDan::showPlayer()
{
    //player:tag100
    auto player = CCSprite::create("defo01.png",DanCell);
    player->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(player);
    player -> setTag(100);
    
    CCAnimationCache* cache = CCAnimationCache::sharedAnimationCache();
    cache->addAnimationsWithFile("Defoko00_Gyaku_Anime.plist");
    CCAnimation* animationD = cache->animationByName("Defoko00_Gyaku_1");
    CCAnimate* actionD = CCAnimate::create(animationD);
    player->runAction(actionD);
    actionD->setTag(101);
    stopTag=101;
}
void DanDan::movePlayer()
{
    CCAnimationCache* cache = CCAnimationCache::sharedAnimationCache();
    cache->addAnimationsWithFile("Defoko00_Anime.plist");
    CCAnimation* animationD = cache->animationByName("Defoko00_1");
    CCAnimate* actionD = CCAnimate::create(animationD);
    CCSprite* player = (CCSprite*)this->getChildByTag(100);
    player->runAction(actionD);
    actionD->setTag(201);
    stopTag=201;
}
void DanDan::stopPlayer()
{
    CCSprite* player = (CCSprite*)this->getChildByTag(100);
    player->stopActionByTag(stopTag);
}

