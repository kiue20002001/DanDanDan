#include "DanDan_First.h"
USING_NS_CC;
bool DanDan::onTouchBegan(cocos2d::Touch* touch,cocos2d::Event* event){
    Rect targetBox;
    Point touchPoint = Vec2(touch->getLocationInView().x, visibleSize.height-touch->getLocationInView().y);
    
    //うえ
    auto target = (Sprite*)this->getChildByTag(201);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        PlayerStop();
        PlayerAction(PlayerStopTag-200,Time,-1);
        int n=PlayerStopTag;
        if(MapDate[PlayerX][PlayerY-1]){
            if(MonsterDate[PlayerX][PlayerY-1]){
                shiftMap(0,-1,Time);
                shiftMonster(0,-1,Time);
                PlayerY++;
            }else{
                PlayerAction(PlayerStopTag+2-200,Time,1);
                PlayerStopTag=n;
                //したの攻撃アクション
            }
        }
        log("Map=%d",MapDate[PlayerX][PlayerY]);
        log("うえ=X%d:Y%d",PlayerX,PlayerY);
        return true;
    }
    //ひだり
    target = (Sprite*)this->getChildByTag(202);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        PlayerStop();
        PlayerAction(1,Time,-1);
        int n=PlayerStopTag;
        if(MapDate[PlayerX-1][PlayerY]){
            if(MonsterDate[PlayerX-1][PlayerY]){
                shiftMap(1,0,Time);
                shiftMonster(1,0,Time);
                PlayerX--;
            }else{
                PlayerAction(PlayerStopTag+2-200,Time,1);
                PlayerStopTag=n;
            }
        }
        log("Map=%d",MapDate[PlayerX][PlayerY]);
        log("ひだり=X%d:Y%d",PlayerX,PlayerY);
        return true;
    }
    //みぎ
    target = (Sprite*)this->getChildByTag(203);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        PlayerStop();
        PlayerAction(5,Time,-1);
        int n=PlayerStopTag;
        if(MapDate[PlayerX+1][PlayerY]){
            if(MonsterDate[PlayerX+1][PlayerY]){
                shiftMap(-1,0,Time);
                shiftMonster(-1,0,Time);
                PlayerX++;
            }else{
                PlayerAction(PlayerStopTag+2-200,Time,1);
                PlayerStopTag=n;
                //みぎの攻撃アクション
            }
        }
        log("Map=%d",MapDate[PlayerX][PlayerY]);
        log("みぎ=X%d:Y%d",PlayerX,PlayerY);
        return true;
    }
    //した
    target = (Sprite*)this->getChildByTag(204);
    targetBox = target->getBoundingBox();
    if (targetBox.containsPoint(touchPoint))
    {
        PlayerStop();
        PlayerAction(PlayerStopTag-200,Time,-1);
        int n=PlayerStopTag;
        if(MapDate[PlayerX][PlayerY-1]){
            if(MonsterDate[PlayerX][PlayerY-1]){
                shiftMap(0,1,Time);
                shiftMonster(0,1,Time);
                PlayerY--;
            }else{
                PlayerAction(PlayerStopTag+2-200,Time,1);
                PlayerStopTag=n;
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
