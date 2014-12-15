//
//  Player.cpp
//  DanDan
//
//  Created by AbeShumpei on 2014/11/21.
//
//player_Tag#100
//Yazirushi_Tag#11-14
//Monster_Tag#300番台
//Action_Player#200番台を使用
//Map#1000番台を使用


#include "DanDan_First.h"
USING_NS_CC;
void DanDan::Dancing(int TagNumber)
{
    
    //拡大のアクション
    CCActionInterval* scaleAction = CCScaleTo::create(Time, Scale);
    //縮小のアクション
    CCActionInterval* scaleAction2 = CCScaleBy::create(Time,1./Scale);
    //拡大->縮小の順番にアクションを並べる
    CCSequence* sequence = CCSequence::create(scaleAction, scaleAction2, NULL);
    //無限リピート
    CCRepeat* repeat = CCRepeat::create(sequence, -1);
    //開始！
    getChildByTag(TagNumber)->runAction(repeat);
}
void DanDan::Jumping(int TagNumber)
{
    
    //時間：1秒　移動距離：X方向に300　ジャンプの最高点：400　ジャンプの回数：3回
    CCActionInterval* scaleAction = CCJumpBy::create(Time*2., ccp(0, 0), DanSize/10., 1);
    //拡大->縮小の順番にアクションを並べる
    CCSequence* sequence = CCSequence::create(scaleAction, NULL);
    //無限リピート
    CCRepeat* repeat = CCRepeat::create(sequence, -1);
    //開始！
    getChildByTag(TagNumber)->runAction(repeat);
}

void DanDan::Dancing_Effect(){
    //背景を踊らす
//    DanDan::Jumping(0);
    //背景を踊らす

    //十字キーを踊らす
    DanDan::Dancing(11);
    DanDan::Dancing(12);
    DanDan::Dancing(13);
    DanDan::Dancing(14);
    //十字キーを踊らす
    //Defokoを踊らす
    DanDan::Jumping(100);
    //Monster
    DanDan::Jumping(300);
    //Defokoを踊らす
}
