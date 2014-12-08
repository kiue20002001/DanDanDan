//
//  DanDan_First.h
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//

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

    //Player.cpp
    void showPlayer();
    int stopTag;
    void movePlayer();
    void stopPlayer();
    //Player.cpp
    
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
