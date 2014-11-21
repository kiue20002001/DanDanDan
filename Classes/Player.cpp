//
//  Player.cpp
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//

#include "DanDan_First.h"
USING_NS_CC;

void DanDan::showPlayer(Size visibleSize,Vec2 origin)
{
    //Create BackGround//
    auto player = Sprite::create("defo01.png");
    // position the sprite on the center of the screen
    player->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    // add the sprite as a child to this layer
    this->addChild(player, 0);
    
    
}
