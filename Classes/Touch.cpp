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
            if(MonsterDate[PlayerX][PlayerY+1]){
                shiftMap(0,-1,Time);
                shiftMonster(0,-1,Time);
                PlayerY++;
            }else{
                //上の攻撃アクション
            }
        }
        log("Map=%d",MapDate[PlayerX][PlayerY]);
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
            log("①");
            if(MonsterDate[PlayerX-1][PlayerY]){
                log("②");
                shiftMap(1,0,Time);
                shiftMonster(1,0,Time);
                PlayerX--;
            }else{
                log("③");
                stopPlayer();
                movePlayer(4,3);
//                stopPlayer();
                this->scheduleOnce(schedule_selector(DanDan::LeftMovePlayer), Time*4);
            }
        }
        log("Map=%d",MapDate[PlayerX][PlayerY]);
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
            if(MonsterDate[PlayerX+1][PlayerY]){
                shiftMap(-1,0,Time);
                shiftMonster(-1,0,Time);
                PlayerX++;
            }else{
                //みぎの攻撃アクション
            }
        }
        log("Map=%d",MapDate[PlayerX][PlayerY]);
        log("みぎ=X%d:Y%d",PlayerX,PlayerY);
        return true;
    }
    target = (Sprite*)this->getChildByTag(204);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {

        if(MapDate[PlayerX][PlayerY-1]){
            if(MonsterDate[PlayerX][PlayerY-1]){
                shiftMap(0,1,Time);
                shiftMonster(0,1,Time);
                PlayerY--;
            }else{
                //したの攻撃アクション
            }
        }
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
