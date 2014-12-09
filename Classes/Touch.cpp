#include "DanDan_First.h"
USING_NS_CC;
bool DanDan::onTouchBegan(cocos2d::Touch* touch,cocos2d::Event* event){
    Rect targetBox;
    Point touchPoint = Vec2(touch->getLocationInView().x, visibleSize.height-touch->getLocationInView().y);
    
    auto target = (Sprite*)this->getChildByTag(201);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        log("うえ");
//        stopPlayer();
        moveMap(0,-1);
        //anime move
        return true;
    }
    target = (Sprite*)this->getChildByTag(202);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        log("ひだり");
        stopPlayer();
        moveMap(1,0);
        movePlayer(1,1);
        return true;
    }
    target = (Sprite*)this->getChildByTag(203);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        log("みぎ");
        stopPlayer();
        moveMap(-1,0);
        movePlayer(2,1);
        return true;
    }
    target = (Sprite*)this->getChildByTag(204);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
//        stopPlayer();
        log("した");
        moveMap(0,1);
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
