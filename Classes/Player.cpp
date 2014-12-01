//
//  Player.cpp
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//  tag showPlayer 100番台を使用
//player:tag100
//うえ:tag 101
//ひだり:tag 102
//みぎ:tag 103
//した:tag 104
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
}
void DanDan::movePlayer()
{
    CCAnimationCache* cache = CCAnimationCache::sharedAnimationCache();
    cache->addAnimationsWithFile("Defo_Walk.plist");
    CCAnimation* animationD = cache->animationByName("Defo_Walk_Ue");
    CCAnimate* actionD = CCAnimate::create(animationD);
    CCSprite* player = (CCSprite*)this->getChildByTag(100);
    player->runAction(actionD);
    actionD->setTag(201);
}

void DanDan::showYazirushi()
{
    //うえ:tag 101
    auto Yazirushi_Ue = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Ue->setPosition(Vec2(visibleSize.width/10, visibleSize.height/2.-visibleSize.width/2.));
    Yazirushi_Ue->setRotation(90);
    this->addChild(Yazirushi_Ue,5);
    Yazirushi_Ue -> setTag(101);
    //ひだり:tag 102
    auto Yazirushi_Hidari = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Hidari->setPosition(Vec2(visibleSize.width/10, visibleSize.height/2.-visibleSize.width/10.*2));
    Yazirushi_Hidari->setRotation(0);
    this->addChild(Yazirushi_Hidari,5);
    Yazirushi_Hidari -> setTag(102);
    //みぎ:tag 103
    auto Yazirushi_Migi = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Migi->setPosition(Vec2(visibleSize.width/10*9, visibleSize.height/2.-visibleSize.width/10.*2));
    Yazirushi_Migi->setRotation(180);
    this->addChild(Yazirushi_Migi,5);
    Yazirushi_Migi -> setTag(103);
    //した:tag 104
    auto Yazirushi_Shita = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Shita->setPosition(Vec2(visibleSize.width/10*9, visibleSize.height/2.-visibleSize.width/2.));
    Yazirushi_Shita->setRotation(270);
    this->addChild(Yazirushi_Shita,5);
    Yazirushi_Shita -> setTag(104);
}
bool DanDan::onTouchBegan(cocos2d::Touch* touch,cocos2d::Event* event){
    Rect targetBox;
    Point touchPoint = Vec2(touch->getLocationInView().x, visibleSize.height-touch->getLocationInView().y);

    auto target = (Sprite*)this->getChildByTag(101);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        log("うえ");
        return true;
    }
    target = (Sprite*)this->getChildByTag(102);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        log("ひだり");
        return true;
    }
    target = (Sprite*)this->getChildByTag(103);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        log("みぎ");
        return true;
    }
    target = (Sprite*)this->getChildByTag(104);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        log("した");
        return true;
    }
    
    return true;
}

void DanDan::onTouchMoved(cocos2d::Touch* touch,cocos2d::Event* event) {
    
    //タッチ中の処理
    
}

void DanDan::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event){
    
    //タッチが終わった時の処理
    
}
