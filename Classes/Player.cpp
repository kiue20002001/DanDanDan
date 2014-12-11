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
    
    movePlayer(2,1);
}
void DanDan::movePlayer(int animeNumber,int moveNumber)
{
    std::string Anime_Str = "Defoko00_Anime_";
    Anime_Str += cocos2d::StringUtils::toString<int>(animeNumber);
    Anime_Str += ".plist";
    std::string Move_Str = "Defoko00_";
    Move_Str += cocos2d::StringUtils::toString<int>(moveNumber);
    
    
    CCAnimationCache* cache = CCAnimationCache::sharedAnimationCache();
    cache->addAnimationsWithFile(Anime_Str);
    CCAnimation* animationD = cache->animationByName(Move_Str);
    CCAnimate* actionD = CCAnimate::create(animationD);
    CCSprite* player = (CCSprite*)this->getChildByTag(100);
    player->runAction(actionD);
    stopTag=201;
    actionD->setTag(stopTag);
}
void DanDan::LeftMovePlayer(float delta)
{
    movePlayer(1,1);
}
void DanDan::RightMovePlayer(float delta)
{
    movePlayer(2,1);
}


void DanDan::stopPlayer()
{
    CCSprite* player = (CCSprite*)this->getChildByTag(100);
    player->stopActionByTag(stopTag);
}

