//
//  Player.cpp
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//  tag showPlayer 100番台を使用
//player:tag100
//  tag movePlayer 200番台を使用
//map:tag 1000番台を使用

#include "DanDan_First.h"
USING_NS_CC;

void DanDan::showMap()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Tile_png.plist");
    auto Map1 = CCSprite::createWithSpriteFrameName("Tile_11.png");
    Map1->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    auto Map2 = CCSprite::createWithSpriteFrameName("Tile_11.png");
    Map2->setPosition(Vec2(DanSize*1.5, DanSize*0.5));
    Map1->addChild(Map2);
    this->addChild(Map1);
    Map1 -> setTag(1000);
}
void DanDan::moveMap(int x,int y)
{
    CCActionInterval* scaleAction = CCMoveBy::create(Time, ccp(DanSize*x, DanSize*y));
    CCSequence* sequence = CCSequence::create(scaleAction, NULL);
    CCRepeat* repeat = CCRepeat::create(sequence, 1);
    getChildByTag(1000)->runAction(repeat);
}
