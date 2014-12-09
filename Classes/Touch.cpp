#include "DanDan_First.h"
USING_NS_CC;
bool DanDan::onTouchBegan(cocos2d::Touch* touch,cocos2d::Event* event){
    Rect targetBox;
    Point touchPoint = Vec2(touch->getLocationInView().x, visibleSize.height-touch->getLocationInView().y);
    
    auto target = (Sprite*)this->getChildByTag(201);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        if(MapDate[PlayerX][PlayerY+1]){
            moveMap(0,-1);
            PlayerY++;
        }
        log("うえ=X%d:Y%d",PlayerX,PlayerY);
        return true;
    }
    target = (Sprite*)this->getChildByTag(202);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        stopPlayer();
        movePlayer(1,1);
        if(MapDate[PlayerX-1][PlayerY]){
            moveMap(1,0);
            PlayerX--;
        }
        
        log("ひだり=X%d:Y%d",PlayerX,PlayerY);
        return true;
    }
    target = (Sprite*)this->getChildByTag(203);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        stopPlayer();
        movePlayer(2,1);
        if(MapDate[PlayerX+1][PlayerY]){
            moveMap(-1,0);
            PlayerX++;
        }
        log("みぎ=X%d:Y%d",PlayerX,PlayerY);
        return true;
    }
    target = (Sprite*)this->getChildByTag(204);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {

        if(MapDate[PlayerX][PlayerY-1]){
            moveMap(0,1);
            PlayerY--;
        }

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
