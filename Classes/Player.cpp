//
//  Player.cpp
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//  tag Player 100番台を使用
//player:tag100
//うえ:tag 101
//ひだり:tag 102
//みぎ:tag 103
//した:tag 104

#include "DanDan_First.h"
USING_NS_CC;

void DanDan::showPlayer()
{
    //player:tag100
//    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Defo.plist");
//    CCSprite *player = CCSprite::createWithSpriteFrameName("Defo_D1.png");
    auto player = Sprite::create("defo01.png",DanCell);
    // position the sprite on the center of the screen
    player->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    // add the sprite as a child to this layer
    this->addChild(player);
    player -> setTag(100);
}

void DanDan::showYazirushi()
{
    //うえ:tag 101
    auto Yazirushi_Ue = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Ue->setPosition(Vec2(visibleSize.width/10, visibleSize.height/2.-visibleSize.width/2.));
    Yazirushi_Ue->setRotation(90);
    this->addChild(Yazirushi_Ue);
    Yazirushi_Ue -> setTag(101);
    //ひだり:tag 102
    auto Yazirushi_Hidari = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Hidari->setPosition(Vec2(visibleSize.width/10, visibleSize.height/2.-visibleSize.width/10.*2));
    Yazirushi_Hidari->setRotation(0);
    this->addChild(Yazirushi_Hidari);
    Yazirushi_Hidari -> setTag(102);
    //みぎ:tag 103
    auto Yazirushi_Migi = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Migi->setPosition(Vec2(visibleSize.width/10*9, visibleSize.height/2.-visibleSize.width/10.*2));
    Yazirushi_Migi->setRotation(180);
    this->addChild(Yazirushi_Migi);
    Yazirushi_Migi -> setTag(103);
    //した:tag 104
    auto Yazirushi_Shita = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Shita->setPosition(Vec2(visibleSize.width/10*9, visibleSize.height/2.-visibleSize.width/2.));
    Yazirushi_Shita->setRotation(270);
    this->addChild(Yazirushi_Shita);
    Yazirushi_Shita -> setTag(104);
    
}
