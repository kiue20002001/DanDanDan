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
    showHeart(1);
    showHeart(2);
}
void DanDan::showHeart(int x)
{
    //player:tag100
    auto Heart = CCSprite::create("Heart1.png",DanCell);
    Heart->setPosition(Vec2(visibleSize.width/2 + origin.x+DanSize*(2.75-0.5*x), visibleSize.height/2 + origin.y+DanSize*4.));
    Heart->setScale(0.5);
    this->addChild(Heart);
    Heart -> setTag(100+x);
//    DanDan::Dancing(100+x);
}




