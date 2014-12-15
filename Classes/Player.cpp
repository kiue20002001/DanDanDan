//
//  Player.cpp
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//player_Tag#100
//Yazirushi_Tag#11-14
//Monster_Tag#300番台
//Action_Player#200番台を使用
//Map#1000番台を使用

#include "DanDan_First.h"
USING_NS_CC;

void DanDan::showPlayer()
{
    //player:tag100
    auto player = CCSprite::create("defo01.png",DanCell);
    player->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(player);
    player -> setTag(100);
    PlayerAction(1,Time,-1);
}



