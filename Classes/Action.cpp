//
//  Player.cpp
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//  tag showPlayer 100番台を使用
#include "DanDan_First.h"
USING_NS_CC;
void DanDan::PlayerAction(int x,double ActionTime,int n)
{
    CCSprite* player =(CCSprite *)this->getChildByTag(100);
    CCAnimation* animation =CCAnimation::create();
    CCAnimate* PkayerAct;
    
    auto cache = CCSpriteFrameCache::getInstance();
    cache->addSpriteFramesWithFile("Defoko_png.plist");
    
    for(int i=1;i<4;i++){
        auto str = __String::createWithFormat("Defoko_%x%i.png",x,i);
        SpriteFrame *sprite = cache->getSpriteFrameByName(str->getCString());
        animation->addSpriteFrame(sprite);
    }
    animation->setDelayPerUnit(ActionTime);
    animation->setLoops(n);

    PkayerAct = CCAnimate::create(animation);
    player->runAction(PkayerAct);
    PlayerStopTag=200+x;
    PkayerAct->setTag(PlayerStopTag);
    log("プレイヤータグ：：%d",PlayerStopTag);
}
void DanDan::PlayerStop()
{
    CCSprite* player = (CCSprite*)this->getChildByTag(100);
    player->stopActionByTag(PlayerStopTag);
}
