//
//  DanDan_First.h
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//
//player_Tag#100
//Yazirushi_Tag#11-14
//Monster_Tag#300番台
//Action_Player#200番台を使用
//Map#1000番台を使用

#ifndef __DanDan__DanDan_First__
#define __DanDan__DanDan_First__

#include "cocos2d.h"

class DanDan : public cocos2d::Layer
{
    //DaDan_first//
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    double DanSize;
    cocos2d::CCRect DanCell;
    
    //Map.cpp
    void createMap();
    void defaultXY();
    void showMap();
    void shiftMap(int x,int y,double MapTime);
    bool MapDate[100][100];
    //Map.cpp
    //Action.cpp
    int  PlayerStopTag;
    void PlayerStop();
    void PlayerAction(int x,double ActionTime,int n);
    void PlayerTouchAction(int x,int y);
    //Action.cpp
    //Player.cpp
    void showPlayer();
    int  PlayerX,PlayerY;//mapの位置
    //Player.cpp
    //Monster.cpp
    void createMonster();
    void showMonster();
    void moveMonster(int animeNumber,int moveNumber);
    void shiftMonster(int x,int y,double MonsterTime);
    void stopMonster();
    int  MonsterX,MonsterY;//mapの位置
    bool MonsterDate[100][100];
    void DamegedMonster(double MonsterTime);
    //Monster.cpp
    
    //Yazirushi.cpp
    void showYazirushi();
    //Yazirushi.cpp

    //Touch.cpp
    bool onTouchBegan(cocos2d::Touch* touch,cocos2d::Event* event);
    void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    //Touch.cpp

    //Effect.cpp
    double Time=1./4.;
    double Scale=1.2;
    void Dancing(int TagNumber);
    void Jumping(int TagNumber);
    void Dancing_Effect();

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(DanDan);
};

#endif // __DanDan_SCENE_H__
