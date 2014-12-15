//Yazirushi_Tag#11-14
//うえ:tag 11
//ひだり:tag 12
//みぎ:tag 13
//した:tag 14
#include "DanDan_First.h"
USING_NS_CC;
void DanDan::showYazirushi()
{
    //うえ:tag 11
    auto Yazirushi_Ue = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Ue->setPosition(Vec2(visibleSize.width/10, visibleSize.height/2.-visibleSize.width/2.));
    Yazirushi_Ue->setRotation(90);
    this->addChild(Yazirushi_Ue,5);
    Yazirushi_Ue -> setTag(11);
    //ひだり:tag 12
    auto Yazirushi_Hidari = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Hidari->setPosition(Vec2(visibleSize.width/10, visibleSize.height/2.-visibleSize.width/10.*2));
    Yazirushi_Hidari->setRotation(0);
    this->addChild(Yazirushi_Hidari,5);
    Yazirushi_Hidari -> setTag(12);
    //みぎ:tag 13
    auto Yazirushi_Migi = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Migi->setPosition(Vec2(visibleSize.width/10*9, visibleSize.height/2.-visibleSize.width/10.*2));
    Yazirushi_Migi->setRotation(180);
    this->addChild(Yazirushi_Migi,5);
    Yazirushi_Migi -> setTag(13);
    //した:tag 14
    auto Yazirushi_Shita = Sprite::create("Yazirushi.png",DanCell);
    Yazirushi_Shita->setPosition(Vec2(visibleSize.width/10*9, visibleSize.height/2.-visibleSize.width/2.));
    Yazirushi_Shita->setRotation(270);
    this->addChild(Yazirushi_Shita,5);
    Yazirushi_Shita -> setTag(14);
    
    
}
