#include "DanDan_First.h"
USING_NS_CC;
bool DanDan::onTouchBegan(cocos2d::Touch* touch,cocos2d::Event* event){
    Rect targetBox;
    Point touchPoint = Vec2(touch->getLocationInView().x, visibleSize.height-touch->getLocationInView().y);
    
    //うえ
    auto target = (Sprite*)this->getChildByTag(11);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        PlayerTouchAction(0,1);
        log("Map=%d",MapDate[PlayerX][PlayerY]);
        log("うえ=X%d:Y%d",PlayerX,PlayerY);
        return true;
    }
    //ひだり
    target = (Sprite*)this->getChildByTag(12);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        PlayerTouchAction(-1,0);
        log("Map=%d",MapDate[PlayerX][PlayerY]);
        log("ひだり=X%d:Y%d",PlayerX,PlayerY);
        return true;
    }
    //みぎ
    target = (Sprite*)this->getChildByTag(13);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        PlayerTouchAction(1,0);
        log("Map=%d",MapDate[PlayerX][PlayerY]);
        log("みぎ=X%d:Y%d",PlayerX,PlayerY);
        return true;
    }
    //した
    target = (Sprite*)this->getChildByTag(14);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        PlayerTouchAction(0,-1);
        log("Map=%d",MapDate[PlayerX][PlayerY]);
        log("した=X%d:Y%d",PlayerX,PlayerY);
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
