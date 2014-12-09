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
void DanDan::createMap()
{
    for(int n=0;n<10;n++){
        MapDate[n][0]=false;
        MapDate[n][9]=false;
        MapDate[0][n]=false;
        MapDate[9][n]=false;
    }

    for(int x=1;x<9;x++){
        for(int y=1;y<9;y++){
            MapDate[x][y]=true;
        }
    }
    
}

void DanDan::showMap()
{
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Tile_png.plist");
    auto MapZero = CCSprite::createWithSpriteFrameName("Tile_11.png");
    MapZero->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    CCSprite *AddMap;
    for(int x=0;x<10;x++){
        for(int y=0;y<10;y++){
            if(MapDate[x][y]){
                AddMap = CCSprite::createWithSpriteFrameName("Tile_13.png");
            }else{
                AddMap = CCSprite::createWithSpriteFrameName("Tile_11.png");
            }
            AddMap->setPosition(Vec2(DanSize*(0.5+x), DanSize*(0.5+y)));
            MapZero->addChild(AddMap);
        }
    }
    this->addChild(MapZero);
    MapZero -> setTag(1000);
}

void DanDan::moveMap(int x,int y)
{
    CCActionInterval* scaleAction = CCMoveBy::create(Time, ccp(DanSize*x, DanSize*y));
    CCSequence* sequence = CCSequence::create(scaleAction, NULL);
    CCRepeat* repeat = CCRepeat::create(sequence, 1);
    getChildByTag(1000)->runAction(repeat);
}
void DanDan::defaultXY()
{
    PlayerX=5,PlayerY=5;
    moveMap(-PlayerX,-PlayerY);
}
